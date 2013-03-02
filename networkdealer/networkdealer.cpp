#include "networkdealer.h"

networkdealer::networkdealer()
{
	netmanager = new QNetworkAccessManager(this);
}
networkdealer::~networkdealer()
{
	delete netmanager;
}

void networkdealer::run(QString _url,QString _savepath)
{
    savepath = _savepath;
    connect(netmanager,SIGNAL(finished(QNetworkReply*)),this,SLOT(reply(QNetworkReply*)));
     qDebug()<<_url;
    netmanager->get(QNetworkRequest(_url));	
}


//============
//change the file for utp to gb18030
//============
void networkdealer::reply(QNetworkReply* r)                                      
{     
	qDebug()<<"replay was called";
	QTextCodec *codec = QTextCodec::codecForName("GB18030");	
	QFile xf(savepath);
	if(!xf.open(QIODevice::WriteOnly))
	{
		qDebug()<<"open "<<savepath << "failed.";
		return;
	}	
	QTextStream xfstream(&xf);
	QString tmp;
	while(!r->atEnd())
	{
		tmp = codec->toUnicode(r->readLine());
		xfstream<<tmp;
	}
	xf.close();
	qDebug()<<"write file ok.";
	emit done();
}
