#ifndef SEBASE_H
#define SEBASE_H
#include<iostream>

//////////////////////////////////////////////////////////////////////////
//对称矩阵下标计算函数

//宏
#define IGG1  0
#define IGG3  1
//#define Huber 2
const int Huber=2;

#define ik (i>=k)? i*(i+1)/2+k : k*(k+1)/2+i
#define kj (k>=j)? k*(k+1)/2+j : j*(j+1)/2+k

//  权倒数计算函数
double CalWeightedReciprocal(double *Q,double *F,int t);
//  权倒数计算函数
double CalWeightedReciprocal(double Q[],double F[],int Fin[],int n);

//可变参数函数
void MyBreak(const char* fmt, ...);
//对称矩阵下标计算函数
int CalSymmetricMatrixSubscript(int i,int j);
//  对称正定矩阵求逆(仅存下三角元素)
bool inverse(double a[],int n);

// 权逆阵传播计算
void Calculate_BQBT(double B[],double Q[],int r,int n,double N[]);

//  将度分秒连写的(double型)角度化为弧度值
double dms_rad(double a);
//  将角度的弧度值化为度分秒连写的角度（double 型） 
double rad_dms(double a);

void PrintM(FILE *fp,double A[],int size, int t,char* fmt,\
			char* title=NULL,bool IsLabel=true);
void  PrintM2(FILE* fp, double M[], int n,int t,char *fmt,\
			  char* title=NULL,bool IsLabel=true);
void  PrintEquation(FILE* fp, double A[], double b[],\
					int n, int m,char *fmt,char* title=NULL);

double CalEquivalentWeight(int fname, double v, double k0, double k1);
double CalMedian(double pp[],int n,bool IsAbs);//中位数计算

#endif
