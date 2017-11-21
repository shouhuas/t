#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>
#include <QObject>
#include <QFileDialog>
#include <QMessageBox>
#include <set>
#include <time.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);


    qbm = new QBizManager();


}

MainWindow::~MainWindow()
{
}



void MainWindow::test()
{
    qbm->doSell();
	qDebug() << "-----------";
}

void MainWindow::doBlance()
{
}


void MainWindow::on_pushButton_clicked()
{
    qbm->doTransfer();
}
