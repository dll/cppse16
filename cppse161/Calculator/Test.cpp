#include"Calculator.hpp"

int main () {
	
	//Calculator cacl0(2,'A',3);//����һ������������
	//cout <<"������Ϊ:"<< cacl0.calChoose_ie() << endl;
	
	Calculator cacl1(2,'+',3);		// ����һ������������
	cout<<"������Ϊ��"<< cacl1.calChoose_ie() << endl;
	Calculator cacl2(2,'-',3);		// ����һ������������
	cout<<"������Ϊ��"<< cacl2.calChoose_ie() << endl;
	Calculator cacl3(2,'*',3);		// ����һ������������
	cout<<"������Ϊ��"<< cacl3.calChoose_sc() << endl;
	Calculator cacl4(2,'/',3);		// ����һ������������
	cout<<"������Ϊ��"<< cacl4.calChoose_sc() << endl;
	
	return 0;
}
