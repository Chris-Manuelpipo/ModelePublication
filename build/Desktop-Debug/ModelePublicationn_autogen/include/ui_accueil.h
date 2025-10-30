/********************************************************************************
** Form generated from reading UI file 'accueil.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCUEIL_H
#define UI_ACCUEIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accueil
{
public:
    QGridLayout *gridLayout;
    QPushButton *btnClient;
    QPushButton *btnAdmin;

    void setupUi(QWidget *accueil)
    {
        if (accueil->objectName().isEmpty())
            accueil->setObjectName("accueil");
        accueil->setWindowModality(Qt::NonModal);
        accueil->resize(813, 569);
        accueil->setMinimumSize(QSize(813, 425));
        gridLayout = new QGridLayout(accueil);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(100, 100, 100, 100);
        btnClient = new QPushButton(accueil);
        btnClient->setObjectName("btnClient");

        gridLayout->addWidget(btnClient, 1, 0, 1, 1);

        btnAdmin = new QPushButton(accueil);
        btnAdmin->setObjectName("btnAdmin");
        btnAdmin->setMinimumSize(QSize(2, 2));
        btnAdmin->setMaximumSize(QSize(16777, 16777215));
        btnAdmin->setAutoDefault(false);
        btnAdmin->setFlat(false);

        gridLayout->addWidget(btnAdmin, 0, 0, 1, 1);


        retranslateUi(accueil);

        btnAdmin->setDefault(false);


        QMetaObject::connectSlotsByName(accueil);
    } // setupUi

    void retranslateUi(QWidget *accueil)
    {
        accueil->setWindowTitle(QCoreApplication::translate("accueil", "Publication des places d'un stade de football", nullptr));
        btnClient->setText(QCoreApplication::translate("accueil", "Client", nullptr));
        btnAdmin->setText(QCoreApplication::translate("accueil", "Administrateur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class accueil: public Ui_accueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCUEIL_H
