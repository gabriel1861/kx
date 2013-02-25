#include "init.h"

init::init()
{
	netmanager = new QNetworkAccessManager(this);
}
init::~init()
{
	delete netmanager;
}

void init::run()
{
    connect(netmanager,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
    netmanager->get(QNetworkRequest(TAERGET));	
}


//============
//change the file for utp to gb18030
//============
void init::reply(QNetworkReply* r)                                      
{     
	qDebug()<<"sever reply ok";
	QTextCodec *codec = QTextCodec::codecForName("GB18030");	
	QFile xf(FILEPATH);
	if(!xf.open(QIODevice::WriteOnly))
	{
		qDebug()<<"open Tatal.xml failed";
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
	qApp->exit();
}
