#include "play2.h"


xmldealerex::xmldealerex()
{}

xmldealerex::~xmldealerex()
{}
	
bool xmldealerex::deal(QString tag,QString context)
{
	qDebug()<<"new deal was called";
	if(filereader.name() == "url")
	{		
		result<<filereader.readElementText();
		return false;
	}
	return true;
}


play2::play2()
{
	file = new xmldealerex();
}

play2::~play2()
{
	delete file;
}


void play2::setbasefile(QString path)
{
	file->SetBaseFile(path);
}


QStringList play2::find()
{
	return file->find("","");
}

