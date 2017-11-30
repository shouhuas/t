#include "qbizmanager.h"
#include "qhttpmanager.h"
#include <queue>
#include <QObject>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <QVariant>


QBizManager::QBizManager( )
{

    initDb();
	


	m_StringList.append("haye welcome cryptopia");
	m_StringList.append("hi welcome cryptopia");
	m_StringList.append("hey welcome cryptopia");
	m_StringList.append("hello welcome cryptopia");
	m_StringList.append("welcome to cryptopia");
	//m_StringList.append("  #-o ");
	//m_StringList.append(":-B ");
	//m_StringList.append(" #:-S ");
	//m_StringList.append(":))");
	//m_StringList.append("hey");


	ticker t;
			   
	t.cookie = "__RequestVerificationToken=Xfh23NS-9BHy19PWe_8FOtg23idwK6VyFH0SQh8OQK9inxWJBUzKuqiU5_4mJTtvQRLKaVluJFMbR93U6HaP4AUDaTQKPJW4rzeF-lQ-CSs1; nlbi_1244263=K9dWS8SUBz+DiR8DFZCruQAAAADja1eNrfKLtLM/zWdzTnAJ; visid_incap_1244263=+bVT8gDhTDGl3O2DykbMxOAZmVkAAAAAQUIPAAAAAACDD0SSFvUVU3cf/RqyoS3s; incap_ses_968_1244263=ST1UF98rcjw6OU6z6gZvDXFPEVoAAAAAwG/Axw86XpUiW+Uyw97MJg==; __asc=4a04615a15fd39fb6e2e8ca0caf; __auc=ce80168e1581a727645194e4178; Cryptopia=ahVykkGrpwkHtu2hkztM1QCINn-H0iDb1fEu7ZDi4Zs-13MO0Vy1UTESHVqIZASehq70-8l0R8yI-j4TMcGPSo_xr-aAhSg9LKFwuy2lq0unk_NdlJZwV7MM277y82jHqmp6JylPtc4vidtVOocZAijF5T8Nh5kPpslicjTfbiKgDT-2aptnhYkAcqwXYEeK_5LrpNPHTPAUnshAjQGu46JpRjvzTSfJEThCzh4CtN0NTYXO-SM33dvpuSiHCiBNBhme2XodojDaGxpcy1n9YE_EVHVs1tnHpea3lYdVEfXDN7Ku3kSV5DAb98WS9pP4KMpu_MRAifWIQrt4usAYnTOafos7M33ycBgCRRKmdzu_tbXnpUe24fjgyA7VcKfD6YDvDOB1dQthrxTCPECqw5spezDl153m9HToUsXlji25_4AuvrdRn78HAHVPAOMS-cD9c4YUrKqmbXqTiANMwq3Cf9FEJ9avbwfCvMgkza45tEgA21TBgBOh6Ydwq2DWGE3v8oo4BWEHRydBqzwFYQmiXm050rvI5k57h4iDFZq-yjnlwCNiZ4ew9QoRMa3bVQ6k98M98UIwIvGJ6ZX3o0NIvfSgyESg7aVulHG2s7YF35bdE2bq08f17B2sSFWe";
	t.message = "&__RequestVerificationToken=Jktv44ETJ7pxdTMRQQqfIYJYs7Jv9CCGBq-tSuNtRCkv0lTjVddBPxFO6UvFh1mZIUgM-5bkiEnpesEratvwS39slv24TWOZ8Z52AleF4ApPxXMi3qa2E74WIcLXh0SRJtGndF6SuZ6wb0lBZuSJhw2";
	m_cookie_msg.append(t);
   
	//t.cookie = "visid_incap_1244263=/wvOMzN2SdeSWWebfD+tR7pg71kAAAAAQUIPAAAAAAB9ORmNhFDFCoC0demJNV3L; nlbi_1244263=8Gz/G7qqlDJdKtyYaz1cMwAAAADGm4MO/QYCFGcHDOqgymck; incap_ses_164_1244263=ogWgex3qFjmGJ8Y8JqVGArpg71kAAAAApL927bTb1pI1fM0hE0ZIqg==; __asc=a2ce76c115f4f12e92db17bbca3; __auc=a2ce76c115f4f12e92db17bbca3; __RequestVerificationToken=D-pK6Mp-SpweK2r2UMLQc2bI3MQ2hWUytBfXHVD_8_u4qV_BHBMTykc_GNCsWlgs40uVBFkaNzn9dQJpSBWklL9JxxwIrOQNF-fjTs5f5_g1; Cryptopia=8oOTodZivm6alZe1yw9ZWSf2FMtr-NUX1bXPFsylEvKpCZ1gwyNoaFYxeIWP0SCMprw_vhTyAHvAHUNYBKJtYAqXPd2YMcgkr21KM6l0H-b-UJxfHstX6A5nnjdRAJ4nq1wew9012aQfo1HSPIqwmYemdaSXagn9f4TIe6Sof7EFrk25ZN3wo1JufLteS1OsBkNCijfa0VjtphH4QmaZlH5Ep0J1lIYk0lvibIlEpCel7KBz8g-sO2_MwDDl7X_R_424uCdA9q6lZ7rAL_CT8W5Ho1rGRnJEeo26Xd4UoZnX55o0aBeH4A1t98DRfuxPW1zCsyX_aOlYV8JiHTmEedNDLxtOIPYzz7WGyQkSLfsiCiR5v6iRkTRjsUnRi3-kvomlFzNiMU0nqpnhnNbAjdYe2LdHdcWzkBvGqChrq6V1Aan2ycU7cNprSR1J5DDb90K_rHfua_p79dn6U0mfoYtMBfYeKHz9OpQvqiEDQHno4-xccJpMHhGZsxDF6XZgk4OKbar4Ukfx9yoGcitRLJAYuncwHA-cQaiGZMZ2ufBpsa9VefDexXGmc_FFaH9FInJh17zX-MaO811Ohxhx9IEGDLuaiOQNxkEdFppujJGj8CZFemB7pCVSoebSz0bT270c0govjG8hDrliGrBDVA";
	//t.message = "&__RequestVerificationToken=zU1J3enjgA2RlOIB2cdDziwpYcfPvTthh3u0gvMmixesLvi9MkVhb6LHAX95PH0byrUdG0tMypzf8vx8cZWGFfUsXxxl3mi0Hp99987Rs3uSjfke5YqaqA3i-t_pFj4Rh1D4xvhCFxZGQkOnXW2bMQ2";
	//m_cookie_msg.append(t);

	//t.cookie = "visid_incap_1244263=+bVT8gDhTDGl3O2DykbMxOAZmVkAAAAAQUIPAAAAAACDD0SSFvUVU3cf/RqyoS3s; __RequestVerificationToken=KM3eSwq1qsi8xtGJBMuHKrHjevfRv8V3NbZ0rh-DXCLSf4eTbSemhZrHgxH1EHPOpJlPTLd5JQDmvOSZZRw1jaRjb6XxRPEJjPXsbLRBNVQ1; nlbi_1244263=8A0IQDfYCiskTpCCaz1cMwAAAACnwPs6vvKKTL+9r4JCLwpw; incap_ses_164_1244263=SmlRDzZj7GN1tsc8JqVGAuNi71kAAAAAaw5gyLzL9xEJ4aD71wx6HA==; __asc=440134e115f4f00aa9b223497d5; __auc=ce80168e1581a727645194e4178; Cryptopia=JRer9J-Xk2x90miFyXgsGgbDl-mPfBf1kbN5zzSu9dHnOr0lLvQvmLZxY5qelBzMO26FWY9OMvzxMv0CTlL33nqlsMmEX0e9O1XMZ0I3ftrflx1WFLA7a9BLiQ2RCYktwbAJfhpzGGDaLTcXpTyZ25JGWowXzAzHuJngArACLTYpw5NvYc3j7dNguNkHbmNI28RKEdOZl6dP18P0os-dal31oqT6Qy0i2PqJlFo49Ls-ZJI7vLXwEb7-a8ko_ZnX_-SQSQCZALsodu2A8yelK1CxKvwGYKhrAmCIq7M_wb0sz2xc9fAJJG6NAiLvERKdWlFho3jGvTvC0lcKj73cCJkM14r5dmRmhFgbLO4OJ6whLLeNY1AkWFVA-BGEx-YB22QEXxfmOMa3_bYJSC_YLmEqeaxzQZHBFAnMF0CTug1Swxfv7Xv5eZPeX87xsvYfheWgOZlu2MwOmpTdroqkxOst0djqWVATcmOUqAhAUs9UnM1RUxxYyj2iCuAkyUUY54_COjudKVUSB1kbNmcLvyZJtX2_wpd5jLXrvob2YCXBRblXQejUTDK6b53WLtV9eGP4Y9g1aMK1TzuCtTUD9DyY_1ne2umzF4jWakpOV66ThSqKePcFwaMAv-0D4OeWqxx-gB0vJKw9mGDu-1t2NA";
	//t.message = "&__RequestVerificationToken=CiADYAiUlvW-b5bm7bM0Pwin5RFl5xZfaBnN9OAovrGCsJ3V4v4pnxSc6Lgz1IkZVU78072RnVmeX1KlZXG_iO21JzFDzkBzDyGYALTywnt4_3iCFoCKbJOZB1G1gAtYGUPzmeA6gK5FdK25Y8tfdQ2";
	//m_cookie_msg.append(t);

}


