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


//----------------------------Undergraduate类的函数实现-----------------------------------


//Undergraduate类的构造函数
Undergraduate::Undergraduate(int IDTemp,string nameTemp,string genderTemp,int gradeTemp,int majorIDTemp, string majorTemp,int classIDTemp, string classNameTemp,float higherMath,float english,float c):Student(IDTemp,nameTemp,genderTemp,gradeTemp,majorIDTemp,majorTemp,classIDTemp,classNameTemp,3)
{
	score.set_score(higherMath,english,c);
}

//Undergraduate类的构造函数
Undergraduate::Undergraduate():Student('1',3)
{	}

//展示一位本科生信息
void Undergraduate::display_a_student()
{
	cout.setf(ios::left);
	cout<<"       "<<setw(6)<<ID<<" "<<setw(6)<<name<<"     "<<setw(5)<<gender<<" "<<grade<<"    "<<setw(15)<<major<<setw(21)<<className<<"       #               "<<setw(9)<<score.get_scores(0)<<"       "<<setw(9)<<score.get_scores(1)<<"      "<<setw(10)<<score.get_scores(2)<<"       "<<setw(9)<<score.get_sumScore()<<"       "<<setw(9)<<classRank<<"       "<<setw(9)<<gradeRank<<endl<<endl;
}

//在管理某个班级中设置学生信息
bool Undergraduate::set_information_to_class()
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
	cout<<endl<<"                                                                               高数 成绩: ";
	cin>>temp;         //设置学生高数成绩
	if(temp.compare("E")==0)
		return false;
	else	
		score.get_scores(0) = calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                               英语 成绩: ";
	cin>>temp;         //设置学生英语成绩
	if(temp.compare("E")==0)
		return false;
	else		
		score.get_scores(1) = calculateString.calculate_real_number(temp);	
	cout<<endl<<"                                                                               C语言成绩: ";
	cin>>temp;         //设置学生C语言成绩
	if(temp.compare("E")==0)
		return false;
	else		
		score.get_scores(2) = calculateString.calculate_real_number(temp);
}

//重载运算符=
void Undergraduate::operator =( Undergraduate &u )
{
	score=u.score;
	ID=u.ID;
	name=u.name;
	gender=u.gender;
	grade=u.grade;
	majorID=u.majorID;
	major=u.major;
	classID=u.classID;
	className=u.className;
	classRank=u.classRank;
	gradeRank=u.classRank;
}