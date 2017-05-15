#include<iostream>
#include<cstdio>
#include<cstdlib>

#include<conio.h>

#include "SEBase.h"
#include "CProbability.h"
#include "CLevelingAdjust.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//��С����ƽ������
void main1()
{
	char * datafile =(char*)("����\\��С����ƽ��\\data.txt");
	char * resultfile =(char*)"����\\��С����ƽ��\\result.txt";
	
	printf("\n\n��С����ƽ�����\n");
	printf("�����ļ��� %s\n",datafile);
	printf("����ļ��� %s\n",resultfile);
	
	FILE *fp=fopen(resultfile,"w");
	if (fp==NULL)
	{
		MyBreak("��������ļ�ʧ�ܣ�");
		return;
	}
	
	CLevelingAdjust level;
	level.resultfp=fp;
	
	level.Inputdata(datafile); 
	level.Printdata();
	level.LS_Adjustment();
	
	fclose(fp);
	
	system(datafile);
	system(resultfile);
}
//////////////////////////////////////////////////////////////////////////
//�պϲ��������
void main5()
{
	char *datafile =(char*)"����\\�պϲ����\\data.txt";
	char *resultfile =(char*)"����\\�պϲ����\\result.txt";
	
	printf("\n\n�պϲ����\n");
	printf("�����ļ��� %s\n",datafile);
	printf("����ļ��� %s\n",resultfile);
	
	FILE *fp=fopen(resultfile,"w");
	if (fp==NULL)
	{
		MyBreak("��������ļ�ʧ�ܣ�");
		return;
	}
	
	CLevelingAdjust level;
	level.resultfp=fp;
	level.Inputdata(datafile); 
	
	level.LineClosure();
	level.LoopClosure();
	
	fclose(fp);
	
}

//////////////////////////////////////////////////////////////////////////
// �ȿ�������ƽ������
void main3()
{
	char *datafile =(char*)"����\\������ƽ��\\data.txt";
	char *resultfile =(char*)"����\\������ƽ��\\result.txt";
	
	printf("\n\n������ƽ�����\n");
	printf("�����ļ��� %s\n",datafile);
	printf("����ļ��� %s\n",resultfile);
	
	FILE *fp=fopen(resultfile,"w");
	if (fp==NULL)
	{
		MyBreak("��������ļ�ʧ�ܣ�");
		return;
	}
	
	CLevelingAdjust level;
	level.resultfp=fp;
	level.Inputdata(datafile); 
	level.FreeNetAdjust();
	
	fclose(fp);
}


//////////////////////////////////////////////////////////////////////////
//  ����ƽ������
void main4()
{
	char *datafile =(char*)"����\\����ƽ��\\data.txt";
	char *resultfile =(char*)"����\\����ƽ��\\result.txt";
	char *QuasiStablefile =(char*)"����\\����ƽ��\\���ȵ�.txt";
	
	printf("\n\n����ƽ�����\n");
	printf("�����ļ��� %s\n",datafile);
	printf("����ļ��� %s\n",resultfile);
	
	FILE *fp=fopen(resultfile,"w");
	if (fp==NULL)
	{
		MyBreak("��������ļ�ʧ�ܣ�");
		return;
	}
	
	CLevelingAdjust level;
	level.resultfp=fp;
	level.Inputdata(datafile); 
//	level.printdata();
	level.Quasi_Stable(QuasiStablefile);
	
	fclose(fp);
}

//////////////////////////////////////////////////////////////////////////
//�ֲ�̽�������
void main2()
{
	char *datafile =(char*)"����\\�ֲ�̽��\\data.txt";
	char *resultfile =(char*)"����\\�ֲ�̽��\\result.txt";
	
	printf("\n\n�ֲ�̽�����\n");
	printf("�����ļ��� %s\n",datafile);
	printf("����ļ��� %s\n",resultfile);
	
	FILE *fp=fopen(resultfile,"w");
	if (fp==NULL)MyBreak("��������ļ�ʧ�ܣ�");
	
	CLevelingAdjust level;
	level.resultfp=fp;
	
	level.Inputdata(datafile); 

	level.DataSnooping(0.003);
	
	fprintf(fp,"\n\n�ڵ�1����6�Ź۲�ֵ����ģ��ֲ�֮����дֲ�̽��:\n");
	level.L[0]+=0.15;
	level.L[5]-=0.05;
	
	level.DataSnooping(0.003);
	
	fclose(fp);	
}

void main0()
{
	printf("     ===== ��5�� ˮ׼��ƽ�� =====");
	printf("\n	1.��С����ƽ��");
	printf("\n	2.�ֲ�̽��");
	printf("\n	3.������ƽ��");
	printf("\n	4.����ƽ��");
	printf("\n	5.�պϲ����\n");

	int sw;
	scanf("%d",&sw);
	
	switch(sw) {
	case 1:
		main1();
		break;
	case 2:
		main2();
		break;
	case 3:
		main3();
		break;
	case 4:
		main4();
		break;
	case 5:
		main5();
		break;
	default:
		break;
	}

}


int main()
{
	while(1){
		system("cls");
		main0();
		cout<<"\nEsc �˳�������������..."<<endl;
		if (getch()==0x1b)
			break;
	}

	return 0;
}
