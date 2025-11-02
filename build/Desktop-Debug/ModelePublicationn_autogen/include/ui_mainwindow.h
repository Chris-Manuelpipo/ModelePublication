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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *inputSiege;
    QLineEdit *inputRangee;
    QLineEdit *inputSection;
    QLabel *Siege_2;
    QLabel *Section_2;
    QLabel *Rangee_2;
    QLineEdit *inputPrix;
    QLabel *Prix_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPublier;
    QPushButton *btnSupprimer;
    QPushButton *btnSauvegarder;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableWidget *tableRessources;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QTableWidget *tableRessources_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1729, 718);
        MainWindow->setDocumentMode(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 88, 26));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(690, 210, 361, 401));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        inputSiege = new QLineEdit(widget);
        inputSiege->setObjectName("inputSiege");

        gridLayout->addWidget(inputSiege, 2, 1, 1, 1);

        inputRangee = new QLineEdit(widget);
        inputRangee->setObjectName("inputRangee");

        gridLayout->addWidget(inputRangee, 1, 1, 1, 1);

        inputSection = new QLineEdit(widget);
        inputSection->setObjectName("inputSection");

        gridLayout->addWidget(inputSection, 0, 1, 1, 1);

        Siege_2 = new QLabel(widget);
        Siege_2->setObjectName("Siege_2");

        gridLayout->addWidget(Siege_2, 2, 0, 1, 1);

        Section_2 = new QLabel(widget);
        Section_2->setObjectName("Section_2");

        gridLayout->addWidget(Section_2, 0, 0, 1, 1);

        Rangee_2 = new QLabel(widget);
        Rangee_2->setObjectName("Rangee_2");

        gridLayout->addWidget(Rangee_2, 1, 0, 1, 1);

        inputPrix = new QLineEdit(widget);
        inputPrix->setObjectName("inputPrix");

        gridLayout->addWidget(inputPrix, 3, 1, 1, 1);

        Prix_2 = new QLabel(widget);
        Prix_2->setObjectName("Prix_2");

        gridLayout->addWidget(Prix_2, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
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

        btnSauvegarder = new QPushButton(widget);
        btnSauvegarder->setObjectName("btnSauvegarder");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icons/sauvegarder.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSauvegarder->setIcon(icon2);

        horizontalLayout->addWidget(btnSauvegarder);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);
        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(1060, 50, 662, 601));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        tableRessources = new QTableWidget(widget1);
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

        verticalLayout_2->addWidget(tableRessources);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 5);
        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(0, 50, 662, 601));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget2);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        tableRessources_2 = new QTableWidget(widget2);
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

        verticalLayout_3->addWidget(tableRessources_2);

        verticalLayout_3->setStretch(0, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1729, 23));
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
        pushButton->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        inputSiege->setPlaceholderText(QCoreApplication::translate("MainWindow", "1,2,3...", nullptr));
        inputRangee->setPlaceholderText(QCoreApplication::translate("MainWindow", "A,B,C,D...", nullptr));
        inputSection->setPlaceholderText(QCoreApplication::translate("MainWindow", "VVIP, VIP, STANDARD, CLASSIC...", nullptr));
        Siege_2->setText(QCoreApplication::translate("MainWindow", "Si\303\250ge :", nullptr));
        Section_2->setText(QCoreApplication::translate("MainWindow", "Section :", nullptr));
        Rangee_2->setText(QCoreApplication::translate("MainWindow", "Rang\303\251e :", nullptr));
        inputPrix->setInputMask(QString());
        inputPrix->setText(QString());
        inputPrix->setPlaceholderText(QCoreApplication::translate("MainWindow", "5000, 10000, 20000...", nullptr));
        Prix_2->setText(QCoreApplication::translate("MainWindow", "Prix :", nullptr));
        btnPublier->setText(QCoreApplication::translate("MainWindow", "Publier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "D\303\251publier", nullptr));
        btnSauvegarder->setText(QCoreApplication::translate("MainWindow", "Sauvegarder", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Places Publi\303\251es", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Places non publi\303\251es", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
