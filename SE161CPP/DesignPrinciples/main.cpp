
#include "Circle.h"
#include "Pillar.h"
#include "PillarCircle.h"

#include "OCP.h"
#include "CRTP.h"

#include "Shape.h"
#include "CCircle.h"
#include "CPillar.h"

#include "CRectangle.h"

#include"ICalcArea.h"
#include"IDrawShape.h"


using namespace std;

int main (int argc, char *argv[]) {
	
	//组合优先
	std::cout<<"1*组合优先原则*"<<endl;
	Circle c(1.0);	std::cout << c.getArea() << std::endl;
	
	Pillar p(c,3.0);	std::cout << p.getVolume() << std::endl;
	
	PillarCircle pc(c,3.0);
	std::cout << pc.getVolume() << std::endl;	//开闭原则
	std::cout<<"\n2**开闭原则OCP(CRTP)**"<<endl;
	//多态是动态绑定（运行时绑定），CRTP是静态绑定（编译时绑定）
	ocp::Shape * ocpS=new ocp::Circle(1);//upcast,Polymorphism==Open Principle
	std::cout<<(*ocpS).getArea()<<endl;//Close Principle
	ocpS=new ocp::Rectangle(1,10);
	std::cout<<(*ocpS).getArea()<<endl;
	
	crtp::Shape<crtp::Circle>* crtpSC=new crtp::Circle(1);//upcast,Polymorphism==Open Principle
	(*crtpSC).calcArea();//Close Principle
	delete crtpSC;
	crtp::Shape<crtp::Rectangle>* crtpSR=new crtp::Rectangle(1,10);
	(*crtpSR).calcArea();
	delete crtpSR;
	
	//面向抽象
	std::cout<<"\n3 ***面向抽象原则***"<<endl;
	CCircle cc(1.0);
	Shape* ptrS = &cc;	 // 用实例类对象初始化接口的指针	CPillar pcp(*ptrS,10);	std::cout << pcp.getVolume() << std::endl;
	delete ptrS;
	
	Shape& refS = cc;	 // 用实例类对象初始化接口的指针
	CPillar rcp(refS,10);
	std::cout << rcp.getVolume() << std::endl;
	
	CRectangle cr(1.0, 2.0);
	Shape& refSR =  cr;	 // 用实例类对象初始化接口的指针
	CPillar rcpr(refSR,10);
	std::cout << rcpr.getVolume() << std::endl;
	
	//单一职责
	std::cout<<"\n4 ****单一职责原则****"<<endl;
	ICalcArea& ica=cr;
	std::cout<<ica.getArea()<<endl;//计算面积
	IDrawShape&ids=cr;
	ids.draw();//绘制图形
	
	
	//不要和陌生人说话
	std::cout<<"\n5 *****不要和陌生人说话*****"<<endl;
	RingCircle::Circle rc(10);
	std::cout<<rc.calcPerimeter()<<" "<<rc.calcArea()<<endl;
	RingCircle::Ring rr(10,1);
	std::cout<<rr.calcPerimeter()<<" "<<rr.calcArea()<<endl;

	return 0;
}

