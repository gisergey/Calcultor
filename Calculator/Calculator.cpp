#include "Calculator.h"

Calculator::Calculator(QObject *parent)
    : QObject{parent}
{

}
double Calculator::Multiplying(double first, double second){
    return first*second;
}
double Calculator::Divid(double first,double second){
    return first/second;
}
double Calculator::Summary(double first, double second){
    return first+second;
}
double Calculator::Minus(double first, double second){
    return first-second;
}
void Calculator::DoMathOperation(double (*MathOperation)(double, double),QString number){
    if(mIsFirstOperationVariable){
        mFirstNumberVariable=number.toDouble();
        mOperationChooseVariable=MathOperation;
        mIsFirstOperationVariable=false;
    }
    else{
        mFirstNumberVariable=mOperationChooseVariable(Calculator::mFirstNumberVariable,number.toDouble());
        mOperationChooseVariable=MathOperation;
    }
}
void Calculator::ClearNumbersSlot(){
    mFirstNumberVariable=0;
    mIsFirstOperationVariable=true;
}
void  Calculator::DoSummurySlot(QString number){
   DoMathOperation(Summary,number);
}
void Calculator::DoDivisionSlot(QString number){
    DoMathOperation(Divid,number);
}
void Calculator::DoMinusSlot(QString number){
    DoMathOperation(Minus,number);
}
void Calculator::DoMultiplyingSlot(QString number){
    DoMathOperation(Multiplying,number);

}
void Calculator::ChangetosummurySlot(){
    mOperationChooseVariable=Summary;
}
void Calculator::ChangetoMinusSlot(){
    mOperationChooseVariable=Minus;
}
void Calculator::ChangetoMultiplyingSlot(){
    mOperationChooseVariable=Multiplying;
}
void Calculator::ChangetoDivisionSlot(){
    mOperationChooseVariable=Divid;
}

void Calculator::DoEquationSlot(QString string){
    //отправляет посчитанный ответ в форму
    if(!mIsFirstOperationVariable){
    mFirstNumberVariable=mOperationChooseVariable(mFirstNumberVariable,string.toDouble());
    mIsFirstOperationVariable=true;
    emit DidEqutionSignal(QString::number(mFirstNumberVariable));
    }
}

