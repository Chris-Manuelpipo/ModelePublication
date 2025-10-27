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
    QGridLayout *gridLayout;
    QLabel *Section_2;
    QLineEdit *inputSection;
    QLineEdit *inputSiege;
    QLineEdit *inputPrix;
    QLabel *Rangee_2;
    QLabel *Siege_2;
    QLabel *Prix_2;
    QLineEdit *inputRangee;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLineEdit *inputRecherche;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPublier;
    QPushButton *btnSupprimer;
    QPushButton *btnModifier;
    QPushButton *btnSauvegarder;
    QWidget *widget1;
    QGridLayout *gridLayout_4;
    QLabel *Filtrage;
    QGroupBox *groupSections;
    QPushButton *btnResetFiltres;
    QGroupBox *groupRangees;
    QGroupBox *groupPrix;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1906, 777);
        MainWindow->setDocumentMode(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableRessources = new QTableWidget(centralwidget);
        if (tableRessources->columnCount() < 6)
            tableRessources->setColumnCount(6);
        tableRessources->setObjectName("tableRessources");
        tableRessources->setEnabled(true);
        tableRessources->setGeometry(QRect(650, 140, 681, 531));
        tableRessources->setMinimumSize(QSize(660, 531));
        tableRessources->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableRessources->setShowGrid(true);
        tableRessources->setSortingEnabled(false);
        tableRessources->setColumnCount(6);
        tableRessources->horizontalHeader()->setVisible(true);
        tableRessources->horizontalHeader()->setDefaultSectionSize(113);
        tableRessources->horizontalHeader()->setHighlightSections(true);
        tableRessources->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableRessources->horizontalHeader()->setStretchLastSection(false);
        tableRessources->verticalHeader()->setVisible(false);
        tableRessources->verticalHeader()->setCascadingSectionResizes(false);
        tableRessources->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableRessources->verticalHeader()->setStretchLastSection(false);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(130, 210, 341, 231));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Section_2 = new QLabel(layoutWidget);
        Section_2->setObjectName("Section_2");

        gridLayout->addWidget(Section_2, 0, 0, 1, 1);

        inputSection = new QLineEdit(layoutWidget);
        inputSection->setObjectName("inputSection");

        gridLayout->addWidget(inputSection, 0, 1, 1, 1);

        inputSiege = new QLineEdit(layoutWidget);
        inputSiege->setObjectName("inputSiege");

        gridLayout->addWidget(inputSiege, 2, 1, 1, 1);

        inputPrix = new QLineEdit(layoutWidget);
        inputPrix->setObjectName("inputPrix");

        gridLayout->addWidget(inputPrix, 3, 1, 1, 1);

        Rangee_2 = new QLabel(layoutWidget);
        Rangee_2->setObjectName("Rangee_2");

        gridLayout->addWidget(Rangee_2, 1, 0, 1, 1);

        Siege_2 = new QLabel(layoutWidget);
        Siege_2->setObjectName("Siege_2");

        gridLayout->addWidget(Siege_2, 2, 0, 1, 1);

        Prix_2 = new QLabel(layoutWidget);
        Prix_2->setObjectName("Prix_2");

        gridLayout->addWidget(Prix_2, 3, 0, 1, 1);

        inputRangee = new QLineEdit(layoutWidget);
        inputRangee->setObjectName("inputRangee");

        gridLayout->addWidget(inputRangee, 1, 1, 1, 1);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(750, 50, 451, 91));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        inputRecherche = new QLineEdit(layoutWidget1);
        inputRecherche->setObjectName("inputRecherche");

        gridLayout_2->addWidget(inputRecherche, 0, 0, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 520, 591, 81));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(25);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnPublier = new QPushButton(widget);
        btnPublier->setObjectName("btnPublier");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icons/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPublier->setIcon(icon);

        horizontalLayout->addWidget(btnPublier);

        btnSupprimer = new QPushButton(widget);
        btnSupprimer->setObjectName("btnSupprimer");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/trash.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSupprimer->setIcon(icon1);

        horizontalLayout->addWidget(btnSupprimer);

        btnModifier = new QPushButton(widget);
        btnModifier->setObjectName("btnModifier");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icons/modification-au-crayon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModifier->setIcon(icon2);

        horizontalLayout->addWidget(btnModifier);

        btnSauvegarder = new QPushButton(widget);
        btnSauvegarder->setObjectName("btnSauvegarder");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icons/sauvegarder.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSauvegarder->setIcon(icon3);

        horizontalLayout->addWidget(btnSauvegarder);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(1350, 190, 531, 431));
        gridLayout_4 = new QGridLayout(widget1);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setHorizontalSpacing(20);
        gridLayout_4->setVerticalSpacing(40);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        Filtrage = new QLabel(widget1);
        Filtrage->setObjectName("Filtrage");
        Filtrage->setTabletTracking(false);
        Filtrage->setLayoutDirection(Qt::LeftToRight);
        Filtrage->setAutoFillBackground(false);
        Filtrage->setTextFormat(Qt::PlainText);
        Filtrage->setAlignment(Qt::AlignCenter);
        Filtrage->setWordWrap(false);

        gridLayout_4->addWidget(Filtrage, 0, 0, 1, 3);

        groupSections = new QGroupBox(widget1);
        groupSections->setObjectName("groupSections");
        groupSections->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(groupSections, 1, 0, 1, 1);

        btnResetFiltres = new QPushButton(widget1);
        btnResetFiltres->setObjectName("btnResetFiltres");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnResetFiltres->sizePolicy().hasHeightForWidth());
        btnResetFiltres->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/icons/sauvegarde.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnResetFiltres->setIcon(icon4);
        btnResetFiltres->setAutoDefault(false);
        btnResetFiltres->setFlat(false);

        gridLayout_4->addWidget(btnResetFiltres, 2, 1, 1, 1);

        groupRangees = new QGroupBox(widget1);
        groupRangees->setObjectName("groupRangees");
        groupRangees->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(groupRangees, 1, 1, 1, 1);

        groupPrix = new QGroupBox(widget1);
        groupPrix->setObjectName("groupPrix");
        groupPrix->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(groupPrix, 1, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1906, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        btnResetFiltres->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Publication des places d'un stade de football", nullptr));
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
        inputRecherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher une place", nullptr));
        btnPublier->setText(QCoreApplication::translate("MainWindow", "Publier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        btnModifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnSauvegarder->setText(QCoreApplication::translate("MainWindow", "Sauvegarder", nullptr));
        Filtrage->setText(QCoreApplication::translate("MainWindow", "Filtrage par ", nullptr));
        groupSections->setTitle(QCoreApplication::translate("MainWindow", "Section", nullptr));
        btnResetFiltres->setText(QCoreApplication::translate("MainWindow", "Pas de filtre", nullptr));
        groupRangees->setTitle(QCoreApplication::translate("MainWindow", "Rang\303\251e", nullptr));
        groupPrix->setTitle(QCoreApplication::translate("MainWindow", "Prix", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
