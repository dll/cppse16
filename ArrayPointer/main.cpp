#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>

using namespace std;

int g=2;

char* getStr1(){
	char* str="abc1";
	return str;
}
char* getStr2(){
	char* str="abc1";
	return str;
}
char* getStr3(){
	char str[10];
	strcpy(str,"abc");
	cout<<"getStr3 str[]:"<<str<<endl;
	return str;
}
char* getStr4(){
	char* str="";
	str=(char*)malloc(sizeof(char)*10);
	strcpy(str,"abc");
	cout<<"getStr4 malloc:"<<str<<endl;
	return str;
}
int main (int argc, char *argv[]) {
	int i=2,j=3,k=4;
	cout<<i<<" "<<&i<<endl;
	cout<<j<<" "<<&j<<endl;
	cout<<k<<" "<<&k<<endl;
	cout<<g<<" "<<&g<<endl;
	
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	cout<<a<<" "<<a+1<<" "<<&a<<" "<<&a+1<<endl;
	
	cout<<i<<" "<<&i<<endl;//0x6eff0c
	int *ptrI=&i;
	char *ptrC;
	double *ptrD;
	cout<<*ptrI<<" "<<ptrI<<endl;
	cout<<"size of Pointer :"<<sizeof(ptrI)<<" "<<sizeof(ptrC)<<" "<<sizeof(ptrD)<<endl;
//	*((int*)0x6eff0c)=9;
//	cout<<i<<" "<<&i<<endl;
	
	char*p1=NULL;
	char*p2=NULL;
	p1=getStr1();
	p2=getStr2();
	cout<<p1<<" "<<p2<<endl;
	cout<<&p1<<" "<<&p2<<endl;
	printf("&p1:%s  &p2:%s\n",p1,p2);
	printf("&p1:%xd  &p2:%xd\n",p1,p2);
	cout<<getStr4()<<" "<<getStr3()<<endl;
	//cout<<getStr3()<<" "<<getStr4()<<endl;
	
	cout<<"P4 "<<endl;
	char*p4=getStr4();
	cout<<p4<<" "<<*p4<<endl;
	free(p4);
	free(p4);
	return 0;
}

