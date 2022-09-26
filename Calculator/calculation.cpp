#include "calculation.h"
#include <QString>
Calculation::Calculation(){

}

double Calculation::Multiplying(double first, double second){
    return first*second;
}
double Calculation::Divid(double first,double second){
    return first/second;
}
double Calculation::Summary(double first, double second){
    return first+second;
}
double Calculation::Minus(double first, double second){
    return first-second;
}

void Calculation::DoSummury(){
   OperationChoose=Summary;
   IsFirstOperation=false;
}
void Calculation::DoEquation(){
    *Answer=QString::number(OperationChoose(Calculation::FirstNumber,Calculation::SecondNumber));
}
