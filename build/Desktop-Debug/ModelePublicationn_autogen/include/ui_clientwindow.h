/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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

class Ui_ClientWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableRessources;
    QPushButton *pushButton;
    QWidget *widget;
    QGridLayout *gridLayout_7;
    QLineEdit *inputRecherche_3;
    QWidget *widget1;
    QGridLayout *gridLayout_9;
    QGroupBox *groupSections_3;
    QGroupBox *groupPrix_3;
    QGroupBox *groupRangees_3;
    QPushButton *btnResetFiltres_3;
    QLabel *Filtrage_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName("ClientWindow");
        ClientWindow->resize(1312, 746);
        centralwidget = new QWidget(ClientWindow);
        centralwidget->setObjectName("centralwidget");
        tableRessources = new QTableWidget(centralwidget);
        if (tableRessources->columnCount() < 6)
            tableRessources->setColumnCount(6);
        tableRessources->setObjectName("tableRessources");
        tableRessources->setEnabled(true);
        tableRessources->setGeometry(QRect(50, 174, 660, 531));
        tableRessources->setMinimumSize(QSize(660, 531));
        tableRessources->setMaximumSize(QSize(661, 16777215));
        tableRessources->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableRessources->setFrameShape(QFrame::StyledPanel);
        tableRessources->setFrameShadow(QFrame::Sunken);
        tableRessources->setShowGrid(true);
        tableRessources->setSortingEnabled(false);
        tableRessources->setColumnCount(6);
        tableRessources->horizontalHeader()->setVisible(true);
        tableRessources->horizontalHeader()->setCascadingSectionResizes(false);
        tableRessources->horizontalHeader()->setMinimumSectionSize(110);
        tableRessources->horizontalHeader()->setDefaultSectionSize(110);
        tableRessources->horizontalHeader()->setHighlightSections(true);
        tableRessources->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableRessources->horizontalHeader()->setStretchLastSection(false);
        tableRessources->verticalHeader()->setVisible(false);
        tableRessources->verticalHeader()->setCascadingSectionResizes(false);
        tableRessources->verticalHeader()->setHighlightSections(true);
        tableRessources->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableRessources->verticalHeader()->setStretchLastSection(false);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 88, 26));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 111, 661, 51));
        gridLayout_7 = new QGridLayout(widget);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        inputRecherche_3 = new QLineEdit(widget);
        inputRecherche_3->setObjectName("inputRecherche_3");

        gridLayout_7->addWidget(inputRecherche_3, 0, 0, 1, 1);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(820, 190, 481, 491));
        gridLayout_9 = new QGridLayout(widget1);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setHorizontalSpacing(20);
        gridLayout_9->setVerticalSpacing(32);
        gridLayout_9->setContentsMargins(8, 8, 0, 0);
        groupSections_3 = new QGroupBox(widget1);
        groupSections_3->setObjectName("groupSections_3");
        groupSections_3->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(groupSections_3, 1, 0, 1, 1);

        groupPrix_3 = new QGroupBox(widget1);
        groupPrix_3->setObjectName("groupPrix_3");
        groupPrix_3->setEnabled(true);
        groupPrix_3->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(groupPrix_3, 1, 2, 1, 1);

        groupRangees_3 = new QGroupBox(widget1);
        groupRangees_3->setObjectName("groupRangees_3");
        groupRangees_3->setContextMenuPolicy(Qt::DefaultContextMenu);
        groupRangees_3->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(groupRangees_3, 1, 1, 1, 1);

        btnResetFiltres_3 = new QPushButton(widget1);
        btnResetFiltres_3->setObjectName("btnResetFiltres_3");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnResetFiltres_3->sizePolicy().hasHeightForWidth());
        btnResetFiltres_3->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icons/sauvegarde.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnResetFiltres_3->setIcon(icon);
        btnResetFiltres_3->setAutoDefault(false);
        btnResetFiltres_3->setFlat(false);

        gridLayout_9->addWidget(btnResetFiltres_3, 2, 1, 1, 1);

        Filtrage_3 = new QLabel(widget1);
        Filtrage_3->setObjectName("Filtrage_3");
        Filtrage_3->setTabletTracking(false);
        Filtrage_3->setLayoutDirection(Qt::LeftToRight);
        Filtrage_3->setAutoFillBackground(false);
        Filtrage_3->setFrameShape(QFrame::NoFrame);
        Filtrage_3->setTextFormat(Qt::PlainText);
        Filtrage_3->setScaledContents(false);
        Filtrage_3->setAlignment(Qt::AlignCenter);
        Filtrage_3->setWordWrap(false);

        gridLayout_9->addWidget(Filtrage_3, 0, 0, 1, 3);

        gridLayout_9->setRowStretch(0, 100);
        gridLayout_9->setRowStretch(1, 300);
        gridLayout_9->setRowStretch(2, 80);
        gridLayout_9->setColumnStretch(0, 100);
        gridLayout_9->setColumnStretch(1, 100);
        gridLayout_9->setColumnStretch(2, 100);
        gridLayout_9->setColumnMinimumWidth(0, 25);
        gridLayout_9->setColumnMinimumWidth(1, 25);
        gridLayout_9->setColumnMinimumWidth(2, 25);
        gridLayout_9->setRowMinimumHeight(0, 5);
        gridLayout_9->setRowMinimumHeight(1, 150);
        gridLayout_9->setRowMinimumHeight(2, 40);
        ClientWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClientWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1312, 23));
        ClientWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ClientWindow);
        statusbar->setObjectName("statusbar");
        ClientWindow->setStatusBar(statusbar);

        retranslateUi(ClientWindow);

        btnResetFiltres_3->setDefault(false);


        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClientWindow)
    {
        ClientWindow->setWindowTitle(QCoreApplication::translate("ClientWindow", "Publication des places d'un stade de football", nullptr));
        pushButton->setText(QCoreApplication::translate("ClientWindow", "Retour", nullptr));
        inputRecherche_3->setPlaceholderText(QCoreApplication::translate("ClientWindow", "Rechercher une place", nullptr));
        groupSections_3->setTitle(QCoreApplication::translate("ClientWindow", "Section", nullptr));
        groupPrix_3->setTitle(QCoreApplication::translate("ClientWindow", "Prix", nullptr));
        groupRangees_3->setTitle(QCoreApplication::translate("ClientWindow", "Rang\303\251e", nullptr));
        btnResetFiltres_3->setText(QCoreApplication::translate("ClientWindow", "Pas de filtre", nullptr));
        Filtrage_3->setText(QCoreApplication::translate("ClientWindow", "Filtrage par :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
