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
//   ԭʼ�������뺯��
void CLevelingAdjust::Inputdata(const char *datafile)
{
	FILE *fp;
	if((fp=fopen(datafile,"r"))==NULL)
	{	       
		MyBreak("\n �����ļ��򲻿�!");  
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
		// GetStationNumber��������Pname[i]�Ƿ�ΪNULL
		// ȷ��Pname[i]�Ƿ�Ϊ������ַ
		Pname[i] = NULL;
	}
	
	char buffer[100]; //��ʱ���飬������ļ��ж����ĵ���	 
	
	//  ��ȡ��֪�߳�����
	for(int i=0;i<=m_knPnumber-1;i++)
	{
		fscanf(fp,"%s",buffer);
		int c=GetStationNumber(buffer);
		
		fscanf(fp,"%lf",&Height[c]);
	}
	
	//  ��ȡ�۲�����
	for(int i=0;i<m_Lnumber;i++)
	{
		fscanf(fp,"%s",buffer); //��ȡ�߳������
		StartP[i]=GetStationNumber(buffer); 
		if(StartP[i]<0)
		{
			fprintf(resultfp,"\n�����ļ�����");
			fprintf(resultfp,"\n��%d���߲����ʼ����Ϊ\"%s\"",i+1,buffer);
			fclose(resultfp);
			exit(0);
		}
		
		fscanf(fp,"%s",buffer);//��ȡ�߳��յ�
		EndP[i]=GetStationNumber(buffer);
		
		if(EndP[i]<0)
		{
			fprintf(resultfp,"\n�����ļ�����");
			fprintf(resultfp,"\n��%d���߲��յ�ĵ���Ϊ\"%s\"",i+1,buffer);
			fclose(resultfp);
			exit(0);
		}		 
		
		fscanf(fp,"%lf%lf",&L[i],&P[i]); //��ȡ�߲�ֵ��·�߳���
		P[i]=1.0/P[i]; 
	}
	
	fclose(fp);
}

//////////////////////////////////////////////////////////////////////////
//   ԭʼ����д������ļ�
void CLevelingAdjust::Printdata()
{
	int i;
	fprintf(resultfp,"\n �۲�ֵ����: %d  �ܵ���: %d  ��֪������%d \n",
			m_Lnumber, m_Pnumber,m_knPnumber);
	fprintf(resultfp,"\n ��ǰ��λȨ����%lf" ,m_Sigma);
	fprintf(resultfp,"\n\n   ��֪�߳�:\n");
	for(int i=0;i<=m_knPnumber-1;i++)
	{
		fprintf(resultfp,"\n%5d %8s  ",i+1,Pname[i]);
		fprintf(resultfp,"%10.4lf  ",Height[i]);
	}
	
	fprintf(resultfp,"\n\n   �߲�۲�ֵ:\n");
	for(int i=0;i<=m_Lnumber-1;i++)
	{
		fprintf(resultfp,"\n%5d %8s %8s",i+1,Pname[StartP[i]],Pname[EndP[i]]);
		fprintf(resultfp,"%12.4lf %10.3lf",L[i],1.0/P[i]);
	}
}

//////////////////////////////////////////////////////////////////////////
//	 �������������ص�����Ӧ�ĵ��
int  CLevelingAdjust::GetStationNumber(char *name)
{
	for(int i=0; i<m_Pnumber; i++) 
	{
		if(Pname[i]!=NULL)
		{
			//������������Ѿ������������ĵ����Ƚ�
			if(strcmp(name,Pname[i])==0)return i;
		}
		else
		{
			//���������һ���µĵ��������µ����ĵ�ַ�ŵ�Pname������
			int len = strlen(name);
			Pname[i] = new char[len+1];
			strcpy(Pname[i], name);
			return i;
		}
	}
	
	return -1;  //Pname�����Ѿ���������û�д������
	
}                                          

