#ifndef JOSEPHUS_H
#define JOSEPHUS_H
#include <list>using namespace std;class Josephus{	private:		int listSize;	// 元素个数		int steps;		// 报数个数		int first;		// 第1人报的数		static list<int> josephusList;// 链表	public:		Josephus(int,int,int);	// 构造函数		void deleteElement();	// 删除元素		void display();			// 显示全部元素};
#endif

