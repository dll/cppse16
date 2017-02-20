#pragma once

#include<string>
#include<iostream>

//第1步：定义Point类
class Point {
	//定义三个私有属性
	private://私有属性/字段
		std::string pName;//名称
		float  pX;//x坐标
		float  pY;//y坐标
	//定义两个公共方法
	public://公共方法
		//添加三个重载构造函数：声明declare
		Point();
		Point(std::string name);
		Point(Point & p);

		Point(std::string name, float x, float y);//创建类对象
		void ShowPoint();//显示对象
};
