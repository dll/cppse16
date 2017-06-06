#include<iostream>
#include"Josephus.h"
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {
	JosephusProblem jose(41,3,1);
	cout << "初始的Josephus圈：\n";	jose.display();
	jose.deleteElement();
	cout << "最后的Josephus圈：";
	jose.display();
	jose.saveJosephusSeq();
	
	vector<JosephusProblem*> testPapers;
	makeTestPapers(testPapers, 41, 30);
	
	return 0;
}

