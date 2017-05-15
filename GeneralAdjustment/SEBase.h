#ifndef SEBASE_H
#define SEBASE_H
#include<iostream>

//////////////////////////////////////////////////////////////////////////
//�Գƾ����±���㺯��

//��
#define IGG1  0
#define IGG3  1
//#define Huber 2
const int Huber=2;

#define ik (i>=k)? i*(i+1)/2+k : k*(k+1)/2+i
#define kj (k>=j)? k*(k+1)/2+j : j*(j+1)/2+k

//  Ȩ�������㺯��
double CalWeightedReciprocal(double *Q,double *F,int t);
//  Ȩ�������㺯��
double CalWeightedReciprocal(double Q[],double F[],int Fin[],int n);

//�ɱ��������
void MyBreak(const char* fmt, ...);
//�Գƾ����±���㺯��
int CalSymmetricMatrixSubscript(int i,int j);
//  �Գ�������������(����������Ԫ��)
bool inverse(double a[],int n);

// Ȩ���󴫲�����
void Calculate_BQBT(double B[],double Q[],int r,int n,double N[]);

//  ���ȷ�����д��(double��)�ǶȻ�Ϊ����ֵ
double dms_rad(double a);
//  ���ǶȵĻ���ֵ��Ϊ�ȷ�����д�ĽǶȣ�double �ͣ� 
double rad_dms(double a);

void PrintM(FILE *fp,double A[],int size, int t,char* fmt,\
			char* title=NULL,bool IsLabel=true);
void  PrintM2(FILE* fp, double M[], int n,int t,char *fmt,\
			  char* title=NULL,bool IsLabel=true);
void  PrintEquation(FILE* fp, double A[], double b[],\
					int n, int m,char *fmt,char* title=NULL);

double CalEquivalentWeight(int fname, double v, double k0, double k1);
double CalMedian(double pp[],int n,bool IsAbs);//��λ������

#endif
