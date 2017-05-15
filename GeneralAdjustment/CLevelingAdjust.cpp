//#include <conio.h>
#include <cstdlib>
#include <cstdarg>
#include <cmath>
#include <cstdio>
#include <string>
#include <string.h>

#include "SEBase.h"
#include "CProbability.h"
#include "CLevelingAdjust.h"

CLevelingAdjust::CLevelingAdjust()
{
	m_Lnumber=0;
	m_Pnumber=0;
	m_StablePnumber=0;
}

CLevelingAdjust::~CLevelingAdjust()
{
	if(m_Lnumber>0)
	{
		delete []StartP;  
		delete []EndP;    
		delete []L;       
		delete []P;       
		delete []V;       
	}
	
	if(m_Pnumber>0)
	{
		delete []Height;   
		delete []ATPA;     
		delete []ATPL;     
		delete []dX;       
		
		for(int i=0; i<m_Pnumber;i++)
			if(Pname[i]!=NULL)delete[](Pname[i]);
			delete []Pname;    
	}
	
}

//////////////////////////////////////////////////////////////////////////
//   原始数据输入函数
void CLevelingAdjust::Inputdata(const char *datafile)
{
	FILE *fp;
	if((fp=fopen(datafile,"r"))==NULL)
	{	       
		MyBreak("\n 数据文件打不开!");  
		exit(0);
	}
	
	fscanf(fp,"%d%d%d",&m_Lnumber,&m_Pnumber,&m_knPnumber);
	
	int unPnumber=m_Pnumber-m_knPnumber;
	
	Height=new double [m_Pnumber];
	dX=new double [m_Pnumber];
	ATPA=new double [m_Pnumber*(m_Pnumber+1)/2];
	ATPL=new double [m_Pnumber];
	StartP=new int [m_Lnumber];
	EndP=new int [m_Lnumber];
	L=new double [m_Lnumber];
	V=new double [m_Lnumber];
	P=new double [m_Lnumber];
	fscanf(fp,"%lf",&m_Sigma);
	
	Pname=new char* [m_Pnumber]; 
	for(int i=0;i<m_Pnumber;i++)
	{
		// GetStationNumber函数根据Pname[i]是否为NULL
		// 确定Pname[i]是否为点名地址
		Pname[i] = NULL;
	}
	
	char buffer[100]; //临时数组，保存从文件中读到的点名	 
	
	//  读取已知高程数据
	for(int i=0;i<=m_knPnumber-1;i++)
	{
		fscanf(fp,"%s",buffer);
		int c=GetStationNumber(buffer);
		
		fscanf(fp,"%lf",&Height[c]);
	}
	
	//  读取观测数据
	for(int i=0;i<m_Lnumber;i++)
	{
		fscanf(fp,"%s",buffer); //读取高程起点名
		StartP[i]=GetStationNumber(buffer); 
		if(StartP[i]<0)
		{
			fprintf(resultfp,"\n数据文件出错：");
			fprintf(resultfp,"\n第%d个高差的起始点名为\"%s\"",i+1,buffer);
			fclose(resultfp);
			exit(0);
		}
		
		fscanf(fp,"%s",buffer);//读取高程终点
		EndP[i]=GetStationNumber(buffer);
		
		if(EndP[i]<0)
		{
			fprintf(resultfp,"\n数据文件出错：");
			fprintf(resultfp,"\n第%d个高差终点的点名为\"%s\"",i+1,buffer);
			fclose(resultfp);
			exit(0);
		}		 
		
		fscanf(fp,"%lf%lf",&L[i],&P[i]); //读取高差值与路线长度
		P[i]=1.0/P[i]; 
	}
	
	fclose(fp);
}

//////////////////////////////////////////////////////////////////////////
//   原始数据写到结果文件
void CLevelingAdjust::Printdata()
{
	int i;
	fprintf(resultfp,"\n 观测值总数: %d  总点数: %d  已知点数：%d \n",
			m_Lnumber, m_Pnumber,m_knPnumber);
	fprintf(resultfp,"\n 验前单位权中误差：%lf" ,m_Sigma);
	fprintf(resultfp,"\n\n   已知高程:\n");
	for(int i=0;i<=m_knPnumber-1;i++)
	{
		fprintf(resultfp,"\n%5d %8s  ",i+1,Pname[i]);
		fprintf(resultfp,"%10.4lf  ",Height[i]);
	}
	
	fprintf(resultfp,"\n\n   高差观测值:\n");
	for(int i=0;i<=m_Lnumber-1;i++)
	{
		fprintf(resultfp,"\n%5d %8s %8s",i+1,Pname[StartP[i]],Pname[EndP[i]]);
		fprintf(resultfp,"%12.4lf %10.3lf",L[i],1.0/P[i]);
	}
}

