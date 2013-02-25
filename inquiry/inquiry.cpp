#include "inquiry.h"

inquriy::inquriy()
{
	SetBaseFile(FILEPATH);
}

void inquriy::SetBaseFile(const QString s)
{
	basefile.setFileName(s);
	if(!basefile.open(QFile::ReadOnly))
		qDebug()<<"open basefile failed.";
	filereader.setDevice(&basefile);
}

void inquriy::find(QString tag)
{
	while(!filereader.atEnd())
	{
		filereader.readNext();
		if(filereader.isStartElement())
		{
			if(filereader.name() == tag)std::cout << filereader.readElementText().toStdString() << std::endl;
		}
		else if(filereader.hasError())
		{
			qDebug()<<"xml read error:"<<filereader.errorString();
		}	
		else if(filereader.atEnd())
		{
			qDebug()<<"xml read done";
		}
	}
}
