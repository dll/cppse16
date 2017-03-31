#ifndef DRAW_H
#define DRAW_H

#include<iostream>

class Draw {
private:
protected:
public:
	Draw();
	~Draw();
	virtual void doDraw ()=0;//纯虚函数：不能创建对象实例，只能声明引用和指针类型
};

#endif

