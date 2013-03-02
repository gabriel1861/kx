#ifndef __INIT_H__
#define __INIT_H__


#include <QApplication>
#include "../networkdealer/networkdealer.h"


class init:public QObject
{
	Q_OBJECT
public:
	init();
	~init();

	void geturl(QString _url,QString _savepath);
private slots:
	void end();

private:
	networkdealer *net;
};
#endif 
