#ifndef ARRAY_H
#define ARRAY_H
#include<fstream>
using namespace std;

class  Array{	public :		Array ( int s ) ;		~Array ( ) ;		int& get ( int index);		void  set ( int index, int& value);		int& operator[ ] (int index) ; 		Array& operator = (Array& rArr) ;//������=����		//��Ԫ�������ز�����<<		friend ostream& operator<<(ostream& out, Array& a);	private: 		int size ;		int * element ;} ;
#endif

