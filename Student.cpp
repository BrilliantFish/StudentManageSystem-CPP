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


//------------------------------Student��ĺ���ʵ��---------------------------------------

//Student��Ĺ��캯��
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

//Student��Ĺ��캯��
Student::Student(char kindStudent='1',int countSubject=0):score(countSubject)
{
	classRank=-1;
	gradeRank=-1;
}

//��ȡѧ��ѧ��
int &Student::get_ID()
{
	return ID;
}

//��ȡѧ������
string Student::get_name()
{
	return name;
}

//��ȡѧ���Ա�
string Student::get_gender()
{
	return gender;
}

//��ȡѧ���꼶
int Student::get_grade()
{
	return grade;
}

//��ȡѧ��רҵ���
int &Student::get_majorID()
{
	return majorID;
}

//��ȡѧ��רҵ
string &Student::get_major()
{
	return major;
}

//��ȡѧ���༶���
long int &Student::get_classID()
{
	return classID;
}

//��ȡѧ���༶
string &Student::get_className()
{
	return className;
}

//��ȡѧ���༶����
int &Student::get_classRank()
{
	return classRank;
}

//��ȡѧ���꼶����
int &Student::get_gradeRank()
{
	return gradeRank;
}

//��ȡѧ��ĳ��Ŀ����
int Student::get_score(int subject)
{
	return score.get_scores(subject);
}

//��ȡ�ܷ�
int Student::get_sumScore()
{
	return score.get_sumScore();
}

//����ѧ����Ϣ
bool Student::set_information( int kindStudent)
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
	cout<<endl<<"                                                                               רҵ ���: ";
	cin>>temp;             //����ѧ��רҵ���
	if(temp.compare("E")==0)
		return false;
	else
		majorID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                               ר     ҵ: ";
	cin>>temp;             //����ѧ��רҵ
	if(temp.compare("E")==0)
		return false;
	else
		major=temp;
	cout<<endl<<"                                                                               �༶ ���: ";
	cin>>temp;             //����ѧ���༶���
	if(temp.compare("E")==0)
		return false;
	else
		classID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                               ��     ��: ";
	cin>>temp;             //����ѧ���༶
	if(temp.compare("E")==0)
		return false;
	else
		className=temp;
	if(kindStudent==1){
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
	else if( kindStudent){
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
	}
	cout<<endl;
	return true;

}

//����ѧ��
bool Student::set_ID()
{
	string temp;
	int n=0;
	cout<<endl<<endl;
	do{
		if(ID!=-1){
			cout<<"                                                                              ����������ѧ�ţ�";
			cin>>temp;
			cout<<endl;
		}
		else{
			cout<<"                                                                    �޸�ѧ�ţ�����������ѧ�ţ�";
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

//��������
bool Student::set_name()
{
	string temp;
	cout<<endl<<endl;
	cout<<"                                                                              ����������������";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else {
		name=temp;
		return true;
	}
}

//�����Ա�
bool Student::set_gender()
{
	string temp;
	cout<<endl<<endl;
	cout<<"                                                                              �����������Ա�";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else {
		gender=temp;
		return true;
	}
}

//�����꼶
bool Student::set_grade()
{
	string temp;
	int n=0;
	cout<<endl<<endl;
	do{
		if(n!=-1){
			cout<<"                                                                              �����������꼶��";
			cin>>temp;
			cout<<endl;
		}
		else{
			cout<<"                                                                    �޸��꼶�������������꼶��";
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

//����רҵ
bool Student::set_major()
{
	string temp;
	cout<<endl<<endl;
	cout<<"                                                                              ����������רҵ��";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else {
		major=temp;
		return true;
	}
}

//���ð༶
bool Student::set_class()
{
	string temp;
	cout<<endl<<endl;
	cout<<"                                                                              ����������༶���ƣ�";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else {
		className=temp;
		return true;
	}
}

//���÷���
bool Student::set_score(int kindStudent,int number)
{
	string temp;
	int n=0;
	cout<<endl<<endl;
	if(kindStudent==1){
		if(number==1){
			do{
				if(n!=-1){
					cout<<"                                                                              ��������������ɼ���";
					cin>>temp;
					cout<<endl;
				}
				else{
					cout<<"                                                                �޸ø����ɼ�����������������ɼ���";
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
					cout<<"                                                                              ����������Ӣ��ɼ���";
					cin>>temp;
					cout<<endl;
				}
				else{
					cout<<"                                                                �޸�Ӣ��ɼ�������������Ӣ��ɼ���";
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
					cout<<"                                                                              ����������C���Գɼ���";
					cin>>temp;
					cout<<endl;
				}
				else{
					cout<<"                                                               �޸�C���Գɼ�������������C���Գɼ���";
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
					cout<<"                                                                              ����������γ̳ɼ���";
					cin>>temp;
					cout<<endl;
				}
				else{
					cout<<"                                                                �޸ÿγ̳ɼ�������������γ̳ɼ���";
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
					cout<<"                                                                              �������������ĳɼ���";
					cin>>temp;
					cout<<endl;
				}
				else{
					cout<<"                                                                �޸����ĳɼ����������������ĳɼ���";
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





