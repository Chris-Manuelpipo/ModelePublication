#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QSet>
//Pour gérer la synchronisation du fichier texte chez le client
#include <QFileSystemWatcher>

#include "Publication.hpp"


namespace Ui {
class ClientWindow;


}

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

private slots:
    void onFileChanged(const QString &path);


    void on_btnResetFiltres_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::ClientWindow *ui;
    Publication gestionnaire;
    void afficherPlaces();
    //Surveille le changement du fichier de sauvegarde places.txt
    QFileSystemWatcher *watcher;
    //Pour créer dynamiquement les boutons radio
    void majBoutons(QVBoxLayout* layout, const QString& valeur, QSet<QString>& ensemble);
    void filtrerTableau();
    void rafraichirTableau();
    void mettreAJourFiltres();

    //Garde les valeurs connues ie celles qui ne seront plus ajoutées commme bouton radios

    QSet<QString> sectionsConnues;
    QSet<QString> rangeesConnues;
    QSet<QString> prixConnus;

    QVBoxLayout *layoutSections;
    QVBoxLayout *layoutRangees;
    QVBoxLayout *layoutPrix;

    //Pour pouvoir décocher les boutons radios
    QRadioButton *dernierClic = nullptr;


};

#endif // CLIENTWINDOW_H
