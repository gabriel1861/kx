//*************************//
//用于获取url.xml 		//
//得到电影路径			//
//*************************//

#include "play.h"
#include <QtGui/QApplication>
#include <QTextCodec>
#include <iostream>
int main(int argc,char* argv[])
{
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	qDebug("kx ^_^...\n");
	QApplication a(argc,argv);
	play o;
	std::cout<<o.geturl(0).toStdString();
	qDebug("geturl ok\n");
	return 0;	
}



