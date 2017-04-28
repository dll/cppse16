#include<iostream>
#include"DrawFactory.h"

using namespace std;

class Menu{
public:
	Menu(){}
	
	void showMainMenu(){
		cout<<"\n设计模式演示"<<endl;
		int mainchoice = 1;
		do {												
			cout <<"\n1:简单工厂模式\n\
				    \n2:工厂方法模式\n\
					\n请选择（1~2）,0 退出"<<endl;	
			cin >> mainchoice;
			switch(mainchoice){
				case 1:showSimpleFactory();break;
				case 2:showFactoryMethod();break;
				case 0:exit(0);
				default:cout<<"输入错误！"<<endl;
			}
			system("cls");
			cout<<"\n设计模式演示"<<endl;
		}while (mainchoice <3 && mainchoice > -1);
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
};

class DesignPatternDemo{
public:
	DesignPatternDemo(){	}
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

