#include "play.h"
xmldealerex::xmldealerex()
{}

xmldealerex::~xmldealerex()
{}
	
bool xmldealerex::deal(QString tag,QString context)
{
	qDebug()<<"new deal was called";
	if(filereader.name() == "b")
	{		
		result<<filereader.readElementText();
		return false;
	}
	return true;
}


play::play()
{
	file = new xmldealerex();
	net = new networkdealer();
	connect(net,SIGNAL(done()),this,SLOT(end()));
}

play::~play()
{
	delete file;
	delete net;
}
	

void play::setbasefile(QString path)
{
	file->SetBaseFile(path);
}


QStringList play::find()
{
	return file->find("","");
}

void play::end()
{
	qDebug()<<"end was called";
	qApp->exit();
}

void play::geturlxml(QString context,QString path)
{
	qDebug()<<"geturlxml was called.";
	net->run(context,path);
}
