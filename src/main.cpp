#include "mainwindow.h"
#include <QApplication>

#include "qbizmanager.h"
#include <QtCore>
#include <QTextCodec>
#include <QDebug>

#include <QObject>

#include <QtDebug>
#include <QFile>
#include <QTextStream >
void customMessageHandler(QtMsgType type, const char *msg)
{
    QString txt;
    switch (type)
   {
    case QtDebugMsg:     //调试信息提示
            txt = QString("%1 Debug: %2\r\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(msg);
            break;
    case QtWarningMsg:  //一般的warning提示
            txt = QString("%1 Warning: %2\r\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(msg);
            break;
    case QtCriticalMsg:    //严重错误提示
            txt = QString("Critical: %1\r\n").arg(msg);
            break;
    case QtFatalMsg:      //致命错误提示
            txt = QString("Fatal: %1\r\n").arg(msg);
            abort();
   default:
           break;
    }

    QFile outFile(QDateTime::currentDateTime().toString("yyyy-MM-dd")+".txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << txt << endl;
}

 bool getHtml(QString url)
 {
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    QNetworkRequest request;
    QSslConfiguration config;//C:\Program Files (x86)\PC Connectivity Solution\;C:\Program Files\Broadcom\Broadcom 802.11 Network Adapter\Driver;;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;%SystemRoot%\system32;%SystemRoot%;%SystemRoot%\System32\Wbem;%SYSTEMROOT%\System32\WindowsPowerShell\v1.0\;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\Intel\OpenCL SDK\2.0\bin\x86;C:\Program Files (x86)\Intel\OpenCL SDK\2.0\bin\x64;C:\Program Files\Lenovo\Bluetooth Software\;C:\Program Files\Lenovo\Bluetooth Software\syswow64;C:\ProgramData\Lenovo\ReadyApps

    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    config.setProtocol(QSsl::TlsV1);
    request.setSslConfiguration(config);

    request.setUrl(QUrl(url));
    QNetworkReply *reply = manager->get(request);
    QByteArray responseData;
    QEventLoop eventLoop;
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();       //block until finish


    QList<QByteArray> headerList = reply->rawHeaderList();
    foreach(QByteArray head, headerList) {
    responseData += head;
    responseData += reply->rawHeader(head);
    }

    QString t = responseData.mid(9,20);
    QString q = "05 Jan 2015 09:53:33";

    int a = t<q;

    manager->deleteResource(request);
    reply->close();
    return 0;
}


//manager->setProxy
int main(int argc, char *argv[])
{
	QTextCodec *xcodec = QTextCodec::codecForLocale();
	QString exeDir = xcodec->toUnicode(QByteArray(argv[0]));
	QString BKE_CURRENT_DIR = "D:/Qt/Qt5.5.1/5.5/msvc2013";
	QStringList  libpath;
	libpath << BKE_CURRENT_DIR + QString::fromLocal8Bit("/plugins/platforms");
	libpath << BKE_CURRENT_DIR << BKE_CURRENT_DIR + QString::fromLocal8Bit("/plugins/imageformats");
	libpath << BKE_CURRENT_DIR + QString::fromLocal8Bit("/plugins");
	libpath << QApplication::libraryPaths();

	BKE_CURRENT_DIR = ".";
	//QStringList  libpath;
	libpath << BKE_CURRENT_DIR + QString::fromLocal8Bit("/plugins/platforms");
	libpath << BKE_CURRENT_DIR << BKE_CURRENT_DIR + QString::fromLocal8Bit("/plugins/imageformats");
	libpath << BKE_CURRENT_DIR + QString::fromLocal8Bit("/plugins");
	libpath << QApplication::libraryPaths();

	QApplication::setLibraryPaths(libpath);
 

	QApplication a(argc, argv);
	qInstallMsgHandler(customMessageHandler);

    //QNetworkProxy proxy;
    //proxy.setType(QNetworkProxy::HttpProxy);
    //proxy.setHostName("127.0.0.1");
    //proxy.setPort(8888);
    //proxy.setUser("username");
    //proxy.setPassword("password");
	QBizManager q;
	q.doTransfer();
  /*  MainWindow w;
    w.show();*/
    return a.exec();
}

