#ifndef BOUNDARRAYTMP_H
#define BOUNDARRAYTMP_H
#include "ArrayTmp.hpp"

template < typename T >
class BoundArrayTmp : public ArrayTmp<T> {
	public :
		using ArrayTmp<T>::size;
//		using ArrayTmp<T>::element;		BoundArrayTmp ( int low = 0, int height = 1 ) ;
		
		const T& get( int index ) const ;
		void set( int index, const T & value ) ;
		T& operator[ ] (int index) ; 
				BoundArrayTmp & operator=(BoundArrayTmp & a);
		~BoundArrayTmp();
		void resize(int sz);
		T begin()const;//第一个元素
		T end()const;//最后一个元素
		void deleteElement(int index);//删除索引为index的元素
		void insertElement(int index,const T& value);//在index索引位置上插入新元素value
		void selectSort();	private:   		int  min;//下界，默认为0
};

template<typename T>
BoundArrayTmp<T>::BoundArrayTmp(int low, int height)\
	: ArrayTmp<T>(height-low+1) {
	if(height-low<0){
		cout<<"Beyond the bounds of Array.\n";
		exit(1);
	}
	min=low;
}
template<typename T> 
BoundArrayTmp<T>::~BoundArrayTmp() {
		ArrayTmp<T>::~ArrayTmp();
}
template<typename T> 
const T& BoundArrayTmp<T>::get( int index ) const{
	if(index<min||index>min+size-1){
		cout<<"Beyond the bounds of index.\n";
		exit(1);
	}
	return ArrayTmp<T>::get(index-min);
}
template < typename T >
void BoundArrayTmp < T > :: set(int index, const T& value){
	if(index<min||index>min+size-1){
		cout<<"Beyond the bounds of index.\n";
		exit(1);
	}
	ArrayTmp<T>::set(index-min,value);
}
template<typename T> 
T& BoundArrayTmp<T>::operator[ ](int index){
	if(index<min||index>min+size-1){
		cout<<"Beyond the bounds of index.\n";
		exit(1);
	}
	return ArrayTmp<T>::get(index-min);
}
template<typename T> 
BoundArrayTmp<T> & BoundArrayTmp<T>::operator=(BoundArrayTmp<T> & a){
	int n=a.size;
	if (size != n) {
		delete[] this->element;
		this->element = new T[n];
		if (this->element == NULL) {
			cout<<"memeory Allocation Error."<<endl;
			exit(1);
		}   
		size = n;   
	}
	T* src = a.element;
	T* dest = ArrayTmp<T>::element;
	while(n--) {
		*dest++ = *src++;  
	}
	return *this;
}
template<typename T> 
void BoundArrayTmp<T>::resize(int sz){//动态扩展
	if(sz <= min) {
		cout<<"Want to Allocate memeory size Error."<<endl;
		exit(1);
	}
	if (sz == size) {
		return;
	}
	T* newList = new T[sz];
	if (newList ==nullptr) {
		cout<<"memeory Allocation Error."<<endl;
		exit(1);
	}
	int n = (size < sz)?size : sz;
	T* src = ArrayTmp<T>::element;
	T* dest = newList;
	while(n>0) {
		*dest++ = *src++;
		n--;
	}
	delete[] this->element;
	this->element = newList;
	size = sz;
}
template<typename T> 
T  BoundArrayTmp<T>::begin()const{
	if(this->element!=nullptr)
		return *this->element;//return this->element[min];
	else
		cout<<"blank array."<<endl;
}
template<typename T> 
T  BoundArrayTmp<T>::end()const{
	if(size!=0)
		return this->element[size-1];
	else
		cout<<"blank array."<<endl;
}
template<typename T> 
void  BoundArrayTmp<T>::deleteElement(int index){
	if(size==min){
		cout<<"blank array."<<endl;
		exit(0);
	}
	if(size==1){
		delete this->element;
		size--;
	}
	if(index<min||index>min+size-1){
		cout<<"Beyond the bounds of index.\n";
		exit(1);
	}
	for(int i=index;i<size-1;i++)
		this->element[i]=this->element[i+1];
	delete &this->element[size-1];
	size--;
}
template<typename T> 
void  BoundArrayTmp<T>::insertElement(int index,const T& value){
	if(index<min||index>min+size){
		cout<<"Beyond the bounds of index.\n";
		exit(1);
	}
	if(size==min && index==min){
		this->element=new T();
		this->element[size]=value;
		size++;
	}
	if(size==index){
		resize(size);
		this->element[size]=value;
		size++;
	}else{
		resize(size);
		for(int i=size;i>index;i--)
		   this->element[i]=this->element[i-1];
		this->element[index]=value;
		size++;
	}
}

template<typename T> 
void swap(const T &a,const T &b){
	T t=a;
	a=b;
	b=t;
}
template<typename T> 
void  BoundArrayTmp<T>::selectSort(){
	if(size==min){
		cout<<"blank array.\n";
		exit(1);
	}
	else{
		int i, j, min;
		for (i = 0; i < size - 1; i++) {
			min = i;
			for (j = i + 1; j < size; j++)
				if (this->element[min] > this->element[j])
					min = j;
			swap(this->element[i], this->element[min]);
		}
	}
}
#endif

