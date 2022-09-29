#ifndef CALCULATORCLASS_H
#define CALCULATORCLASS_H

#include <QObject>

class CalculatorClass : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorClass(QObject *parent = nullptr);

 //   QString *Answer;



    double static MultiplyingFunction(double first, double second);
    double static DividFunction(double first,double second);
    double static MinusFunction(double first, double second);
    double static SummaryFunction(double first,double secnd);

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

    void DoMathOperationFunction(double(*MathOperation)(double first,double second),QString number);
    void CalculateAndswerFunction();
};

#endif // CALCULATORCLASS_H
