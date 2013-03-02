#ifndef __NETWORKDEALER_H__
#define __NETWORKDEALER_H__

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTextCodec>
#include <QFile>
#include <QTextCodec>
#include <QDebug>

class networkdealer :public QObject
{
	Q_OBJECT
public:
	networkdealer();
	~networkdealer();
	void run(QString _url,QString _savepath);	//download the file from url

signals:
      void done(); 
private slots:
	void reply(QNetworkReply* r);
private:
	QNetworkAccessManager *netmanager;

	QString savepath;
};

#endif
