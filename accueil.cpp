#include "accueil.h"
#include "ui_accueil.h"
#include "mainwindow.h"
#include "clientwindow.h"

accueil::accueil(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::accueil)
{
    ui->setupUi(this);
}

accueil::~accueil()
{
    delete ui;
}

void accueil::on_btnAdmin_clicked()
{
    MainWindow *admin = new MainWindow();
    admin->show();
    this->close();
}


void accueil::on_btnClient_clicked()
{
    ClientWindow *client = new ClientWindow();
    client->show();
    this->close();
}

