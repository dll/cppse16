#ifndef STACKTMP_H
#define STACKTMP_H

#include<iostream>
using namespace std;

const int size=10;
template<typename T>
class MyStack {
private:
	T stack[size];//s-->stack
	int top;
protected:
public:
	MyStack(){}
	~MyStack(){}
	void display()const;
};
template<class T>
bool MyStack<T>::isEmpty(){
	if (top)
		return false;
	else
		return true;
}
template<class T>
	if(top==size){
		cout<<"stack is full"<<endl;
T MyStack<T>::pop(){
	if(top==0){
		cout<<"stack is empty"<<endl;
}
template<class T>
void MyStack<T>::display()const{
	if(top==0)
		cout<<"stack is empty"<<endl;
	for(int i=0; i<top; i++)
		cout<<stack[i]<<endl;
}
#endif
