#pragma once

#include<string>
#include<iostream>

//��1��������Point��
class Point {
	//��������˽������
	private://˽������/�ֶ�
		std::string pName;//����
		float  pX;//x����
		float  pY;//y����
	//����������������
	public://��������
		//����������ع��캯��������declare
		Point();
		Point(std::string name);
		Point(Point & p);

		Point(std::string name, float x, float y);//���������
		void ShowPoint();//��ʾ����
};
