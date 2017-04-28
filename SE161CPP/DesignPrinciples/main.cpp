
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
	
	//�������
	std::cout<<"1*�������ԭ��*"<<endl;
	Circle c(1.0);	std::cout << c.getArea() << std::endl;
	
	Pillar p(c,3.0);	std::cout << p.getVolume() << std::endl;
	
	PillarCircle pc(c,3.0);
	std::cout << pc.getVolume() << std::endl;	//����ԭ��
	std::cout<<"\n2**����ԭ��OCP(CRTP)**"<<endl;
	//��̬�Ƕ�̬�󶨣�����ʱ�󶨣���CRTP�Ǿ�̬�󶨣�����ʱ�󶨣�
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
	
	//�������
	std::cout<<"\n3 ***�������ԭ��***"<<endl;
	CCircle cc(1.0);
	Shape* ptrS = &cc;	 // ��ʵ��������ʼ���ӿڵ�ָ��	CPillar pcp(*ptrS,10);	std::cout << pcp.getVolume() << std::endl;
	delete ptrS;
	
	Shape& refS = cc;	 // ��ʵ��������ʼ���ӿڵ�ָ��
	CPillar rcp(refS,10);
	std::cout << rcp.getVolume() << std::endl;
	
	CRectangle cr(1.0, 2.0);
	Shape& refSR =  cr;	 // ��ʵ��������ʼ���ӿڵ�ָ��
	CPillar rcpr(refSR,10);
	std::cout << rcpr.getVolume() << std::endl;
	
	//��һְ��
	std::cout<<"\n4 ****��һְ��ԭ��****"<<endl;
	ICalcArea& ica=cr;
	std::cout<<ica.getArea()<<endl;//�������
	IDrawShape&ids=cr;
	ids.draw();//����ͼ��
	
	
	//��Ҫ��İ����˵��
	std::cout<<"\n5 *****��Ҫ��İ����˵��*****"<<endl;
	RingCircle::Circle rc(10);
	std::cout<<rc.calcPerimeter()<<" "<<rc.calcArea()<<endl;
	RingCircle::Ring rr(10,1);
	std::cout<<rr.calcPerimeter()<<" "<<rr.calcArea()<<endl;

	return 0;
}

