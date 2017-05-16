#ifndef MYARRAYT_H
#define MYARRAYT_H
template<typename T>
class myArrayT {
private:
protected:
	int size;
	T * element;//整形数组
public:
	//inline
	myArrayT(int size=0){
		this->size=size;
		element=new T[size];
	}
	~myArrayT(){
		delete []element;
	}
	T & operator[](int index){
		return element[index];
	}
	void set(int index, T value){
		element[index]=value;
	}
	T get(int index){
		return element[index];
	}
};

#endif
