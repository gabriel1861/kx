//**********************************//
//get the total.xml 				//
//all the movie information in it 	//
//**********************************//



#include <QApplication>
#include "init.h"

const static QString UCL("http://10.168.200.1/mov/xml/Total.xml");
const static QString FILEPATH("../Total.xml");

int main(int argc,char* argv[])
{
	qDebug()<<"kx ^_^...";
	QApplication a(argc,argv);
	init i;
	i.geturl(UCL,FILEPATH);
	qDebug()<<"get total ok.";
	return a.exec();
}
