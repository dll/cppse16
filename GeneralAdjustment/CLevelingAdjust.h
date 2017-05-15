#ifndef CLEVELINGADJUST_H
#define CLEVELINGADJUST_H
#include<iostream>

using namespace std;

class CLevelingAdjust {
public:
	CLevelingAdjust();
	virtual ~CLevelingAdjust();
	
	int m_Lnumber;      //高差总数
	int m_Pnumber;      //总点数
	int m_knPnumber;    //已知点数
	int m_StablePnumber; //拟稳点数
	double m_pvv;        //[pvv]
	FILE   *resultfp;    //文件指针,输出计算结果
	
	double  m_Sigma;  //验前单位权中误差（粗差探测、 闭合差计算用）
	double  Alhpa;     // 显著水平（粗差探测程序用）
	
	int *StartP;     //高差起点号
	int *EndP;       //高差终点号
	char   **Pname;   //点名地址数组
	double  *L;       //观测值数组
	double  *Height;  //高程值数组
	double  *P;       //观测值的权
	
	double  *ATPA,*ATPL; //法方程系数矩阵与自由项
	double  *dX;      //参数平差值（高程改正数）   
	double  *V;       //残差数组
	double  m_mu;      //验后单位权中误差
	
	int *IsStable; //是否为拟稳点号
	
	void   Inputdata(const char *datafile);//输入原始数据函数
	void   Printdata(); //输出原始数据函数
	int    GetStationNumber(char *name); //获取点号函数
	void   ca_H0();       //近似高程计算函数
	void   ca_ATPA();  //法方程组成函数
	void   ca_dX();    //平差值计算函数
	void   PrintResult();  //精度估计与平差值输出函数
	double ca_V();     //残差计算函数	
	
	void   LS_Adjustment();//最小二乘平差函数
	void   Quasi_Stable( char *file);//拟稳平差函数
	void   FreeNetAdjust();//自由网平差函数
	
	void  FindShortPath(int p1,int exclude, int root[],\
						double diff[],double S[]);    //最短路线搜索
	void  LineClosure(); // 路线闭合差计算
	void  LoopClosure(); //环闭合差计算
	
	void DataSnooping(double arfa);//粗差探测
};

#endif

