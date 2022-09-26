#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::add_number_on_line(QString digit){
    if(IsNumberExist){
        ui->OutputLine->setText(ui->OutputLine->text()+digit);
    }
    else{
        ui->OutputLine->setText(digit);
        IsNumberExist=true;
    }
}
void MainWindow::on_pushButton_9_clicked(){
    add_number_on_line("9");
}
void MainWindow::on_pushButton_8_clicked(){
    add_number_on_line("8");
}
void MainWindow::on_pushButton_7_clicked(){
     add_number_on_line("7");
}
void MainWindow::on_pushButton_6_clicked(){
   add_number_on_line("6");
}
void MainWindow::on_pushButton_5_clicked(){
 add_number_on_line("5");
}
void MainWindow::on_pushButton_4_clicked(){
 add_number_on_line("4");
}
void MainWindow::on_pushButton_3_clicked(){
 add_number_on_line("3");
}
void MainWindow::on_pushButton_2_clicked(){
 add_number_on_line("2");
}
void MainWindow::on_pushButton_1_clicked(){
 add_number_on_line("1");
}
void MainWindow::on_pushButton_0_clicked(){
    QString digit="0";
    if(IsNumberExist){
        ui->OutputLine->setText(ui->OutputLine->text()+digit);
    }
}
void MainWindow::on_pushButton_clear_clicked(){
    IsNumberExist=false;
    ui->OutputLine->setText("0");
}
void MainWindow::Cl(){
    IsNumberExist=false;
    ui->OutputLine->setText("0");
}
void MainWindow::on_pushButton_equals_clicked()
{
    emit MainWindow::DoCalculation(ui->OutputLine->text());
}

void MainWindow::ShowAnswer(QString string){
    ui->OutputLine->setText(string);
}
void MainWindow::on_pushButton_plus_clicked()
{
    emit MakeSumm(ui->OutputLine->text());
    Cl();
}
void MainWindow::on_pushButton_mines_clicked()
{
    emit MakeMinus(ui->OutputLine->text());
    Cl();
}
void MainWindow::on_pushButton_division_clicked()
{
    emit MakeDivision(ui->OutputLine->text());
    Cl();
}
void MainWindow::on_pushButton_multiplay_clicked()
{
    emit MakeMultiplication(ui->OutputLine->text());
    Cl();
}

