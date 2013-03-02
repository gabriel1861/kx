//*************************//
//用于获取total.xml 		//
//得到所有电影信息			//
//*************************//

#include "inquiry.h"
#include <QtGui/QApplication>
#include <QTextCodec>
#include <QStringList>
#include <iostream>
const static QString FILEPATH("../Total.xml");

int main(int argc,char* argv[])
{
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	printf("kx ^_^...\n");
	QApplication a(argc,argv);
	inquriy inqu;
 	inqu.SetBaseFile(FILEPATH);
	
	QStringList r = inqu.find(argv[1]);
	for(int i = 0;i < r.size();i ++)
	{
		std::cout<<r.at(i).toStdString()<<std::endl;
	}
	return 0;
}



