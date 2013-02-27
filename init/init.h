#ifndef __INIT_H__
#define __INIT_H__

#include <stdio.h>
#include <string.h>

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtGui/QApplication>
#include <QTextCodec>
#include <QFile>
#include <QXmlStreamReader>
#include <QTextCodec>
#include <QDebug>

const  static QUrl TAERGET("http://10.168.200.1/mov/xml/Total.xml"); 
const static QString FILEPATH("../Total.xml");

class init :public QObject
{
	Q_OBJECT
public:
	init();
	~init();
	void run();

private slots:
	void reply(QNetworkReply* r);
private:
	QNetworkAccessManager *netmanager;
};

#endif
