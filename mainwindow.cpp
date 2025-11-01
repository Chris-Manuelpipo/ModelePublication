#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), idEnCours(-1)
{
    ui->setupUi(this);

    // Charger les places depuis le fichier
    gestionnaire.charger("places.txt");

    // Initialiser les listes si nécessaire
    initialiserPlaces();

    // Mettre à jour les tableaux UI
    mettreAJourTables();

    // Rendre les champs non modifiables sauf le prix
    ui->inputSection->setReadOnly(true);
    ui->inputRangee->setReadOnly(true);
    ui->inputSiege->setReadOnly(true);
    ui->inputPrix->setReadOnly(false); // Prix reste modifiable

    // Remplir le formulaire quand une place non publiée est sélectionnée
    connect(ui->tableRessources_2, &QTableWidget::cellClicked, this, [this](int row, int col){
        Q_UNUSED(col);
        if (row < 0 || row >= placesNonPubliees.size()) return;

        idEnCours = placesNonPubliees[row].getId();
        ui->inputSection->setText(QString::fromStdString(placesNonPubliees[row].getSection()));
        ui->inputRangee->setText(QString::fromStdString(placesNonPubliees[row].getRangee()));
        ui->inputSiege->setText(QString::number(placesNonPubliees[row].getSiege()));
        ui->inputPrix->setText(QString::number(placesNonPubliees[row].getPrix()));
    });

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
        Ressource("A", "1", 1, 50000, false),
        Ressource("A", "1", 2, 50000, false),
        Ressource("B", "2", 1, 30000, false),
        Ressource("C", "3", 5, 10000, false)
    };
}

// Mettre à jour les deux tableaux
void MainWindow::mettreAJourTables()
{
    const auto& ressources = gestionnaire.getRessources();

    // ----- Table publiées -----
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

    // ----- Table non publiées -----
    ui->tableRessources_2->clear();
    int nbNonPub = 0;
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


// Publier une place
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

    QMessageBox::information(this, "Publication réussie", "La place a été publiée !");
}


// Supprimer une place publiée ie la ramener comme non publiée
// (Dépublier une place sélectionnée dans le tableau des publiées)

void MainWindow::on_btnSupprimer_clicked()
{
    int row = ui->tableRessources->currentRow();
    if (row < 0) return;

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
        QMessageBox::information(this, "Dépublication", "La place a été remise comme non publiée !");
    }
}

// Sauvegarder toutes les places publiées
void MainWindow::on_btnSauvegarder_clicked()
{
    // gestionnaire.vider(); // vider l'ancien contenu
    // for (auto& p : placesPubliees)
    //     gestionnaire.ajouter(p); // ajouter toutes les places publiées

    if (gestionnaire.sauvegarder("places.txt"))
        QMessageBox::information(this, "Succès", "Données sauvegardées !");
    else
        QMessageBox::warning(this, "Erreur", "Échec de la sauvegarde !");
}
