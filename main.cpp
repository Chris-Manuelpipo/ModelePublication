#include "mainwindow.h"
#include <QFile>

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;

    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ModelePublicationn_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QFile styleFile(":/new/prefix1/style.qss");

    if (styleFile.open(QFile::ReadOnly)) {
        QString style(styleFile.readAll());
        a.setStyleSheet(style);
        qDebug() << "✅ Style chargé !";
    }else {
        qDebug() << "❌ Impossible d’ouvrir le style";
    }

    MainWindow w;
    w.show();
    return a.exec();
}
