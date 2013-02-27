#include "play.h"

play::play()
{
	SetBaseFile(FILEPATH);
}

play::~play()
{}

QString play::geturl(int pos)
{
	while(!filereader.atEnd())
	{
		filereader.readNext();
		if(filereader.isStartElement())
		{
			if(filereader.name() == "b")
			{
				QString code = filereader.readElementText().split(",").at(pos);
				code.remove(QChar('\n'), Qt::CaseInsensitive);
				return URLFRONT + code + URLBACK;
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

void play::SetBaseFile(const QString s)
{
	basefile.setFileName(s);
	if(!basefile.open(QFile::ReadOnly))
		qDebug()<<"open basefile failed.";
	filereader.setDevice(&basefile);
}
