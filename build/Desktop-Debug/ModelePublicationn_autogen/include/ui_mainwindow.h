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
    QGridLayout *gridLayout_2;
    QTableWidget *tableRessources_2;
    QGridLayout *gridLayout;
    QLabel *Section_2;
    QLineEdit *inputSiege;
    QLineEdit *inputRangee;
    QLineEdit *inputSection;
    QLabel *Rangee_2;
    QLabel *Siege_2;
    QLabel *Prix_2;
    QLineEdit *inputPrix;
    QTableWidget *tableRessources;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPublier;
    QPushButton *btnSupprimer;
    QPushButton *btnModifier;
    QPushButton *btnSauvegarder;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1820, 800);
        MainWindow->setDocumentMode(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        tableRessources_2 = new QTableWidget(centralwidget);
        tableRessources_2->setObjectName("tableRessources_2");
        tableRessources_2->setEnabled(true);
        tableRessources_2->setMinimumSize(QSize(660, 531));
        tableRessources_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableRessources_2->setFrameShape(QFrame::StyledPanel);
        tableRessources_2->setFrameShadow(QFrame::Sunken);
        tableRessources_2->setShowGrid(true);
        tableRessources_2->setSortingEnabled(false);
        tableRessources_2->setColumnCount(0);
        tableRessources_2->horizontalHeader()->setMinimumSectionSize(110);
        tableRessources_2->horizontalHeader()->setDefaultSectionSize(131);
        tableRessources_2->horizontalHeader()->setHighlightSections(true);
        tableRessources_2->verticalHeader()->setVisible(false);
        tableRessources_2->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        gridLayout_2->addWidget(tableRessources_2, 0, 0, 2, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setVerticalSpacing(30);
        Section_2 = new QLabel(centralwidget);
        Section_2->setObjectName("Section_2");

        gridLayout->addWidget(Section_2, 0, 0, 1, 1);

        inputSiege = new QLineEdit(centralwidget);
        inputSiege->setObjectName("inputSiege");

        gridLayout->addWidget(inputSiege, 2, 1, 1, 1);

        inputRangee = new QLineEdit(centralwidget);
        inputRangee->setObjectName("inputRangee");

        gridLayout->addWidget(inputRangee, 1, 1, 1, 1);

        inputSection = new QLineEdit(centralwidget);
        inputSection->setObjectName("inputSection");

        gridLayout->addWidget(inputSection, 0, 1, 1, 1);

        Rangee_2 = new QLabel(centralwidget);
        Rangee_2->setObjectName("Rangee_2");

        gridLayout->addWidget(Rangee_2, 1, 0, 1, 1);

        Siege_2 = new QLabel(centralwidget);
        Siege_2->setObjectName("Siege_2");

        gridLayout->addWidget(Siege_2, 2, 0, 1, 1);

        Prix_2 = new QLabel(centralwidget);
        Prix_2->setObjectName("Prix_2");

        gridLayout->addWidget(Prix_2, 3, 0, 1, 1);

        inputPrix = new QLineEdit(centralwidget);
        inputPrix->setObjectName("inputPrix");

        gridLayout->addWidget(inputPrix, 3, 1, 1, 1);

        gridLayout->setColumnStretch(0, 5);

        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

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

        gridLayout_2->addWidget(tableRessources, 0, 2, 2, 1);

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

        gridLayout_2->addLayout(horizontalLayout, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1820, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Publication des places d'un stade de football", nullptr));
        Section_2->setText(QCoreApplication::translate("MainWindow", "Section :", nullptr));
        inputSiege->setPlaceholderText(QCoreApplication::translate("MainWindow", "1,2,3...", nullptr));
        inputRangee->setPlaceholderText(QCoreApplication::translate("MainWindow", "A,B,C,D...", nullptr));
        inputSection->setPlaceholderText(QCoreApplication::translate("MainWindow", "VVIP, VIP, STANDARD, CLASSIC...", nullptr));
        Rangee_2->setText(QCoreApplication::translate("MainWindow", "Rang\303\251e :", nullptr));
        Siege_2->setText(QCoreApplication::translate("MainWindow", "Si\303\250ge :", nullptr));
        Prix_2->setText(QCoreApplication::translate("MainWindow", "Prix :", nullptr));
        inputPrix->setInputMask(QString());
        inputPrix->setText(QString());
        inputPrix->setPlaceholderText(QCoreApplication::translate("MainWindow", "5000, 10000, 20000...", nullptr));
        btnPublier->setText(QCoreApplication::translate("MainWindow", "Publier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        btnModifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnSauvegarder->setText(QCoreApplication::translate("MainWindow", "Sauvegarder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
