#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);

    layoutSections = new QVBoxLayout(ui->groupSections_3);
    layoutRangees  = new QVBoxLayout(ui->groupRangees_3);
    layoutPrix     = new QVBoxLayout(ui->groupPrix_3);
    // Connexion de la barre de recherche
    connect(ui->inputRecherche_3, &QLineEdit::textChanged, this, &ClientWindow::filtrerTableau);


    //Charger les ressources publiées par l’administrateur
    gestionnaire.charger("places.txt");
    afficherPlaces();
    rafraichirTableau();

    //Initialisation du watcher
    watcher = new QFileSystemWatcher(this);
    watcher->addPath("places.txt");  //Surveiller le fichier des ressources

    //Connecter le signal à un slot
    connect(watcher, &QFileSystemWatcher::fileChanged, this, &ClientWindow::onFileChanged);
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::afficherPlaces(){
    const auto& ressources = gestionnaire.getRessources();
    ui->tableRessources->setRowCount(ressources.size());
    ui->tableRessources->setColumnCount(6);
    QStringList headers = {"ID", "Section", "Rangée", "Siège", "Prix (FCFA)", "Disponible"};
    ui->tableRessources->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < ressources.size(); ++i) {
        const auto& r = ressources[i];
        ui->tableRessources->setItem(i, 0, new QTableWidgetItem(QString::number(r.getId())));
        ui->tableRessources->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(r.getSection())));
        ui->tableRessources->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(r.getRangee())));
        ui->tableRessources->setItem(i, 3, new QTableWidgetItem(QString::number(r.getSiege())));
        ui->tableRessources->setItem(i, 4, new QTableWidgetItem(QString::number(r.getPrix())));
        ui->tableRessources->setItem(i, 5, new QTableWidgetItem(r.estDisponible() ? "Oui" : "Non"));
    }
}

void ClientWindow::onFileChanged(const QString &path)
{
    qDebug() << "Fichier modifié :" << path;

    //Recharger les nouvelles ressources
    gestionnaire.charger("places.txt");
    //afficherPlaces();
    rafraichirTableau();

    qDebug() << "Places affichées :" << path;

    //on réajoute le fichier au watcher
    watcher->addPath(path);
}


//Fonction pour raffraichir le tableau des places

void ClientWindow::rafraichirTableau() {
    const auto& ressources = gestionnaire.getRessources(); //retourne la liste des ressources

    int nbPub = 0;
    for (const auto& r : ressources)
        if (r.estDisponible()) ++nbPub;
    ui->tableRessources->setRowCount(nbPub);

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
        if (!r.estDisponible()) continue; // n'afficher que les places publiées

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

void ClientWindow::mettreAJourFiltres() {
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

void ClientWindow::filtrerTableau() {
    QString recherche = ui->inputRecherche_3->text().toLower();

    QString filtreSection, filtreRangee, filtrePrix;

    for (auto rb : ui->groupSections_3->findChildren<QRadioButton*>())
        if (rb->isChecked()) filtreSection = rb->text();

    for (auto rb : ui->groupRangees_3->findChildren<QRadioButton*>())
        if (rb->isChecked()) filtreRangee = rb->text();

    for (auto rb : ui->groupPrix_3->findChildren<QRadioButton*>())
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

void ClientWindow::majBoutons(QVBoxLayout *layout, const QString &valeur, QSet<QString>&) {
    QRadioButton *radio = new QRadioButton(valeur);
    layout->addWidget(radio);
    connect(radio, &QRadioButton::toggled, this, [=](bool checked){
        if (radio == dernierClic){
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


void ClientWindow::on_btnResetFiltres_3_clicked()
{
    for (auto rb : this->findChildren<QRadioButton*>()) {
        rb->setAutoExclusive(false);
        rb->setChecked(false);
        rb->setAutoExclusive(true);
    }
    ui->inputRecherche_3->clear();
    filtrerTableau();
}

