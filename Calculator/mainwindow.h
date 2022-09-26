#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <calculation.h>

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


    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_clear_clicked();


    void on_pushButton_division_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_equals_clicked();

    void ShowAnswer(QString);

signals:
    void ToClearNumber();
    void MakeDivision(QString);
    void MakeMultiplication(QString);
    void MakeSumm(QString);
    void MakeMinus(QString);
    void DoCalculation(QString);

private slots:
    void on_pushButton_mines_clicked();

    void on_pushButton_multiplay_clicked();

private:
    void Cl();
    void add_number_on_line(QString digit);
    bool IsNumberExist=false;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
