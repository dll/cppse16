#include<stdio.h>
#include<stdlib.h> 
#include<time.h>    

/*
功能：三种方式输入搜索数据
名称：InputData
参数[in]：input输入方式，1为键盘，2为文件，3为随机
参数[out]array:返回数据
参数[in]:n数据个数
返回值：无
*/
void InputData(int input,int array[],int n){ 
	int  i=0;

	if(input==1)//键盘输入 
	 	for(i=0;i<n;i++)
			scanf("%d",&array[i]); 
	else if(input==2){//文件读入
		int fn=0;
		FILE *fp=fopen("data.txt","r");  
		if(!fp){
			printf("open file failed!");
			exit(0);
		}
		for(fn=0;!feof(fp)&&fn<n;fn++)
			fscanf(fp,"%d",&array[fn]);
		if(fn<n){//文件中的数据不足，继续键盘输入
			printf("please input %d numbers\n",n-fn+1);
			for(i=fn-1;i<n;i++)
				scanf("%d",&array[i]);
		}
		fclose(fp);
	}
	else if(input==3){//随机生成
		time_t t;
		int start,end;
		srand((unsigned)time(&t));
		printf("please input start and end\n");
		scanf("%d%d",&start,&end);
		for(i=0;i<end;i++)
			array[i]=start + rand()%(end-start);
	 }else{
		printf("Input Error!");
		exit(0);
	}

} 
 int main(){
	int a[100];
	int in,n;
	printf("Please Choice input data method and numbers\n\
		   1:Keybroad input\n\
		   2:File input\n\
		   3:Random input\n");
	scanf("%d%d",&in,&n);//n<100
	InputData(in,a,n);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	
	 return 0;
 }  

 /*
 测试：
 Please Choice input data method and numbers
 1:Keybroad input
 2:File input
 3:Random input
 1
 3
 1 2 3
 1 2 3
 
 Please Choice input data method and numbers
 1:Keybroad input
 2:File input
 3:Random input
 2
 5
 1 2 3 4 5
 
 data.txt
 1 2 3 4 5 6 7 8 9 10
 
 Please Choice input data method and numbers
 1:Keybroad input
 2:File input
 3:Random input
 2
 12
 please input 2 numbers
 11 12
 1 2 3 4 5 6 7 8 9 10 11 12
 
 Please Choice input data method and numbers
 1:Keybroad input
 2:File input
 3:Random input
 3
 10
 please input start and end
 2 40
 8 6 7 22 24 29 12 23 14 39
 
 */
