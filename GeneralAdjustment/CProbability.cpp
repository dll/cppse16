#include <cmath>

#include "CProbability.h"

//////////////////////////////////////////////////////////////////////////
//  ����  n/2 �Ħ�����ֵ: ��(n/2)
double CProbability::gam(int n)
{
	int i;
	double k;
	
	if(n%2)
	{
		k=1.772453850905516;
		i=3;
	}
	else
	{
		k=2;
		i=4;
	}
	
	while(i<n)
	{
		k*=i;
		i+=2;
	}
	
	return k;
}

//////////////////////////////////////////////////////////////////////////
//	  ��̬�ֲ�����ֵ:  p(-��,u)
double CProbability::norm(double u)
{
	if(u<-5.0) return 0.0;
	if(u>5.0) return 1.0;
	
	double y=fabs(u)/sqrt(2.0);
	
	double p=1.0+y*(0.0705230784+y*(0.0422820123+y*(0.0092705272+
			y*(0.0001520143+y*(0.0002765672+y*0.0000430638)))));
	
	double er =1- pow( p, -16.0 );
	p=(u<0.0)? 0.5-0.5*er: 0.5+0.5*er;
	return p;
}

//////////////////////////////////////////////////////////////////////////
// ��̬�ֲ��ķ�����, p(-��,u)=p ; ��֪p, ����u
double CProbability::re_norm(double p)
{
	if(p==0.5) return 0.0;
	if(p>0.9999997) return 5.0;
	if(p<0.0000003) return -5.0;
	if(p<0.5) return -re_norm(1.0-p);
	
	double y=-log(4.0*p*(1.0-p));
	y=y*(1.570796+y*(0.3706988e-1\
		+y*(-0.836435359e-3+y*(-0.2250947e-3\
		+y*(0.68412183e-5+y*(0.58242385e-5\
		+y*(-0.1045275e-5+y*(0.8360937e-7\
		+y*(-0.3231081e-8+y*(0.3657763e-10\
		+y*0.6936234e-12))))))))));
	
	return sqrt(y);	
}
//////////////////////////////////////////////////////////////////////////
// chi ���ֲ�����ֵ���ܶ�ֵ:
// ����ֵ: ����(0,x)�ϵĸ���p, f-�ܶ�ֵ
double CProbability::chi2(int n,double x,double *f)
{
	double iai;
	double p,Ux;	
	double pi=3.14159265358979312;
	
	double y=x/2.0;
	if(n%2)
	{
		Ux=sqrt(y/pi)*exp(-y);
		p=2.0*norm(sqrt(x))-1.0;
		iai=0.5;
	}
	else
	{
		Ux=y*exp(-y);
		p=1.0-exp(-y);
		iai=1.0;
	}
	
	while(iai!=0.5*n)
	{
		p = p-Ux/iai;
		Ux = Ux*y/iai;
		iai+=1.0;
	} 
	*f = Ux/x;
	return p;
	
}

//////////////////////////////////////////////////////////////////////////
//	chi���ֲ��ķ�����:  p=F(0,x)
//  ��֪����ֵp,���ɶ�n������x 
double CProbability::re_chi2(int n,double p)
{
	if(p>0.9999999)p=0.9999999;
	if(n==1)
	{
		double x=re_norm((1.0-p)/2.0);
		return x*x;
	}
	
	if(n==2)return -2.0*log(1.0-p);
	
	double u = re_norm(p);
	double w = 2.0/(9.0*n);
	double x0 = 1.0-w+u*sqrt(w);
	x0 = n*x0*x0*x0;
	
	while(1)
	{
		double f;
		double pp=chi2(n,x0,&f);
		if(f+1.0==1.0)return x0;
		double xx=x0-(pp-p)/f;
		if(fabs(x0-xx)<0.001) return xx;
		
		x0=xx;
	}
	
}
//////////////////////////////////////////////////////////////////////////
//  ����F�ֲ�����ֵ: ����(0,x)�ϵĸ���p
//  ��֪F,n1,n2, ��p,f
//  f: F���ĸ����ܶ�ֵ
double CProbability::F(int n1,int n2, double x,double *f)
{
	double y=n1*x/(n2+n1*x);
	double p=B(n1,n2,y,f);
	
	if(f!=nullptr)*f= *f/x;
	return p;
}

