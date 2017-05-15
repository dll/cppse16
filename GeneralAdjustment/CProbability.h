#ifndef CPROBABILITY_H
#define CPROBABILITY_H

//���ʼ�����
class CProbability
{
public:
	// ٤�꺯��
	double gam(int n);
	//  ��̬�ֲ��ķֲ�����ֵ: p(-��,u)
	double norm(double u);
	//  ��̬�ֲ��ķ�����, p(-��,u) ; ��֪p, ����u
	double re_norm(double q);
	//  chi2�ֲ��ķֲ�������p(0,x)
	double chi2(int n,double x,double *f);
	//  chi2�ֲ��ķ�������p=chi2(0,x),��֪x������p
	double re_chi2(int n,double p);
	//B�ֲ�����ֵ��F�ֲ���t�ֲ�����ֵ���㽫���ñ�����
	double B(int n1,int n2, double x,double *Ux);
	//  F�ֲ�����ֵ:����(0,x)�ϵĸ���p, f-�ܶ�ֵ
	double F(int n1,int n2, double x,double *f);
	//  F�ֲ��ķ�������p=F(0,x), ��֪p,����x
	double re_F(int n1,int n2,double p);
	//  t�ֲ��ķֲ�����ֵ
	double t(int n, double x,double *f=nullptr);
	//  t�ֲ��ķ�����: p(-��,u)=p; ��֪p, ����u
	double re_t(int n,double p); 
};

#endif

