#include<cstdarg>
#include <cstdio>
#include <cmath>
#include "SEBase.h"

//////////////////////////////////////////////////////////////////////////
//   ��ʾ��ʾ��Ϣ
void MyBreak(const char* fmt, ...)
{
	char buffer[256];
	va_list argptr;
	va_start(argptr, fmt);
	vsprintf(buffer, fmt, argptr);
	va_end(argptr);	
}

//////////////////////////////////////////////////////////////////////////
//       �Գƾ����±���㺯��
int CalSymmetricMatrixSubscript(int i,int j)
{
	return (i>=j)? i*(i+1)/2+j :j*(j+1)/2+i;
}

//////////////////////////////////////////////////////////////////////////
//  Ȩ�������㺯��
double CalWeightedReciprocal(double *Q,double *F,int t)
{
	double q=0.0;
	for(int i=0;i<t;i++)
		for(int j=0;j<t;j++) 
		q+=Q[CalSymmetricMatrixSubscript(i,j)]*F[i]*F[j];
	
	return q;	
}
//////////////////////////////////////////////////////////////////////////
//  Ȩ�������㺯��(ϵ��ϵ�н�����ѹ��)
double CalWeightedReciprocal(double Q[],double F[],int Fin[],int n)
{
	double q=0.0;
	for(int k=0;k<n;k++)
	{
		int i=Fin[k];
		for(int s=0;s<n;s++) 
		{
			int j=Fin[s];
			q+=Q[CalSymmetricMatrixSubscript(i,j)]*F[k]*F[s];
		}
	}
	return q;
}

//////////////////////////////////////////////////////////////////////////
//  ���ȷ�����д��(double��)�ǶȻ�Ϊ����ֵ
double dms_rad(double a)
{
	//��ȡ�Ƕ�ֵ�ķ���
	double sign=(a<0.0) ? -1.0 : 1.0;
	a=fabs(a);
	
	//��ȡ�Ƕ�ֵ������
	int d=(int)((a+0.00001)/10000.0);
	a=a-d*10000.0;
	if(a<0.0){ d=d-1; a=a+10000;}
	
	//��ȡ�Ƕ�ֵ�����ּ���ֵ
	int m=(int)((a+0.00001)/100.0);
	a=a-m*100;
	if(a<0.0){ m=m-1; a=a+100.0;}
	
	a=sign*(d*3600.0+m*60.0+a)/206264.806247096363;
	
	return a;
}
//////////////////////////////////////////////////////////////////////////
//  ���ǶȵĻ���ֵ��Ϊ�ȷ�����д�ĽǶȣ�double �ͣ� 
double rad_dms(double a)
{
	a=a*206264.806247096363;
	
	double sign=(a<0.0) ? -1.0 : 1.0;
	a=fabs(a);
	
	int d=(int)(a/3600.0+0.0000001);
	a=a-d*3600.0;
	
	if(a<0.0){ d=d-1; a=a+3600.0; }
	
	int m=(int)(a/60.0+0.0001);
	a=a-m*60.0;
	if(a<0.0){ m=m-1; a=a+60.0; }
	
	a=d*10000.0+m*100.0+a;
	
	return a*sign;
}

//////////////////////////////////////////////////////////////////////////
//    Ȩ���󴫲�����
void Calculate_BQBT(double B[],double Q[],int r,int n,double N[])
{
	for(int i=0;i<r;i++)
		for(int j=0;j<=i;j++)
	{
		double nCalSymmetricMatrixSubscript=0.0;
		for(int k=0;k<n;k++)
			for(int s=0;s<n;s++)
			nCalSymmetricMatrixSubscript+=B[i*n+k]*Q[CalSymmetricMatrixSubscript(k,s)]*B[j*n+s];
		N[CalSymmetricMatrixSubscript(i,j)]+=nCalSymmetricMatrixSubscript;
	}
}


