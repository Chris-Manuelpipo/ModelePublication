#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QWidget>

namespace Ui {
class accueil;
}

class accueil : public QWidget
{
    Q_OBJECT

public:
    explicit accueil(QWidget *parent = nullptr);
    ~accueil();

private slots:
    void on_btnAdmin_clicked();
    void on_btnClient_clicked();

private:
    Ui::accueil *ui;
};

#endif // ACCUEIL_H
