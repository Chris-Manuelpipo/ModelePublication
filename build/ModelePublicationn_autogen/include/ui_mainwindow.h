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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QTableWidget *tableRessources_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableWidget *tableRessources;
    QLabel *label_4;
    QSplitter *splitter_2;
    QLabel *label_3;
    QSplitter *splitter;
    QLabel *Prix_2;
    QLineEdit *inputPrix;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPublier;
    QPushButton *btnDepublier;
    QPushButton *pdfButton;
    QGroupBox *groupBoxStatistiques;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layoutStatistiques;
    QLabel *labelTotal;
    QLabel *labelPubliees;
    QLabel *labelPublieesParSection;
    QLabel *labelNonPubliees;
    QLabel *labelNonPublieesParSection;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout;
    QLabel *Section_2;
    QComboBox *comboBox;
    QLabel *Rangee_2;
    QComboBox *comboBox_2;
    QLabel *Siege_2;
    QComboBox *comboBox_3;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1796, 823);
        MainWindow->setDocumentMode(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 10, 91, 27));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icons/arrowback.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 130, 662, 611));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        tableRessources_2 = new QTableWidget(layoutWidget);
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
        verticalLayout_3->setStretch(1, 5);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(1130, 130, 662, 611));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        tableRessources = new QTableWidget(layoutWidget1);
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
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(710, 280, 381, 41));
        label_4->setAlignment(Qt::AlignCenter);
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setGeometry(QRect(710, 550, 381, 91));
        splitter_2->setOrientation(Qt::Vertical);
        label_3 = new QLabel(splitter_2);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignCenter);
        splitter_2->addWidget(label_3);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        Prix_2 = new QLabel(splitter);
        Prix_2->setObjectName("Prix_2");
        splitter->addWidget(Prix_2);
        inputPrix = new QLineEdit(splitter);
        inputPrix->setObjectName("inputPrix");
        splitter->addWidget(inputPrix);
        splitter_2->addWidget(splitter);
        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(710, 660, 381, 101));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnPublier = new QPushButton(layoutWidget2);
        btnPublier->setObjectName("btnPublier");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icons/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPublier->setIcon(icon1);

        horizontalLayout->addWidget(btnPublier);

        btnDepublier = new QPushButton(layoutWidget2);
        btnDepublier->setObjectName("btnDepublier");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icons/trash.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDepublier->setIcon(icon2);

        horizontalLayout->addWidget(btnDepublier);

        pdfButton = new QPushButton(layoutWidget2);
        pdfButton->setObjectName("pdfButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icons/sauvegarder.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdfButton->setIcon(icon3);

        horizontalLayout->addWidget(pdfButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);
        groupBoxStatistiques = new QGroupBox(centralwidget);
        groupBoxStatistiques->setObjectName("groupBoxStatistiques");
        groupBoxStatistiques->setGeometry(QRect(710, 30, 381, 231));
        groupBoxStatistiques->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(groupBoxStatistiques);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 30, 361, 191));
        layoutStatistiques = new QVBoxLayout(verticalLayoutWidget);
        layoutStatistiques->setObjectName("layoutStatistiques");
        layoutStatistiques->setContentsMargins(0, 0, 0, 0);
        labelTotal = new QLabel(verticalLayoutWidget);
        labelTotal->setObjectName("labelTotal");

        layoutStatistiques->addWidget(labelTotal);

        labelPubliees = new QLabel(verticalLayoutWidget);
        labelPubliees->setObjectName("labelPubliees");

        layoutStatistiques->addWidget(labelPubliees);

        labelPublieesParSection = new QLabel(verticalLayoutWidget);
        labelPublieesParSection->setObjectName("labelPublieesParSection");

        layoutStatistiques->addWidget(labelPublieesParSection);

        labelNonPubliees = new QLabel(verticalLayoutWidget);
        labelNonPubliees->setObjectName("labelNonPubliees");

        layoutStatistiques->addWidget(labelNonPubliees);

        labelNonPublieesParSection = new QLabel(verticalLayoutWidget);
        labelNonPublieesParSection->setObjectName("labelNonPublieesParSection");

        layoutStatistiques->addWidget(labelNonPublieesParSection);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(710, 340, 381, 181));
        gridLayout = new QGridLayout(layoutWidget3);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Section_2 = new QLabel(layoutWidget3);
        Section_2->setObjectName("Section_2");

        gridLayout->addWidget(Section_2, 0, 0, 1, 1);

        comboBox = new QComboBox(layoutWidget3);
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        Rangee_2 = new QLabel(layoutWidget3);
        Rangee_2->setObjectName("Rangee_2");

        gridLayout->addWidget(Rangee_2, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(layoutWidget3);
        comboBox_2->setObjectName("comboBox_2");

        gridLayout->addWidget(comboBox_2, 1, 1, 1, 1);

        Siege_2 = new QLabel(layoutWidget3);
        Siege_2->setObjectName("Siege_2");

        gridLayout->addWidget(Siege_2, 2, 0, 1, 1);

        comboBox_3 = new QComboBox(layoutWidget3);
        comboBox_3->setObjectName("comboBox_3");

        gridLayout->addWidget(comboBox_3, 2, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 3);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1796, 23));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Publication des places d'un stade de football", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Places non publi\303\251es(S\303\251lectionner une place pour l\303\240 publier)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Places Publi\303\251es(S\303\251lectionner une place pour l\303\240 d\303\251publier)", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Trier les places publi\303\251es par :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Modifier le prix de la place \303\240 publier", nullptr));
        Prix_2->setText(QCoreApplication::translate("MainWindow", "Prix :", nullptr));
        inputPrix->setInputMask(QString());
        inputPrix->setText(QString());
        inputPrix->setPlaceholderText(QCoreApplication::translate("MainWindow", "5000, 10000, 20000...", nullptr));
        btnPublier->setText(QCoreApplication::translate("MainWindow", "Publier", nullptr));
        btnDepublier->setText(QCoreApplication::translate("MainWindow", "D\303\251publier", nullptr));
        pdfButton->setText(QCoreApplication::translate("MainWindow", "Sauvegarder en pdf", nullptr));
        groupBoxStatistiques->setTitle(QCoreApplication::translate("MainWindow", "Statistiques globales", nullptr));
        labelTotal->setText(QCoreApplication::translate("MainWindow", "Total de places : 0", nullptr));
        labelPubliees->setText(QCoreApplication::translate("MainWindow", "Publi\303\251es : 0", nullptr));
        labelPublieesParSection->setText(QCoreApplication::translate("MainWindow", "Publi\303\251es par section :", nullptr));
        labelNonPubliees->setText(QCoreApplication::translate("MainWindow", "Non publi\303\251es : 0", nullptr));
        labelNonPublieesParSection->setText(QCoreApplication::translate("MainWindow", "Non publi\303\251es par section :", nullptr));
        Section_2->setText(QCoreApplication::translate("MainWindow", "Section :", nullptr));
        Rangee_2->setText(QCoreApplication::translate("MainWindow", "Rang\303\251e :", nullptr));
        Siege_2->setText(QCoreApplication::translate("MainWindow", "Si\303\250ge :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
