#include<iostream>
#include"Josephus.h"

using namespace std;

int main (int argc, char *argv[]) {
	Josephus jose(41,3,1);
	cout << "��ʼ��JosephusȦ��\n";	jose.display();
	jose.deleteElement();
	cout << "����JosephusȦ��";
	jose.display();
	return 0;
}

