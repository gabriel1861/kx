//*************************//
//用于获取url.xml 		//
//得到电影路径			//
//*************************//

#include "play.h"
#include <QtGui/QApplication>
#include <QTextCodec>
#include <iostream>


const static QString URLFRONT = "http://10.168.200.1/return.asp?info=";
const static QString BASEFILEPATH = "../url.xml";
const static QString FILEPATH = "../info.xml";

static int JI = 0;

int main(int argc,char* argv[])
{
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	qDebug("kx ^_^...\n");
	QApplication a(argc,argv);
	play o;
	o.setbasefile(BASEFILEPATH);
	QStringList r = o.find();
	
	if(r.size() != 1)
	{
		qDebug()<<r.size();
		qDebug()<<"find failed.";
		qApp->exit();
	}

	if((strcmp(argv[1],"howmany") == 0) || (strcmp(argv[1],"manyhow") == 0))
	{
		//from 0 last one was empty 
		qDebug()<<"total have"<<r.at(0).split(",").size() - 2<<"ji";
		return 0;
	}
	else 
	{
		JI = atoi(argv[1]);

		QString code = r.at(0).split(",").at(JI);
		code.remove(QChar('\n'), Qt::CaseInsensitive);
	
		o.geturlxml(URLFRONT + code,FILEPATH);
		qDebug("geturl ok\n");
	}

	return a.exec();	
}



