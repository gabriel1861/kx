#ifndef __OPEN_H__
#define __OPEN_H__

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
#include <iostream>

const static QString URLFRONT = "http://10.168.200.1/mov/";
const static QString URLBACK = "/url.xml";
const static QString FILEPATH = "../url.xml";
const static QString BASEFILEPATH("../Total.xml");

class open: public QObject
{
	Q_OBJECT
public:
	open();
	~open();
public:
	void openfile(QString);
	

private slots:
	void reply(QNetworkReply* r);
private:
	QNetworkAccessManager *netmanager;
	QString GeturlPath(QString);
	void GeturlFile(QString);

	QFile basefile;
	QXmlStreamReader filereader;
	void SetBaseFile(QString);
};
#endif
