//**********************************//
//print file name (by use param "a" )//
//use with grep					 //
//**********************************//

#ifndef __INQUIRY_H__
#define __INQUIRY_H__

#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>
#include <iostream>
#include "../xmldealer/xmldealer.h"

class inquriy:public xmldealer
{
public:
	inquriy();
	~inquriy();
	QStringList find(QString tag);

private: 
	virtual bool deal(QString tag,QString context);
};

#endif
