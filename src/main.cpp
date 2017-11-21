#include <QCoreApplication>
#include "qbizmanager.h"
#include <QtCore>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	QBizManager q;
    q.doTransfer();
    return a.exec();
}

