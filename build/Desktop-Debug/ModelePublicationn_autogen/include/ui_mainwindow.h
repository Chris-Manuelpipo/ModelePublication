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
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *Section_2;
    QLineEdit *inputSection;
    QLineEdit *inputSiege;
    QLineEdit *inputPrix;
    QLabel *Rangee_2;
    QLabel *Siege_2;
    QLabel *Prix_2;
    QLineEdit *inputRangee;
    QTableWidget *tableRessources;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPublier;
    QPushButton *btnSupprimer;
    QPushButton *btnModifier;
    QPushButton *btnSauvegarder;
    QGridLayout *gridLayout_2;
    QLineEdit *inputRecherche;
    QGridLayout *gridLayout_4;
    QGroupBox *groupSections;
    QGroupBox *groupPrix;
    QGroupBox *groupRangees;
    QPushButton *btnResetFiltres;
    QLabel *Filtrage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1875, 800);
        MainWindow->setDocumentMode(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setHorizontalSpacing(75);
        gridLayout_3->setVerticalSpacing(35);
        gridLayout_3->setContentsMargins(50, 50, 50, 50);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setVerticalSpacing(30);
        Section_2 = new QLabel(centralwidget);
        Section_2->setObjectName("Section_2");

        gridLayout->addWidget(Section_2, 0, 0, 1, 1);

        inputSection = new QLineEdit(centralwidget);
        inputSection->setObjectName("inputSection");

        gridLayout->addWidget(inputSection, 0, 1, 1, 1);

        inputSiege = new QLineEdit(centralwidget);
        inputSiege->setObjectName("inputSiege");

        gridLayout->addWidget(inputSiege, 2, 1, 1, 1);

        inputPrix = new QLineEdit(centralwidget);
        inputPrix->setObjectName("inputPrix");

        gridLayout->addWidget(inputPrix, 3, 1, 1, 1);

        Rangee_2 = new QLabel(centralwidget);
        Rangee_2->setObjectName("Rangee_2");

        gridLayout->addWidget(Rangee_2, 1, 0, 1, 1);

        Siege_2 = new QLabel(centralwidget);
        Siege_2->setObjectName("Siege_2");

        gridLayout->addWidget(Siege_2, 2, 0, 1, 1);

        Prix_2 = new QLabel(centralwidget);
        Prix_2->setObjectName("Prix_2");

        gridLayout->addWidget(Prix_2, 3, 0, 1, 1);

        inputRangee = new QLineEdit(centralwidget);
        inputRangee->setObjectName("inputRangee");

        gridLayout->addWidget(inputRangee, 1, 1, 1, 1);

        gridLayout->setColumnStretch(0, 5);
        gridLayout->setColumnStretch(1, 50);
        gridLayout->setColumnMinimumWidth(0, 5);
        gridLayout->setColumnMinimumWidth(1, 25);
        gridLayout->setRowMinimumHeight(0, 10);
        gridLayout->setRowMinimumHeight(1, 10);
        gridLayout->setRowMinimumHeight(2, 10);
        gridLayout->setRowMinimumHeight(3, 10);

        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);

        tableRessources = new QTableWidget(centralwidget);
        tableRessources->setObjectName("tableRessources");
        tableRessources->setEnabled(true);
        tableRessources->setMinimumSize(QSize(660, 531));
        tableRessources->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableRessources->setFrameShape(QFrame::StyledPanel);
        tableRessources->setFrameShadow(QFrame::Sunken);
        tableRessources->setShowGrid(true);
        tableRessources->setSortingEnabled(false);
        tableRessources->setColumnCount(0);
        tableRessources->horizontalHeader()->setMinimumSectionSize(110);
        tableRessources->horizontalHeader()->setDefaultSectionSize(110);
        tableRessources->horizontalHeader()->setHighlightSections(false);
        tableRessources->verticalHeader()->setVisible(false);
        tableRessources->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        gridLayout_3->addWidget(tableRessources, 1, 1, 2, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, 61, -1, 0);
        btnPublier = new QPushButton(centralwidget);
        btnPublier->setObjectName("btnPublier");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icons/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPublier->setIcon(icon);

        horizontalLayout->addWidget(btnPublier);

        btnSupprimer = new QPushButton(centralwidget);
        btnSupprimer->setObjectName("btnSupprimer");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/trash.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSupprimer->setIcon(icon1);

        horizontalLayout->addWidget(btnSupprimer);

        btnModifier = new QPushButton(centralwidget);
        btnModifier->setObjectName("btnModifier");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icons/modification-au-crayon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModifier->setIcon(icon2);

        horizontalLayout->addWidget(btnModifier);

        btnSauvegarder = new QPushButton(centralwidget);
        btnSauvegarder->setObjectName("btnSauvegarder");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icons/sauvegarder.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSauvegarder->setIcon(icon3);

        horizontalLayout->addWidget(btnSauvegarder);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);

        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        inputRecherche = new QLineEdit(centralwidget);
        inputRecherche->setObjectName("inputRecherche");

        gridLayout_2->addWidget(inputRecherche, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setHorizontalSpacing(20);
        gridLayout_4->setVerticalSpacing(32);
        gridLayout_4->setContentsMargins(8, 8, -1, -1);
        groupSections = new QGroupBox(centralwidget);
        groupSections->setObjectName("groupSections");
        groupSections->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(groupSections, 1, 0, 1, 1);

        groupPrix = new QGroupBox(centralwidget);
        groupPrix->setObjectName("groupPrix");
        groupPrix->setEnabled(true);
        groupPrix->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(groupPrix, 1, 2, 1, 1);

        groupRangees = new QGroupBox(centralwidget);
        groupRangees->setObjectName("groupRangees");
        groupRangees->setContextMenuPolicy(Qt::DefaultContextMenu);
        groupRangees->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(groupRangees, 1, 1, 1, 1);

        btnResetFiltres = new QPushButton(centralwidget);
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

        Filtrage = new QLabel(centralwidget);
        Filtrage->setObjectName("Filtrage");
        Filtrage->setTabletTracking(false);
        Filtrage->setLayoutDirection(Qt::LeftToRight);
        Filtrage->setAutoFillBackground(false);
        Filtrage->setFrameShape(QFrame::NoFrame);
        Filtrage->setTextFormat(Qt::PlainText);
        Filtrage->setScaledContents(false);
        Filtrage->setAlignment(Qt::AlignCenter);
        Filtrage->setWordWrap(false);

        gridLayout_4->addWidget(Filtrage, 0, 0, 1, 3);

        gridLayout_4->setRowStretch(0, 100);
        gridLayout_4->setRowStretch(1, 300);
        gridLayout_4->setRowStretch(2, 80);
        gridLayout_4->setColumnStretch(0, 100);
        gridLayout_4->setColumnStretch(1, 100);
        gridLayout_4->setColumnStretch(2, 100);
        gridLayout_4->setColumnMinimumWidth(0, 25);
        gridLayout_4->setColumnMinimumWidth(1, 25);
        gridLayout_4->setColumnMinimumWidth(2, 25);
        gridLayout_4->setRowMinimumHeight(0, 5);
        gridLayout_4->setRowMinimumHeight(1, 150);
        gridLayout_4->setRowMinimumHeight(2, 40);

        gridLayout_3->addLayout(gridLayout_4, 1, 2, 2, 1);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 4);
        gridLayout_3->setRowStretch(2, 1);
        gridLayout_3->setColumnStretch(1, 1);
        gridLayout_3->setColumnStretch(2, 1);
        gridLayout_3->setColumnMinimumWidth(0, 1);
        gridLayout_3->setColumnMinimumWidth(1, 1);
        gridLayout_3->setColumnMinimumWidth(2, 1);
        gridLayout_3->setRowMinimumHeight(0, 1);
        gridLayout_3->setRowMinimumHeight(1, 1);
        gridLayout_3->setRowMinimumHeight(2, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1875, 23));
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
        btnPublier->setText(QCoreApplication::translate("MainWindow", "Publier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        btnModifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnSauvegarder->setText(QCoreApplication::translate("MainWindow", "Sauvegarder", nullptr));
        inputRecherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher une place", nullptr));
        groupSections->setTitle(QCoreApplication::translate("MainWindow", "Section", nullptr));
        groupPrix->setTitle(QCoreApplication::translate("MainWindow", "Prix", nullptr));
        groupRangees->setTitle(QCoreApplication::translate("MainWindow", "Rang\303\251e", nullptr));
        btnResetFiltres->setText(QCoreApplication::translate("MainWindow", "Pas de filtre", nullptr));
        Filtrage->setText(QCoreApplication::translate("MainWindow", "Filtrage par :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