//////////////////////////////////////////////////////////////////////////
//	      �߳̽���ֵ����
void CLevelingAdjust::ca_H0()
{
	for(int i=m_knPnumber;i<m_Pnumber;i++)Height[i]=-9999.9;
	
	int jj=0; //��������Ƹ̵߳ĵ���
	for(int ii=1;;ii++)
	{
		for(int i=0;i<m_Lnumber;i++)
		{
			int k1=StartP[i];  //�߲�����
			int k2=EndP[i];    //�߲��յ��
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
			fprintf(resultfp,"\n\n���е��޷���������Ը߳�:\n");
			for(int i=0;i<m_Pnumber;i++)
			{
				if(Height[i]<-9999.0) printf("\n%s",Pname[i]);
			}
			MyBreak("���Ƹ̼߳���ʧ�ܣ�");
			fclose(resultfp);
			exit(0);
		}
	} 
}
//////////////////////////////////////////////////////////////////////////
//  ��ɷ�����
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
//    �߳�ƽ��ֵ����
void CLevelingAdjust::ca_dX()
{
	if(!inverse(ATPA,m_Pnumber))
	{
		MyBreak("\n������ϵ��������!");
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
//   �в����
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
//   ƽ��ֵ���
void  CLevelingAdjust::PrintResult()
{
	fprintf(resultfp,"\n\n           ==== �߳�ƽ��ֵ���侫�� ====\n");
	fprintf(resultfp,"\n    ����   ���Ƹ߳�   ������   �߳�ƽ��ֵ  �����\n");
	for(int i=0; i<m_Pnumber; i++)
	{
		fprintf(resultfp,"\n %5s ",Pname[i]);
		double dx=dX[i];
		double qii=ATPA[CalSymmetricMatrixSubscript(i,i)];
		fprintf(resultfp,"%12.4lf%9.4lf%12.4lf%9.4lf",
				Height[i]-dx,dx,Height[i],sqrt(qii)*m_mu);
	}
	fprintf(resultfp,"\n\n\n              ==== �۲�ֵƽ��ֵ���侫�� ====\n");
	fprintf(resultfp,"\n   No. �� ��  �� ��  �۲�߲�    ��");
	fprintf(resultfp,"     �߲�ƽ��ֵ   �۲�Ȩ   �����\n");
	
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
//    ˮ׼����С����ƽ��
void  CLevelingAdjust::LS_Adjustment()
{
	ca_H0(); //���Ƹ̼߳���
	ca_ATPA(); // ��ɷ�����
	
	//������֪��
	for(int i=0;i<m_knPnumber;i++) ATPA[CalSymmetricMatrixSubscript(i,i)]=1.0e30;
	
	ca_dX(); // �߳�ƽ��ֵ����
	double pvv=ca_V();  // �в����
	
	m_mu=sqrt(pvv/(m_Lnumber-(m_Pnumber-m_knPnumber)));
	fprintf(resultfp,"\n\n  ��С����ƽ������\n    [pvv]=%-12.8lf",pvv);
	fprintf(resultfp,"\n       ��=��%lf",m_mu);
	
	PrintResult();
	return ;
}

//////////////////////////////////////////////////////////////////////////
//       ˮ׼����������ƽ��
void CLevelingAdjust::FreeNetAdjust()
{
	ca_ATPA(); //��ɷ�����
	
	int tt=m_Pnumber*(m_Pnumber+1)/2;
	for(int i=0; i<tt; i++)	ATPA[i]+=1.0/m_Pnumber;  
	
	ca_dX();
	
	for(int i=0;  i<tt; i++) ATPA[i]-=1.0/m_Pnumber; 
	
	double pvv = ca_V();
	fprintf(resultfp,"\n    [pvv]=%-12.8lf",pvv);
	m_mu= sqrt(pvv/(m_Lnumber-(m_Pnumber-1)));
	fprintf(resultfp,"\n       ��=��%lf",m_mu);
	
	PrintResult();
	
	PrintM2(resultfp,ATPA,m_Pnumber,4,"%15e ","Qx");	
} 



//////////////////////////////////////////////////////////////////////////
//       ˮ׼������ƽ��
//       2008��07��16
void CLevelingAdjust::Quasi_Stable(char *file) //file�����ȵ����ļ�
{
	//���ļ�����ȡ���ȵ���
	FILE *fp=fopen(file,"r");
	if(fp==NULL)
	{
		MyBreak("���ȵ��ļ��򲻿���");
		fclose(resultfp);
		exit(0);
	}
	
	fscanf(fp,"%d",&m_StablePnumber);
	if(m_StablePnumber>m_Pnumber || m_StablePnumber<1)
	{
		MyBreak("���ȵ�������!");
		fclose(resultfp);
		exit(0);		
	}
	
	IsStable=new int[m_Pnumber];
	
	for(int i=0;i<=m_Pnumber-1;i++) IsStable[i]=false;
	
	fprintf(resultfp,"\n%s\n","\n   ���ȵ㣺");
	for(int i=0;i<=m_StablePnumber-1;i++)
	{
		char name[100];
		fscanf(fp,"%s",name);
		int k=GetStationNumber(name);
		if(k<0)
		{
			fprintf(resultfp,"\n���ȵ����ļ�����");
			fprintf(resultfp,"\n�����������ļ���û�еĵ�����%s",name);
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
	fprintf(resultfp,"\n    ��λȨ�����:   m=%lf",m_mu);
	
	PrintResult();
	PrintM2(resultfp,ATPA,m_Pnumber,4,"%15e ","Qx");		
}

//////////////////////////////////////////////////////////////////////////
//	·�߱պϲ����	
void CLevelingAdjust::LineClosure()
{
	if(m_knPnumber<2)return; // ��֪����С��2
	
	fprintf(resultfp,"\n\n  === ·�߱պϲ���� === ");
	
	int *neighbor=new int[m_Pnumber];       //�ڽӵ�����
	double *diff=new double[m_Pnumber]; //�߲��ۼ�ֵ����
	double *S=new double[m_Pnumber];    //·�߳��ۼ�ֵ����
	
	for(int i=0; i<m_knPnumber-1; i++)
	{
		FindShortPath(i,-1,neighbor,diff,S); //�������·�ߣ������й۲�ֵ
		
		for(int j=i+1;j<m_knPnumber;j++)
		{
			if(neighbor[j]<0)
			{
				fprintf(resultfp,"%s-%s֮���ҵ��������·��",
						Pname[i],Pname[j]);
				continue;
			}
			
			// �������·���ϵĵ��
			fprintf(resultfp,"\n    ����·�ߣ�");
			int k=j;
			while(1)
			{
				fprintf(resultfp,"%s - ",Pname[k]);
				k=neighbor[k];
				if(k==i)break;
			}
			fprintf(resultfp,"%s ",Pname[i]);
			
			// �պϲ���㣬�޲���������
			double W=Height[i]+diff[j]-Height[j]; // �պϲ�
			double limit=2.0*sqrt(S[j])*m_Sigma;  // �޲�
			
			fprintf(resultfp,"\n      W=%7.3lf  (�޲�:%7.3lf) ",
					-W,limit); // ��Ϊ����ĵ���Ƿ���ģ����Ապϲ�Ϊ����
		}
	}
	delete []neighbor;
	delete []S;
	delete []diff;	
}

//////////////////////////////////////////////////////////////////////////
//  �������·��
void CLevelingAdjust::FindShortPath(int p,int exclude,int neighbor[],
									double diff[],double S[])
{
	for(int i=0; i<m_Pnumber; i++) 
	{
		neighbor[i]=-1;  // ��û���ڽӵ�
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
//	���պϲ����	
void CLevelingAdjust::LoopClosure()
{		
	fprintf(resultfp,"\n\n  === ���պϲ���� === ");
	
	int num=m_Lnumber-(m_Pnumber-1);
	if(num<1)
	{
		fprintf(resultfp,"\n    �ޱպϻ�\n\n");		
		return;
	}
	
	int *neighbor=new int[m_Pnumber]; //�ڽӵ�����
	int *used=new int[m_Lnumber]; //�۲�ֵ�Ƿ��Ѿ����ڱպϲ����
	double *diff=new double[m_Pnumber]; //�߲��ۼ�ֵ����
	double *S=new double[m_Pnumber];	//·�߳�����
	
	for(int i=0; i<=m_Lnumber-1; i++) used[i]=0;
	
	for(int i=0; i<m_Lnumber; i++)
	{
		int k1=StartP[i];
		int k2=EndP[i];
		if(used[i]) continue;
		
		FindShortPath(k2,i,neighbor,diff,S);//�������·�ߣ���i�Ź۲�ֵ���ܲμ�
		
		if(neighbor[k1]<0)
		{
			fprintf(resultfp,"\n�۲�ֵ%s - %s���κι۲�߲����ɱպϻ�",
					Pname[k1],Pname[k2]);
		}
		else
		{
			used[i]=1;
			fprintf(resultfp,"\n   ���պϲ ");
			int p1=k1;
			while(1)//�������
			{
				int p2=neighbor[p1];
				fprintf(resultfp,"%s - ",Pname[p1]);
				
				for(int r=0;r<m_Lnumber;r++)//���ù��Ĺ۲�ֵ�궨
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
			
			double W=L[i]+diff[k1];   //�պϲ�
			double SS=S[k1]+1.0/P[i]; //����
			fprintf(resultfp,"\n     W=%7.4lf  (�޲�:%7.4lf) ",
					-W,2.0*sqrt(SS)*m_Sigma);
		}
	}
	
	delete []neighbor;
	delete []used;
	delete []diff;
	delete []S;		
} 
//////////////////////////////////////////////////////////////////////////
//   ˮ׼���ֲ�̽��
void CLevelingAdjust::DataSnooping(double arfa)
{
	CProbability pp;
	double U=pp.re_norm(1.0-arfa/2.0);
	
	ca_H0(); //���Ƹ̼߳���	
	
	double pvv;
	int k;
	for(k=0; ; k++)
	{
		ca_ATPA(); // ��ɷ�����
		
		//������֪��
		for(int i=0;i<m_knPnumber;i++) ATPA[CalSymmetricMatrixSubscript(i,i)]=1.0e30;
		
		ca_dX(); // �߳�ƽ��ֵ����
		pvv=ca_V(); // �в����
		
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
		fprintf(resultfp,"\n�ֲ�������%d \n�ֲ��ֵ��",k);
		for(int i=0;i<=m_Lnumber-1;i++)
		{
			if(P[i]>1.0e-10) continue;
			fprintf(resultfp,"\n  %2d %8s %8s  %12.4lf ",
					i+1,Pname[StartP[i]],Pname[EndP[i]],V[i]);
		}	
	}
	else fprintf(resultfp,"\n�ֲ�̽��δ���ֲִ�\n");
	
	m_mu= sqrt(pvv/(m_Lnumber-k-(m_Pnumber-m_knPnumber)));
	fprintf(resultfp,"\n       ��=��%lf",m_mu);
	
	PrintResult();
	
}
