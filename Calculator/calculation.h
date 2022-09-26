#ifndef CALCULATION_H
#define CALCULATION_H

#include <QString>
#include <QObject>
class Calculation
{
public:
    Calculation();

    double FirstNumber;
    double SecondNumber;
    bool IsFirstOperation=true;
    QString *Answer;
    double(*OperationChoose)(double first,double second);


    double static Multiplying(double first, double second);
    double static Divid(double first,double second);
    double static Minus(double first, double second);
    double static Summary(double first,double secnd);
private slots:
    void DoMultiplying();
    void DoSummury();
    void DoMinus();
    void DoDivision();
    void DoEquation();
signals:
    void CalculateAndswer();

private:

};


#endif // CALCULATION_H
