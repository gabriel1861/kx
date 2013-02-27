//*************************//
//用于获取url.xml 		//
//得到电影路径			//
//*************************//

#include "open.h"
#include <QtGui/QApplication>
#include <QTextCodec>
int main(int argc,char* argv[])
{
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	printf("kx ^_^...\n");
	QApplication a(argc,argv);
	open o;
	o.openfile(argv[1]);
	printf("geturl ok\n");
	return a.exec();	
}



