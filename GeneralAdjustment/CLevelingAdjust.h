#ifndef CLEVELINGADJUST_H
#define CLEVELINGADJUST_H
#include<iostream>

using namespace std;

class CLevelingAdjust {
public:
	CLevelingAdjust();
	virtual ~CLevelingAdjust();
	
	int m_Lnumber;      //�߲�����
	int m_Pnumber;      //�ܵ���
	int m_knPnumber;    //��֪����
	int m_StablePnumber; //���ȵ���
	double m_pvv;        //[pvv]
	FILE   *resultfp;    //�ļ�ָ��,���������
	
	double  m_Sigma;  //��ǰ��λȨ�����ֲ�̽�⡢ �պϲ�����ã�
	double  Alhpa;     // ����ˮƽ���ֲ�̽������ã�
	
	int *StartP;     //�߲�����
	int *EndP;       //�߲��յ��
	char   **Pname;   //������ַ����
	double  *L;       //�۲�ֵ����
	double  *Height;  //�߳�ֵ����
	double  *P;       //�۲�ֵ��Ȩ
	
	double  *ATPA,*ATPL; //������ϵ��������������
	double  *dX;      //����ƽ��ֵ���̸߳�������   
	double  *V;       //�в�����
	double  m_mu;      //���λȨ�����
	
	int *IsStable; //�Ƿ�Ϊ���ȵ��
	
	void   Inputdata(const char *datafile);//����ԭʼ���ݺ���
	void   Printdata(); //���ԭʼ���ݺ���
	int    GetStationNumber(char *name); //��ȡ��ź���
	void   ca_H0();       //���Ƹ̼߳��㺯��
	void   ca_ATPA();  //��������ɺ���
	void   ca_dX();    //ƽ��ֵ���㺯��
	void   PrintResult();  //���ȹ�����ƽ��ֵ�������
	double ca_V();     //�в���㺯��	
	
	void   LS_Adjustment();//��С����ƽ���
	void   Quasi_Stable( char *file);//����ƽ���
	void   FreeNetAdjust();//������ƽ���
	
	void  FindShortPath(int p1,int exclude, int root[],\
						double diff[],double S[]);    //���·������
	void  LineClosure(); // ·�߱պϲ����
	void  LoopClosure(); //���պϲ����
	
	void DataSnooping(double arfa);//�ֲ�̽��
};

#endif