//////////////////////////////////////////////////////////////////////////
//	 点名存贮，返回点名对应的点号
int  CLevelingAdjust::GetStationNumber(char *name)
{
	for(int i=0; i<m_Pnumber; i++) 
	{
		if(Pname[i]!=NULL)
		{
			//将待查点名与已经存入点名数组的点名比较
			if(strcmp(name,Pname[i])==0)return i;
		}
		else
		{
			//待查点名是一个新的点名，将新点名的地址放到Pname数组中
			int len = strlen(name);
			Pname[i] = new char[len+1];
			strcpy(Pname[i], name);
			return i;
		}
	}
	
	return -1;  //Pname数组已经存满，且没有待查点名
	
}                                          

//////////////////////////////////////////////////////////////////////////
//	      高程近似值计算
void CLevelingAdjust::ca_H0()
{
	for(int i=m_knPnumber;i<m_Pnumber;i++)Height[i]=-9999.9;
	
	int jj=0; //计算出近似高程的点数
	for(int ii=1;;ii++)
	{
		for(int i=0;i<m_Lnumber;i++)
		{
			int k1=StartP[i];  //高差起点号
			int k2=EndP[i];    //高差终点号
			if(Height[k1]>-9999.0 && Height[k2]<-9999.0)
			{
				Height[k2]=Height[k1]+L[i];
				jj++;
			}
			else if(Height[k1]<-9999.0 && Height[k2]>-9999.0)
			{
				Height[k1]=Height[k2]-L[i];
				jj++;
			}
		} 
		
		if(jj==(m_Pnumber-m_knPnumber))break;
		if(ii>(m_Pnumber-m_knPnumber))
		{
			fprintf(resultfp,"\n\n下列点无法计算出概略高程:\n");
			for(int i=0;i<m_Pnumber;i++)
			{
				if(Height[i]<-9999.0) printf("\n%s",Pname[i]);
			}
			MyBreak("近似高程计算失败！");
			fclose(resultfp);
			exit(0);
		}
	} 
}
//////////////////////////////////////////////////////////////////////////
//  组成法方程
void CLevelingAdjust::ca_ATPA()
{
	int t=m_Pnumber;
	
	for(int i=0; i<t*(t+1)/2; i++) ATPA[i]=0.0;
	for(int i=0; i<t; i++) ATPL[i]=0.0;
	
	for(int k=0; k<m_Lnumber; k++)
	{
		int i=StartP[k];
		int j=EndP[k];
		double Pk=P[k];
		double Lk=L[k]-(Height[j]-Height[i]);
		
		ATPL[i]-=Pk*Lk;
		ATPL[j]+=Pk*Lk;
		ATPA[CalSymmetricMatrixSubscript(i,i)]+=Pk;
		ATPA[CalSymmetricMatrixSubscript(j,j)]+=Pk;
		ATPA[CalSymmetricMatrixSubscript(i,j)]-=Pk;
	}
}
//////////////////////////////////////////////////////////////////////////
//    高程平差值计算
void CLevelingAdjust::ca_dX()
{
	if(!inverse(ATPA,m_Pnumber))
	{
		MyBreak("\n法方程系数矩阵降秩!");
		fclose(resultfp);
		exit(0);
	}
	
	for(int i=0; i<m_Pnumber; i++)
	{
		double xi=0.0;
		for(int j=0; j<m_Pnumber; j++)
		{
			xi+=ATPA[CalSymmetricMatrixSubscript(i,j)]*ATPL[j];
		}
		dX[i]=xi;
		Height[i]+=xi;
	}
}

//////////////////////////////////////////////////////////////////////////
//   残差计算
double  CLevelingAdjust::ca_V()
{
	double pvv=0.0;
	for(int i=0;i<=m_Lnumber-1;i++)
	{
		int k1=StartP[i];
		int k2=EndP[i];
		V[i]=Height[k2]-Height[k1]-L[i];
		pvv+=V[i]*V[i]*P[i];
	}
	return(pvv);
}

