#include "MainwindowClass.h"
#include "ui_mainwindow.h"

MainWindowClass::MainWindowClass(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindowClass::~MainWindowClass()
{
    delete ui;
}
void MainWindowClass::AddNumberonlineFunction(QString digit){
    if(mIsNumberExistVariable){
        ui->OutputLine->setText(ui->OutputLine->text()+digit);
    }
    else{
        ui->OutputLine->setText(digit);
        mIsNumberExistVariable=true;
    }
}
void MainWindowClass::on_pushButton_9_clicked(){
    AddNumberonlineFunction("9");
}
void MainWindowClass::on_pushButton_8_clicked(){
    AddNumberonlineFunction("8");
}
void MainWindowClass::on_pushButton_7_clicked(){
     AddNumberonlineFunction("7");
}
void MainWindowClass::on_pushButton_6_clicked(){
   AddNumberonlineFunction("6");
}
void MainWindowClass::on_pushButton_5_clicked(){
 AddNumberonlineFunction("5");
}
void MainWindowClass::on_pushButton_4_clicked(){
 AddNumberonlineFunction("4");
}
void MainWindowClass::on_pushButton_3_clicked(){
 AddNumberonlineFunction("3");
}
void MainWindowClass::on_pushButton_2_clicked(){
 AddNumberonlineFunction("2");
}
void MainWindowClass::on_pushButton_1_clicked(){
 AddNumberonlineFunction("1");
}
void MainWindowClass::on_pushButton_0_clicked(){
    QString digit="0";
    if(mIsNumberExistVariable){
        ui->OutputLine->setText(ui->OutputLine->text()+digit);
    }
}
void MainWindowClass::on_pushButton_clear_clicked(){
    mIsNumberExistVariable=false;
    ui->OutputLine->setText("0");
}
void MainWindowClass::on_pushButton_equals_clicked()
{
    emit MainWindowClass::DoCalculationSignal(ui->OutputLine->text());
}

void MainWindowClass::ShowAnswerSlot(QString string){
    ui->OutputLine->setText(string);

}
void MainWindowClass::on_pushButton_plus_clicked()
{
    if(!mIsNumberExistVariable){
        emit ChangetoSumSignal();
        return;
    }
    emit MakeSummSingal(ui->OutputLine->text());
    mIsNumberExistVariable=false;

}
void MainWindowClass::on_pushButton_mines_clicked()
{
    if(!mIsNumberExistVariable){
        emit ChangetoMinusSignal();
        return;
    }
    emit MakeMinusSignal(ui->OutputLine->text());
    mIsNumberExistVariable=false;

}
void MainWindowClass::on_pushButton_division_clicked()
{
    if(!mIsNumberExistVariable){
        emit ChangetoDivisionSignal();
        return;
    }
    emit MakeDivisionSignal(ui->OutputLine->text());
    mIsNumberExistVariable=false;

}
void MainWindowClass::on_pushButton_multiplay_clicked()
{
    if(!mIsNumberExistVariable){
        emit ChangetoMultiplicationSignal();
        return;
    }
    emit MakeMultiplicationSignal(ui->OutputLine->text());
    mIsNumberExistVariable=false;

}

