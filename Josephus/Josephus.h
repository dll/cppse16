#ifndef JOSEPHUS_H
#define JOSEPHUS_H
#include <list>
#include <vector>
#include <fstream>
#include<cstdlib>
#include<ctime>

#include <queue>

	int listSize;	// Ԫ�ظ���
	int steps;		// ����
	int first;		// ��1�˱�����λ��
	static list<int> josephusList;// ����
	vector<int> josephusSeq;
	static queue<int> josephusQueue;//����
public:
//	JosephusProblem(){}
	JosephusProblem(int,int,int first=1);	// ���캯��
	void deleteElement();	// ɾ��Ԫ��
	void display();			// ��ʾȫ��Ԫ��		// ��ʾȫ��Ԫ��
	void saveJosephusSeq();
	friend void makeTestPapers(vector<JosephusProblem*> testPapers,int tps, int ls);
	void makeJosephusSeq();	// ��������
	
	void JosephusQueue();//STL queueʵ��Լɪ������
#endif