//////////////////////////////////////////////////////////////////////////
//   平差值输出
void  CLevelingAdjust::PrintResult()
{
	fprintf(resultfp,"\n\n           ==== 高程平差值及其精度 ====\n");
	fprintf(resultfp,"\n    点名   近似高程   改正数   高程平差值  中误差\n");
	for(int i=0; i<m_Pnumber; i++)
	{
		fprintf(resultfp,"\n %5s ",Pname[i]);
		double dx=dX[i];
		double qii=ATPA[CalSymmetricMatrixSubscript(i,i)];
		fprintf(resultfp,"%12.4lf%9.4lf%12.4lf%9.4lf",
				Height[i]-dx,dx,Height[i],sqrt(qii)*m_mu);
	}
	fprintf(resultfp,"\n\n\n              ==== 观测值平差值及其精度 ====\n");
	fprintf(resultfp,"\n   No. 起 点  终 点  观测高差    ｖ");
	fprintf(resultfp,"     高差平差值   观测权   中误差\n");
	
	for(int i=0;i<=m_Lnumber-1;i++)
	{
		int k1=StartP[i];
		int k2=EndP[i];
		double qii=ATPA[CalSymmetricMatrixSubscript(k1,k1)];
		double qjj= ATPA[CalSymmetricMatrixSubscript(k2,k2)] ;
		double qCalSymmetricMatrixSubscript=ATPA[CalSymmetricMatrixSubscript(k1,k2)];
		double ml=sqrt(qii+qjj-2.0*qCalSymmetricMatrixSubscript)*m_mu;
		fprintf(resultfp,"\n%5d %5s%5s ",i+1,Pname[k1],Pname[k2]);
		fprintf(resultfp,"%12.4lf %8.4lf%11.4lf%9.2lf%10.4lf",
				L[i],V[i],L[i]+V[i],P[i],ml);
	}
}

//////////////////////////////////////////////////////////////////////////
//    水准网最小二乘平差
void  CLevelingAdjust::LS_Adjustment()
{
	ca_H0(); //近似高程计算
	ca_ATPA(); // 组成法方程
	
	//处理已知点
	for(int i=0;i<m_knPnumber;i++) ATPA[CalSymmetricMatrixSubscript(i,i)]=1.0e30;
	
	ca_dX(); // 高程平差值计算
	double pvv=ca_V();  // 残差计算
	
	m_mu=sqrt(pvv/(m_Lnumber-(m_Pnumber-m_knPnumber)));
	fprintf(resultfp,"\n\n  最小二乘平差结果：\n    [pvv]=%-12.8lf",pvv);
	fprintf(resultfp,"\n       μ=±%lf",m_mu);
	
	PrintResult();
	return ;
}

//////////////////////////////////////////////////////////////////////////
//       水准网－自由网平差
void CLevelingAdjust::FreeNetAdjust()
{
	ca_ATPA(); //组成法方程
	
	int tt=m_Pnumber*(m_Pnumber+1)/2;
	for(int i=0; i<tt; i++)	ATPA[i]+=1.0/m_Pnumber;  
	
	ca_dX();
	
	for(int i=0;  i<tt; i++) ATPA[i]-=1.0/m_Pnumber; 
	
	double pvv = ca_V();
	fprintf(resultfp,"\n    [pvv]=%-12.8lf",pvv);
	m_mu= sqrt(pvv/(m_Lnumber-(m_Pnumber-1)));
	fprintf(resultfp,"\n       μ=±%lf",m_mu);
	
	PrintResult();
	
	PrintM2(resultfp,ATPA,m_Pnumber,4,"%15e ","Qx");	
} 



