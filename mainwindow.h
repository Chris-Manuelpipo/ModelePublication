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
    void on_btnDepublier_clicked();
    void on_btnSauvegarder_clicked();
    void on_pushButton_clicked();
    void filtrerPlaces();
    void on_pdfButton_clicked();

private:
    int idEnCours = -1;
    Ui::MainWindow *ui;
    Publication gestionnaire;
    void initialiserPlaces();
    void rafraichirTableau();
    void mettreAJourTables();
    void mettreAJourResume();
    void remplirSelecteursDepuisPlaces();
    QVector<Ressource> placesNonPubliees;
    QVector<Ressource> placesPubliees;
};
