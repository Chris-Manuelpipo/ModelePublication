#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "clientwindow.h" //Pour mettre à jour les filtres après publication

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    layoutSections = new QVBoxLayout(ui->groupSections);
    layoutRangees  = new QVBoxLayout(ui->groupRangees);
    layoutPrix     = new QVBoxLayout(ui->groupPrix);

    // Connexion de la barre de recherche
    connect(ui->inputRecherche, &QLineEdit::textChanged, this, &MainWindow::filtrerTableau);
    //On affiche le tableau au démarrage de l'application
    gestionnaire.charger("places.txt");
    rafraichirTableau();

}
MainWindow::~MainWindow() {
    delete ui;
}


//Fonction pour raffraichir le tableau des places

void MainWindow::rafraichirTableau() {
    const auto& ressources = gestionnaire.getRessources(); //retourne la liste des ressources
    ui->tableRessources->setRowCount(ressources.size()); //le nombre de lignes du tableau correspond au nombre de places
    ui->tableRessources->setColumnCount(6);
    QStringList headers = {"ID", "Section", "Rangée", "Siège", "Prix (FCFA)", "Disponible"};
    ui->tableRessources->setHorizontalHeaderLabels(headers);

    //Nettoyer les ensembles pour les filtres
    sectionsConnues.clear();
    rangeesConnues.clear();
    prixConnus.clear();

    for (int i = 0; i < ressources.size(); ++i) {
        const auto& r = ressources[i];
        QString section = QString::fromStdString(r.getSection());
        QString rangee  = QString::fromStdString(r.getRangee());
        QString prix    = QString::number(r.getPrix());

        ui->tableRessources->setItem(i, 0, new QTableWidgetItem(QString::number(r.getId())));
        ui->tableRessources->setItem(i, 1, new QTableWidgetItem(section));
        ui->tableRessources->setItem(i, 2, new QTableWidgetItem(rangee));
        ui->tableRessources->setItem(i, 3, new QTableWidgetItem(QString::number(r.getSiege())));
        ui->tableRessources->setItem(i, 4, new QTableWidgetItem(prix));
        ui->tableRessources->setItem(i, 5, new QTableWidgetItem(r.estDisponible() ? "Oui" : "Non"));

        //Enregistre les filtres connus
        sectionsConnues.insert(section);
        rangeesConnues.insert(rangee);
        prixConnus.insert(prix);
    }

    mettreAJourFiltres();

}

//Fonction pour mettre les filtres à jour

void MainWindow::mettreAJourFiltres() {
    // Nettoyer les anciens boutons
    QLayoutItem *child;
    while ((child = layoutSections->takeAt(0)) != nullptr) delete child->widget();
    while ((child = layoutRangees->takeAt(0)) != nullptr) delete child->widget();
    while ((child = layoutPrix->takeAt(0)) != nullptr) delete child->widget();

    // Ajouter les nouveaux boutons
    for (const QString &val : sectionsConnues)
        majBoutons(layoutSections, val, sectionsConnues);
    for (const QString &val : rangeesConnues)
        majBoutons(layoutRangees, val, rangeesConnues);
    for (const QString &val : prixConnus)
        majBoutons(layoutPrix, val, prixConnus);
}

//Fonction de filtrage à partir des boutons radios

void MainWindow::majBoutons(QVBoxLayout *layout, const QString &valeur, QSet<QString>&) {
    QRadioButton *radio = new QRadioButton(valeur);
    layout->addWidget(radio);
    connect(radio, &QRadioButton::toggled, this, [=](bool checked){
        if (radio->isChecked() && radio == dernierClic){
            radio->setAutoExclusive(false);
            radio->setChecked(false);
            radio->setAutoExclusive(true);
            dernierClic = nullptr;
            filtrerTableau();
        }else{
            dernierClic = radio;
            filtrerTableau();}
    });
}

//Fonction de filtrage à partir de la barre de recherche

