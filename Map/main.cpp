#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <iterator>
#include <cstdio>
using namespace std;

class Speaker{
public:
	Speaker(){
		m_name = "";
		memset(m_score, 0 ,3*sizeof(int));//?ʹ��memset��
	}
public://?˼��
	string m_name;
	int m_score[3];
};
//����ѡ��
int GenSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v){
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//26(24)
	random_shuffle(str.begin(), str.end());//ϴ���㷨��
	
	for (int i = 0; i < 24; i++){
		Speaker tmp;
		tmp.m_name = "ѡ��";
		tmp.m_name = tmp.m_name + str[i];
		mapSpeaker.insert(pair<int, Speaker>(100 + i, tmp));//ѡ�ַŽ�map 122ѡ��W 67
	}
	for (int i = 0; i < 24; i++)
		v.push_back(100 + i);//�μӱ��α���ѡ������
	
	return 0;
}
//ѡ�ֳ�ǩ
int speech_contest_draw(vector<int> &v){
	random_shuffle(v.begin(), v.end());	
	return 0;
}
//ѡ�ֱ���������ͼ��
int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2)
{
	//5.С������÷� ��¼���� ���ǰ���� ������
	multimap<int, int, greater<int>> multmapGroup;
	int tmpCount = 0;
	int tmpIndex = index - 1;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
		tmpCount++;
		//1. 10����ί���
		deque<int> dscore;
		for (int i = 0; i < 10; i++){
			int score = 50 + rand()%50;//���ֵ
			dscore.push_back(score);
		}
		//2. ����
		sort(dscore.begin(), dscore.end());
		//3. ȥ����߷ֺ���ͷ֣���ƽ��ֵ
		dscore.pop_back();//ɾ�����һ��Ԫ��
		dscore.pop_front();//ɾ����һ��Ԫ��
		int sum_score = accumulate(dscore.begin(), dscore.end(), 0);
		int average_score = sum_score/dscore.size();
		//4. //�÷ִ����������
		mapSpeaker[*it].m_score[tmpIndex] = average_score; 
		
		//6. ƽ����  ��� �Ž�����
		multmapGroup.insert(pair<int, int>(average_score, *it));
		
		//7. �������  6��һ��С��
		if(tmpCount % 6 == 0){
			cout<<"С��ı����ɼ���"<<endl;
			for (multimap<int, int>::iterator mit = multmapGroup.begin(); mit != multmapGroup.end(); mit++){
				//��� ���� �÷�
				cout << mit->second << '\t' << mapSpeaker[mit->second].m_name << '\t' << mit->first <<endl;
			}
			//8. ǰ�������� ����v2
			while (multmapGroup.size() > 3)	{
				multimap<int, int>::iterator mit1 = multmapGroup.begin();//multimapĬ���Ǵ�С����˳������ȥ��
				v2.push_back(mit1->second);//v2 ���ǰ������������ ���
				multmapGroup.erase(mit1);
			}
			//9. ɾ�� ��С������ɼ�
			multmapGroup.clear();
		}
	}
	return 0;
	
};
//�������
int speech_contest_print(int index, vector<int> &v, map<int, Speaker> &mapSpeaker){
	
	printf("**��%d�ֱ��� ��������**:\n", index);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)	{
		//��� ���� ����
		cout<<"��ţ�"<<*it<<'\t'<<mapSpeaker[*it].m_name<<'\t'<<mapSpeaker[*it].m_score[index-1]<<endl;
	}
	return 0;
}

int main(){
	int contest_flag = 1;
	//�������ݽṹ������ѡ�ַŵ�������
	map<int, Speaker> mapSpeaker;
	vector<int> v1;//��1���ݽ���������
	vector<int> v2;//��2���ݽ���������
	vector<int> v3;//��3���ݽ���������
	vector<int> v4;// ���ǰ���� �ݽ���������
	
	//����ѡ��
	GenSpeaker(mapSpeaker, v1);
	
	cout<<"\n\n*****����1����ʼ��1�ֱ���*****"<<endl;
	int a = 0;
	while (contest_flag){
		//������ж�
		char c = cin.get();
		if ( (c >= '0') && (c <= '9') ){
			cin.putback (c);
			cin >> a;
		}
		if ((a == 1)&&(contest_flag == 1)){
			contest_flag = 2;
			speech_contest_draw(v1);
			speech_contest(1, v1, mapSpeaker, v2);
			speech_contest_print(1, v2, mapSpeaker);
			cout<<"\n\n*****����2����ʼ��2�ֱ���*****"<<endl;
		}
		if((a == 2)&&(contest_flag == 2)){
			contest_flag = 3;
			speech_contest_draw(v2);
			speech_contest(2, v2, mapSpeaker, v3);
			speech_contest_print(2, v3, mapSpeaker); 
			cout<<"\n\n*****����3����ʼ��3�ֱ���*****"<<endl;
		}
		if((a == 3)&&(contest_flag == 3)){
			contest_flag = 0;
			speech_contest_draw(v3);
			speech_contest(3, v3, mapSpeaker, v4);
			speech_contest_print(3, v4, mapSpeaker); 
		}
	}
	
	cout<<"\n\nend"<<endl;
	system("pause");
	return 0;
}
