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
void testFactoryMethod(){
	cout<<"\n***工厂方法模式***\n"<<endl;
	int choice = 1;
	DrawFactory* pdf = nullptr;  // 定义接口的引用
	cout <<"1:画圆;2:画矩形;3:画三角形。请选择（1~3）,0 退出"<<endl;	;
	while(cin >> choice){
		switch(choice){		// 根据用户选择生成工厂实例
		case 0: exit(0);
		case 1: pdf = new CirFactory ();break;
		case 2: pdf = new RecFactory ();break;
		case 3: pdf = new TriFactory ();break;
		default:cout<<"请输入1,2,3！"<<endl;continue;
		}
		pdf -> MakeDrawer () -> draw (); // 调用工厂方法 生成画图对象画图
		cout <<"1:画圆;2:画矩形;3:画三角形。请选择（1~3）,0 退出"<<endl;	
	}
}
void testSingleton(){
	Singleton *s1=Singleton::getSingleton();
	cout<<"s1地址"<<s1<<endl;
	Singleton *s2=Singleton::getSingleton();
	cout<<"s2地址"<<s2<<endl;
	if(s1==s2)
		cout<<"只能实例化一个对象"<<endl;
	system("pause");
}
void testPrimeGenerator(){
	unsigned low, up;
	cout<<"请输入开始和结束的区间(非整数退出)："<<endl;
	cin>>low>>up;
	while(cin.fail()){
		cout<<"输入数据类型错误！\n请重新输入"<<endl;
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
		std::cerr << "不能打开primegenerator.data文件!\n";
		system("pause");
		exit(0);
	}
	while(fin>>low>>up){
		PrimeGenerator pg(low,up);
		pg.GetPrimeSequence();
		if(!pg.SavePrimeSequence()){
			cout<<"保存素数序列结果失败！"<<endl;
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
	intStackTmp.display();//2,3   1,2后进先出
	
	StackTmp<char> charStackTmp;
	charStackTmp.init();
	charStackTmp.push('A');
	charStackTmp.display();
	charStackTmp.pop();
	charStackTmp.display();
	charStackTmp.push('A');charStackTmp.push('B');charStackTmp.push('C');
	charStackTmp.display();//1,2,3
	charStackTmp.pop();
	charStackTmp.display();//2,3   1,2后进先出
	string n;
	int a;
	char g;
	unsigned w;
	double s;
	//读文件流
	ifstream ifs("Employee.data");
	while(ifs>>n>>a>>g>>w>>s){
		Employee empn(n,a,g,w,s);
		empn.Output();
	}
	ifs.close();
	
	StackTmp<Employee> EmployeeStackTmp;//类属
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
//	//组合优先
//	std::cout<<"1*组合优先原则*"<<endl;
//	Circle c(1.0);
//	std::cout << c.getArea() << std::endl;
//	
//	Pillar p(c,3.0);
//	std::cout << p.getVolume() << std::endl;
//	
//	PillarCircle pc(c,3.0);
//	std::cout << pc.getVolume() << std::endl;
//	//开闭原则
//	std::cout<<"\n2**开闭原则OCP(CRTP)**"<<endl;
//	//多态是动态绑定（运行时绑定），CRTP是静态绑定（编译时绑定）
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
//	//面向抽象
//	std::cout<<"\n3 ***面向抽象原则***"<<endl;
//	CCircle cc(1.0);
//	Shape* ptrS = &cc;	 // 用实例类对象初始化接口的指针
//	CPillar pcp(*ptrS,10);
//	std::cout << pcp.getVolume() << std::endl;
//	delete ptrS;
//	
//	Shape& refS = cc;	 // 用实例类对象初始化接口的指针
//	CPillar rcp(refS,10);
//	std::cout << rcp.getVolume() << std::endl;
//	
//	CRectangle cr(1.0, 2.0);
//	Shape& refSR =  cr;	 // 用实例类对象初始化接口的指针
//	CPillar rcpr(refSR,10);
//	std::cout << rcpr.getVolume() << std::endl;
//	
//	//单一职责
//	std::cout<<"\n4 ****单一职责原则****"<<endl;
//	ICalcArea& ica=cr;
//	std::cout<<ica.getArea()<<endl;//计算面积
//	IDrawShape&ids=cr;
//	ids.draw();//绘制图形
//	
//	
//	//不要和陌生人说话
//	std::cout<<"\n5 *****不要和陌生人说话*****"<<endl;
//	RingCircle::Circle rc(10);
//	std::cout<<rc.calcPerimeter()<<" "<<rc.calcArea()<<endl;
//	RingCircle::Ring rr(10,1);
//	std::cout<<rr.calcPerimeter()<<" "<<rr.calcArea()<<endl;
//}
//class默认私有，struct默认公有
struct {
	void (*ptrFunction)(void); //声明一个函数指针
	string menu;
}mainMenu[] = {   //结构体初始化,5
//	{ testDesignPrinciple,"设计原则"},
	{ testDesignPattern,"设计模式演示"},
	{ testSimpleFactory, "简单工厂模式"},
	{ testFactoryMethod, "工厂方法模式"},
	{ testSingleton, "单例模式"},
	{ testPrimeGenerator, "素数生成器"}, 
	{ testPrimeSaveArray,"素数存储"},
	{ testGenericProgramming,"泛型编程"},
	{ testStackTmp,"栈类模板"},
	{ nullptr, ""}      
};
//非成员函数，普通函数
void testMainMenu(void){
	int idx,i;
	while(1){ 
		system("cls");
		printf("\n\t\t===========================\n");
		printf("\t\t|       设计模式演示      |\n");
		printf("\t\t---------------------------\n");
		for(i=0; mainMenu[i].ptrFunction!=0; i++)
			cout<<"\t\t"<<setw(5)<<i<<" "<<setw(-20)<<mainMenu[i].menu<<endl;
		printf("\t\t===========================\n");
		printf("\t 请输入菜单序号并按ENTER键([-1]返回):");
		scanf("%d",&idx); //10进制的整数
		if(idx<i){	
			if(-1==idx)return;
			(*mainMenu[idx].ptrFunction)();
		}
		else printf("\t输入错误的数字[%2d];请重新输入!\n", idx);
	}
}

int main (int argc, char *argv[]) {
	testMainMenu();
	return 0;
}

