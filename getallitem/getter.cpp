#include "getter.h"

getter::getter()
{
	s = new store();
	n = new net();
	connect(n,SIGNAL(donex(QString)),this,SLOT(makeurl(QString)));
}

getter::~getter()
{
	delete s;
	delete n;
}

QString  getter::find(char* d)
{
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());	
	QString q(QObject::tr(d));
	s->init();
	return s->findex(q);
}
void getter::makeurl(QString p)
{
	QStringList items = p.split(",");
	printf("make url ok\n");
	for(int i = 0;i < items.size();i ++)
	{
		QString show = "http://10.168.200.1/kuue/" + items[i] + ".mkv";
		qDebug()<<show;
	}
	qApp->exit();
}
void getter::get(QString d)
{
	n->getfilepath(d);
}

