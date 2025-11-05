#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "accueil.h"
#include <QMessageBox>

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




    //Rendre les champs non modifiables sauf le prix
    // ui->inputSection->setReadOnly(true);
    // ui->inputRangee->setReadOnly(true);
    // ui->inputSiege->setReadOnly(true);
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

// Initialisation d'exemple si le fichier est vide
void MainWindow::initialiserPlaces()
{
    if (!placesNonPubliees.empty() || !placesPubliees.empty())
        return; // déjà initialisé

    placesNonPubliees = {
        Ressource("VVIP", "A", 1, 50000, false),
        Ressource("VVIP", "A", 2, 50000, false),
        Ressource("VVIP", "A", 3, 50000, false),
        Ressource("VVIP", "A", 4, 50000, false),
        Ressource("VVIP", "A", 5, 50000, false),
        Ressource("VIP", "A", 1, 30000, false),
        Ressource("VIP", "A", 2, 30000, false),
        Ressource("VIP", "A", 3, 30000, false),
        Ressource("VIP", "A", 4, 30000, false),
        Ressource("VIP", "A", 5, 30000, false),
        Ressource("VIP", "B", 1, 30000, false),
        Ressource("VIP", "B", 2, 30000, false),
        Ressource("VIP", "B", 3, 30000, false),
        Ressource("VIP", "B", 4, 30000, false),
        Ressource("VIP", "B", 5, 30000, false),
        Ressource("STANDARD", "A", 1, 30000, false),
        Ressource("STANDARD", "A", 2, 30000, false),
        Ressource("STANDARD", "A", 3, 30000, false),
        Ressource("STANDARD", "A", 4, 30000, false),
        Ressource("STANDARD", "A", 5, 30000, false),
        Ressource("STANDARD", "B", 1, 30000, false),
        Ressource("STANDARD", "B", 2, 30000, false),
        Ressource("STANDARD", "B", 3, 30000, false),
        Ressource("STANDARD", "B", 4, 30000, false),
        Ressource("STANDARD", "B", 5, 30000, false),
        Ressource("CLASSIC", "A", 1, 10000, false),
        Ressource("CLASSIC", "A", 2, 10000, false),
        Ressource("CLASSIC", "A", 3, 10000, false),
        Ressource("CLASSIC", "A", 4, 10000, false),
        Ressource("CLASSIC", "A", 5, 10000, false),
        Ressource("CLASSIC", "B", 1, 10000, false),
        Ressource("CLASSIC", "B", 2, 10000, false),
        Ressource("CLASSIC", "B", 3, 10000, false),
        Ressource("CLASSIC", "B", 4, 10000, false),
        Ressource("CLASSIC", "B", 5, 10000, false),
        Ressource("CLASSIC", "C", 1, 10000, false),
        Ressource("CLASSIC", "C", 2, 10000, false),
        Ressource("CLASSIC", "C", 3, 10000, false),
        Ressource("CLASSIC", "C", 4, 10000, false),
        Ressource("CLASSIC", "C", 5, 10000, false),
    };

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

    // Mettre à jour prix si nécessaire
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



