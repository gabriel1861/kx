#ifndef __GETTER_H__
#define __GETTER_H__
#include <stdio.h>
#include <string.h>
#include <QObject>

#include "../common/store.h"
#include "../common/net.h"

class getter :public QObject
{
	Q_OBJECT	
public:
	QString find(char* d);
	void get(QString d);	
	getter();
	~getter();

private slots:
	
	void makeurl(QString p);
private:
	net *n;
	store *s;
};
#endif
