#include "ArrayTmp.h"

template<typename T> ArrayTmp<T> ::ArrayTmp (int s){ 
	size = (s > 1 ) ? s : 1 ;
	element = new T [ size ] ;
}template < typename T > ArrayTmp < T > :: ~ArrayTmp(){
	delete [ ] element ; 
}template < typename T > const T& ArrayTmp < T > :: get( int index ) const{
	return  element [ index ] ; 
}template < typename T >void ArrayTmp < T > :: set(int index, const T& value){
	element [ index ] = value ; 
}