//! [0]
bool QBizManager::initDb()
{
    QSqlDatabase  db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("a.db");
    if (!db.open()) {

        return false;
    }

    QSqlQuery query;
    query.exec("create table User(var1 varchar(128),var2 varchar(128),var3 varchar(128),var4 varchar(128))");
    query.exec("create table Order(User varchar(20) primary key)");


    query.exec("select * FROM Order");
        if (query.next()) {
			;// £»¡¢¡¢ m_s.insert(query.value(0).toString());
             qDebug()<<"11111111111111";

        }



    return true;
}


QBizManager::~QBizManager()
{
}


void QBizManager::SubmitTrade(const QString& rate, int buysell)
{
	QString secret = "m//zW/FBxXC8akWe5zBR8LUiK2RJLgF7kxcdUD5AwLs=";
	QString publicKey = "853384ce523546008b9592739287c2d6";
	QString once = QString("c6%1").arg(QDateTime::currentMSecsSinceEpoch());// .mid(5, 9);

	QString url = "https://www.cryptopia.co.nz/api/SubmitTrade";
	QString nonce = QString("c6%1").arg(QDateTime::currentMSecsSinceEpoch()).mid(5, 9);
	QString amount = QString::number(90 - nonce.mid(7, 1).toInt() - nonce.mid(7, 1).toInt() / 7.0 + nonce.mid(8, 1).toInt() + nonce.mid(8, 1).toInt() / 3.0);

	QString strbuysell = QString::number(buysell);

	QString str_Rate = "0.00000" + rate;
	if(rate.length()==2)
		str_Rate = "0.000000" + rate;
	if (rate.length() == 3)
		str_Rate = "0.00000" + rate;
	if (rate.length() == 4)
		str_Rate = "0.0000" + rate;

	QString post_data = "{\"TradePairId\": null,\"Market\":\"LIZI/BTC\",\"Type\":" + strbuysell + ",\"Rate\":" + str_Rate + ",\"Amount\":" + amount + "}";

	QString m;
	QByteArray bb;
	bb = QCryptographicHash::hash(post_data.toLatin1(), QCryptographicHash::Md5);
	m.append(bb.toBase64());

	QString requestContentBase64String = m;
	QString signature = publicKey + "POST" + url.toLatin1().toPercentEncoding().toLower() + nonce + requestContentBase64String;
	QString hmacsignature = QMessageAuthenticationCode::hash(signature.toLatin1(), QByteArray::fromBase64(secret.toLatin1()), QCryptographicHash::Sha256).toBase64();
	QString header_value = "amx " + publicKey + ":" + hmacsignature + ":" + nonce;

	QByteArray send;
	send.append(post_data);
	QString source;
	QHttpManager::GetInstance().HttpPost("https://www.cryptopia.co.nz/api/SubmitTrade", send, source, header_value);
}


