#ifndef STACKTMP_H
#define STACKTMP_H

#include<iostream>
using namespace std;

const int size=10;
template<typename T>
class StackTmp {
private:
	T stack[size];//s-->stack
	int top;
protected:
public:
	StackTmp(){}
	~StackTmp(){}public:	void  init()  {top=0;}	void  push(T e);//element	T  pop();	bool isEmpty();
	void display()const;
};
template<class T>
bool StackTmp<T>::isEmpty(){
	if (top)
		return false;
	else
		return true;
}
template<class T>void StackTmp<T>::push(T e){
	if(top==size){
		cout<<"stack is full"<<endl;		return;	}	stack[top]=e;	top++;}template<class T>
T StackTmp<T>::pop(){
	if(top==0){
		cout<<"stack is empty"<<endl;//		return nullptr;	}	top--;	return stack[top];
}
template<class T>
void StackTmp<T>::display()const{
	if(top==0)
		cout<<"stack is empty"<<endl;
	for(int i=0; i<top; i++)
		cout<<stack[i]<<endl;
}
#endif

