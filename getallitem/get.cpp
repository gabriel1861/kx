#include "getter.h"
int main(int argc,char* argv[])
{
	printf("kx ^_^...\n");
	QApplication a(argc,argv);
	getter g;
	QString result = g.find(argv[1]);
	if(result == "") return 0;
	g.get(result);
	return a.exec();
}
