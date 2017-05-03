#include "MyVector.h"
#include<iomanip>
//template<typename T>
//MyVector<T>::MyVector(int n) {
//	create(n);
//}
//template<typename T>
//MyVector<T>::MyVector(int n,T* oldV) {
//	create(n);
//	for(int i=1;i<=size;i++)
//		V[i]=oldV[i-1];
//}

//template<typename T>
//MyVector<T>::~MyVector() {
//	delete [] V;
//}
//
//template<typename T>
//void MyVector<T>::create(int n){
//	if(n<1){
//		size=0;
//		V=0;
//	}else{
//		size=n;
//		V=new T[size+1];
//	}
//}

//template<typename T>
//void MyVector<T>::display() {
//	for(int i=1;i<=size;i++)
//		cout<<setw(10)<<V[i]<<" ";
//	cout<<endl;
//}

//template<typename T>
//MyVector<T> MyVector<T>::operator=(const MyVector<T>& V2) {
//	if(size!=V2.size)
//		create(V2.size);
//	for(int i=1;i<=size;i++)
//		V[i]=V2.V[i];
//	return *this;
//}
//
//template<typename T>
//MyVector<T> MyVector<T>::operator+(const MyVector<T>& V2) {
//	check(size!=V2.size,"向量长度不同，不可相加！");
//	MyVector<T> temp(size);
//	
//	for(int i=1;i<=size;i++)
//		temp.V[i]=V[i]+V2.V[i];
//	return temp;
//}
//								   
