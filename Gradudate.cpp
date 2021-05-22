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
//----------------------------Graduate��ĺ���ʵ��---------------------------------------

//Graduate��Ĺ��캯��
Graduate::Graduate():Student('1',2)
{}

//Graduate��Ĺ��캯��
Graduate::Graduate(int IDTemp,string nameTemp,string genderTemp,int gradeTemp,int majorIDTemp, string majorTemp,int classIDTemp, string classNameTemp,string researchTopicTemp,string tutorTemp,float lesson,float thesis):Student(IDTemp,nameTemp,genderTemp,gradeTemp,majorIDTemp,majorTemp,classIDTemp,classNameTemp,2)
{
	researchTopic=researchTopicTemp;
	tutor=tutorTemp;
	score.set_score(lesson,thesis,0);
}

//��ȡ�о����о�����
string Graduate::get_researchTopic()
{
	return researchTopic;
}

//��ȡ�о�����ʦ
string Graduate::get_tutor()
{
	return tutor;
}

//չʾһλ�о�����Ϣ
void Graduate::display_a_student()
{
	cout.setf(ios::left);
	cout<<"     "<<setw(4)<<ID<<"  "<<setw(7)<<name<<"  "<<setw(5)<<gender<<" "<<grade<<"    "<<setw(16)<<major<<setw(21)<<className<<"          "<<setw(19)<<researchTopic<<"  "<<setw(10)<<tutor<<"      #           "<<setw(8)<<score.get_scores(0)<<"   "<<setw(7)<<score.get_scores(1)<<"     "<<setw(9)<<score.get_sumScore()<<"     "<<setw(9)<<classRank<<"     "<<setw(9)<<gradeRank<<endl;
}

//�����о�����
bool Graduate::set_researchTopic()
{
	cout<<endl<<endl;
	string temp;
	cout<<"                                                                              �����������о����⣺";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else {
		researchTopic=temp;
		return true;
	}
}

//���õ�ʦ
bool Graduate::set_tutor()
{
	string temp;
	cout<<endl<<endl;
	cout<<"                                                                              ���������뵼ʦ��";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else {
		tutor=temp;
		return true;
	}
}

//���������=
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

//�ڹ���ĳ���༶������ѧ����Ϣ
bool Graduate::set_information_to_class()
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
	cout<<endl<<"                                                                               �о� ����: ";
	cin>>temp;         //����ѧ���о�����
	if(temp.compare("E")==0)
		return false;
	else	
		researchTopic=temp; 
	cout<<endl<<"                                                                               ��     ʦ: ";
	cin>>temp;         //����ѧ��Ӣ��ɼ�
	if(temp.compare("E")==0)
		return false;
	else		
		tutor=temp;	

	cout<<endl<<"                                                                               �γ� �ɼ�: ";
	cin>>temp;         //����ѧ���γ̳ɼ�
	if(temp.compare("E")==0)
		return false;
	else
		score.get_scores(0) = calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                               ���� �ɼ�: ";
	cin>>temp;         //����ѧ�����ĳɼ�
	if(temp.compare("E")==0)
		return false;
	else		
		score.get_scores(1) = calculateString.calculate_real_number(temp);
	cout<<endl;
	return true;
}