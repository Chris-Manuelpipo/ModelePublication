#pragma once
#include <QMainWindow>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QSet>
#include "Publication.hpp"
#include "Ressource.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnPublier_clicked();
    void on_btnSupprimer_clicked();
    //void on_btnModifier_clicked();
    void on_btnSauvegarder_clicked();
    //void on_tableRessources_2_itemSelectionChanged();
    //void on_btnResetFiltres_clicked();

    void on_pushButton_clicked();

private:
    int idEnCours = -1;
    Ui::MainWindow *ui;
    Publication gestionnaire;
    void initialiserPlaces();
    void rafraichirTableau();
    void mettreAJourTables();
    QVector<Ressource> placesNonPubliees;
    QVector<Ressource> placesPubliees;

    //void filtrerTableau();
    //void mettreAJourFiltres();


    //Pour créer dynamiquement les boutons radio
    //void majBoutons(QVBoxLayout* layout, const QString& valeur, QSet<QString>& ensemble);

    //Garde les valeurs connues ie celles qui ne seront plus ajoutées commme bouton radios

    //QSet<QString> sectionsConnues;
    //QSet<QString> rangeesConnues;
    //QSet<QString> prixConnus;

    //QVBoxLayout *layoutSections;
    //QVBoxLayout *layoutRangees;
    //QVBoxLayout *layoutPrix;

    //Décocher un bouton radio

    //QRadioButton *dernierClic = nullptr;
};
