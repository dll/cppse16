#ifndef JOSEPHUS_H
#define JOSEPHUS_H
#include <list>using namespace std;class Josephus{	private:		int listSize;	// Ԫ�ظ���		int steps;		// ��������		int first;		// ��1�˱�����		static list<int> josephusList;// ����	public:		Josephus(int,int,int);	// ���캯��		void deleteElement();	// ɾ��Ԫ��		void display();			// ��ʾȫ��Ԫ��};
#endif

