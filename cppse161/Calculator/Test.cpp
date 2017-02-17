#include"Calculator.hpp"

int main () {
	
	//Calculator cacl0(2,'A',3);//生成一个计算器对象
	//cout <<"计算结果为:"<< cacl0.calChoose_ie() << endl;
	
	Calculator cacl1(2,'+',3);		// 生成一个计算器对象
	cout<<"计算结果为："<< cacl1.calChoose_ie() << endl;
	Calculator cacl2(2,'-',3);		// 生成一个计算器对象
	cout<<"计算结果为："<< cacl2.calChoose_ie() << endl;
	Calculator cacl3(2,'*',3);		// 生成一个计算器对象
	cout<<"计算结果为："<< cacl3.calChoose_sc() << endl;
	Calculator cacl4(2,'/',3);		// 生成一个计算器对象
	cout<<"计算结果为："<< cacl4.calChoose_sc() << endl;
	
	return 0;
}