//////////////////////////////////////////////////////////////////////////
//    ���ļ��������
void PrintM(FILE *fp,double A[],int size, int t,char* fmt,\
			char* title,bool IsLabel)
{
	if(title)fprintf(fp,"\n %s: ",title);
	int j=0;
	for(int i=0;i<size;i++)
	{
		if(i%t==0)
		{
			j++;
			if(IsLabel)fprintf(fp,"\n%3d ",j);
			else fprintf(fp,"\n    ");
		}
		fprintf(fp,fmt,A[i]);
	}	
	fprintf(fp,"\n");
}
//////////////////////////////////////////////////////////////////////////
//  ���ļ�����Գƾ���������Ԫ�أ�
void  PrintM2(FILE* fp, double M[], int n, int t,char *fmt,
			  char* title,bool IsLabel)
{
	if(title)fprintf(fp,"\n %s: ",title);
	
	int index=0;
	for(int i=0;i<n;i++)
	{
		if(IsLabel)fprintf(fp,"\n%3d ",i+1);
		else fprintf(fp,"\n    ");
		for(int j=0;j<=i;j++)
		{
			if(j>0 && j%t==0)fprintf(fp,"\n    ");
			fprintf(fp,fmt,M[index++]);
		}
	}
	fprintf(fp,"\n");	
}
//////////////////////////////////////////////////////////////////////////
//  ���ļ�������Է�����
void  PrintEquation(FILE* fp, double A[], double b[],
					int n, int t, char *fmt, char* title)
{
	if(title)fprintf(fp,"\n %s: ",title);
	for(int i=0;i<n;i++)
	{
		fprintf(fp,"\n%3d ",i+1);
		for(int j=0;j<t;j++)
		{
			fprintf(fp,fmt,A[i*t+j]);
		}
		fprintf(fp,fmt,b[i]);
	}
}
//////////////////////////////////////////////////////////////////////////
//  �Գ�������������(����������Ԫ��)
bool inverse(double a[],int n)
{
	double *a0=new double[n];
	for(int k=0;k<n;k++)
	{ 
		double a00=a[0];
		if(a00+1.0==1.0)
		{
			delete []a0; 
			return false;
		}
		for(int i=1;i<n;i++)
		{
			double ai0 = a[i*(i+1)/2];
			
			if(i<=n-k-1)a0[i]= -ai0/a00;
			else        a0[i]=  ai0/a00;
			
			for(int j=1;j<=i;j++)
			{
				a[(i-1)*i/2+j-1]=a[i*(i+1)/2+j]+ai0*a0[j];
			} 
		}
		for(int i=1;i<n;i++)
		{
			a[(n-1)*n/2+i-1]=a0[i];
		}
		a[n*(n+1)/2-1]=1.0/a00;
	} 
	delete []a0;
	return true;
}

double CalEquivalentWeight(int fname, double v, double k0, double k1)
{
	double a;
	switch(fname)
	{
	case IGG1://IGG1����
		v=fabs(v);
		if(v<=k0)return 1.0;
		if(v>k1)return 0.0;
		return k0/v;
	case IGG3://IGG3����
		v=fabs(v);
		if(v<=k0)return 1.0;
		if(v>k1)return 0.0;
		a=(k1-v)/(k1-k0);
		return k0/v*a*a;
	case Huber: // Huber����
		v=fabs(v);
		if(v<=k0)return 1.0;
		return k0/v;
	default:
		MyBreak("�ȼ�Ȩ�������ƴ���");
		return 1.0;
	}
}
//////////////////////////////////////////////////////////////////////////
// ��λ�����㣺�������ɴ���С���򣬷���ֵΪ��λ��
double CalMedian(double pp[],int n,bool IsAbs)
{
	double *p=new double [n];
	if(IsAbs)
		for(int i=0;i<n;i++)p[i]=fabs(pp[i]);
	else
		for(int i=0;i<n;i++)p[i]=pp[i];
	
	int k=n/2;
	while(k>0)
	{  
		for(int j=k;j<=n-1;j++)
		{  
			double t=p[j]; 
			int i=j-k;
			
			while( (i>=0) && (p[i]>t) )
			{
				p[i+k]=p[i];	
				i=i-k;  
			}
			p[i+k]=t;
		}
		k=k/2;
	}
	
	double mean = (n%2==1)? p[n/2] : (p[n/2]+p[n/2-1])/2.0;
	delete []p;
	
	return  mean;
}
