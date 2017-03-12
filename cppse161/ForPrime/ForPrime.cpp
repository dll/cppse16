// ForPrime.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;

void Prime::getPrime() {
	for (int i = lownumb; i < upnumb; i++) {
		if (isPrime(i) == true) {
			cout << i << ", ";//��ӡ��ʾ
			arrayPrimes[count] = i;//arrayPrimes[i] = i??
			count++;
		}
	}

}
bool Prime::isPrime(int numb) {
	if (numb == 1)
		return false;//��Ȼ���У�1��������
	else if (numb == 2)//Ψһż������
		return true;
	else {
		//3��С��numb��ÿһ����i��i��numb�����ܳ�����������������������
		for (int i = 3; i < numb; i++){
			if (numb%i == 0)
				return false;
		}
		return true;
	}
}

PrimeManager::PrimeManager(const Prime& p) {//�����������ͣ�ȷ��P�����޸ģ���д���캯��
	dArray = NULL;
	count = p.count;
	dArray = new int[count];
	if (!dArray)
		throw - 1;//���ϵͳû�гɹ�����ռ䣬���׳��쳣
	for (int i = 0; i < count; i++)
		dArray[i] = p.arrayPrimes[i];
}

//��ӡ����������
void PrimeManager::PrimePyramid() {
	int col = 0;//��
	int row = 1;//��
	int rows = 0;//����
	int level = 0;//�㣨���У�
	
	//forѭ����Ϊ�˵õ��������������1��1����2��2��3��3,,,n-1��n-1����n���򲻶���Ϊʣ�������
	for (int i = 0; i < count; i++) {
		col++;
		if (rows <= col) {
			col = 0;
			rows = ++row;
			level++;
		}
	}
	col = 0; row = 1; rows = 1;//�������ָ�λ
	int levels = level;//�ܲ���
	//��ӡ������
	for (int i = 0; i < count; i++) {
		if (levels == level - row + 1) {
			for (int j = 0; j <= levels; j++)
				cout << setw(2) << " ";//��ӡ��߿ո�*��ʾ
			levels--;
		}
		cout << setw(3) << dArray[i] << " ";//��̬����
		col++;
		if (rows <= col) {
			cout << endl;//ÿ��ֻ��һ������
			col = 0;
			rows = ++row;
		}
	}
	cout << endl;
}
void PrimeManager::PrimePrint() {//�����������ͣ�ȷ��P�����޸�
	cout << "\n\nPrimeManager Print " << count << " Primes:" << endl;
	for (int i = 1; i <= count; i++)
		if (i % 6 == 0) {//ÿ��6������
			cout << setw(3) << dArray[i - 1] << " " << endl;//setw(3),ռ�����ַ����
		}
		else
			cout << setw(3) << dArray[i - 1] << " ";
	cout << endl;
}
PrimeManager::~PrimeManager() {
	if (dArray != NULL)
		delete[] dArray;//�ͷŹ��캯������Ŀռ�
}