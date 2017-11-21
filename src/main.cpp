#include <QApplication>

#include "qbizmanager.h"
#include <QtCore>
#include <QTextCodec>
#include <QDebug>

#include <QObject>

#include <QtDebug>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QBizManager q;
    q.doTransfer();
    return a.exec();
}

