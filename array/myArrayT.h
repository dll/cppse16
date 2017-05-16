#ifndef MYARRAYT_H
#define MYARRAYT_H
template<typename T>
class myArrayT {
private:
protected:
	int size;
	T * element;//整形数组
public:
	myArrayT(int size=0);
	~myArrayT();
	T & operator[](int index);
	void set(int index,T value);
	T get(int index);
	
//	myArrayT(int size=0){
//		this->size=size;
//		element=new T[size];
//	}
//	~myArrayT(){
//		delete []element;
//	}
//	T & operator[](int index){
//		return element[index];
//	}
//	void set(int index, T value){
//		element[index]=value;
//	}
//	T get(int index){
//		return element[index];
//	}
};

template<typename T>
myArrayT<T>::myArrayT(int sz) {
	if(sz<=0){
		size=0;
		element=0;
	}else{		
		this->size=sz;
		element=new T[size];
	}
}
template<typename T>
myArrayT<T>::~myArrayT() {
	delete []element;
}
template<typename T>
T & myArrayT<T>::operator[](int index){
	if(index<0 || index>size)
		throw std::out_of_range("ERROR:Out of range Array!");
	return element[index];
}
template<typename T>
void myArrayT<T>::set(int index, T value){
	element[index]=value;
}
template<typename T>
T myArrayT<T>::get(int index){
	return element[index];
}
#endif