//////////////////////////////////////////////////////////////////////////
//       水准网拟稳平差
//       2008－07－16
void CLevelingAdjust::Quasi_Stable(char *file) //file是拟稳点名文件
{
	//打开文件，获取拟稳点名
	FILE *fp=fopen(file,"r");
	if(fp==NULL)
	{
		MyBreak("拟稳点文件打不开！");
		fclose(resultfp);
		exit(0);
	}
	
	fscanf(fp,"%d",&m_StablePnumber);
	if(m_StablePnumber>m_Pnumber || m_StablePnumber<1)
	{
		MyBreak("拟稳点数错误!");
		fclose(resultfp);
		exit(0);		
	}
	
	IsStable=new int[m_Pnumber];
	
	for(int i=0;i<=m_Pnumber-1;i++) IsStable[i]=false;
	
	fprintf(resultfp,"\n%s\n","\n   拟稳点：");
	for(int i=0;i<=m_StablePnumber-1;i++)
	{
		char name[100];
		fscanf(fp,"%s",name);
		int k=GetStationNumber(name);
		if(k<0)
		{
			fprintf(resultfp,"\n拟稳点名文件出错：");
			fprintf(resultfp,"\n出现了数据文件中没有的点名：%s",name);
			fclose(resultfp);
			exit(0);			
		}
		IsStable[k] = 1;
		fprintf(resultfp,"\n%10s ",Pname[k]);
	}
	fclose(fp);
	
	ca_ATPA();
	for(int i=0;i<m_Pnumber;i++)
	{
		for(int j=0;j<=i;j++)
			if(IsStable[i] && IsStable[j] )
			ATPA[CalSymmetricMatrixSubscript(i,j)]+=1.0/m_StablePnumber;
	}
	
	ca_dX();
	
	for(int i=0;i<m_Pnumber;i++)
	{
		for(int j=0;j<=i;j++)
			ATPA[CalSymmetricMatrixSubscript(i,j)]-=1.0/m_StablePnumber;
	}
	
	double pvv = ca_V();
	m_mu= sqrt(pvv/(m_Lnumber-(m_Pnumber-1)));
	
	fprintf(resultfp,"\n    [pvv]=%-12.8lf",pvv);
	fprintf(resultfp,"\n    单位权中误差:   m=%lf",m_mu);
	
	PrintResult();
	PrintM2(resultfp,ATPA,m_Pnumber,4,"%15e ","Qx");		
}

//////////////////////////////////////////////////////////////////////////
//	路线闭合差计算	
void CLevelingAdjust::LineClosure()
{
	if(m_knPnumber<2)return; // 已知点数小于2
	
	fprintf(resultfp,"\n\n  === 路线闭合差计算 === ");
	
	int *neighbor=new int[m_Pnumber];       //邻接点数组
	double *diff=new double[m_Pnumber]; //高差累加值数组
	double *S=new double[m_Pnumber];    //路线长累加值数组
	
	for(int i=0; i<m_knPnumber-1; i++)
	{
		FindShortPath(i,-1,neighbor,diff,S); //搜索最短路线，用所有观测值
		
		for(int j=i+1;j<m_knPnumber;j++)
		{
			if(neighbor[j]<0)
			{
				fprintf(resultfp,"%s-%s之间找到不到最短路线",
						Pname[i],Pname[j]);
				continue;
			}
			
			// 输出附合路线上的点号
			fprintf(resultfp,"\n    附合路线：");
			int k=j;
			while(1)
			{
				fprintf(resultfp,"%s - ",Pname[k]);
				k=neighbor[k];
				if(k==i)break;
			}
			fprintf(resultfp,"%s ",Pname[i]);
			
			// 闭合差计算，限差计算与输出
			double W=Height[i]+diff[j]-Height[j]; // 闭合差
			double limit=2.0*sqrt(S[j])*m_Sigma;  // 限差
			
			fprintf(resultfp,"\n      W=%7.3lf  (限差:%7.3lf) ",
					-W,limit); // 因为输出的点号是反向的，所以闭合差为负号
		}
	}
	delete []neighbor;
	delete []S;
	delete []diff;	
}

//////////////////////////////////////////////////////////////////////////
//  搜索最短路径
void CLevelingAdjust::FindShortPath(int p,int exclude,int neighbor[],
									double diff[],double S[])
{
	for(int i=0; i<m_Pnumber; i++) 
	{
		neighbor[i]=-1;  // 还没有邻接点
		S[i]=1.0e30;
	}
	S[p]=0.0;
	diff[p]=0.0;
	neighbor[p]=p;
	
	for(int i=0;;i++)
	{
		bool successful=true; 
		for(int j=0;j<=m_Lnumber-1;j++)
		{
			if(j==exclude) continue;
			int p1=StartP[j];
			int p2=EndP[j];
			double S12=1.0/P[j];
			if(neighbor[p1]<0 && neighbor[p2]<0) continue;
			
			if(S[p2]>S[p1]+S12)
			{
				neighbor[p2]=p1;
				S[p2]=S[p1]+S12;
				diff[p2]=diff[p1]+L[j];
				successful=false;
			}
			else if(S[p1]>S[p2]+S12)
			{
				neighbor[p1]=p2;
				S[p1]=S[p2]+S12;
				diff[p1]=diff[p2]-L[j];
				successful = false;
			}
		}
		if(successful)break;
	}
	
	return ;
}

