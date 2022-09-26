#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject
{
    Q_OBJECT
public:
    explicit Calculator(QObject *parent = nullptr);
    double FirstNumber;
    double SecondNumber;
    bool IsFirstOperation=true;
 //   QString *Answer;
    double(*OperationChoose)(double first,double second);


    double static Multiplying(double first, double second);
    double static Divid(double first,double second);
    double static Minus(double first, double second);
    double static Summary(double first,double secnd);

signals:
    void DidEqution(QString string);
public slots:
    void DoMultiplying(QString string);
    void DoSummury(QString string);
    void DoMinus(QString string);
    void DoDivision(QString string);
    void DoEquation(QString string);
    void ClearNumbers();
private:
    void DoMathOperation(double(*MathOperation)(double first,double second),QString number);
    void CalculateAndswer();
};

#endif // CALCULATOR_H
