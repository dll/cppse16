#ifndef ARRAYTMP_H
#define ARRAYTMP_H
#include<iostream>
using namespace std;

//int-->T
template< typename T >class  ArrayTmp{
	public :		ArrayTmp ( int s ) ;		~ ArrayTmp () ;		const T& get( int index ) const ;		void set( int index, const T & value ) ;		T& operator[ ] (int index) ; //重载[]
		ArrayTmp<T>& operator=( const ArrayTmp<T> & a );//重载=，类模板作参数	
		void display()const;	protected: 		int size;		T * element;} ;template<typename T> 
ArrayTmp<T> ::ArrayTmp (int s){ 
	size = (s > 1 ) ? s : 1 ;
	element = new T [ size ] ;
}
template < typename T > 
ArrayTmp < T > :: ~ArrayTmp(){
	delete [] element ; 
	element=nullptr;
}
template < typename T > 
const T& ArrayTmp < T > :: get( int index ) const{
	return  element [ index ] ; 
}
template < typename T >
void ArrayTmp < T > :: set(int index, const T& value){
	element [ index ] = value ; 
}
template < typename T >
T& ArrayTmp < T > :: operator[ ] (int index){
	return  element [ index ] ; 
}

template < typename T >ArrayTmp <T>&  ArrayTmp <T> :: operator=( const ArrayTmp <T> & a ){
	int n=a.size;
	if (size != n) {
		delete[] element;
		element = new T[n];
		if (element == NULL) {
			cout<<"memeory Allocation Error."<<endl;
			exit(1);
		}   
		size = n;   
	}
	T* src = a.element;
	T* dest = element;
	while(n--) {
		*dest++ = *src++;  
	}
	return *this;
}
template < typename T > void ArrayTmp <T> ::display()const{
	for(int i=0;i<size-1;i++){
		cout<<element[i]<<" ";
	}
	cout<<element[size-1]<<endl;
}
#endif

