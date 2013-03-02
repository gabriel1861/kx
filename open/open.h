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

#include "../networkdealer/networkdealer.h"
#include "../xmldealer/xmldealer.h"



class xmldealerex:public xmldealer
{
public:
	xmldealerex();
	~xmldealerex();
private: 
	virtual bool deal(QString tag,QString context);
};


class open: public QObject
{
	Q_OBJECT
public:
	open();
	~open();

	void geturlxml(QString context,QString path);
	void setbasefile(QString path);	
	QStringList find(QString context);

private:
	xmldealerex *file;
	networkdealer *net;

private slots:
	void end();
};
#endif
