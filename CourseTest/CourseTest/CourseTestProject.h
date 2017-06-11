#ifndef COURSETESTPROJECT_H
#define COURSETESTPROJECT_H

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>

using namespace std;

typedef struct tagTESTPROJECT{
	string stuNo;
	string stuName;
	string ctProject;
}TestProject;

class CourseTestProject {
private:
	int stuprjNum;
	static vector<TestProject> initialTestProject;
	static vector<TestProject> finalTestProject;
	vector<string> tps;
protected:
public:
	CourseTestProject(int sp){
		stuprjNum=sp;
		InitialTestProjectFromFile();
	}
	void InitialTestProjectFromFile();
	void RandomShuffleTestProject();
	void FinalTestProjectOutput();
};

#endif

