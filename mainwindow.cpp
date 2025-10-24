#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gestionnaire.charger("places.txt");
    rafraichirTableau();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::rafraichirTableau() {
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

void MainWindow::on_btnPublier_clicked() {
    QString section = ui->inputSection->text();
    QString rangee = ui->inputRangee->text();
    int siege = ui->inputSiege->text().toInt();
    double prix = ui->inputPrix->text().toDouble();

    if (section.isEmpty() || rangee.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    Ressource res(section.toStdString(), rangee.toStdString(), siege, prix);
    if (gestionnaire.publier(res)) {
        rafraichirTableau();
    }
}

void MainWindow::on_btnSupprimer_clicked() {
    auto selected = ui->tableRessources->currentRow();
    if (selected >= 0) {
        int id = ui->tableRessources->item(selected, 0)->text().toInt();
        gestionnaire.retirer(id);
        rafraichirTableau();
    }
}

void MainWindow::on_btnSauvegarder_clicked() {
    if (gestionnaire.sauvegarder("places.txt")) {
        QMessageBox::information(this, "Succès", "Données sauvegardées !");
    }
}
