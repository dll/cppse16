#include"Point.h"

//��2����ʵ����ķ���
//���캯��/����
Point::Point(std::string name, float x, float y) {
	this->pName = name;//������name��ֵ����������pName
	this->pX = x;//ͬ��
	this->pY = y;//ͬ��
}

//��ʾ����/����
void Point::ShowPoint() {
	std::cout << pName << "  " << pX << "  " << pY <<"\n"<< std::endl;//����ʾ���ϴ�ӡ
}

//ʵ���������صĹ��캯��������define
Point::Point(){}
Point::Point(std::string name) {
	this->pName = name;
}
Point::Point(Point & p) {
	this->pName = p.pName;
	this->pX = p.pX;
	this->pY = p.pY;
}