#ifndef MYBOUNDARRAY_H
#define MYBOUNDARRAY_H

#include<iostream>
#include<cstdlib>
#include"myArrayT.hpp"

using namespace std;

template < typename T >
class BoundArray : public myArrayT < T >
{ 
	public :
		using myArrayT<T>::size;
		BoundArray ( int low = 0, int height = 1 ): myArrayT<T>(height-low+1) {
			if(height-low<0){
				cout<<"Beyond the bounds of Array.\n";
				exit(1);
			}
			min=low;
		}
		~BoundArray(){
			myArrayT<T>::~myArrayT();
		}
		T& operator[ ](int index){
			if(index<min||index>min+size-1){
				cout<<"Beyond the bounds of index.\n";
				exit(1);
			}
			return myArrayT<T>::element[index-min];
		}
		BoundArray & operator=(BoundArray & a);
	private:   
		int  min ;
} ; 
	
#endif