void QBizManager::SubmitTransfer(const QString& Username)
{
	QString secret = "Zq+eZdCSkGih5lpaOCz5r6UtTd5G1dbgoQaHCjQGmAs=";
	QString publicKey = "e6c9bffdf54643d8af3fc3fadefd41b7";
	QString once = QString("c6%1").arg(QDateTime::currentMSecsSinceEpoch());// .mid(5, 9);

	QString url = "https://www.cryptopia.co.nz/api/SubmitTransfer";
	QString nonce = QString("c6%1").arg(QDateTime::currentMSecsSinceEpoch()).mid(5, 9);
	QString amount = "1";// QString::number(1 + nonce.mid(8, 1).toInt() % 2);
	QString post_data = "{\"Currency\":\"LIZI\",\"Username\":\""+ Username +"\",\"Amount\":" + amount + "}";;;

	QString m;
	QByteArray bb;
    bb = QCryptographicHash::hash(post_data.toLatin1(), QCryptographicHash::Md5);
	m.append(bb.toBase64());

	QString requestContentBase64String = m;
    QString signature = publicKey + "POST" + url.toLatin1().toPercentEncoding().toLower() + nonce + requestContentBase64String;
    QString hmacsignature = QMessageAuthenticationCode::hash(signature.toLatin1(), QByteArray::fromBase64(secret.toLatin1()), QCryptographicHash::Sha256).toBase64();
	QString header_value = "amx " + publicKey + ":" + hmacsignature + ":" + nonce;

	QByteArray send;
	send.append(post_data);
	QString source;
	QHttpManager::GetInstance().HttpPost("https://www.cryptopia.co.nz/api/SubmitTransfer", send, source, header_value);
}

