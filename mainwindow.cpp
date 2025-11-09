#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "accueil.h"
#include <QPrinter>
#include <QTextDocument>
#include <QFileDialog>
#include <QTextTable>
#include <QMessageBox>
// #include <QtCharts>
// #include <QtCharts/QChartView>
// #include <QtCharts/QBarSeries>
// #include <QtCharts/QBarSet>
// #include <QtCharts/QBarCategoryAxis>
// #include <QtCharts/QValueAxis>


// using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), idEnCours(-1)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);//bloquer le bouton aggrandir
    setFixedSize(size()); //bloquer aussi le redimensionnement
    //Initialiser les listes de places (non publiées)
    initialiserPlaces();

    //Charger les places depuis le fichier
    gestionnaire.charger("places.txt");
    remplirSelecteursDepuisPlaces();

    //Mettre à jour les tableaux UI
    mettreAJourTables();

    ui->inputPrix->setReadOnly(false); //Prix reste modifiable

    //Remplir le formulaire quand une place non publiée est sélectionnée
    connect(ui->tableRessources_2, &QTableWidget::cellClicked, this, [this](int row, int col){
        Q_UNUSED(col);
        if (row < 0 || row >= placesNonPubliees.size()) return;

        idEnCours = placesNonPubliees[row].getId();
        // ui->inputSection->setText(QString::fromStdString(placesNonPubliees[row].getSection()));
        // ui->inputRangee->setText(QString::fromStdString(placesNonPubliees[row].getRangee()));
        // ui->inputSiege->setText(QString::number(placesNonPubliees[row].getSiege()));
        ui->inputPrix->setText(QString::number(placesNonPubliees[row].getPrix()));
    });

    //selecteurs
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::filtrerPlaces);
    connect(ui->comboBox_2, &QComboBox::currentTextChanged, this, &MainWindow::filtrerPlaces);
    connect(ui->comboBox_3, &QComboBox::currentTextChanged, this, &MainWindow::filtrerPlaces);
    idEnCours = -1; // aucune sélection au départ
}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::initialiserPlaces()
{
    if (!placesNonPubliees.empty() || !placesPubliees.empty())
        return; // déjà initialisé

    struct TypePlace {
        QString type;
        QStringList rangees;
        int debutSiege;
        int finSiege;
        double prix;
    };

    // Définition simple des sections
    QVector<TypePlace> types = {
        {"VVIP", {"A", "B", "C", "D", "E"}, 1, 10, 50000},
        {"VIP", {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"}, 1, 10, 30000},
        {"STANDARD", {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"}, 1, 35, 20000},
        {"CLASSIC", {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"}, 1, 50, 10000}
    };

    // Génération automatique
    for (const auto &t : types) {
        for (const QString &rangee : t.rangees) {
            for (int i = t.debutSiege; i <= t.finSiege; ++i) {
                placesNonPubliees.emplace_back(
                    t.type.toStdString(),
                    rangee.toStdString(),
                    i,
                    t.prix,
                    false
                    );
            }
        }
    }
}



// Mettre à jour les deux tableaux
void MainWindow::mettreAJourTables()
{
    const auto& ressources = gestionnaire.getRessources();

    //Table publiées
    ui->tableRessources->clear();
    int nbPub = 0;
    for (const auto& r : ressources)
        if (r.estDisponible()) ++nbPub;
    ui->tableRessources->setRowCount(nbPub);
    ui->tableRessources->setColumnCount(6);
    ui->tableRessources->setHorizontalHeaderLabels({"ID", "Section", "Rangée", "Siège", "Prix", "Disponible"});

    int iPub = 0;
    for (const auto& r : ressources) {
        if (!r.estDisponible()) continue;
        ui->tableRessources->setItem(iPub, 0, new QTableWidgetItem(QString::number(r.getId())));
        ui->tableRessources->setItem(iPub, 1, new QTableWidgetItem(QString::fromStdString(r.getSection())));
        ui->tableRessources->setItem(iPub, 2, new QTableWidgetItem(QString::fromStdString(r.getRangee())));
        ui->tableRessources->setItem(iPub, 3, new QTableWidgetItem(QString::number(r.getSiege())));
        ui->tableRessources->setItem(iPub, 4, new QTableWidgetItem(QString::number(r.getPrix())));
        ui->tableRessources->setItem(iPub, 5, new QTableWidgetItem("Oui"));
        ++iPub;
    }

    //Table non publiées
    ui->tableRessources_2->clear();
    int nbNonPub = 0;
    //Pour mettre les places non publiees dans dans le tableau
    for (const auto& r : placesNonPubliees){
        if (gestionnaire.publier(r)) ++nbNonPub; ;
    }
    for (const auto& r : ressources)
        if (!r.estDisponible()) ++nbNonPub;
    ui->tableRessources_2->setRowCount(nbNonPub);
    ui->tableRessources_2->setColumnCount(5);
    ui->tableRessources_2->setHorizontalHeaderLabels({"ID", "Section", "Rangée", "Siège", "Prix"});

    int iNonPub = 0;
    for (const auto& r : ressources) {
        if (r.estDisponible()) continue;
        ui->tableRessources_2->setItem(iNonPub, 0, new QTableWidgetItem(QString::number(r.getId())));
        ui->tableRessources_2->setItem(iNonPub, 1, new QTableWidgetItem(QString::fromStdString(r.getSection())));
        ui->tableRessources_2->setItem(iNonPub, 2, new QTableWidgetItem(QString::fromStdString(r.getRangee())));
        ui->tableRessources_2->setItem(iNonPub, 3, new QTableWidgetItem(QString::number(r.getSiege())));
        ui->tableRessources_2->setItem(iNonPub, 4, new QTableWidgetItem(QString::number(r.getPrix())));
        ++iNonPub;
    }
}


//Publier une place
void MainWindow::on_btnPublier_clicked()
{
    int row = ui->tableRessources_2->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une place à publier !");
        return;
    }
    int id = ui->tableRessources_2->item(row, 0)->text().toInt();
    Ressource* res = gestionnaire.rechercher(id);
    if (!res) return;

    //Mettre le prix à jour si nécessaire
    res->setPrix(ui->inputPrix->text().toDouble());
    res->setDisponible(true);
    mettreAJourTables();
    gestionnaire.sauvegarder("places.txt");
    ui->inputPrix->clear();

    QMessageBox::information(this, "Publication réussie", "La place a été publiée !");
}


//Dépublier une place sélectionnée dans le tableau des publiées

void MainWindow::on_btnSupprimer_clicked()
{
    int row = ui->tableRessources->currentRow();
    if (row < 0){
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une place à publier !");
        return;
    }


    int id = ui->tableRessources->item(row, 0)->text().toInt();
    Ressource* res = gestionnaire.rechercher(id);
    if (!res) return;

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmation",
        QString("Voulez-vous vraiment dépublier la place id : '%1' ?").arg(id),
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        res->setDisponible(false);
        mettreAJourTables();
        gestionnaire.sauvegarder("places.txt");
        QMessageBox::information(this, "Dépublication", "La place a été dépubliée !");
    }
}

// Sauvegarder toutes les places publiées
void MainWindow::on_btnSauvegarder_clicked()
{
    if (gestionnaire.sauvegarder("places.txt"))
        QMessageBox::information(this, "Succès", "Données sauvegardées !");
    else
        QMessageBox::warning(this, "Erreur", "Échec de la sauvegarde !");
}

//Bouton retour à l'accueil
void MainWindow::on_pushButton_clicked()
{
    accueil *acc = new accueil();
    acc->show();
    this->close();

}

//selecteur
void MainWindow::filtrerPlaces()
{
    QString sectionChoisie = ui->comboBox->currentText();
    QString rangeeChoisie  = ui->comboBox_2->currentText();
    QString siegeChoisi    = ui->comboBox_3->currentText();

    for (int i = 0; i < ui->tableRessources_2->rowCount(); ++i) {
        bool visible = true;

        QString section = ui->tableRessources_2->item(i, 1)->text();  // colonne 1 = section
        QString rangee  = ui->tableRessources_2->item(i, 2)->text();  // colonne 2 = rangée
        QString siege   = ui->tableRessources_2->item(i, 3)->text();  // colonne 3 = siège

        if (sectionChoisie != "Toutes" && section != sectionChoisie)
            visible = false;
        if (rangeeChoisie != "Toutes" && rangee != rangeeChoisie)
            visible = false;
        if (siegeChoisi != "Tous" && siege != siegeChoisi)
            visible = false;

        ui->tableRessources_2->setRowHidden(i, !visible);
    }
}

//remplir le sélecteur de manière dynamique
void MainWindow::remplirSelecteursDepuisPlaces()
{
    //On vide d’abord les sélecteurs pour éviter les doublons
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();

    //Ensembles pour éviter les doublons
    QSet<QString> sections;
    QSet<QString> rangees;
    QSet<QString> sieges;

    //Parcourir les places non publiées
    for (const auto &r : placesNonPubliees) {
        sections.insert(QString::fromStdString(r.getSection()));
        rangees.insert(QString::fromStdString(r.getRangee()));
        sieges.insert(QString::number(r.getSiege()));
    }

    //Ajouter les options dans les QComboBox
    ui->comboBox->addItem("Toutes");
    for (const QString &s : sections)
        ui->comboBox->addItem(s);

    ui->comboBox_2->addItem("Toutes");
    for (const QString &r : rangees)
        ui->comboBox_2->addItem(r);

    ui->comboBox_3->addItem("Tous");
    for (const QString &s : sieges)
        ui->comboBox_3->addItem(s);
}




void MainWindow::on_pdfButton_clicked()
{
    // Choisir le fichier PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "*.pdf");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf")) fileName += ".pdf";

    //Récupération des ressources
    const auto& ressources = gestionnaire.getRessources();

    int total = ressources.size();
    int publiees = 0, nonPubliees = 0;
    QMap<QString, int> placesParSection;
    QMap<QString, int> placesParRangee;

    double totalPrix = 0;

    for (const auto& r : ressources) {
        if (r.estDisponible()) publiees++;
        else nonPubliees++;

        placesParSection[QString::fromStdString(r.getSection())]++;
        placesParRangee[QString::fromStdString(r.getRangee())]++;
        totalPrix += r.getPrix();
    }

    //Map imbriquée : section → (rangée → nombre de places)
    QMap<QString, QMap<QString, int>> statsSectionRangee;

    //Map pour compter total, publiées et non publiées par section
    QMap<QString, int> totalParSection;
    QMap<QString, int> publieesParSection;
    QMap<QString, int> nonPublieesParSection;

    //Construire les statistiques
    for (const auto &r : ressources) {
        QString section = QString::fromStdString(r.getSection());
        QString rangee = QString::fromStdString(r.getRangee());

        // Compter les places totales et par rangée
        statsSectionRangee[section][rangee] += 1;
        totalParSection[section] += 1;

        // Distinguer publiées et non publiées
        if (r.estDisponible())
            publieesParSection[section] += 1;
        else
            nonPublieesParSection[section] += 1;
    }

    QString html;

    // === Titre principal ===
    html += "<div style='text-align:center; margin-bottom:30px;'>";
    html += "<h1 style='color:#27AE60; font-size:26px; border-bottom:3px solid #27AE60; "
            "display:inline-block; padding-bottom:6px;'>"
            "RAPPORT DÉTAILLÉ DES PLACES DU STADE"
            "</h1>";
    html += "<p style='font-size:14px; color:#555;'>"
            "Généré automatiquement par le système de gestion des ressources"
            "</p>";
    html += "</div>";

    // === Statistiques générales ===
    html += "<h2 style='color:#2ECC71;'>Statistiques générales</h2>";
    html += "<ul>";
    html += "<li><b>Nombre total de places :</b> " + QString::number(total) + "</li>";
    html += "<li><b>Places publiées :</b> " + QString::number(publiees) + "</li>";
    html += "<li><b>Places non publiées :</b> " + QString::number(nonPubliees) + "</li>";
    // html += "<li><b>Prix moyen :</b> " + QString::number(total ? totalPrix / total : 0, 'f', 2) + " FCFA</li>";
    html += "</ul>";

    // === Statistiques par section et rangée ===
    html += "<h3 style='color:#27AE60;'>Places par section et par rangée</h3>";
    for (auto sectionIt = statsSectionRangee.begin(); sectionIt != statsSectionRangee.end(); ++sectionIt) {
        QString section = sectionIt.key();
        html += "<h4 style='color:#2ECC71; margin-top:10px;'>" + section + "</h4><ul>";

        html += "<li><b style='color:black;'>Total places :</b> " + QString::number(totalParSection[section]) + "</li>";
        html += "<li><b style='color:#27AE60;'>Places publiées :</b> " + QString::number(publieesParSection[section]) + "</li>";
        html += "<li><b style='color:#E74C3C;'>Places non publiées :</b> " + QString::number(nonPublieesParSection[section]) + "</li>";

        const QMap<QString, int> &rangees = sectionIt.value();
        html += "<li><b>Détail par rangée :</b><ul>";
        for (auto rangeeIt = rangees.begin(); rangeeIt != rangees.end(); ++rangeeIt) {
            html += "<li>Rangée <b>" + rangeeIt.key() + "</b> : " +
                    QString::number(rangeeIt.value()) + " places</li>";
        }
        html += "</ul></li>";
        html += "</ul>";
    }



    // Créer l'objet QTextDocument
    QTextDocument doc;

    html += "<h2 style='color:#2ECC71;'>Liste des places</h2>";
    html += "<table border='1' cellspacing='0' cellpadding='4' width='100%'>";
    html += "<tr style='background-color:#27AE60; color:white;'><th>ID</th><th>Section</th><th>Rangée</th><th>Siège</th><th>Prix</th><th>Disponible</th></tr>";

    // Parcourir toutes les ressources (publiées + non publiées)
    //const auto& ressources = gestionnaire.getRessources();
    for (const auto &r : ressources) {
        html += "<tr>";
        html += "<td>" + QString::number(r.getId()) + "</td>";
        html += "<td>" + QString::fromStdString(r.getSection()) + "</td>";
        html += "<td>" + QString::fromStdString(r.getRangee()) + "</td>";
        html += "<td>" + QString::number(r.getSiege()) + "</td>";
        html += "<td>" + QString::number(r.getPrix()) + "</td>";
        html += "<td>" + QString(r.estDisponible() ? "Oui" : "Non") + "</td>";
        html += "</tr>";
    }
    html += "</table>";

    doc.setHtml(html);

    // Configurer l'imprimante PDF
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    // Générer le PDF
    doc.print(&printer);

    QMessageBox::information(this, "PDF généré", "Le fichier PDF a été enregistré à: " + fileName);
}
