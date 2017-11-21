#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "qbizmanager.h"
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QButtonGroup>

#include <QStandardItemModel>
#include <QSqlTableModel>
#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <vector>
#include <deque>
#include <QList>
struct Db_Data
{
    QString var1;
    QString var2;
    QString var3;
    QString var4;
};

struct Url_referer
{
    QString var1;
    QString var2;
    QString var3;
};


using namespace  std;
namespace Ui {
class MainWindow;
}
class MainWindow :  public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

 Ui::MainWindow *ui;
private:

  //  bool initDb();

    void GetUrl();


public slots:
  void test();
  void doBlance();

private slots:


    void on_pushButton_clicked();

private:


QBizManager  * qbm;

};

#endif
