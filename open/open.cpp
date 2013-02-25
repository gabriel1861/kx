#include "open.h"

open::open()
{
	netmanager = new QNetworkAccessManager(this);
	SetBaseFile(BASEFILEPATH);
}

open::~open()
{
	delete netmanager;
}

void open::openfile(QString filename)
{
	GeturlFile(filename);
}
void open::GeturlFile(QString filename)
{
    connect(netmanager,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));	
     QString urlpath = GeturlPath(filename);
	qDebug()<<urlpath;
    netmanager->get(QNetworkRequest(urlpath));	
}

QString open::GeturlPath(QString filename)
{
	while(!filereader.atEnd())
	{
		filereader.readNext();
		if(filereader.isStartElement())
		{
			if(filereader.name() == "a")
			{
				if(filereader.readElementText() == "南家三姐妹")
				{
					filereader.readNext();							
					QString path = filereader.readElementText();	
					qDebug()<<path<<"___";
					return URLFRONT + path + URLBACK;
				}
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

//============
//change the file for utp to gb18030
//============
void open::reply(QNetworkReply* r)                                      
{     
	qDebug()<<"sever reply ok";
	QTextCodec *codec = QTextCodec::codecForName("GB18030");	
	QFile xf(FILEPATH);
	if(!xf.open(QIODevice::WriteOnly))
	{
		qDebug()<<"open url.xml failed";
		qApp->exit();
	}	
	QTextStream xfstream(&xf);
	QString tmp;
	
	r->readLine();
	//xfstream <<"?xml version='1.0' encoding='utf-8'?><root>"<<endl;
	xfstream << "<root>"<<endl;
	while(!r->atEnd())
	{
		tmp = codec->toUnicode(r->readLine());
		xfstream<<tmp;
	}
	xf.close();
}

void open::SetBaseFile(const QString s)
{
	basefile.setFileName(s);
	if(!basefile.open(QFile::ReadOnly))
		qDebug()<<"open basefile failed.";
	filereader.setDevice(&basefile);
}

