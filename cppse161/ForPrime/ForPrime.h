#pragma once

const int MAXCOUNT = 256;

//����
class Prime {
	int lownumb, upnumb;//��Χ����
	int count;//�����ĸ���
	int arrayPrimes[MAXCOUNT*1000];//�洢��ÿ��������256*1000���������㹻����
public:
	friend class PrimeManager;//PrimeManager����Է���Prime���˽�г�Ա��

	Prime(int l, int u):lownumb(l),upnumb(u){
		count = 0;
	}
	void getPrime();//���ɺ���
	bool isPrime(int numb);//�жϺ���
};

class PrimeManager {
	int count;//����
	int sArray[MAXCOUNT];//�洢�����ľ�̬���飨static�����������ã�
	int *dArray;//�洢�����Ķ�̬���飨dynamic����ָ�룬���ٿռ��ָ�룡
public:
	PrimeManager(const Prime& p);
	void PrimePyramid();
	void PrimePrint();
	~PrimeManager();//��������
};