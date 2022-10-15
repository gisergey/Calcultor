#include "Mainwindow.h"
#include "ui_Mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSignalMapper* mapper=new QSignalMapper(this);
    connect(mapper,SIGNAL(mappedString(const QString&)),this,SLOT(AddNumbersSlot(const QString&)));

    connect(ui->pushButton_0,SIGNAL(clicked()),mapper,SLOT(map()));
    mapper->setMapping(ui->pushButton_0,"0");
    connect(ui->pushButton_1,SIGNAL(clicked()),mapper,SLOT(map()));
    mapper->setMapping(ui->pushButton_1,"1");
    connect(ui->pushButton_2,SIGNAL(clicked()),mapper,SLOT(map()));
    mapper->setMapping(ui->pushButton_2,"2");
    connect(ui->pushButton_3,SIGNAL(clicked()),mapper,SLOT(map()));
    mapper->setMapping(ui->pushButton_3,"3");
    connect(ui->pushButton_4,SIGNAL(clicked()),mapper,SLOT(map()));
    mapper->setMapping(ui->pushButton_4,"4");
    connect(ui->pushButton_5,SIGNAL(clicked()),mapper,SLOT(map()));
    mapper->setMapping(ui->pushButton_5,"5");
    connect(ui->pushButton_6,SIGNAL(clicked()),mapper,SLOT(map()));
    mapper->setMapping(ui->pushButton_6,"6");
    connect(ui->pushButton_7,SIGNAL(clicked()),mapper,SLOT(map()));
    mapper->setMapping(ui->pushButton_7,"7");
    connect(ui->pushButton_8,SIGNAL(clicked()),mapper,SLOT(map()));
    mapper->setMapping(ui->pushButton_8,"8");
    connect(ui->pushButton_9,SIGNAL(clicked()),mapper,SLOT(map()));
    mapper->setMapping(ui->pushButton_9,"9");

}
void MainWindow::AddNumbersSlot(const QString& digit){

    if(mIsNumberExistVariable){
        ui->OutputLine->setText(ui->OutputLine->text()+digit);
    }
    else if(digit!="0"){
        ui->OutputLine->setText(digit);
        mIsNumberExistVariable=true;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pushButton_9_clicked(){
    //AddNumberonline("9");
}
void MainWindow::on_pushButton_8_clicked(){
    //AddNumberonline("8");
}
void MainWindow::on_pushButton_7_clicked(){
     //AddNumberonline("7");
}
void MainWindow::on_pushButton_6_clicked(){
   //AddNumberonline("6");
}
void MainWindow::on_pushButton_5_clicked(){
 //AddNumberonline("5");
}
void MainWindow::on_pushButton_4_clicked(){
 //AddNumberonline("4");
}
void MainWindow::on_pushButton_3_clicked(){
 //AddNumberonline("3");
}
void MainWindow::on_pushButton_2_clicked(){
 //AddNumberonline("2");
}
void MainWindow::on_pushButton_1_clicked(){
 //AddNumberonline("1");
}
void MainWindow::on_pushButton_0_clicked(){
    //QString digit="0";
    //if(mIsNumberExistVariable){
      //  ui->OutputLine->setText(ui->OutputLine->text()+digit);
    //}
}*/
void MainWindow::on_pushButton_clear_clicked(){
    mIsNumberExistVariable=false;
    ui->OutputLine->setText("0");
}
void MainWindow::on_pushButton_equals_clicked()
{
    emit MainWindow::DoCalculationSignal(ui->OutputLine->text());
}

void MainWindow::ShowAnswerSlot(QString string){
    ui->OutputLine->setText(string);

}
void MainWindow::on_pushButton_plus_clicked()
{
    if(!mIsNumberExistVariable){
        emit ChangetoSumSignal();
        return;
    }
    emit MakeSummSingal(ui->OutputLine->text());
    mIsNumberExistVariable=false;

}
void MainWindow::on_pushButton_mines_clicked()
{
    if(!mIsNumberExistVariable){
        emit ChangetoMinusSignal();
        return;
    }
    emit MakeMinusSignal(ui->OutputLine->text());
    mIsNumberExistVariable=false;

}
void MainWindow::on_pushButton_division_clicked()
{
    if(!mIsNumberExistVariable){
        emit ChangetoDivisionSignal();
        return;
    }
    emit MakeDivisionSignal(ui->OutputLine->text());
    mIsNumberExistVariable=false;

}
void MainWindow::on_pushButton_multiplay_clicked()
{
    if(!mIsNumberExistVariable){
        emit ChangetoMultiplicationSignal();
        return;
    }
    emit MakeMultiplicationSignal(ui->OutputLine->text());
    mIsNumberExistVariable=false;

}

