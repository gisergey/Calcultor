#include "Mainwindow.h"
#include "Calculator.h"
#include <QApplication>



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
    MainWindow w("localhost",2323);
    Calculator calcul;
    // w.Answer=Answers;
    //calcul.Answer=Answers;
    QObject::connect(&w,SIGNAL(MakeSummSingal(QString)),&calcul,SLOT(doSummurySlot(QString)));
    QObject::connect(&w,SIGNAL(MakeMinusSignal(QString)),&calcul,SLOT(doMinusSlot(QString)));
    QObject::connect(&w,SIGNAL(MakeMultiplicationSignal(QString)),&calcul,SLOT(doMultiplyingSlot(QString)));
    QObject::connect(&w,SIGNAL(MakeDivisionSignal(QString)),&calcul,SLOT(doDivisionSlot(QString)));

    QObject::connect(&w,SIGNAL(ChangetoSumSignal()),&calcul,SLOT(ChangetosummurySlot()));
    QObject::connect(&w,SIGNAL(ChangetoMinusSignal()),&calcul,SLOT(ChangetoMinusSlot()));
    QObject::connect(&w,SIGNAL(ChangetoMultiplicationSignal()),&calcul,SLOT(ChangetoMultiplyingSlot()));
    QObject::connect(&w,SIGNAL(ChangetoDivisionSignal()),&calcul,SLOT(ChangetoDivisionSlot()));

    QObject::connect(&w,SIGNAL(DoCalculationSignal(QString)),&calcul,SLOT(doEquationSlot(QString)));
    QObject::connect(&calcul,SIGNAL(DidEqutionSignal(QString)),&w,SLOT(ShowAnswerSlot(QString)));
    QObject::connect(&calcul,SIGNAL(DidEqutionSignal(QString)),&w,SLOT(SentToServerSlot(QString)));
    QObject::connect(&w,SIGNAL(ToClearNumberSignal()),&calcul,SLOT(ClearNumbersSlot()));

    w.show();

    return a.exec();
}
