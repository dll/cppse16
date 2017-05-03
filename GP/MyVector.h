#ifndef MYVECTOR_H
#define MYVECTOR_H
#include<string>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<fstream>

using namespace std;

template<typename T>
class MyVector {
private:
	int size;//T
	T *V;
protected:
public:
	void create(int);//int 3
	MyVector(int);
	MyVector(int n, T*);//T int char float double string Point
	~MyVector();
	MyVector<T> operator=(const MyVector<T>& V2);
	inline void check(bool ErrorCondition, const string message="操作失败!"){
		if(ErrorCondition)
			throw message;
	}
	void display();
	MyVector<T> operator+(const MyVector<T>& V2);
//	template<typename t>
//	friend MyVector<t> operator+(const MyVector<t>&V1, const MyVector<t>&V2);
	void saveMyVector(string filename);
};


template<typename T>
MyVector<T>::MyVector(int n) {
	create(n);
}
template<typename T>
MyVector<T>::MyVector(int n,T* oldV) {
	create(n);
	for(int i=1;i<=size;i++)
		V[i]=oldV[i-1];
}

template<typename T>
MyVector<T>::~MyVector() {
	delete [] V;
}

template<typename T>
void MyVector<T>::create(int n){
	if(n<1){
		size=0;
		V=0;
	}
	else{
		size=n;
		V=new T[size+1];
	}
}

template<typename T>
void MyVector<T>::display() {
	cout<<V<<endl;
	for(int i=1;i<=size;i++)
		cout<<setiosflags(ios::right)
			<<setiosflags(ios::fixed)
			<<setiosflags(ios::showpoint)
			<<setprecision(3)
			<<setw(10)<<V[i]<<" ";
	cout<<endl;
}


template<typename T>
MyVector<T> MyVector<T>::operator=(const MyVector<T>& V2) {
	if(size!=V2.size)
		create(V2.size);
	for(int i=1;i<=size;i++)
		V[i]=V2.V[i];
	return *this;
}

template<typename T>
MyVector<T>  MyVector<T>::operator+(const MyVector<T>& V2) {
	check(size!=V2.size,"向量长度不同，不可相加！");
	MyVector<T>  temp(size);
	cout<<temp.V<<endl;
	for(int i=1;i<=size;i++)
		temp.V[i]=V[i]+V2.V[i];
	return temp;
}
								   
//template<typename t>
//MyVector<t> operator+(const MyVector<t>&V1, const MyVector<t>&V2){
//	if(V1.size!=V2.size){
//		cout<<"向量长度不同，不可相加！"<<endl;
//		exit(0);
//	}
//	MyVector<t>  temp(V1.size);
//	for(int i=1;i<=V1.size;i++)
//		temp.V[i]=V1.V[i]+V2.V[i];
//	return temp;
//}
template<typename T>
void MyVector<T>::saveMyVector(string filename){
	ofstream ofout("myvector.txt");
	for(int i=1;i<=size;i++){
		ofout<<V[i]<<" ";
	}
	ofout<<endl;
	ofout.close();
}

#endif

