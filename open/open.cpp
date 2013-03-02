#include "open.h"

xmldealerex::xmldealerex()
{}

xmldealerex::~xmldealerex()
{}

bool xmldealerex::deal(QString tag,QString context)
{
	if(filereader.name() == "a")
	{
		if(filereader.readElementText() == context)
		{
			filereader.readNext();										
			result<<filereader.readElementText();
			qDebug()<<result.size();
			return false;
		}
	}	
	return true;
}


open::open()
{
	file = new xmldealerex();
	net = new networkdealer();
	connect(net,SIGNAL(done()),this,SLOT(end()));
}

open::~open()
{
	delete file;
	delete net;
}



QStringList open::find(QString context)
{
	return file->find("",context);
}


void open::geturlxml(QString context,QString path)
{
	net->run(context,path);
}

void open::setbasefile(QString path)
{
	file->SetBaseFile(path);
}

void open::end()
{
	qApp->exit();
}
