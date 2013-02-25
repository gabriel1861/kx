//*************************//
//用于获取total.xml 		//
//得到所有电影信息			//
//*************************//

#include "inquiry.h"
#include <QtGui/QApplication>
#include <QTextCodec>
int main(int argc,char* argv[])
{
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	printf("kx ^_^...\n");
	QApplication a(argc,argv);
	inquriy i;
	i.find(argv[1]);
	return 0;
}



