#include<iostream>
#include"DrawFactory.h"
#include "Singleton.h"

using namespace std;

class Menu{
public:
//	Menu(){}
	
	void showMainMenu(){
		cout<<"\n���ģʽ��ʾ"<<endl;
		int mainchoice = 1;
		do {												
			cout <<"\n1:�򵥹���ģʽ\n\
				    \n2:��������ģʽ\n\
					\n3:����ģʽ\n\
					\n4:XXX\n\
					\n��ѡ��1~4��,0 �˳�"<<endl;	
			cin >> mainchoice;
			switch(mainchoice){
				case 1:showSimpleFactory();break;
				case 2:showFactoryMethod();break;
				case 3:showSingleton();break;
				case 4:showXXX(); break;
				case 0:exit(0);
				default:cout<<"�������"<<endl;
			}
			system("cls");
			cout<<"\n���ģʽ��ʾ"<<endl;
		}while (mainchoice <4 && mainchoice > -1);
	}	
	void showSimpleFactory(){
		cout<<"\n***�򵥹���ģʽ***\n"<<endl;
		int choice = 1;
		while(choice!=0){
			do {												
				cout <<"1:��Բ;2:������;3:�������Ρ���ѡ��1~3��,0 �˳�"<<endl;	
				cin >> choice;
			}while (choice < 0 || choice > 3);
			if(choice==0)break;
			DrawFactory::getInstance(choice) -> draw ();	
			// ͨ������ȡ�ýӿڵ�ʵ�����ʵ�����Զ�̬�󶨷�ʽ����ʵ����Ļ�ͼ����
		}	
	}
	void showFactoryMethod(){
		cout<<"\n***��������ģʽ***\n"<<endl;
		int choice = 1;
		DrawFactory* pdf = nullptr;  // ����ӿڵ�����
		cout <<"1:��Բ;2:������;3:�������Ρ���ѡ��1~3��,������ �˳�"<<endl;	
		while(cin >> choice){
			cout <<"1:��Բ;2:������;3:�������Ρ���ѡ��1~3��,������ �˳�"<<endl;	
			switch(choice){								// �����û�ѡ�����ɹ���ʵ��
			case 1: pdf = new CirFactory ();break;
			case 2: pdf = new RecFactory ();break;
			case 3: pdf = new TriFactory ();break;
			default:cout<<"������1,2,3��"<<endl;continue;
			}
			pdf -> MakeDrawer () -> draw (); // ���ù������� ���ɻ�ͼ����ͼ
		}
	}
	void showSingleton(){
		Singleton *s1=Singleton::getSingleton();
		cout<<"s1��ַ"<<s1<<endl;
		Singleton *s2=Singleton::getSingleton();
		cout<<"s2��ַ"<<s2<<endl;
		if(s1==s2)
			cout<<"ֻ��ʵ����һ������"<<endl;
		system("pause");
	}
	//4.
	void showXXX(){
		cout<<"����ӵ��ĸ���ʾ"<<endl;
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