void QBizManager::CancelTrade(const QString & OrderId)
{
	QString secret = "m//zW/FBxXC8akWe5zBR8LUiK2RJLgF7kxcdUD5AwLs=";
	QString publicKey = "853384ce523546008b9592739287c2d6";
	QString once = QString("c6%1").arg(QDateTime::currentMSecsSinceEpoch()).mid(5, 9);

	QString url = "https://www.cryptopia.co.nz/api/CancelTrade";
	QString nonce = QString("c6%1").arg(QDateTime::currentMSecsSinceEpoch()).mid(5, 9);
	QString post_data = "{\"Type\":\"All\",\"OrderId\":"+ OrderId  +",\"TradePairId\":5186}";

	QString m;
	QByteArray bb;
    bb = QCryptographicHash::hash(post_data.toLatin1(), QCryptographicHash::Md5);
	m.append(bb.toBase64());

	QString requestContentBase64String = m;
    QString signature = publicKey + "POST" + url.toLatin1().toPercentEncoding().toLower() + nonce + requestContentBase64String;
    QString hmacsignature = QMessageAuthenticationCode::hash(signature.toLatin1(), QByteArray::fromBase64(secret.toLatin1()), QCryptographicHash::Sha256).toBase64();
	QString header_value = "amx " + publicKey + ":" + hmacsignature + ":" + nonce;

	QByteArray send;
	send.append(post_data);
	QString source;
	QHttpManager::GetInstance().HttpPost("https://www.cryptopia.co.nz/api/CancelTrade", send, source, header_value);
}

void QBizManager::GetTradeHistory()
{
	QString secret = "m//zW/FBxXC8akWe5zBR8LUiK2RJLgF7kxcdUD5AwLs=";
	QString publicKey = "853384ce523546008b9592739287c2d6";
	QString once = QString("c6%1").arg(QDateTime::currentMSecsSinceEpoch()).mid(5, 9);

	QString url = "https://www.cryptopia.co.nz/api/GetOpenOrders";
	QString nonce = QString("c6%1").arg(QDateTime::currentMSecsSinceEpoch()).mid(5, 9);
	QString post_data = "{\"Currency\":\"LIZI\",\"Count\":'5'}";

	QString m;
	QByteArray bb;
    bb = QCryptographicHash::hash(post_data.toLatin1(), QCryptographicHash::Md5);
	m.append(bb.toBase64());

	QString requestContentBase64String = m;
    QString signature = publicKey + "POST" + url.toLatin1().toPercentEncoding().toLower() + nonce + requestContentBase64String;
    QString hmacsignature = QMessageAuthenticationCode::hash(signature.toLatin1(), QByteArray::fromBase64(secret.toLatin1()), QCryptographicHash::Sha256).toBase64();
	QString header_value = "amx " + publicKey + ":" + hmacsignature + ":" + nonce;

	QByteArray send;
	send.append(post_data);
	QString source;
	QHttpManager::GetInstance().HttpPost("https://www.cryptopia.co.nz/api/GetOpenOrders", send, source, header_value);

	QStringList _QStringList = source.split("OrderId");

	for (size_t i = 1; i < _QStringList.size(); i++)
	{
		QString str = _QStringList.at(i);
		QString OrderId = str.mid(2,9);
		CancelTrade(OrderId);
	}
}

