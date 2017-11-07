#ifndef JOSEPHUS_H
#define JOSEPHUS_H
#include <list>
#include <vector>
#include <fstream>
#include<cstdlib>
#include<ctime>

#include <queue>
using namespace std;class JosephusProblem{private:	
	int listSize;	// 元素个数
	int steps;		// 报数
	int first;		// 第1人报数的位置
	static list<int> josephusList;// 链表
	vector<int> josephusSeq;
	static queue<int> josephusQueue;//队列
public:
	JosephusProblem(int,int,int first=1);	// 构造函数
	int deleteElement();	// 删除元素
	void display();			// 显示全部元素		// 显示全部元素
	void saveJosephusSeq();
	friend void makeTestPapers(vector<JosephusProblem*> testPapers,int tps, int ls);
	void makeJosephusSeq();	// 生成序列
	
	void JosephusQueue();//STL queue实现约瑟夫环问题};
#endif

