#include<iostream>
#include"DrawFactory.h"

using namespace std;

int main (int argc, char *argv[]) {
	
	cout<<"\n***�򵥹���ģʽ***\n"<<endl;
	int choice = 1;
	while(choice!=0){		do {															cout <<"1:��Բ;2:������;3:�������Ρ���ѡ��1~3��,0 �˳�"<<endl;				cin >> choice;		}while (choice < 0 || choice > 3);
		if(choice==0)break;		DrawFactory::getInstance(choice) -> draw ();			// ͨ������ȡ�ýӿڵ�ʵ�����ʵ�����Զ�̬�󶨷�ʽ����ʵ����Ļ�ͼ����	}
	cout<<"\n***��������ģʽ***\n"<<endl;
	DrawFactory* pdf = nullptr;  // ����ӿڵ�����
	cout <<"1:��Բ;2:������;3:�������Ρ���ѡ��1~3��,������ �˳�"<<endl;	
	while(cin >> choice){
		cout <<"1:��Բ;2:������;3:�������Ρ���ѡ��1~3��,������ �˳�"<<endl;			switch(choice){								// �����û�ѡ�����ɹ���ʵ��			case 1: pdf = new CirFactory ();break;			case 2: pdf = new RecFactory ();break;			case 3: pdf = new TriFactory ();break;
			default:cout<<"������1,2,3��"<<endl;continue;		}		pdf -> MakeDrawer () -> draw (); // ���ù������� ���ɻ�ͼ����ͼ	}
	
	return 0;
}

