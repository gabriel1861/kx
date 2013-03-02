#include "inquiry.h"

inquriy::inquriy():xmldealer()
{}

inquriy::~inquriy()
{}
//覆盖父类的find 减少 传入参数
QStringList inquriy::find(QString tag)
{
	return xmldealer::find(tag,"");
}

//覆盖父类虚函数deal（）
bool inquriy::deal(QString tag,QString context)
{
	if(filereader.name() == tag) 
	{
		result << filereader.readElementText();
	}
	return true;
}
