#include"Point.h"
//第3步：使用类，创建对象，调用方法
int main() {

	std::cout << "对象直接访问" << std::endl;
	Point pnt("滁州市",118.18F, 32.18F);//pnt即是一个由Point类实例化的点
	pnt.ShowPoint();//显示

	std::cout << "\n\n4构造函数重载演示" << std::endl;
	Point pnt1;
	pnt1.ShowPoint();

	Point pnt2("图书馆");
	pnt2.ShowPoint();

	Point pnt3(pnt);
	pnt3.ShowPoint();

	//指针变量的间接访问演示
	std::cout << "\n\n1个指针变量pPnt的间接访问" << std::endl;
	Point * pPnt = &pnt;
	pPnt->ShowPoint();

	pPnt = &pnt1;
	pPnt->ShowPoint();

	pPnt = &pnt2;
	(*pPnt).ShowPoint();

	//引用变量的应用（取代指针）
	std::cout << "\n\n多个引用变量rPnt1,rPnt2,...的直接访问对应变量数据" << std::endl;
	Point & rPnt = pnt;
	rPnt.ShowPoint();

	Point & rPnt1 = pnt1;
	rPnt1.ShowPoint();

	Point & rPnt2 = pnt2;
	rPnt2.ShowPoint();

	system("pause");//暂停

	return 0;
}