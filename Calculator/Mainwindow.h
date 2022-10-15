#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Calculator.h"
#include <QSignalMapper>
//#include <calculation.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //QString* Answer;

public slots:


    /*void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_0_clicked();*/

    void on_pushButton_clear_clicked();


    void on_pushButton_division_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_equals_clicked();
    void AddNumbersSlot(const QString&);
    void ShowAnswerSlot(QString);

signals:
    void ChangetoSumSignal();
    void ChangetoMinusSignal();
    void ChangetoMultiplicationSignal();
    void ChangetoDivisionSignal();



    void ToClearNumberSignal();



    void MakeSummSingal(QString);
    void MakeMinusSignal(QString);
    void MakeMultiplicationSignal(QString);
    void MakeDivisionSignal(QString);

    void DoCalculationSignal(QString);

private slots:
    void on_pushButton_mines_clicked();

    void on_pushButton_multiplay_clicked();

private:

    bool mIsNumberExistVariable=false;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
