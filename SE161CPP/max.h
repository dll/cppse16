#ifndef MAX_H
#define MAX_H
//��������
int myMax ( int a , int b ) { return ( a > b ) ? a:b;}//long max ( long a , long b ) { return ( a > b ) ? a : b ;}//double max ( double a , double  b ) { return ( a >b)? a : b ; }//char max ( char a , char b ) { return ( a > b ) ? a : b ;}

//����ģ��
template < typename  T >T  myMax ( T  a , T  b ){ return  a > b ? a : b ; }
//���غ���ģ��
template <typename T>T myMax( const T a, const T b , const T c){ T t ;  t = myMax(a, b) ;    return myMax ( t, c ) ;  }
#endif
