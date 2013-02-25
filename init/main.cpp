//**********************************//
//get the total.xml 				//
//all the movie information in it 	//
//**********************************//

#include "init.h"
int main(int argc,char* argv[])
{
	printf("kx ^_^...\n");
	QApplication a(argc,argv);
	init i;
	i.run();
	printf("gettotal ok\n");
	return a.exec();	
	//store x;
	//qDebug()<<x.init()<<endl;
	//qDebug()<<x.SetFile("all.xml")<<endl;
	//qDebug()<<x.built()<<endl;
	
	//qApp->exit();

	//while(!r->atEnd())
      //  xfstream << codec->toUnicode(r->readLine());
    	//xf.close();
    	//qDebug()<<tmp;
	//QXmlStreamReader socx(tmp);
	//socx.setDevice(&tmp);
	//while(!socx.atEnd())
	//{	
	//	socx.readNext();
	//	if(socx.isStartElement())
	//	{
	//		if(socx.name() == "b")
	//			qDebug()<<socx.readElementText();
	//	}		                
	//	else if(socx.hasError())
        //	{
      //                  qDebug()<<"xml read error:"<<socx.errorString()<<endl;
        //        }
      //          else if(socx.atEnd())
        //        {
      //                  qDebug()<<"xml read done"<<endl;
        //        }
	//}
       // qApp->exit();
	//return 0;
}
