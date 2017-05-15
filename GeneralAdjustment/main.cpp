#include<iostream>
#include<cstdio>
#include<cstdlib>

#include<conio.h>

#include "SEBase.h"
#include "CProbability.h"
#include "CLevelingAdjust.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//最小二乘平差算例
void main1()
{
	char * datafile =(char*)("算例\\最小二乘平差\\data.txt");
	char * resultfile =(char*)"算例\\最小二乘平差\\result.txt";
	
	printf("\n\n最小二乘平差计算\n");
	printf("数据文件： %s\n",datafile);
	printf("结果文件： %s\n",resultfile);
	
	FILE *fp=fopen(resultfile,"w");
	if (fp==NULL)
	{
		MyBreak("创建结果文件失败！");
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
//闭合差计算算例
void main5()
{
	char *datafile =(char*)"算例\\闭合差计算\\data.txt";
	char *resultfile =(char*)"算例\\闭合差计算\\result.txt";
	
	printf("\n\n闭合差计算\n");
	printf("数据文件： %s\n",datafile);
	printf("结果文件： %s\n",resultfile);
	
	FILE *fp=fopen(resultfile,"w");
	if (fp==NULL)
	{
		MyBreak("创建结果文件失败！");
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
// 秩亏自由网平差算例
void main3()
{
	char *datafile =(char*)"算例\\自由网平差\\data.txt";
	char *resultfile =(char*)"算例\\自由网平差\\result.txt";
	
	printf("\n\n自由网平差计算\n");
	printf("数据文件： %s\n",datafile);
	printf("结果文件： %s\n",resultfile);
	
	FILE *fp=fopen(resultfile,"w");
	if (fp==NULL)
	{
		MyBreak("创建结果文件失败！");
		return;
	}
	
	CLevelingAdjust level;
	level.resultfp=fp;
	level.Inputdata(datafile); 
	level.FreeNetAdjust();
	
	fclose(fp);
}


//////////////////////////////////////////////////////////////////////////
//  拟稳平差算例
void main4()
{
	char *datafile =(char*)"算例\\拟稳平差\\data.txt";
	char *resultfile =(char*)"算例\\拟稳平差\\result.txt";
	char *QuasiStablefile =(char*)"算例\\拟稳平差\\拟稳点.txt";
	
	printf("\n\n拟稳平差计算\n");
	printf("数据文件： %s\n",datafile);
	printf("结果文件： %s\n",resultfile);
	
	FILE *fp=fopen(resultfile,"w");
	if (fp==NULL)
	{
		MyBreak("创建结果文件失败！");
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
//粗差探测差算例
void main2()
{
	char *datafile =(char*)"算例\\粗差探测\\data.txt";
	char *resultfile =(char*)"算例\\粗差探测\\result.txt";
	
	printf("\n\n粗差探测计算\n");
	printf("数据文件： %s\n",datafile);
	printf("结果文件： %s\n",resultfile);
	
	FILE *fp=fopen(resultfile,"w");
	if (fp==NULL)MyBreak("创建结果文件失败！");
	
	CLevelingAdjust level;
	level.resultfp=fp;
	
	level.Inputdata(datafile); 

	level.DataSnooping(0.003);
	
	fprintf(fp,"\n\n在第1、第6号观测值加入模拟粗差之后进行粗差探测:\n");
	level.L[0]+=0.15;
	level.L[5]-=0.05;
	
	level.DataSnooping(0.003);
	
	fclose(fp);	
}

void main0()
{
	printf("     ===== 第5章 水准网平差 =====");
	printf("\n	1.最小二乘平差");
	printf("\n	2.粗差探测");
	printf("\n	3.自由网平差");
	printf("\n	4.拟稳平差");
	printf("\n	5.闭合差计算\n");

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
		cout<<"\nEsc 退出，其它键继续..."<<endl;
		if (getch()==0x1b)
			break;
	}

	return 0;
}
