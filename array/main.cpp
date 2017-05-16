#include<iostream>

#include "myArray.h"
#include "myArrayT.h"
#include"myBoundArray.hpp"

using namespace std;

void testarray(){
	//1,c++提供的数组类型，存在设计缺陷：溢出问题
	int iArray[100];
	for(int i=1;i<=100;i++)
		iArray[i]=i;
	cout<<"c++提供的数组类型，存在设计缺陷：溢出问题"<<endl;
	cout<<iArray[0]<<" "<<iArray[1]<<" "<<iArray[100]<<" "<<iArray[101]<<endl;
	for(int i=1;i<=100;i++)
		cout<<iArray[i]<<" ";
	cout<<endl;
	
	char cArray[26];
	for(int i=0;i<26;i++)
		cArray[i]='a'+i;
	
	for(int i=0;i<=26;i++)
		cout<<cArray[i]<<" ";
	
	cout<<endl;
	double dArray[2];
	dArray[3]=3.14;
	cout<<dArray[0]<<endl;
}
void testmyArray(){
//	2,实现类模板，解决溢出问题（直接检查index范围并抛出异常）
	cout<<"实现类模板，解决溢出问题（直接检查index范围并抛出异常）"<<endl;
		myArray mya(10);
		for(int i=0;i<10;i++)
	//		mya.set(i,i+1);
			mya[i]=i+1;
		for(int i=0;i<10;i++)
	//	cout<<mya.get(i)<<" ";
			cout<<mya[i]<<" ";
		try{	
			myArrayT<int> myat(10);
			for(int i=0;i<10;i++)
				//		myat.set(i,i+1);
				myat[i]=i+1;
			for(int i=0;i<10;i++)
				//	cout<<myat.get(i)<<" ";
				cout<<myat[i]<<" ";
			cout<<endl;
			
			myArrayT<double> myat1(10);
			for(int i=0;i<10;i++)
				//		myat1.set(i,i+1);
				myat1[i]=i*3.14+1;
			for(int i=0;i<10;i++)
				//	cout<<myat1.get(i)<<" ";
				cout<<myat1[i]<<" ";
			cout<<endl;
			
			cout<<myat1[0]<<" ";
			cout<<myat1[1]<<" ";
			
			cout<<"\nmyArrayT抛出异常"<<endl;
			cout<<myat1[11]<<" ";
			cout<<myat1[-1]<<" ";
			cout<<myat1[100]<<" ";
			
		}catch(out_of_range& exp){
			cerr<<exp.what();
		}
		cout<<endl<<endl;
}
void testBoundArray(){
	//3,实现类模板及继承，解决溢出问题（由子类BoundArray检查index范围并抛出异常）
	cout<<"实现类模板及继承，解决溢出问题（由子类BoundArray检查index范围并抛出异常）"<<endl;
	BoundArray<int> ba(0,9);
	for(int i=0;i<10;i++)
		ba[i]=i+1;
	for(int i=0;i<=10;i++)
		cout<<ba[i]<<" ";
	cout<<endl;
}
int main (int argc, char *argv[]) {
	testarray();
	testmyArray();
	testBoundArray();
	return 0;
}

