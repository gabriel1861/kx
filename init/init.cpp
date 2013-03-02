#include "init.h"

init::init()
{
	net = new networkdealer();
	connect(net,SIGNAL(done()),this,SLOT(end()));
}

init::~init()
{
	delete net;
}
void init::geturl(QString _url,QString _savepath)
{
	net->run(_url,_savepath);
}

void init::end()
{
	qApp->exit();
}
