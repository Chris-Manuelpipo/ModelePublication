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
#include <QtWidgets/QGroupBox>
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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnSauvegarder;
    QPushButton *btnSupprimer;
    QPushButton *btnPublier;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *Section_2;
    QLineEdit *inputSection;
    QLineEdit *inputSiege;
    QLineEdit *inputPrix;
    QLabel *Rangee_2;
    QLabel *Siege_2;
    QLabel *Prix_2;
    QLineEdit *inputRangee;
    QLabel *Filtrage;
    QGroupBox *groupSections;
    QGroupBox *groupRangees;
    QGroupBox *groupPrix;
    QPushButton *btnResetFiltres;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QLineEdit *inputRecherche;
    QPushButton *btnMoodifier;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1909, 807);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableRessources = new QTableWidget(centralwidget);
        if (tableRessources->columnCount() < 6)
            tableRessources->setColumnCount(6);
        tableRessources->setObjectName("tableRessources");
        tableRessources->setGeometry(QRect(640, 140, 671, 531));
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
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(90, 530, 391, 101));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnSauvegarder = new QPushButton(layoutWidget);
        btnSauvegarder->setObjectName("btnSauvegarder");
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btnSauvegarder->setIcon(icon);

        horizontalLayout_2->addWidget(btnSauvegarder);

        btnSupprimer = new QPushButton(layoutWidget);
        btnSupprimer->setObjectName("btnSupprimer");
        QIcon icon1;
        iconThemeName = QString::fromUtf8("user-trash");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btnSupprimer->setIcon(icon1);

        horizontalLayout_2->addWidget(btnSupprimer);

        btnPublier = new QPushButton(layoutWidget);
        btnPublier->setObjectName("btnPublier");
        QIcon icon2;
        iconThemeName = QString::fromUtf8("emblem-default");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btnPublier->setIcon(icon2);

        horizontalLayout_2->addWidget(btnPublier);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(120, 200, 341, 231));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Section_2 = new QLabel(layoutWidget1);
        Section_2->setObjectName("Section_2");

        gridLayout->addWidget(Section_2, 0, 0, 1, 1);

        inputSection = new QLineEdit(layoutWidget1);
        inputSection->setObjectName("inputSection");

        gridLayout->addWidget(inputSection, 0, 1, 1, 1);

        inputSiege = new QLineEdit(layoutWidget1);
        inputSiege->setObjectName("inputSiege");

        gridLayout->addWidget(inputSiege, 2, 1, 1, 1);

        inputPrix = new QLineEdit(layoutWidget1);
        inputPrix->setObjectName("inputPrix");

        gridLayout->addWidget(inputPrix, 3, 1, 1, 1);

        Rangee_2 = new QLabel(layoutWidget1);
        Rangee_2->setObjectName("Rangee_2");

        gridLayout->addWidget(Rangee_2, 1, 0, 1, 1);

        Siege_2 = new QLabel(layoutWidget1);
        Siege_2->setObjectName("Siege_2");

        gridLayout->addWidget(Siege_2, 2, 0, 1, 1);

        Prix_2 = new QLabel(layoutWidget1);
        Prix_2->setObjectName("Prix_2");

        gridLayout->addWidget(Prix_2, 3, 0, 1, 1);

        inputRangee = new QLineEdit(layoutWidget1);
        inputRangee->setObjectName("inputRangee");

        gridLayout->addWidget(inputRangee, 1, 1, 1, 1);

        Filtrage = new QLabel(centralwidget);
        Filtrage->setObjectName("Filtrage");
        Filtrage->setGeometry(QRect(1410, 190, 391, 61));
        Filtrage->setTabletTracking(false);
        Filtrage->setLayoutDirection(Qt::LeftToRight);
        Filtrage->setAutoFillBackground(false);
        Filtrage->setTextFormat(Qt::PlainText);
        Filtrage->setAlignment(Qt::AlignCenter);
        Filtrage->setWordWrap(false);
        groupSections = new QGroupBox(centralwidget);
        groupSections->setObjectName("groupSections");
        groupSections->setGeometry(QRect(1350, 310, 141, 181));
        groupSections->setAlignment(Qt::AlignCenter);
        groupRangees = new QGroupBox(centralwidget);
        groupRangees->setObjectName("groupRangees");
        groupRangees->setGeometry(QRect(1520, 310, 151, 181));
        groupRangees->setAlignment(Qt::AlignCenter);
        groupPrix = new QGroupBox(centralwidget);
        groupPrix->setObjectName("groupPrix");
        groupPrix->setGeometry(QRect(1700, 310, 161, 181));
        groupPrix->setAlignment(Qt::AlignCenter);
        btnResetFiltres = new QPushButton(centralwidget);
        btnResetFiltres->setObjectName("btnResetFiltres");
        btnResetFiltres->setGeometry(QRect(1550, 520, 111, 41));
        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(750, 50, 451, 91));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        inputRecherche = new QLineEdit(layoutWidget2);
        inputRecherche->setObjectName("inputRecherche");

        gridLayout_2->addWidget(inputRecherche, 0, 0, 1, 1);

        btnMoodifier = new QPushButton(centralwidget);
        btnMoodifier->setObjectName("btnMoodifier");
        btnMoodifier->setGeometry(QRect(500, 570, 88, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1909, 23));
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
        Section_2->setText(QCoreApplication::translate("MainWindow", "Section :", nullptr));
        inputSection->setPlaceholderText(QCoreApplication::translate("MainWindow", "VVIP, VIP, STANDARD, CLASSIC...", nullptr));
        inputSiege->setPlaceholderText(QCoreApplication::translate("MainWindow", "1,2,3...", nullptr));
        inputPrix->setInputMask(QString());
        inputPrix->setText(QString());
        inputPrix->setPlaceholderText(QCoreApplication::translate("MainWindow", "5000, 10000, 20000...", nullptr));
        Rangee_2->setText(QCoreApplication::translate("MainWindow", "Rang\303\251e :", nullptr));
        Siege_2->setText(QCoreApplication::translate("MainWindow", "Si\303\250ge :", nullptr));
        Prix_2->setText(QCoreApplication::translate("MainWindow", "Prix :", nullptr));
        inputRangee->setPlaceholderText(QCoreApplication::translate("MainWindow", "A,B,C,D...", nullptr));
        Filtrage->setText(QCoreApplication::translate("MainWindow", "Filtrage par ", nullptr));
        groupSections->setTitle(QCoreApplication::translate("MainWindow", "Section", nullptr));
        groupRangees->setTitle(QCoreApplication::translate("MainWindow", "Rang\303\251e", nullptr));
        groupPrix->setTitle(QCoreApplication::translate("MainWindow", "Prix", nullptr));
        btnResetFiltres->setText(QCoreApplication::translate("MainWindow", "Pas de filtre", nullptr));
        inputRecherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher une place", nullptr));
        btnMoodifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
