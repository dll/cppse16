#include "stdafx.h"

using namespace std;

int main(){
	int low, up;
	cout << "�������������������䣺" << endl;
	cin >> low >> up;
	//ȷ��low<up
	if (low > up)
	{ low = low + up; up = low - up; low = low - up; }

	Prime p1(low, up);
	p1.getPrime();

	PrimeManager PM(p1);
	//PM.PrimePrintSA();//��ӡ��̬�����е�������������MAXCOUNT(256)
	PM.PrimePyramid();//��ӡ��������������ο�git�ֿ��е�ʵ�ֹ���
	PM.PrimePrint();//�ɴ�ӡ����256������

	return 0;
}

