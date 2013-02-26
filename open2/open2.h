#ifndef __OPEN2_H__
#define __OPEN2_H__

#include <QObject>
#include <QtGui/QApplication>
#include <QTextCodec>
#include <QFile>
#include <QXmlStreamReader>
#include <QTextCodec>
#include <QDebug>
#include <iostream>
#include <QStringList>


const static QString URLFRONT = "http://10.168.200.1/kuuf/";
const static QString URLBACK = ".mkv";
const static QString FILEPATH = "../url.xml";

class open2
{
public:
	open2();
	~open2();

public:
	QString geturl(int);

	QFile basefile;
	QXmlStreamReader filereader;
	void SetBaseFile(QString);
};
#endif