void MainWindow::filtrerTableau() {
    QString recherche = ui->inputRecherche->text().toLower();

    QString filtreSection, filtreRangee, filtrePrix;

    for (auto rb : ui->groupSections->findChildren<QRadioButton*>())
        if (rb->isChecked()) filtreSection = rb->text();

    for (auto rb : ui->groupRangees->findChildren<QRadioButton*>())
        if (rb->isChecked()) filtreRangee = rb->text();

    for (auto rb : ui->groupPrix->findChildren<QRadioButton*>())
        if (rb->isChecked()) filtrePrix = rb->text();

    for (int i = 0; i < ui->tableRessources->rowCount(); ++i) {
        QString section = ui->tableRessources->item(i, 1)->text();
        QString rangee  = ui->tableRessources->item(i, 2)->text();
        QString prix    = ui->tableRessources->item(i, 4)->text();

        bool visible = true;

        if (!filtreSection.isEmpty() && section != filtreSection) visible = false;
        if (!filtreRangee.isEmpty() && rangee != filtreRangee) visible = false;
        if (!filtrePrix.isEmpty() && prix != filtrePrix) visible = false;

        if (!recherche.isEmpty() &&
            !section.toLower().contains(recherche) &&
            !rangee.toLower().contains(recherche) &&
            !prix.toLower().contains(recherche))
            visible = false;

        ui->tableRessources->setRowHidden(i, !visible);
    }
}

//Fonction pour réinitialiser les filtres(Afficher toutes les places)

void MainWindow::on_btnResetFiltres_clicked() {
    for (auto rb : this->findChildren<QRadioButton*>()) {
        rb->setAutoExclusive(false);
        rb->setChecked(false);
        rb->setAutoExclusive(true);
    }
    ui->inputRecherche->clear();
    filtrerTableau();
}

void MainWindow::on_btnModifier_clicked(){

    int selected = ui->tableRessources->currentRow();

    if (selected < 0) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une ressource à modifier !");
        return;
    }

    // On récupère les données de la ligne sélectionnée
    idEnCours = ui->tableRessources->item(selected, 0)->text().toInt();
    QString section = ui->tableRessources->item(selected, 1)->text();
    QString rangee  = ui->tableRessources->item(selected, 2)->text();
    QString siege   = ui->tableRessources->item(selected, 3)->text();
    QString prix    = ui->tableRessources->item(selected, 4)->text();

    //On remplit les champs
    ui->inputSection->setText(section);
    ui->inputRangee->setText(rangee);
    ui->inputSiege->setText(siege);
    ui->inputPrix->setText(prix);

    QMessageBox::information(this, "Mode modification", "Modifiez les champs puis appuyez sur Publier pour valider.");

};

//Fonction pour publier une place

void MainWindow::on_btnPublier_clicked() {
    QString section = ui->inputSection->text();
    QString rangee = ui->inputRangee->text();
    int siege = ui->inputSiege->text().toInt();
    double prix = ui->inputPrix->text().toDouble();

    if (section.isEmpty() || rangee.isEmpty()  ) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }
    if(siege == 0 ){
        QMessageBox::warning(this, "Erreur", "Le numéro de siège est un entier positif !");
        return;
    }

    if(prix == 0 ){
        QMessageBox::warning(this, "Erreur", "Le prix d'une place ne peut ni etre une chaine ni nul!");
        return;
    }

    Ressource res(section.toStdString(), rangee.toStdString(), siege, prix);

    //Gérer la modification des ressources

    if (idEnCours == -1) {
        //Mode ajout
        if (gestionnaire.publier(res)) {
            rafraichirTableau();
        }else{
            QMessageBox::information(this, "Information", "Cette place a déjà été publiée !");
        }
    }
    //Modification

    else {
        //Mode modification
        if (gestionnaire.modifier(idEnCours, res)) {
            rafraichirTableau();
            QMessageBox::information(this, "Modifié", "La place a été mise à jour !");
            idEnCours = -1; // Reset du mode modification
        }else {
            QMessageBox::warning(this, "Erreur", "La modification a échoué !");
        }
    }


    // On vide les champs après action
    ui->inputSection->clear();
    ui->inputRangee->clear();
    ui->inputSiege->clear();
    ui->inputPrix->clear();
}

//Fonction pour supprimer une place

void MainWindow::on_btnSupprimer_clicked() {
    int selected = ui->tableRessources->currentRow();
    if (selected < 0) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une ligne à supprimer !");
        return;
    }

    int id = ui->tableRessources->item(selected, 0)->text().toInt(); //selected : ligne de la place à supprimer 0: colonne de l'ID


    //Boîte de confirmation
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(
        this,
        "Confirmation de suppression",
        QString("Voulez-vous vraiment supprimer cette place id : '%1' ?").arg(id),
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        gestionnaire.retirer(id);
        rafraichirTableau();
        QMessageBox::information(this, "Suppression", "La ressource a été supprimée avec succès !");
    }
}


//Fonction pour sauvegarder la publication dans le fichier places.txt

void MainWindow::on_btnSauvegarder_clicked(){
    if (gestionnaire.sauvegarder("places.txt")) {
        QMessageBox::information(this, "Succès", "Données sauvegardées !");
    }
}
