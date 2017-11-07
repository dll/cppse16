#include <stdio.h>
#include <stdlib.h>

void fun1(){printf("call fun 1");}//功能函数
void fun2(){printf("call fun 2");}
void fun3(){printf("call fun 3");}
void funn(){printf("call fun n");}//n代表某个函数

void funn1(){printf("call fun n1");}//新增此函数，往往会写到动态链接库中
void funn2(){printf("call fun n2");}
/*
每新增功能，需添加一个新菜单，在24行添加，25行改4为5,32行添加,39行5改为6共4处修改
*/
void SwitchCaseMenu(){
	printf("\nSwitch Case Menu Demo");
	int mainchoice = 1;
	do {
		while(1){
			printf("\
				\n1:fun 1\n\
				\n2:fun 2\n\
				\n3:fun 3\n\
				\n4:fun n\n\
				\n5:fun n1\n\
				\nChoice(1--5),0 quit");
			scanf("%d", &mainchoice);
			switch(mainchoice){
				case 1:fun1();break;
				case 2:fun2();break;
				case 3:fun3();break;
				case 4:funn();break;
				case 5:funn1();break;
				case 0:exit(0);
				default:printf("Input[ %d ]Error!ReEnter!\n",mainchoice);
			}
			system("pause");
			system("cls");
		}
	}while (mainchoice <6 && mainchoice > -1);
}	

struct FPMENU{
	void (*funPointer)(void); //int *p;
	char menu[20];
}mainMenu[] = {   
	{ fun1, "fun 1"},
	{ fun2, "fun 2"},
	{ fun3, "fun 3"},
	{ funn, "fun n"}, 
	{ funn1,"fun n1"},
	{ funn2,"fun n2"},
	{ NULL, ""}      
};
/*
每新增功能，需添加一个新菜单，仅在50行添加，共1处修改
*/
void FunPointerMenu(void){
	int idx,i;
	while(1){   
		printf("\n\t\t==============================\n");
		printf("\t\t| Function Pointer Menu Demo |\n");
		printf("\t\t------------------------------\n");
		for(i=0; mainMenu[i].funPointer!=NULL; i++)
			printf("\t\t| %2d:  %-18s    |\n", i+1, mainMenu[i].menu);
			
		printf("\t\t==============================\n");
		printf("\tEnter Number To Choice Menu([0]Quit):");
		scanf("%d",&idx);
		
		if(idx<=i){	
			if(0==idx)
				exit(0);
			(*mainMenu[idx-1].funPointer)();//使用函数指针调用功能函数
		}
		else printf("\tInput[ %d ]Error!;ReEnter!\n", idx);
	}
}

int main(int argc, char *argv[]) {
	
	//SwitchCaseMenu();
	FunPointerMenu();
	return 0;
}
/*
==============================
| Function Pointer Menu Demo |
------------------------------
|  1:  fun 1                 |
|  2:  fun 2                 |
|  3:  fun 3                 |
|  4:  fun n                 |
|  5:  fun n1                |
==============================
Enter Number To Choice Menu([0]Quit):1
call fun 1
*/
