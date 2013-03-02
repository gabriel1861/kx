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
	
	QString code = r.at(0).split(",").at(0);
	code.remove(QChar('\n'), Qt::CaseInsensitive);
	
	o.geturlxml(URLFRONT + code,FILEPATH);
	qDebug("geturl ok\n");
	return a.exec();	
}



