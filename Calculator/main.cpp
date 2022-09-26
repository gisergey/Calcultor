#include "mainwindow.h"
#include "calculator.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>


int main(int argc, char *argv[])
{
    //  QTranslator translator;
    //  const QStringList uiLanguages = QLocale::system().uiLanguages();
    //for (const QString &locale : uiLanguages) {
    //     const QString baseName = "Calculator_" + QLocale(locale).name();
    // if (translator.load(":/i18n/" + baseName)) {
    //      a.installTranslator(&translator);
    //        break;
    //     }
    //    }
    QApplication a(argc, argv);
    //QString *Answers=new QString();
    //  *Answers="0";
    MainWindow w;
    Calculator calcul;
    // w.Answer=Answers;
    //calcul.Answer=Answers;
    QObject::connect(&w,SIGNAL(MakeSumm(QString)),&calcul,SLOT(DoSummury(QString)));
    QObject::connect(&w,SIGNAL(MakeMinus(QString)),&calcul,SLOT(DoMinus(QString)));
    QObject::connect(&w,SIGNAL(MakeMultiplication(QString)),&calcul,SLOT(DoMultiplying(QString)));
    QObject::connect(&w,SIGNAL(MakeDivision(QString)),&calcul,SLOT(DoDivision(QString)));

    QObject::connect(&w,SIGNAL(DoCalculation(QString)),&calcul,SLOT(DoEquation(QString)));
    QObject::connect(&calcul,SIGNAL(DidEqution(QString)),&w,SLOT(ShowAnswer(QString)));
    QObject::connect(&w,SIGNAL(ToClearNumber()),&calcul,SLOT(ClearNumbers()));

    w.show();
    //delete(Answers);
    return a.exec();
}
