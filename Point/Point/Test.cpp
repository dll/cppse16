#include"Point.h"
//第3步：使用类，创建对象，调用方法
int main() {

	Point pnt("滁州市",118.18F, 32.18F);//pnt即是一个由Point类实例化的点
	pnt.ShowPoint();//显示

	system("pause");//暂停

	return 0;
}