//////////////////////////////////////////////////////////////////////////
//    F�ֲ��ķ�������p=F(0,x), ��֪p,����x
double CProbability::re_F(int n1,int n2,double p)
{
	double d,f0;
	
	double a=2.0/(9.0*n1);
	double b=2.0/(9.0*n2);
	double a1=1.0-a;
	double b1=1.0-b;
	double u=re_norm(p);
	double e=b1*b1-b*u*u;
	
	if(e<=0.8)
	{
		double a1=2.0*pow(n2+0.0,0.5*n2-1.0);
		double a2=pow(n1+0.0,0.5*n2);
		double B=gam(n1)*gam(n2)/gam(n1+n2);
		double f=a1/a2/B/(1-p);
		f0=pow(f,2.0/n2);
		
	}
	else
	{
		f0=(a1*b1+u*sqrt(a1*a1*b+a*e))/e;
		f0=f0*f0*f0;
	}
	
	if(f0<0.0)f0=0.01;
	
	while(1)
	{
		double pp=F(n1,n2,f0,&d);
		double df=(p-pp)/d;
		
		while(fabs(f0)<fabs(df))df/=2.0;
		f0=f0+df;
		
		if( fabs(df)/f0<0.0001 || fabs(df)<0.0001) //����Чλ�������Ƿ��˳�����
		{ 
			return f0;
		}
	}
	
}


//////////////////////////////////////////////////////////////////////////
//      B�ֲ�����ֵ:����(0,x)�ϵĸ���p
//      ��֪x,n1,n2, ��q,Ux
//      Ux: x���ĸ����ܶ�ֵ
//   2008-3-5,  ������B�ֲ�����,
double CProbability::B(int n1,int n2, double x,double *Ux)
{
	int iai,ibi;
	double p,u;
	
	double pi=3.14159265358979312;
	
	if(n1%2 && n2%2)   /*  n1,n2��������  */
	{
		u=sqrt(x*(1.0-x))/pi;
		p=1.0-2.0*atan(sqrt((1.0-x)/x))/pi;
		iai=ibi=1;
	}
	
	if(n1%2 && !(n2%2) ) /*  n1������,n2��ż��  */
	{
		u=sqrt(x)*(1.0-x)/2.0;
		p=sqrt(x);
		iai=1;
		ibi=2;
	}
	
	if(!(n1%2) && n2%2)  /*  n1��ż��,n2������  */
	{
		u=x*sqrt(1.0-x)/2.0;
		p=1.0-sqrt(1.0-x);
		iai=2;
		ibi=1;
	}
	
	if(!(n1%2) && !(n2%2))  /*  n1,n2����ż��  */
	{
		u=x*(1.0-x);
		p=x;
		iai=ibi=2;
	}
	
	while((ibi!=n2) || (iai!=n1))
	{
		if(ibi!=n2)
		{  
			p=p+2.0*u/ibi;
			u=u*(1.0+iai/(ibi+0.0))*(1.0-x);
			ibi=ibi+2;
		}  
		if(iai!=n1)
		{   
			p=p-2.0*u/iai;
			u=u*(1.0+ibi/(0.0+iai))*x;
			iai=iai+2;
		}   
	}
	
	if(Ux!=nullptr) *Ux=u;
	return p;
}

//////////////////////////////////////////////////////////////////////////
//        t�ֲ��ķֲ�����ֵ�������t�Ļ���ֵ��  //nn ���ɶ�
//   2008-3-5, ���
double CProbability::t(int nn, double t,double *f) 
{
	if(t+1.0==1.0)return 0.5;
	
	double x=t*t/(nn+t*t);
	
	double P=0.5*B(1,nn,x,f);
	
	if(x<0.0) P=0.5-P;
	else      P=0.5+P;
	
	if(f!=nullptr) *f= *f/fabs(t);
	
	return P;
}

//////////////////////////////////////////////////////////////////////////
//   t�ֲ��ķ�������p=F(x),��֪p������x
//    2008-3-5
double CProbability::re_t(int n,double p)
{
	if(p<0.5)
	{
		return -re_t(n,1.0-p);
	}
	double x;
	double pi=3.14159265358979312;
	
	if(n==1)
	{
		x=tan(pi*(p-0.5));
	}
	else if(n==2)
	{
		double u=2.0*p-1.0;
		u=u*u;
		x=sqrt(2.0*u/(1.0-u));
	}
	else
	{
		x=re_norm(p)*sqrt(n/(n-2.0));
		
		while(1)
		{
			double f; //�ܶ�ֵ
			double F=t(n,x,&f);
			double dx=(F-p)/f;
			x=x-dx;
			if(fabs(dx)<0.001) break;
		}
	}
	return x;
}
