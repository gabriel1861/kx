//*************************//
//用于获取url.xml 		//
//得到电影路径			//
//*************************//

#include "play2.h"
#include <QtGui/QApplication>
#include <QTextCodec>
#include <QStringList>

const static QString BASEFILEPATH = "../info.xml";
const static QString FORNTPATH = "http://10.168.200.1/";

int main(int argc,char* argv[])
{
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	printf("kx ^_^...\n");
	QApplication a(argc,argv);
	play2 o;
	o.setbasefile(BASEFILEPATH);
	
	QStringList r = o.find();
	if(r.size() != 1)
	{
		qDebug()<<r.size();
		qDebug()<<"find failed.";
		qApp->exit();
	}
	
	qDebug()<<r.at(0);
	QStringList list = r.at(0).split("/");
	for(int i = 0;i < list.size();i ++)
	{
		qDebug()<<list.at(i);
	} 
	QString finalpath = FORNTPATH + list.at(3) + "/" + list.at(4);
	std::cout<<finalpath.toStdString()<<std::endl;
	return 0;	
}



