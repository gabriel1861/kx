#ifndef __PLAY2_H__
#define __PLAY2_H__

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

#include "../xmldealer/xmldealer.h"

class xmldealerex : public xmldealer
{
public: 
	xmldealerex();
	~xmldealerex();
	
	virtual bool deal(QString tag,QString context);	
};

class play2
{
public:
	play2();
	~play2();

	void setbasefile(QString path);
	QStringList find();
	
	xmldealerex *file;
};
#endif