//////////////////////////////////////////////////////////////////////////
//	环闭合差计算	
void CLevelingAdjust::LoopClosure()
{		
	fprintf(resultfp,"\n\n  === 环闭合差计算 === ");
	
	int num=m_Lnumber-(m_Pnumber-1);
	if(num<1)
	{
		fprintf(resultfp,"\n    无闭合环\n\n");		
		return;
	}
	
	int *neighbor=new int[m_Pnumber]; //邻接点数组
	int *used=new int[m_Lnumber]; //观测值是否已经用于闭合差计算
	double *diff=new double[m_Pnumber]; //高差累加值数组
	double *S=new double[m_Pnumber];	//路线长数组
	
	for(int i=0; i<=m_Lnumber-1; i++) used[i]=0;
	
	for(int i=0; i<m_Lnumber; i++)
	{
		int k1=StartP[i];
		int k2=EndP[i];
		if(used[i]) continue;
		
		FindShortPath(k2,i,neighbor,diff,S);//搜索最短路线，第i号观测值不能参加
		
		if(neighbor[k1]<0)
		{
			fprintf(resultfp,"\n观测值%s - %s与任何观测边不构成闭合环",
					Pname[k1],Pname[k2]);
		}
		else
		{
			used[i]=1;
			fprintf(resultfp,"\n   环闭合差： ");
			int p1=k1;
			while(1)//输出点名
			{
				int p2=neighbor[p1];
				fprintf(resultfp,"%s - ",Pname[p1]);
				
				for(int r=0;r<m_Lnumber;r++)//将用过的观测值标定
				{
					if(StartP[r]==p1 && EndP[r]==p2)
					{
						used[r]=1;
						break;
					}
					else if(StartP[r]==p2 && EndP[r]==p1)
					{
						used[r]=1;
						break;
					}
				}
				if(p2==k2)break;
				else p1=p2;
			}
			fprintf(resultfp,"%s - %s  ",Pname[k2],Pname[k1]);
			
			double W=L[i]+diff[k1];   //闭合差
			double SS=S[k1]+1.0/P[i]; //环长
			fprintf(resultfp,"\n     W=%7.4lf  (限差:%7.4lf) ",
					-W,2.0*sqrt(SS)*m_Sigma);
		}
	}
	
	delete []neighbor;
	delete []used;
	delete []diff;
	delete []S;		
} 
//////////////////////////////////////////////////////////////////////////
//   水准网粗差探测
void CLevelingAdjust::DataSnooping(double arfa)
{
	CProbability pp;
	double U=pp.re_norm(1.0-arfa/2.0);
	
	ca_H0(); //近似高程计算	
	
	double pvv;
	int k;
	for(k=0; ; k++)
	{
		ca_ATPA(); // 组成法方程
		
		//处理已知点
		for(int i=0;i<m_knPnumber;i++) ATPA[CalSymmetricMatrixSubscript(i,i)]=1.0e30;
		
		ca_dX(); // 高程平差值计算
		pvv=ca_V(); // 残差计算
		
		double max_v=0.0;
		int    max_i;
		for(int i=0;i<=m_Lnumber-1;i++)
		{
			if(P[i]<1.0e-10) continue;
			int k1=StartP[i];
			int k2=EndP[i];
			double qii=ATPA[CalSymmetricMatrixSubscript(k1,k1)];
			double qjj= ATPA[CalSymmetricMatrixSubscript(k2,k2)] ;
			double qCalSymmetricMatrixSubscript=ATPA[CalSymmetricMatrixSubscript(k1,k2)];
			
			double qv=1.0/P[i]-(qii+qjj-2.0*qCalSymmetricMatrixSubscript);
			double mv=sqrt(qv)*m_Sigma;
			
			double vi=V[i]/mv;
			
			if(fabs(vi) > max_v )
			{
				max_v=fabs(vi);
				max_i=i;
			}
		}
		
		if(max_v>U)P[max_i]=0.0;
		else break;
	} 
	if(k>0)
	{
		fprintf(resultfp,"\n粗差总数：%d \n粗差估值：",k);
		for(int i=0;i<=m_Lnumber-1;i++)
		{
			if(P[i]>1.0e-10) continue;
			fprintf(resultfp,"\n  %2d %8s %8s  %12.4lf ",
					i+1,Pname[StartP[i]],Pname[EndP[i]],V[i]);
		}	
	}
	else fprintf(resultfp,"\n粗差探测未发现粗差\n");
	
	m_mu= sqrt(pvv/(m_Lnumber-k-(m_Pnumber-m_knPnumber)));
	fprintf(resultfp,"\n       μ=±%lf",m_mu);
	
	PrintResult();
	
}
