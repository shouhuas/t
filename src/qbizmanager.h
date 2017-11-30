#ifndef QBIZMANAGER_H
#define QBIZMANAGER_H
#include <QObject>
#include "qhttpmanager.h"
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMap>
#include <QHash>
#include <QSet>


struct ticker{
    QString cookie;
    QString message ;

};

class QBizManager : public QObject
{
 Q_OBJECT
public:
    QBizManager( );

     ~QBizManager();
public:
     bool initDb();


	 QString GetMarketOrders();
	
	 void SubmitTrade(const QString& rate, int buysell);
	 void SubmitTransfer(const QString& Username);
	 void SubmitTip();
	 
	 void GetBalance();
	 void GetTradeHistory();

     void doSell();
     void doTransfer();
	 void SendChatMessage(const QString & post_data, const QString & cookie);

	 void PostMessages(const QString& Username);

	 void CancelTrade(const QString &);

	 void doCancle();

	 

signals:
        void sig_displayCaptcha(const QString& ok_market);
        void sig_showStartPrice(const QString& ok_market);
void closed();
    private Q_SLOTS:



private:

    QString GetJsonValue(const QString& json,const  QString&  key,const  QString&  ukey=0);
   QString  GetPriceValue(const QString& json,const  QString&  key,const  QString&  ukey=0);
  //  QString hmacSha1(const QString &key,                 const QString &secret);


private:
 
	QString history;

	QVector<ticker> m_cookie_msg;
  

	QStringList m_StringList;

	QStringList m_cookieList;

};



#endif // QBIZMANAGER_H
