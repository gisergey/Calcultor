#include "calculator.h"

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
    if(IsFirstOperation){
        FirstNumber=number.toDouble();
        OperationChoose=MathOperation;
        IsFirstOperation=false;
    }
    else{
        FirstNumber=OperationChoose(Calculator::FirstNumber,number.toDouble());
        OperationChoose=MathOperation;
    }
}
void Calculator::ClearNumbers(){
    FirstNumber=0;
    IsFirstOperation=true;
}
void  Calculator::DoSummury(QString number){
   DoMathOperation(Calculator::Summary,number);
}
void Calculator::DoDivision(QString number){
    DoMathOperation(Divid,number);
}
void Calculator::DoMinus(QString number){
    DoMathOperation(Minus,number);
}
void Calculator::DoMultiplying(QString number){
    DoMathOperation(Multiplying,number);
}

void Calculator::DoEquation(QString string){
    //отправляет посчитанный ответ в форму
    if(!IsFirstOperation){
    FirstNumber=OperationChoose(FirstNumber,string.toDouble());
    IsFirstOperation=true;
    emit DidEqution(QString::number(FirstNumber));
    }
}

