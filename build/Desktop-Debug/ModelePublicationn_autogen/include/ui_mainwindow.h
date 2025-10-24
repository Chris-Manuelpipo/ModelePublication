/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableRessources;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnSauvegarder;
    QPushButton *btnSupprimer;
    QPushButton *btnPublier;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLineEdit *inputRangee;
    QLineEdit *inputPrix;
    QLabel *Prix_2;
    QLineEdit *inputSection;
    QLabel *Section_2;
    QLabel *Siege_2;
    QLabel *Rangee_2;
    QLineEdit *inputSiege;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1360, 701);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableRessources = new QTableWidget(centralwidget);
        if (tableRessources->columnCount() < 6)
            tableRessources->setColumnCount(6);
        tableRessources->setObjectName("tableRessources");
        tableRessources->setGeometry(QRect(560, 60, 671, 531));
        tableRessources->setMinimumSize(QSize(671, 531));
        tableRessources->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableRessources->setShowGrid(true);
        tableRessources->setSortingEnabled(false);
        tableRessources->setColumnCount(6);
        tableRessources->horizontalHeader()->setDefaultSectionSize(111);
        tableRessources->horizontalHeader()->setHighlightSections(false);
        tableRessources->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableRessources->horizontalHeader()->setStretchLastSection(false);
        tableRessources->verticalHeader()->setVisible(false);
        tableRessources->verticalHeader()->setCascadingSectionResizes(false);
        tableRessources->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableRessources->verticalHeader()->setStretchLastSection(false);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 390, 391, 101));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnSauvegarder = new QPushButton(widget);
        btnSauvegarder->setObjectName("btnSauvegarder");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("document-save")));
        btnSauvegarder->setIcon(icon);

        horizontalLayout_2->addWidget(btnSauvegarder);

        btnSupprimer = new QPushButton(widget);
        btnSupprimer->setObjectName("btnSupprimer");
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("user-trash")));
        btnSupprimer->setIcon(icon1);

        horizontalLayout_2->addWidget(btnSupprimer);

        btnPublier = new QPushButton(widget);
        btnPublier->setObjectName("btnPublier");
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("emblem-default")));
        btnPublier->setIcon(icon2);

        horizontalLayout_2->addWidget(btnPublier);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(80, 90, 341, 231));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        inputRangee = new QLineEdit(widget1);
        inputRangee->setObjectName("inputRangee");

        gridLayout->addWidget(inputRangee, 1, 1, 1, 1);

        inputPrix = new QLineEdit(widget1);
        inputPrix->setObjectName("inputPrix");

        gridLayout->addWidget(inputPrix, 3, 1, 1, 1);

        Prix_2 = new QLabel(widget1);
        Prix_2->setObjectName("Prix_2");

        gridLayout->addWidget(Prix_2, 3, 0, 1, 1);

        inputSection = new QLineEdit(widget1);
        inputSection->setObjectName("inputSection");

        gridLayout->addWidget(inputSection, 0, 1, 1, 1);

        Section_2 = new QLabel(widget1);
        Section_2->setObjectName("Section_2");

        gridLayout->addWidget(Section_2, 0, 0, 1, 1);

        Siege_2 = new QLabel(widget1);
        Siege_2->setObjectName("Siege_2");

        gridLayout->addWidget(Siege_2, 2, 0, 1, 1);

        Rangee_2 = new QLabel(widget1);
        Rangee_2->setObjectName("Rangee_2");

        gridLayout->addWidget(Rangee_2, 1, 0, 1, 1);

        inputSiege = new QLineEdit(widget1);
        inputSiege->setObjectName("inputSiege");

        gridLayout->addWidget(inputSiege, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1360, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnSauvegarder->setText(QCoreApplication::translate("MainWindow", "Sauvegarder", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        btnPublier->setText(QCoreApplication::translate("MainWindow", "Publier", nullptr));
        inputPrix->setInputMask(QString());
        inputPrix->setText(QString());
        Prix_2->setText(QCoreApplication::translate("MainWindow", "Prix :", nullptr));
        Section_2->setText(QCoreApplication::translate("MainWindow", "Section :", nullptr));
        Siege_2->setText(QCoreApplication::translate("MainWindow", "Si\303\250ge :", nullptr));
        Rangee_2->setText(QCoreApplication::translate("MainWindow", "Rang\303\251e :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
