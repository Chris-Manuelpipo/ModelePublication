#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "accueil.h"

ClientWindow::ClientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);//bloquer le bouton aggrandir
    setFixedSize(size()); //bloquer aussi le redimensionnement
    layoutSections = new QVBoxLayout(ui->groupSections_3);
    layoutRangees  = new QVBoxLayout(ui->groupRangees_3);
    layoutPrix     = new QVBoxLayout(ui->groupPrix_3);
    //Connexion de la barre de recherche
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

//Action à la modification du fichier
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
    const auto& ressources = gestionnaire.getRessources();

    // Compter uniquement les places disponibles
    int nbPub = 0;
    for (const auto& r : ressources)
        if (r.estDisponible()) ++nbPub;

    ui->tableRessources->clear();
    ui->tableRessources->setRowCount(nbPub);
    ui->tableRessources->setColumnCount(6);
    QStringList headers = {"ID", "Section", "Rangée", "Siège", "Prix (FCFA)", "Disponible"};
    ui->tableRessources->setHorizontalHeaderLabels(headers);

    sectionsConnues.clear();
    rangeesConnues.clear();
    prixConnus.clear();

    int ligne = 0;
    for (const auto& r : ressources) {
        if (!r.estDisponible()) continue;

        QString section = QString::fromStdString(r.getSection());
        QString rangee  = QString::fromStdString(r.getRangee());
        QString prix    = QString::number(r.getPrix());

        ui->tableRessources->setItem(ligne, 0, new QTableWidgetItem(QString::number(r.getId())));
        ui->tableRessources->setItem(ligne, 1, new QTableWidgetItem(section));
        ui->tableRessources->setItem(ligne, 2, new QTableWidgetItem(rangee));
        ui->tableRessources->setItem(ligne, 3, new QTableWidgetItem(QString::number(r.getSiege())));
        ui->tableRessources->setItem(ligne, 4, new QTableWidgetItem(prix));
        ui->tableRessources->setItem(ligne, 5, new QTableWidgetItem("Oui"));

        sectionsConnues.insert(section);
        rangeesConnues.insert(rangee);
        prixConnus.insert(prix);

        ++ligne;
    }

    mettreAJourFiltres();
}

/*void ClientWindow::rafraichirTableau() {
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
}*/

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
        auto *sectionItem = ui->tableRessources->item(i, 1);
        auto *rangeeItem  = ui->tableRessources->item(i, 2);
        auto *prixItem    = ui->tableRessources->item(i, 4);
        auto *siegeItem    = ui->tableRessources->item(i, 3);

        //Vérifie que la ligne est complète
        if (!sectionItem || !rangeeItem || !prixItem || !siegeItem) continue;

        QString section = sectionItem->text();
        QString rangee  = rangeeItem->text();
        QString prix    = prixItem->text();
        QString siege    = siegeItem->text();

        bool visible = true;
        if (!filtreSection.isEmpty() && section != filtreSection) visible = false;
        if (!filtreRangee.isEmpty() && rangee != filtreRangee) visible = false;
        if (!filtrePrix.isEmpty() && prix != filtrePrix) visible = false;
        //La barre de recherche sert uniquement à rechercher une place à partir du siège
        if (!recherche.isEmpty() && !siege.toLower().contains(recherche))
            visible = false;

        ui->tableRessources->setRowHidden(i, !visible);
    }
}


/*void ClientWindow::filtrerTableau() {
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
}*/

/*void ClientWindow::majBoutons(QVBoxLayout *layout, const QString &valeur, QSet<QString>&) {
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
}*/

void ClientWindow::majBoutons(QVBoxLayout *layout, const QString &valeur, QSet<QString>&) {
    QRadioButton *radio = new QRadioButton(valeur);
    layout->addWidget(radio);

    connect(radio, &QRadioButton::clicked, this, [=]() mutable {
        // Si on clique sur le même bouton déjà sélectionné → on le décoche
        if (dernierClic == radio) {
            radio->setAutoExclusive(false);
            radio->setChecked(false);
            radio->setAutoExclusive(true);
            dernierClic = nullptr;
        } else {
            dernierClic = radio;
        }
        filtrerTableau();
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


void ClientWindow::on_pushButton_clicked()
{
    accueil *acc = new accueil();
    acc->show();
    this->close();

}

