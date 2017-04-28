#include<iostream>
#include<fstream>
#include<cstdlib>
#include"PrimeGenerator.h"
#include"PrimerManager.h"
#include"saPrimeGenerator.h"
#include"daPrimeGenerator.h"
#include"max.h"
#include"ArrayTmp.hpp"
#include "BoundArrayTmp.hpp"
#include<ctime>
#include"StackTmp.hpp"

#include"Employee.h"
#include<fstream>
#include"Menu.h"

using namespace std;

void testDesignPattern(){
	DesignPatternDemo *dpd=new DesignPatternDemo();
	dpd->DesignPatternDemoMenu();
	delete dpd;
}

void testSimpleFactory(){
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
void testFactoryMethod(){
	cout<<"\n***��������ģʽ***\n"<<endl;
	int choice = 1;
	DrawFactory* pdf = nullptr;  // ����ӿڵ�����
	cout <<"1:��Բ;2:������;3:�������Ρ���ѡ��1~3��,0 �˳�"<<endl;	;
	while(cin >> choice){
		switch(choice){		// �����û�ѡ�����ɹ���ʵ��
		case 0: exit(0);
		case 1: pdf = new CirFactory ();break;
		case 2: pdf = new RecFactory ();break;
		case 3: pdf = new TriFactory ();break;
		default:cout<<"������1,2,3��"<<endl;continue;
		}
		pdf -> MakeDrawer () -> draw (); // ���ù������� ���ɻ�ͼ����ͼ
		cout <<"1:��Բ;2:������;3:�������Ρ���ѡ��1~3��,0 �˳�"<<endl;	
	}
}
void testSingleton(){
	Singleton *s1=Singleton::getSingleton();
	cout<<"s1��ַ"<<s1<<endl;
	Singleton *s2=Singleton::getSingleton();
	cout<<"s2��ַ"<<s2<<endl;
	if(s1==s2)
		cout<<"ֻ��ʵ����һ������"<<endl;
	system("pause");
}
void testPrimeGenerator(){
	unsigned low, up;
	cout<<"�����뿪ʼ�ͽ���������(�������˳�)��"<<endl;
	cin>>low>>up;
	while(cin.fail()){
		cout<<"�����������ʹ���\n����������"<<endl;
		cin.clear();
		cin.ignore(1024,'\n');
		cin>>low>>up;
	}
	PrimeGenerator pg(low,up);
	pg.GetPrimeSequence();
}
void testPrimeSaveArray(){
	unsigned low, up;
	
	string pglowup = "primegenerator.data";
	ifstream fin(pglowup.c_str());
//	ifstream fin;
//	fin.open(pglowup.c_str(),ios::in);
	if (!fin) {
		std::cerr << "���ܴ�primegenerator.data�ļ�!\n";
		system("pause");
		exit(0);
	}
	while(fin>>low>>up){
		PrimeGenerator pg(low,up);
		pg.GetPrimeSequence();
		if(!pg.SavePrimeSequence()){
			cout<<"�����������н��ʧ�ܣ�"<<endl;
			system("pause");
			exit(0);
		}

	}
	fin.close();
	saPrimeGenerator saPG(100,1);
	saPG.PrintPrime();

	daPrimeGenerator daPG(100,1);
	daPG.PrintPrime();
	
	PrimerManager pm;
	pm.SavePrimerToFile(daPG);
}
void testGenericProgramming(){
	cout<<myMax(10,8)<<endl;
	cout<<myMax(10,18)<<endl;
	cout<<myMax('a', 'b')<<endl;// myMax<char>
	cout<<myMax(56, 'b')<<endl;// error: no matching function for call to 'myMax(int, char)'
	cout<<myMax(10,18,3)<<endl;

	ArrayTmp <int>  IntAry( 5 ) ;
	for (int i = 0; i < 5; i ++ )  IntAry.set ( i, i ) ;
	IntAry.display();
	cout << "Integer Array : \n" ;
	for (int i = 0; i < 5; i ++ )  cout << IntAry.get(i) << endl ;
	
	ArrayTmp <double> DouAry( 5 ) ;
	for (int i = 0; i < 5; i ++ )  DouAry.set ( i, (i+1)*0.35 ) ;
	cout << "Double Array : \n" ;
	for (int i = 0; i < 5; i ++ )  cout << DouAry.get(i) << '\t' ;
	cout<<endl;
	
	ArrayTmp <int>  IntAry1( 5 ) ;
	IntAry1=IntAry;
	cout << "ArrayTmp IntAry1: \n" ;
	for (int i = 0; i < 8; i ++ )  cout << IntAry1.get(i) << endl ;

	BoundArrayTmp <int>  IntAry2(0,4) ;
	for (int i = 0; i < 5; i ++ )  IntAry2.set ( i, i ) ;
	cout<<"First Element of BoundArrayTmp IntAry2:"<<IntAry2.begin()<<endl;
	cout<<"Last Element of BoundArrayTmp IntAry2:"<<IntAry2.end()<<endl;
	cout << "BoundArrayTmp IntAry2: \n" ;
	IntAry2.display();
	IntAry2.deleteElement(3);//
	IntAry2.display();
	IntAry2.resize(5);
	IntAry2.set(4,44);
	IntAry2.insertElement(2,11);
	IntAry2.display();
	for (int i = 0; i < 8; i ++ )  
		cout << IntAry2.get(i) << endl ;
	
	BoundArrayTmp <int>  IntAry3(1,5) ;
	BoundArrayTmp <int>  IntAry4(0,40) ;
	IntAry3=IntAry2;
	IntAry4=IntAry2;
	cout << "BoundArrayTmp IntAry4: \n" ;
	for (int i = 0; i < 8; i ++ )  cout << IntAry4.get(i) << endl ;

	srand( (unsigned)time( NULL ) );
	IntAry2.deleteElement(rand()%IntAry2.size);
	IntAry2.display();

	BoundArrayTmp <int>  IntAry5(0,9) ;
	cout << "Random BoundArrayTmp IntAry5: \n" ;
	for (int i = 0; i < 10; i ++ )  
		IntAry5.set(i,rand()%100) ;
	IntAry5.display();
	IntAry5.selectSort();
	IntAry5.display();
}
void testStackTmp(){
	StackTmp<int> intStackTmp;
	intStackTmp.init();
	intStackTmp.push(66);
	intStackTmp.display();
	intStackTmp.pop();
	intStackTmp.display();
	intStackTmp.push(1);intStackTmp.push(2);intStackTmp.push(3);
	intStackTmp.display();//1,2,3
	intStackTmp.pop();
	intStackTmp.display();//2,3   1,2����ȳ�
	
	StackTmp<char> charStackTmp;
	charStackTmp.init();
	charStackTmp.push('A');
	charStackTmp.display();
	charStackTmp.pop();
	charStackTmp.display();
	charStackTmp.push('A');charStackTmp.push('B');charStackTmp.push('C');
	charStackTmp.display();//1,2,3
	charStackTmp.pop();
	charStackTmp.display();//2,3   1,2����ȳ�
	string n;
	int a;
	char g;
	unsigned w;
	double s;
	//���ļ���
	ifstream ifs("Employee.data");
	while(ifs>>n>>a>>g>>w>>s){
		Employee empn(n,a,g,w,s);
		empn.Output();
	}
	ifs.close();
	
	StackTmp<Employee> EmployeeStackTmp;//����
	EmployeeStackTmp.init();
	ifstream eifs("Employee.data");
	while(eifs>>n>>a>>g>>w>>s){
		Employee empn(n,a,g,w,s);
		EmployeeStackTmp.push(empn);
	}
	EmployeeStackTmp.display();
	eifs.close();
}
//void testDesignPrinciple(){
//	//�������
//	std::cout<<"1*�������ԭ��*"<<endl;
//	Circle c(1.0);
//	std::cout << c.getArea() << std::endl;
//	
//	Pillar p(c,3.0);
//	std::cout << p.getVolume() << std::endl;
//	
//	PillarCircle pc(c,3.0);
//	std::cout << pc.getVolume() << std::endl;
//	//����ԭ��
//	std::cout<<"\n2**����ԭ��OCP(CRTP)**"<<endl;
//	//��̬�Ƕ�̬�󶨣�����ʱ�󶨣���CRTP�Ǿ�̬�󶨣�����ʱ�󶨣�
//	ocp::Shape * ocpS=new ocp::Circle(1);//upcast,Polymorphism==Open Principle
//	std::cout<<(*ocpS).getArea()<<endl;//Close Principle
//	ocpS=new ocp::Rectangle(1,10);
//	std::cout<<(*ocpS).getArea()<<endl;
//	
//	crtp::Shape<crtp::Circle>* crtpSC=new crtp::Circle(1);//upcast,Polymorphism==Open Principle
//	(*crtpSC).calcArea();//Close Principle
//	delete crtpSC;
//	crtp::Shape<crtp::Rectangle>* crtpSR=new crtp::Rectangle(1,10);
//	(*crtpSR).calcArea();
//	delete crtpSR;
//	
//	//�������
//	std::cout<<"\n3 ***�������ԭ��***"<<endl;
//	CCircle cc(1.0);
//	Shape* ptrS = &cc;	 // ��ʵ��������ʼ���ӿڵ�ָ��
//	CPillar pcp(*ptrS,10);
//	std::cout << pcp.getVolume() << std::endl;
//	delete ptrS;
//	
//	Shape& refS = cc;	 // ��ʵ��������ʼ���ӿڵ�ָ��
//	CPillar rcp(refS,10);
//	std::cout << rcp.getVolume() << std::endl;
//	
//	CRectangle cr(1.0, 2.0);
//	Shape& refSR =  cr;	 // ��ʵ��������ʼ���ӿڵ�ָ��
//	CPillar rcpr(refSR,10);
//	std::cout << rcpr.getVolume() << std::endl;
//	
//	//��һְ��
//	std::cout<<"\n4 ****��һְ��ԭ��****"<<endl;
//	ICalcArea& ica=cr;
//	std::cout<<ica.getArea()<<endl;//�������
//	IDrawShape&ids=cr;
//	ids.draw();//����ͼ��
//	
//	
//	//��Ҫ��İ����˵��
//	std::cout<<"\n5 *****��Ҫ��İ����˵��*****"<<endl;
//	RingCircle::Circle rc(10);
//	std::cout<<rc.calcPerimeter()<<" "<<rc.calcArea()<<endl;
//	RingCircle::Ring rr(10,1);
//	std::cout<<rr.calcPerimeter()<<" "<<rr.calcArea()<<endl;
//}
//classĬ��˽�У�structĬ�Ϲ���
struct {
	void (*ptrFunction)(void); //����һ������ָ��
	string menu;
}mainMenu[] = {   //�ṹ���ʼ��,5
//	{ testDesignPrinciple,"���ԭ��"},
	{ testDesignPattern,"���ģʽ��ʾ"},
	{ testSimpleFactory, "�򵥹���ģʽ"},
	{ testFactoryMethod, "��������ģʽ"},
	{ testSingleton, "����ģʽ"},
	{ testPrimeGenerator, "����������"}, 
	{ testPrimeSaveArray,"�����洢"},
	{ testGenericProgramming,"���ͱ��"},
	{ testStackTmp,"ջ��ģ��"},
	{ nullptr, ""}      
};
//�ǳ�Ա��������ͨ����
void testMainMenu(void){
	int idx,i;
	while(1){ 
		system("cls");
		printf("\n\t\t===========================\n");
		printf("\t\t|       ���ģʽ��ʾ      |\n");
		printf("\t\t---------------------------\n");
		for(i=0; mainMenu[i].ptrFunction!=0; i++)
			cout<<"\t\t"<<setw(5)<<i<<" "<<setw(-20)<<mainMenu[i].menu<<endl;
		printf("\t\t===========================\n");
		printf("\t ������˵���Ų���ENTER��([-1]����):");
		scanf("%d",&idx); //10���Ƶ�����
		if(idx<i){	
			if(-1==idx)return;
			(*mainMenu[idx].ptrFunction)();
		}
		else printf("\t������������[%2d];����������!\n", idx);
	}
}

int main (int argc, char *argv[]) {
	testMainMenu();
	return 0;
}

