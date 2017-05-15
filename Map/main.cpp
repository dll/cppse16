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
		memset(m_score, 0 ,3*sizeof(int));//?使用memset？
	}
public://?思考
	string m_name;
	int m_score[3];
};
//产生选手
int GenSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v){
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//26(24)
	random_shuffle(str.begin(), str.end());//洗牌算法？
	
	for (int i = 0; i < 24; i++){
		Speaker tmp;
		tmp.m_name = "选手";
		tmp.m_name = tmp.m_name + str[i];
		mapSpeaker.insert(pair<int, Speaker>(100 + i, tmp));//选手放进map 122选手W 67
	}
	for (int i = 0; i < 24; i++)
		v.push_back(100 + i);//参加本次比赛选手名单
	
	return 0;
}
//选手抽签
int speech_contest_draw(vector<int> &v){
	random_shuffle(v.begin(), v.end());	
	return 0;
}
//选手比赛，流程图？
int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2)
{
	//5.小组比赛得分 记录下来 求出前三名 后三名
	multimap<int, int, greater<int>> multmapGroup;
	int tmpCount = 0;
	int tmpIndex = index - 1;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
		tmpCount++;
		//1. 10个评委打分
		deque<int> dscore;
		for (int i = 0; i < 10; i++){
			int score = 50 + rand()%50;//随机值
			dscore.push_back(score);
		}
		//2. 排序
		sort(dscore.begin(), dscore.end());
		//3. 去除最高分和最低分，求平均值
		dscore.pop_back();//删除最后一个元素
		dscore.pop_front();//删除第一个元素
		int sum_score = accumulate(dscore.begin(), dscore.end(), 0);
		int average_score = sum_score/dscore.size();
		//4. //得分存放在容器中
		mapSpeaker[*it].m_score[tmpIndex] = average_score; 
		
		//6. 平均分  编号 放进容器
		multmapGroup.insert(pair<int, int>(average_score, *it));
		
		//7. 处理分组  6人一个小组
		if(tmpCount % 6 == 0){
			cout<<"小组的比赛成绩："<<endl;
			for (multimap<int, int>::iterator mit = multmapGroup.begin(); mit != multmapGroup.end(); mit++){
				//编号 姓名 得分
				cout << mit->second << '\t' << mapSpeaker[mit->second].m_name << '\t' << mit->first <<endl;
			}
			//8. 前三名晋级 放在v2
			while (multmapGroup.size() > 3)	{
				multimap<int, int>::iterator mit1 = multmapGroup.begin();//multimap默认是从小到大顺序插入进去的
				v2.push_back(mit1->second);//v2 存放前三名晋级名单 编号
				multmapGroup.erase(mit1);
			}
			//9. 删除 本小组比赛成绩
			multmapGroup.clear();
		}
	}
	return 0;
	
};
//比赛结果
int speech_contest_print(int index, vector<int> &v, map<int, Speaker> &mapSpeaker){
	
	printf("**第%d轮比赛 晋级名单**:\n", index);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)	{
		//编号 姓名 分数
		cout<<"编号："<<*it<<'\t'<<mapSpeaker[*it].m_name<<'\t'<<mapSpeaker[*it].m_score[index-1]<<endl;
	}
	return 0;
}

int main(){
	int contest_flag = 1;
	//定义数据结构，所有选手放到容器中
	map<int, Speaker> mapSpeaker;
	vector<int> v1;//第1轮演讲比赛名单
	vector<int> v2;//第2轮演讲比赛名单
	vector<int> v3;//第3轮演讲比赛名单
	vector<int> v4;// 最后前三名 演讲比赛名单
	
	//产生选手
	GenSpeaker(mapSpeaker, v1);
	
	cout<<"\n\n*****输入1，开始第1轮比赛*****"<<endl;
	int a = 0;
	while (contest_flag){
		//输入的判断
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
			cout<<"\n\n*****输入2，开始第2轮比赛*****"<<endl;
		}
		if((a == 2)&&(contest_flag == 2)){
			contest_flag = 3;
			speech_contest_draw(v2);
			speech_contest(2, v2, mapSpeaker, v3);
			speech_contest_print(2, v3, mapSpeaker); 
			cout<<"\n\n*****输入3，开始第3轮比赛*****"<<endl;
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