void QBizManager::GetBalance()
{
	QString secret = "m//zW/FBxXC8akWe5zBR8LUiK2RJLgF7kxcdUD5AwLs=";
	QString publicKey = "853384ce523546008b9592739287c2d6";
	QString once = QString("c6%1").arg(QDateTime::currentMSecsSinceEpoch()).mid(5, 9);

	QString url = "https://www.cryptopia.co.nz/api/SubmitTrade";
	QString nonce =   QString("c6%1").arg(QDateTime::currentMSecsSinceEpoch()).mid(5, 9);
	QString post_data = "{\"Currency\":\"LIZI\"}";

	QString m;
	QByteArray bb;
    bb = QCryptographicHash::hash(post_data.toLatin1(), QCryptographicHash::Md5);
	m.append(bb.toBase64());

	QString requestContentBase64String = m;
    QString signature = publicKey + "POST" + url.toLatin1().toPercentEncoding().toLower() + nonce + requestContentBase64String;
    QString hmacsignature = QMessageAuthenticationCode::hash(signature.toLatin1(), QByteArray::fromBase64(secret.toLatin1()), QCryptographicHash::Sha256).toBase64();
	QString header_value = "amx " + publicKey + ":" + hmacsignature + ":" + nonce;

	QByteArray send;
	send.append(post_data);
	QString source;
	QHttpManager::GetInstance().HttpPost("https://www.cryptopia.co.nz/api/SubmitTrade", send, source, header_value);
}

#include <QSet>
void QBizManager::SubmitTip()
{
	QString secret = "Zq+eZdCSkGih5lpaOCz5r6UtTd5G1dbgoQaHCjQGmAs=";
	QString publicKey = "e6c9bffdf54643d8af3fc3fadefd41b7";
	QString once = QString("c6%1").arg(QDateTime::currentMSecsSinceEpoch());// .mid(5, 9);

	QString url = "https://www.cryptopia.co.nz/api/SubmitTip";
	QString nonce = QString("c6%1").arg(QDateTime::currentMSecsSinceEpoch()).mid(5, 9);
	QString amount = "1";// QString::number(1 + nonce.mid(8, 1).toInt() % 2);
	QString post_data = "{\"Currency\":\"LIZI\",\"ActiveUsers\":\"10\",\"Amount\":\"2\"}";;;

	QString m;
	QByteArray bb;
    bb = QCryptographicHash::hash(post_data.toLatin1(), QCryptographicHash::Md5);
	m.append(bb.toBase64());

	QString requestContentBase64String = m;
    QString signature = publicKey + "POST" + url.toLatin1().toPercentEncoding().toLower() + nonce + requestContentBase64String;
    QString hmacsignature = QMessageAuthenticationCode::hash(signature.toLatin1(), QByteArray::fromBase64(secret.toLatin1()), QCryptographicHash::Sha256).toBase64();
	QString header_value = "amx " + publicKey + ":" + hmacsignature + ":" + nonce;

	QByteArray send;
	send.append(post_data);
	QString source;
	QHttpManager::GetInstance().HttpPost("https://www.cryptopia.co.nz/api/SubmitTip", send, source, header_value);
}

