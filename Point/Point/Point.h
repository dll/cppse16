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
		Point(std::string name, float x, float y);//���������
		void ShowPoint();//��ʾ����
};
