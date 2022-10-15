#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject
{
    Q_OBJECT
public:
    explicit Calculator(QObject *parent = nullptr);

 //   QString *Answer;



    double static Multiplying(double first, double second);
    double static Divid(double first,double second);
    double static Minus(double first, double second);
    double static Summary(double first,double secnd);

signals:
    void DidEqutionSignal(QString string);
public slots:
    void ChangetosummurySlot();
    void ChangetoMinusSlot();
    void ChangetoMultiplyingSlot();
    void ChangetoDivisionSlot();

    void DoMultiplyingSlot(QString string);
    void DoSummurySlot(QString string);
    void DoMinusSlot(QString string);
    void DoDivisionSlot(QString string);

    void DoEquationSlot(QString string);
    void ClearNumbersSlot();
private:
    double(*mOperationChooseVariable)(double first,double second);
    double mFirstNumberVariable;
    double mSecondNumberVariable;
    bool mIsFirstOperationVariable=true;

    void DoMathOperation(double(*MathOperation)(double first,double second),QString number);
    void CalculateAndswer();
};

#endif // CALCULATOR_H