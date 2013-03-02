#include "xmldealer.h"


void xmldealer::SetBaseFile(const QString s)
{
	basefile.setFileName(s);
	if(!basefile.open(QFile::ReadOnly))
		qDebug()<<"open basefile failed.";
	filereader.setDevice(&basefile);
}

QStringList xmldealer::find(QString tag,QString context)
{
	result.clear();
	while(!filereader.atEnd())
	{
		filereader.readNext();
		if(filereader.isStartElement())
		{
			if(!deal(tag,context)) 
				return result;
		}
		else if(filereader.hasError())
		{
			qDebug()<<"xml read error:"<<filereader.errorString();
			result.clear();
			return result;
		}	
		else if(filereader.atEnd())
		{
			qDebug()<<"xml read done";
			return result;
		}
	}
	result.clear();
	return result;
}
