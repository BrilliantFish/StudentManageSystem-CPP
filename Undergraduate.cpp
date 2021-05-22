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


//----------------------------Undergraduate��ĺ���ʵ��-----------------------------------


//Undergraduate��Ĺ��캯��
Undergraduate::Undergraduate(int IDTemp,string nameTemp,string genderTemp,int gradeTemp,int majorIDTemp, string majorTemp,int classIDTemp, string classNameTemp,float higherMath,float english,float c):Student(IDTemp,nameTemp,genderTemp,gradeTemp,majorIDTemp,majorTemp,classIDTemp,classNameTemp,3)
{
	score.set_score(higherMath,english,c);
}

//Undergraduate��Ĺ��캯��
Undergraduate::Undergraduate():Student('1',3)
{	}

//չʾһλ��������Ϣ
void Undergraduate::display_a_student()
{
	cout.setf(ios::left);
	cout<<"       "<<setw(6)<<ID<<" "<<setw(6)<<name<<"     "<<setw(5)<<gender<<" "<<grade<<"    "<<setw(15)<<major<<setw(21)<<className<<"       #               "<<setw(9)<<score.get_scores(0)<<"       "<<setw(9)<<score.get_scores(1)<<"      "<<setw(10)<<score.get_scores(2)<<"       "<<setw(9)<<score.get_sumScore()<<"       "<<setw(9)<<classRank<<"       "<<setw(9)<<gradeRank<<endl<<endl;
}

//�ڹ���ĳ���༶������ѧ����Ϣ
bool Undergraduate::set_information_to_class()
{
	string temp;
	cout<<endl<<"                                                                               ѧ     ��: ";
	cin>>temp;              //����ѧ��ѧ��
	if(temp.compare("E")==0)
		return false;
	else
		ID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                               ��     ��: ";
	cin>>temp;              //����ѧ������
	if(temp.compare("E")==0)
		return false;
	else
		name=temp;

	cout<<endl<<"                                                                               ��     ��: ";
	cin>>temp;              //����ѧ���Ա�
	if(temp.compare("E")==0)
		return false;
	else
		gender=temp;

	cout<<endl<<"                                                                               ��     ��: ";
	cin>>temp;              //����ѧ���꼶
	if(temp.compare("E")==0)
		return false;
	else
		grade=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                               ���� �ɼ�: ";
	cin>>temp;         //����ѧ�������ɼ�
	if(temp.compare("E")==0)
		return false;
	else	
		score.get_scores(0) = calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                               Ӣ�� �ɼ�: ";
	cin>>temp;         //����ѧ��Ӣ��ɼ�
	if(temp.compare("E")==0)
		return false;
	else		
		score.get_scores(1) = calculateString.calculate_real_number(temp);	
	cout<<endl<<"                                                                               C���Գɼ�: ";
	cin>>temp;         //����ѧ��C���Գɼ�
	if(temp.compare("E")==0)
		return false;
	else		
		score.get_scores(2) = calculateString.calculate_real_number(temp);
}

//���������=
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