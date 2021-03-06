#ifndef __PLAY_H__
#define __PLAY_H__

#include <QObject>
#include <QtGui/QApplication>
#include <QTextCodec>
#include <QFile>
#include <QXmlStreamReader>
#include <QTextCodec>
#include <QDebug>
#include <iostream>
#include <QStringList>

#include "../xmldealer/xmldealer.h"
#include "../networkdealer/networkdealer.h"

class xmldealerex : public xmldealer
{
public: 
	xmldealerex();
	~xmldealerex();
	
	virtual bool deal(QString tag,QString context);	
};


class play :  public QObject
{
	Q_OBJECT
public:
	play();
	~play();
	
public:
	void geturlxml(QString context,QString path);
	void setbasefile(QString path);
	QStringList find();
	

	xmldealerex *file;
	networkdealer *net;
private slots:
	void end();
};
#endif
