#pragma once
#include <QMainWindow>
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
    void on_btnSauvegarder_clicked();

private:
    Ui::MainWindow *ui;
    Publication gestionnaire;

    void rafraichirTableau();
};
