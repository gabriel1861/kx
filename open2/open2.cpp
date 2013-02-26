#include "open2.h"

open2::open2()
{
	SetBaseFile(FILEPATH);
}

open2::~open2()
{}

QString open2::geturl(int pos)
{
	while(!filereader.atEnd())
	{
		filereader.readNext();
		if(filereader.isStartElement())
		{
			if(filereader.name() == "b")
			{
				return URLFRONT + filereader.readElementText().split(",").at(pos) + URLBACK;
			}
		}
		else if(filereader.hasError())
		{
			qDebug()<<"xml read error:"<<filereader.errorString();
			return "";
		}	
		else if(filereader.atEnd())
		{
			qDebug()<<"xml read done";
			return "";
		}
	}
	return "";
}

void open2::SetBaseFile(const QString s)
{
	basefile.setFileName(s);
	if(!basefile.open(QFile::ReadOnly))
		qDebug()<<"open basefile failed.";
	filereader.setDevice(&basefile);
}