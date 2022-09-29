#include "CalculatorClass.h"

CalculatorClass::CalculatorClass(QObject *parent)
    : QObject{parent}
{

}
double CalculatorClass::MultiplyingFunction(double first, double second){
    return first*second;
}
double CalculatorClass::DividFunction(double first,double second){
    return first/second;
}
double CalculatorClass::SummaryFunction(double first, double second){
    return first+second;
}
double CalculatorClass::MinusFunction(double first, double second){
    return first-second;
}
void CalculatorClass::DoMathOperationFunction(double (*MathOperation)(double, double),QString number){
    if(mIsFirstOperationVariable){
        mFirstNumberVariable=number.toDouble();
        mOperationChooseVariable=MathOperation;
        mIsFirstOperationVariable=false;
    }
    else{
        mFirstNumberVariable=mOperationChooseVariable(CalculatorClass::mFirstNumberVariable,number.toDouble());
        mOperationChooseVariable=MathOperation;
    }
}
void CalculatorClass::ClearNumbersSlot(){
    mFirstNumberVariable=0;
    mIsFirstOperationVariable=true;
}
void  CalculatorClass::DoSummurySlot(QString number){
   DoMathOperationFunction(SummaryFunction,number);
}
void CalculatorClass::DoDivisionSlot(QString number){
    DoMathOperationFunction(DividFunction,number);
}
void CalculatorClass::DoMinusSlot(QString number){
    DoMathOperationFunction(MinusFunction,number);
}
void CalculatorClass::DoMultiplyingSlot(QString number){
    DoMathOperationFunction(MultiplyingFunction,number);

}
void CalculatorClass::ChangetosummurySlot(){
    mOperationChooseVariable=SummaryFunction;
}
void CalculatorClass::ChangetoMinusSlot(){
    mOperationChooseVariable=MinusFunction;
}
void CalculatorClass::ChangetoMultiplyingSlot(){
    mOperationChooseVariable=MultiplyingFunction;
}
void CalculatorClass::ChangetoDivisionSlot(){
    mOperationChooseVariable=DividFunction;
}

void CalculatorClass::DoEquationSlot(QString string){
    //отправляет посчитанный ответ в форму
    if(!mIsFirstOperationVariable){
    mFirstNumberVariable=mOperationChooseVariable(mFirstNumberVariable,string.toDouble());
    mIsFirstOperationVariable=true;
    emit DidEqutionSignal(QString::number(mFirstNumberVariable));
    }
}

