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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnAdmin;
    QPushButton *btnClient;

    void setupUi(QWidget *accueil)
    {
        if (accueil->objectName().isEmpty())
            accueil->setObjectName("accueil");
        accueil->resize(813, 425);
        gridLayoutWidget = new QWidget(accueil);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(200, 80, 391, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnAdmin = new QPushButton(gridLayoutWidget);
        btnAdmin->setObjectName("btnAdmin");
        btnAdmin->setAutoDefault(false);
        btnAdmin->setFlat(false);

        gridLayout->addWidget(btnAdmin, 0, 0, 1, 1);

        btnClient = new QPushButton(gridLayoutWidget);
        btnClient->setObjectName("btnClient");

        gridLayout->addWidget(btnClient, 1, 0, 1, 1);


        retranslateUi(accueil);

        btnAdmin->setDefault(false);


        QMetaObject::connectSlotsByName(accueil);
    } // setupUi

    void retranslateUi(QWidget *accueil)
    {
        accueil->setWindowTitle(QCoreApplication::translate("accueil", "Publication des places d'un stade de football", nullptr));
        btnAdmin->setText(QCoreApplication::translate("accueil", "Administrateur", nullptr));
        btnClient->setText(QCoreApplication::translate("accueil", "Client", nullptr));
    } // retranslateUi

};

namespace Ui {
    class accueil: public Ui_accueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCUEIL_H
