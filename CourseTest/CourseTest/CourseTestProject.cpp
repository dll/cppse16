#include "CourseTestProject.h"

vector<TestProject> CourseTestProject::initialTestProject;
vector<TestProject> CourseTestProject::finalTestProject;


void CourseTestProject::InitialTestProjectFromFile(){
	try{
		ifstream ifin("project.dat",ios::in);
		string no,name,proj;
		if (!ifin.is_open()){
			throw string("Read project.dat failed!");
		}
		while(ifin>>no>>name>>proj){
			TestProject tp;
			tp.stuNo=no;tp.stuName=name;tp.ctProject=proj;
			initialTestProject.push_back(tp);
			cout<<no<<" "<<setw(8)<<name<<" | "<<proj<<endl;
			tps.push_back(proj);
			stuprjNum++;
		}
		ifin.close();
	}catch(string const& s){
		cout << "Exception: " << s <<endl;
		system("pause");
		exit(1);
	}
}

void CourseTestProject::RandomShuffleTestProject(){
	
	finalTestProject=initialTestProject;
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
//	random_shuffle(tps.begin(), tps.end());	
	// 使用系统时钟作为种子
	shuffle(tps.begin(), tps.end(), default_random_engine(seed));
	int i;
	for(i=0;i<initialTestProject.size();i++){
		finalTestProject.at(i).ctProject=tps.at(i);
	}
	if(initialTestProject.size()<stuprjNum){
		
	}
}
const string getCurrentSystemTime()
{
	auto tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
	struct tm* ptm = localtime(&tt);
	char date[60] = {0};
	sprintf(date, "%d-%02d-%02d      %02d:%02d:%02d",
			(int)ptm->tm_year + 1900,(int)ptm->tm_mon + 1,(int)ptm->tm_mday,
			(int)ptm->tm_hour,(int)ptm->tm_min,(int)ptm->tm_sec);
	return string(date);
}

void CourseTestProject::FinalTestProjectOutput(){
	try{
		ofstream ofout("project.res",ios::out);
		ofout<<"    测绘工程161 《C++程序设计》课程设计项目表        "<<endl;
		ofout<<"======================================================"<<endl;
		for(TestProject testProject:finalTestProject){
			ofout<<testProject.stuNo<<" "<<setw(6)<<testProject.stuName\
				<<" "<<testProject.ctProject<<endl;
		}
		ofout<<"======================================================"<<endl;
		ofout<<getCurrentSystemTime()<<endl;
		ofout.close();
		system("notepad project.res");
		
	}catch(...){
		cout<<"Write project.res failed!"<<endl;
		system("pause");
		exit(1);
	}
	
}
