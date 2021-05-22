#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;
#include "Menu.h"
#include "Calculate String.h"
#include "Score.h"
#include "Student.h"
#include "Undergraduate.h"
#include "Graduate.h"
//----------------------------Graduate类的函数实现---------------------------------------

//Graduate类的构造函数
Graduate::Graduate():Student('1',2)
{}

//Graduate类的构造函数
Graduate::Graduate(int IDTemp,string nameTemp,string genderTemp,int gradeTemp,int majorIDTemp, string majorTemp,int classIDTemp, string classNameTemp,string researchTopicTemp,string tutorTemp,float lesson,float thesis):Student(IDTemp,nameTemp,genderTemp,gradeTemp,majorIDTemp,majorTemp,classIDTemp,classNameTemp,2)
{
	researchTopic=researchTopicTemp;
	tutor=tutorTemp;
	score.set_score(lesson,thesis,0);
}

//获取研究生研究课题
string Graduate::get_researchTopic()
{
	return researchTopic;
}

//获取研究生导师
string Graduate::get_tutor()
{
	return tutor;
}

//展示一位研究生信息
void Graduate::display_a_student()
{
	cout.setf(ios::left);
	cout<<"     "<<setw(4)<<ID<<"  "<<setw(7)<<name<<"  "<<setw(5)<<gender<<" "<<grade<<"    "<<setw(16)<<major<<setw(21)<<className<<"          "<<setw(19)<<researchTopic<<"  "<<setw(10)<<tutor<<"      #           "<<setw(8)<<score.get_scores(0)<<"   "<<setw(7)<<score.get_scores(1)<<"     "<<setw(9)<<score.get_sumScore()<<"     "<<setw(9)<<classRank<<"     "<<setw(9)<<gradeRank<<endl;
}

//设置研究课题
bool Graduate::set_researchTopic()
{
	cout<<endl<<endl;
	string temp;
	cout<<"                                                                              请重新输入研究课题：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else {
		researchTopic=temp;
		return true;
	}
}

//设置导师
bool Graduate::set_tutor()
{
	string temp;
	cout<<endl<<endl;
	cout<<"                                                                              请重新输入导师：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else {
		tutor=temp;
		return true;
	}
}

//重载运算符=
void Graduate::operator =( Graduate &g )
{
	score=g.score;
	ID=g.ID;
	name=g.name;
	gender=g.gender;
	grade=g.grade;
	majorID=g.majorID;
	major=g.major;
	classID=g.classID;
	className=g.className;
	classRank=g.classRank;
	gradeRank=g.classRank;
	researchTopic=g.researchTopic;
	tutor=g.tutor;
}

//在管理某个班级中设置学生信息
bool Graduate::set_information_to_class()
{
	string temp;
	cout<<endl<<"                                                                               学     号: ";
	cin>>temp;              //设置学生学号
	if(temp.compare("E")==0)
		return false;
	else
		ID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                               姓     名: ";
	cin>>temp;              //设置学生姓名
	if(temp.compare("E")==0)
		return false;
	else
		name=temp;

	cout<<endl<<"                                                                               性     别: ";
	cin>>temp;              //设置学生性别
	if(temp.compare("E")==0)
		return false;
	else
		gender=temp;

	cout<<endl<<"                                                                               年     级: ";
	cin>>temp;              //设置学生年级
	if(temp.compare("E")==0)
		return false;
	else
		grade=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                               研究 课题: ";
	cin>>temp;         //设置学生研究课题
	if(temp.compare("E")==0)
		return false;
	else	
		researchTopic=temp; 
	cout<<endl<<"                                                                               导     师: ";
	cin>>temp;         //设置学生英语成绩
	if(temp.compare("E")==0)
		return false;
	else		
		tutor=temp;	

	cout<<endl<<"                                                                               课程 成绩: ";
	cin>>temp;         //设置学生课程成绩
	if(temp.compare("E")==0)
		return false;
	else
		score.get_scores(0) = calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                               论文 成绩: ";
	cin>>temp;         //设置学生论文成绩
	if(temp.compare("E")==0)
		return false;
	else		
		score.get_scores(1) = calculateString.calculate_real_number(temp);
	cout<<endl;
	return true;
}