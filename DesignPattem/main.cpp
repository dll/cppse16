#include<iostream>
#include"DrawFactory.h"
#include "Singleton.h"

using namespace std;

class Menu{
public:
//	Menu(){}
	
	void showMainMenu(){
		cout<<"\n设计模式演示"<<endl;
		int mainchoice = 1;
		do {												
			cout <<"\n1:简单工厂模式\n\
				    \n2:工厂方法模式\n\
					\n3:单例模式\n\
					\n4:XXX\n\
					\n请选择（1~4）,0 退出"<<endl;	
			cin >> mainchoice;
			switch(mainchoice){
				case 1:showSimpleFactory();break;
				case 2:showFactoryMethod();break;
				case 3:showSingleton();break;
				case 4:showXXX(); break;
				case 0:exit(0);
				default:cout<<"输入错误！"<<endl;
			}
			system("cls");
			cout<<"\n设计模式演示"<<endl;
		}while (mainchoice <4 && mainchoice > -1);
	}	
	void showSimpleFactory(){
		cout<<"\n***简单工厂模式***\n"<<endl;
		int choice = 1;
		while(choice!=0){
			do {												
				cout <<"1:画圆;2:画矩形;3:画三角形。请选择（1~3）,0 退出"<<endl;	
				cin >> choice;
			}while (choice < 0 || choice > 3);
			if(choice==0)break;
			DrawFactory::getInstance(choice) -> draw ();	
			// 通过工厂取得接口的实例类的实例并以动态绑定方式调用实力类的画图方法
		}	
	}
	void showFactoryMethod(){
		cout<<"\n***工厂方法模式***\n"<<endl;
		int choice = 1;
		DrawFactory* pdf = nullptr;  // 定义接口的引用
		cout <<"1:画圆;2:画矩形;3:画三角形。请选择（1~3）,非整数 退出"<<endl;	
		while(cin >> choice){
			cout <<"1:画圆;2:画矩形;3:画三角形。请选择（1~3）,非整数 退出"<<endl;	
			switch(choice){								// 根据用户选择生成工厂实例
			case 1: pdf = new CirFactory ();break;
			case 2: pdf = new RecFactory ();break;
			case 3: pdf = new TriFactory ();break;
			default:cout<<"请输入1,2,3！"<<endl;continue;
			}
			pdf -> MakeDrawer () -> draw (); // 调用工厂方法 生成画图对象画图
		}
	}
	void showSingleton(){
		Singleton *s1=Singleton::getSingleton();
		cout<<"s1地址"<<s1<<endl;
		Singleton *s2=Singleton::getSingleton();
		cout<<"s2地址"<<s2<<endl;
		if(s1==s2)
			cout<<"只能实例化一个对象"<<endl;
		system("pause");
	}
	//4.
	void showXXX(){
		cout<<"请添加第四个演示"<<endl;
		system("pause");
	}
};

class DesignPatternDemo{
public:
	//DesignPatternDemo(){}
	void DesignPatternDemoMenu(){
		Menu *mainMenu=new Menu();
		mainMenu->showMainMenu();
		delete mainMenu;
	}
};

int main (int argc, char *argv[]) {
	DesignPatternDemo *dpd=new DesignPatternDemo();
	dpd->DesignPatternDemoMenu();
	delete dpd;
	return 0;
}

