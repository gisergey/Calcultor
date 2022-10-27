#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Calculator.h"
#include <QSignalMapper>
#include <QTcpSocket>
#include <QLineEdit>
#include <QTime>
#include <QDataStream>
#include <QMessageBox>
#include <QTimeEdit>
//#include <calculation.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString& strHost,int nPort,QWidget *parent=nullptr);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //QString* Answer;

public slots:


    void SentToServerSlot(QString);
    void toClearNumberClickSlot();
    void toDivisionNumberClickSlot();

    void toPlusNumberClickSlot();
    void toMinusNumberClickSlot();
    void toMultiplyNumberClickSlot();
    void toEqualNumberClickSlot();

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
    void ReadyReadSlot   (                            );
    void ErrorSlot       (QAbstractSocket::SocketError);

   // void ConnectedSlot(                      );
private:
    QTcpSocket* mpTcpSocket;
    quint16 mnNextBlockSize;
    bool mIsNumberExistVariable=false;
    //bool mIsFirstTime=true;
    //QTime mStartTime;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
