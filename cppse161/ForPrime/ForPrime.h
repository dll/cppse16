#pragma once

const int MAXCOUNT = 256;

//素数
class Prime {
	int lownumb, upnumb;//范围区间
	int count;//素数的个数
	int arrayPrimes[MAXCOUNT*1000];//存储的每个素数，256*1000个素数，足够啦！
public:
	friend class PrimeManager;//PrimeManager类可以访问Prime类的私有成员！

	Prime(int l, int u):lownumb(l),upnumb(u){
		count = 0;
	}
	void getPrime();//生成函数
	bool isPrime(int numb);//判断函数
};

class PrimeManager {
	int count;//个数
	int sArray[MAXCOUNT];//存储素数的静态数组（static），可以弃用！
	int *dArray;//存储素数的动态数组（dynamic）即指针，开辟空间的指针！
public:
	PrimeManager(const Prime& p);
	void PrimePyramid();
	void PrimePrint();
	~PrimeManager();//析构函数
};