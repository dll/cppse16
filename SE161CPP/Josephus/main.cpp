#include<iostream>
#include"Josephus.h"

using namespace std;

int main (int argc, char *argv[]) {
	Josephus jose(41,3,1);
	cout << "初始的Josephus圈：\n";	jose.display();
	jose.deleteElement();
	cout << "最后的Josephus圈：";
	jose.display();
	return 0;
}