void QBizManager::doSell()
{
	int loop = 0;
	int int_buy_price = 0;
	int int_sell_price = 0;
	while (1)
	{
		if (int_buy_price == 0)
		{

			doCancle();

			QString source;
			QHttpManager::GetInstance().HttpGet("https://www.cryptopia.co.nz/api/GetMarketOrders/LIZI_BTC", source);

			int p = source.indexOf("Price");
			int p2 = source.indexOf("\"", p + 10);
			QString buy_price = source.mid(p + 7, 10);

			QString sell_price;
		
				int p3 = source.indexOf("Sell");
				p = source.indexOf("Price", p3);
				p2 = source.indexOf("\"", p + 10);

				int p5 = source.indexOf("Volume", p2);
				int p6 = source.indexOf("\"", p5 + 10);

				QString sell_volume = source.mid(p5 + 8, p6 - p5 - 9);

		
					sell_price = source.mid(p + 7, 10);
		

			buy_price = buy_price.mid(2).replace(",", "");
			sell_price = sell_price.mid(2).replace(",", "");
			int_buy_price = sell_price.toInt();
			int_sell_price = sell_price.toInt();

		}

		if (loop % 10 == 1)
		{

			doCancle();

			QString source;
			QHttpManager::GetInstance().HttpGet("https://www.cryptopia.co.nz/api/GetMarketOrders/LIZI_BTC", source);

			int p = source.indexOf("Price");
			int p2 = source.indexOf("\"", p + 10);
			QString buy_price = source.mid(p + 7, 10);

			QString sell_price;
		

				int p3 = source.indexOf("Sell");
				p = source.indexOf("Price", p3);
				p2 = source.indexOf("\"", p + 10);

				int p5 = source.indexOf("Volume", p2);
				int p6 = source.indexOf("\"", p5 + 10);

				QString sell_volume = source.mid(p5 + 8, p6 - p5 - 9);
				sell_price = source.mid(p + 7, 10);
		


			buy_price = buy_price.mid(2).replace(",", "");
			sell_price = sell_price.mid(2).replace(",", "");
			int_buy_price = sell_price.toInt();
			int_sell_price = sell_price.toInt();

		}

		doCancle();

		if (int_sell_price == 0)
			continue;

		for (int i = int_sell_price; i <= int_sell_price + 10; i++)
		{
			QString rate = QString::number(i);
			SubmitTrade(rate, 1);
		}

		loop++;
	}
	return;
}

void QBizManager::doTransfer()
{
	int loop = 0;
    QString b_buy_price;
    while (1)
	{
		if (b_buy_price.isEmpty())
		{			
			QString source;
			QHttpManager::GetInstance().HttpGet("https://www.cryptopia.co.nz/api/GetMarketOrders/LIZI_BTC", source);

			int p = source.indexOf("Price");
			int p2 = source.indexOf("\"", p + 10);
			QString buy_price = source.mid(p + 7, 10);

			b_buy_price = buy_price;
		}

		if (loop % 15 == 1)
		{
			QString source;
			QHttpManager::GetInstance().HttpGet("https://www.cryptopia.co.nz/api/GetMarketOrders/LIZI_BTC", source);

			int p = source.indexOf("Price");
			int p2 = source.indexOf("\"", p + 10);
			QString buy_price = source.mid(p + 7, 10);
			b_buy_price = buy_price;
		}
		
		int NN = b_buy_price.mid(7,3).toInt();
		doCancle();
		for (int i = NN; i >= NN-10; i--)
		{
			QString rate = QString::number(i);		
			SubmitTrade(rate,0);
		}
		loop++;
    }
    return;
}


void QBizManager::doCancle()
{
	GetTradeHistory();
	return;
}

void QBizManager::SendChatMessage(const QString & post_data, const QString & cookie)
{
	QByteArray send;
	send.append(post_data);
	QString source;
	QHttpManager::GetInstance().HttpPost_msg("https://www.cryptopia.co.nz/Chat/SendChatMessage", send, source, cookie);
	return;
}


void QBizManager::PostMessages(const QString& Username)
{
	QString post_data = "__RequestVerificationToken=cXcAcgxk4Zz6IN-rKTKwk0V3bsfiPZPI8fqJhKLEHbwKmdDcacGplLSOH2TFtf2PpWU-ajsIUNsgwo_1NqKxhqRCEil4v3i5H5_QYU4sEoVjHnJkKitig1RF3aHKd41SCFIbrj12Qp2fCfBxUhIKhQ2&Recipiants=" + Username + "&Subject=dsfsd&Message=%3Cp%3Efojbn15%3C%2Fp%3E&X-Requested-With=XMLHttpRequest";

	QString m;
	QByteArray bb;
    bb = QCryptographicHash::hash(post_data.toLatin1(), QCryptographicHash::Md5);
	m.append(bb.toBase64());
	QString header_value = "amx ";

	QByteArray send;
	send.append(post_data);
	QString source;
	QHttpManager::GetInstance().HttpPost("https://www.cryptopia.co.nz/UserMessage/CreateMessage?Length=11", send, source, header_value);
	return;


}
