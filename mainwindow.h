#pragma once
#include <QMainWindow>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QSet>

#include "Publication.hpp"

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
    void on_btnMoodifier_clicked();
    void on_btnSauvegarder_clicked();
    void on_btnResetFiltres_clicked();

private:
    Ui::MainWindow *ui;
    Publication gestionnaire;

    void rafraichirTableau();
    void filtrerTableau();
    void mettreAJourFiltres();


    // Pour créer dynamiquement les boutons radio
    void majBoutons(QVBoxLayout* layout, const QString& valeur, QSet<QString>& ensemble);

    // Garde les valeurs connues
    QSet<QString> sectionsConnues;
    QSet<QString> rangeesConnues;
    QSet<QString> prixConnus;

    QVBoxLayout *layoutSections;
    QVBoxLayout *layoutRangees;
    QVBoxLayout *layoutPrix;
};
