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
const static QString FILEPATH("../Total.xml");

class inquriy
{
public:
	inquriy();

public: 
	void find(QString tag);
private:
	QFile basefile;
	QXmlStreamReader filereader;
	void SetBaseFile(QString);
};

#endif
