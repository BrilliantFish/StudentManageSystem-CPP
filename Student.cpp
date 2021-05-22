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


//------------------------------Student类的函数实现---------------------------------------

//Student类的构造函数
Student::Student(int IDTemp,string nameTemp,string genderTemp,int gradeTemp,int majorIDTemp, string majorTemp,int classIDTemp, string classNameTemp,int countSubjectTemp):score(countSubjectTemp)
{
	ID=IDTemp;
	name=nameTemp;
	gender=genderTemp;
	grade=gradeTemp;
	majorID=majorIDTemp;
	major=majorTemp;
	classID=classIDTemp;
	className=classNameTemp;
	classRank=-1;
	gradeRank=-1;
}

//Student类的构造函数
Student::Student(char kindStudent='1',int countSubject=0):score(countSubject)
{
	classRank=-1;
	gradeRank=-1;
}

//获取学生学号
int &Student::get_ID()
{
	return ID;
}

//获取学生姓名
string Student::get_name()
{
	return name;
}

//获取学生性别
string Student::get_gender()
{
	return gender;
}

//获取学生年级
int Student::get_grade()
{
	return grade;
}

//获取学生专业编号
int &Student::get_majorID()
{
	return majorID;
}

//获取学生专业
string &Student::get_major()
{
	return major;
}

//获取学生班级编号
long int &Student::get_classID()
{
	return classID;
}

//获取学生班级
string &Student::get_className()
{
	return className;
}

//获取学生班级排名
int &Student::get_classRank()
{
	return classRank;
}

//获取学生年级排名
int &Student::get_gradeRank()
{
	return gradeRank;
}

//获取学生某科目分数
int Student::get_score(int subject)
{
	return score.get_scores(subject);
}

//获取总分
int Student::get_sumScore()
{
	return score.get_sumScore();
}

//设置学生信息
bool Student::set_information( int kindStudent)
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
	cout<<endl<<"                                                                               专业 编号: ";
	cin>>temp;             //设置学生专业编号
	if(temp.compare("E")==0)
		return false;
	else
		majorID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                               专     业: ";
	cin>>temp;             //设置学生专业
	if(temp.compare("E")==0)
		return false;
	else
		major=temp;
	cout<<endl<<"                                                                               班级 编号: ";
	cin>>temp;             //设置学生班级编号
	if(temp.compare("E")==0)
		return false;
	else
		classID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                               班     级: ";
	cin>>temp;             //设置学生班级
	if(temp.compare("E")==0)
		return false;
	else
		className=temp;
	if(kindStudent==1){
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
	else if( kindStudent){
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
	}
	cout<<endl;
	return true;

}

//设置学号
bool Student::set_ID()
{
	string temp;
	int n=0;
	cout<<endl<<endl;
	do{
		if(ID!=-1){
			cout<<"                                                                              请重新输入学号：";
			cin>>temp;
			cout<<endl;
		}
		else{
			cout<<"                                                                    无该学号，请重新输入学号：";
			cin>>temp;
			cout<<endl;
		}
		if(temp.compare("E")==0)
			return false;
		else {
			n=calculateString.calculate_real_number(temp);
		}
	}while(n==-1);

	ID=calculateString.calculate_real_number(temp);
	return true;
}

//设置姓名
bool Student::set_name()
{
	string temp;
	cout<<endl<<endl;
	cout<<"                                                                              请重新输入姓名：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else {
		name=temp;
		return true;
	}
}

//设置性别
bool Student::set_gender()
{
	string temp;
	cout<<endl<<endl;
	cout<<"                                                                              请重新输入性别：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else {
		gender=temp;
		return true;
	}
}

//设置年级
bool Student::set_grade()
{
	string temp;
	int n=0;
	cout<<endl<<endl;
	do{
		if(n!=-1){
			cout<<"                                                                              请重新输入年级：";
			cin>>temp;
			cout<<endl;
		}
		else{
			cout<<"                                                                    无该年级，请重新输入年级：";
			cin>>temp;
			cout<<endl;
		}
		if(temp.compare("E")==0)
			return false;
		else {
			n=calculateString.calculate_real_number(temp);
		}
	}while(n==-1);
	grade=calculateString.calculate_real_number(temp);
	return true;
}

//设置专业
bool Student::set_major()
{
	string temp;
	cout<<endl<<endl;
	cout<<"                                                                              请重新输入专业：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else {
		major=temp;
		return true;
	}
}

//设置班级
bool Student::set_class()
{
	string temp;
	cout<<endl<<endl;
	cout<<"                                                                              请重新输入班级名称：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else {
		className=temp;
		return true;
	}
}

//设置分数
bool Student::set_score(int kindStudent,int number)
{
	string temp;
	int n=0;
	cout<<endl<<endl;
	if(kindStudent==1){
		if(number==1){
			do{
				if(n!=-1){
					cout<<"                                                                              请重新输入高数成绩：";
					cin>>temp;
					cout<<endl;
				}
				else{
					cout<<"                                                                无该高数成绩，请重新输入高数成绩：";
					cin>>temp;
					cout<<endl;
				}
				if(temp.compare("E")==0)
					return false;
				else {
					n=calculateString.calculate_real_number(temp);
				}
			}while(n==-1);
			n=calculateString.calculate_real_number(temp);
			score.get_scores(0)=n;
			return true;
		}
		else if(number==2){
			do{
				if(n!=-1){
					cout<<"                                                                              请重新输入英语成绩：";
					cin>>temp;
					cout<<endl;
				}
				else{
					cout<<"                                                                无该英语成绩，请重新输入英语成绩：";
					cin>>temp;
					cout<<endl;
				}
				if(temp.compare("E")==0)
					return false;
				else {
					n=calculateString.calculate_real_number(temp);
				}
			}while(n==-1);
			n=calculateString.calculate_real_number(temp);
			score.get_scores(1)=n;
			return true;
		}
		else if(number==3){
			do{
				if(n!=-1){
					cout<<"                                                                              请重新输入C语言成绩：";
					cin>>temp;
					cout<<endl;
				}
				else{
					cout<<"                                                               无该C语言成绩，请重新输入C语言成绩：";
					cin>>temp;
					cout<<endl;
				}
				if(temp.compare("E")==0)
					return false;
				else {
					n=calculateString.calculate_real_number(temp);
				}
			}while(n==-1);
			n=calculateString.calculate_real_number(temp);
			score.get_scores(2)=n;
			return true;
		}
	}
	else if(kindStudent==2){
		if(number==1){
			do{
				if(n!=-1){
					cout<<"                                                                              请重新输入课程成绩：";
					cin>>temp;
					cout<<endl;
				}
				else{
					cout<<"                                                                无该课程成绩，请重新输入课程成绩：";
					cin>>temp;
					cout<<endl;
				}
				if(temp.compare("E")==0)
					return false;
				else {
					n=calculateString.calculate_real_number(temp);
				}
			}while(n==-1);
			n=calculateString.calculate_real_number(temp);
			score.get_scores(0)=n;
			return true;
		}
		else if(number==2){
			do{
				if(n!=-1){
					cout<<"                                                                              请重新输入论文成绩：";
					cin>>temp;
					cout<<endl;
				}
				else{
					cout<<"                                                                无该论文成绩，请重新输入论文成绩：";
					cin>>temp;
					cout<<endl;
				}
				if(temp.compare("E")==0)
					return false;
				else {
					n=calculateString.calculate_real_number(temp);
				}
			}while(n==-1);
			n=calculateString.calculate_real_number(temp);
			score.get_scores(1)=n;
			return true;
		}
	}
}





