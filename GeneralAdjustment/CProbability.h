#ifndef CPROBABILITY_H
#define CPROBABILITY_H

//概率计算类
class CProbability
{
public:
	// 伽玛函数
	double gam(int n);
	//  正态分布的分布函数值: p(-∞,u)
	double norm(double u);
	//  正态分布的反函数, p(-∞,u) ; 已知p, 返回u
	double re_norm(double q);
	//  chi2分布的分布函数：p(0,x)
	double chi2(int n,double x,double *f);
	//  chi2分布的反函数：p=chi2(0,x),已知x，反求p
	double re_chi2(int n,double p);
	//B分布函数值，F分布和t分布函数值计算将调用本函数
	double B(int n1,int n2, double x,double *Ux);
	//  F分布函数值:区间(0,x)上的概率p, f-密度值
	double F(int n1,int n2, double x,double *f);
	//  F分布的反函数：p=F(0,x), 已知p,反求x
	double re_F(int n1,int n2,double p);
	//  t分布的分布函数值
	double t(int n, double x,double *f=nullptr);
	//  t分布的反函数: p(-∞,u)=p; 已知p, 返回u
	double re_t(int n,double p); 
};

#endif

