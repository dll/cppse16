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
	std::cout << pName << "  " << pX << "  " << pY << std::endl;//����ʾ���ϴ�ӡ
}