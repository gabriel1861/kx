#ifndef __XMLDEALER_H__
#define __XMLDEALER_H__
#include <QStringList>
#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>
class xmldealer
{
protected:
	QFile basefile;
	QXmlStreamReader filereader;
	virtual bool deal(QString tag,QString){ qDebug()<<"base class deal was called something wrong.";return false;}
public:
	void SetBaseFile(QString);
	QStringList find(QString tag,QString context);
	QStringList result;
};
#endif
