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
#include "ManageStudent.h"
#include "Class.h"
#include "ManageClass.h"
#include "Speciality.h"
#include "ManagerSpeciality.h"
#include "Interface.h"

//排序
bool compare_U(Undergraduate &p1,Undergraduate &p2){
	return p1.get_sumScore()>p2.get_sumScore();   //降序
}

bool compare_G(Graduate &p1,Graduate &p2){
	return p1.get_sumScore()>p2.get_sumScore();   //降序
}

//读取文件
void Interface::read_file(char *u="本科生.txt",char *g="研究生.txt",char *c="班级.txt",char *s="专业.txt")
{
	int IDTemp;
	string nameTemp;
	string genderTemp;
	int gradeTemp;
	int majorIDTemp;
	string majorTemp;
	long int classIDTemp;
	string classNameTemp;
	string researchTopicTemp;
	string tutorTemp;
	int scoreTemp[3];
	vector <Undergraduate> undergraduate;
	vector <Graduate> graduate;
	vector < Class <Undergraduate> > uClassTemp;
	vector < Class <Graduate> > gClassTemp;
	vector <int > recordID;
	vector <long int> recordClassID;
	int countAllClassID=0;
	vector < int > recordMajorID;
	int countAllMajorID=0;
	vector <int> recordGrade;
	int countAllGrade=0;

//---------------------------------------读取本科生文件---------------------------------------	
	ifstream inU(u);
	if(!inU){
		cout<<"error\n";
		exit(0);
	}

	inU.peek();
	while(!inU.eof()){
		inU>>IDTemp>>nameTemp>>genderTemp>>gradeTemp>>majorIDTemp>>majorTemp>>classIDTemp>>classNameTemp>>scoreTemp[0]>>scoreTemp[1]>>scoreTemp[2];
		Undergraduate uStu(IDTemp,nameTemp,genderTemp,gradeTemp,majorIDTemp,majorTemp,classIDTemp,classNameTemp,scoreTemp[0],scoreTemp[1],scoreTemp[2]);
		undergraduate.push_back(uStu);
		int cflag=0;
		for(int i=0;i<countAllClassID;i++){
			if(recordClassID[i]==classIDTemp){
				cflag=1;
				break;
			}
		}
		if(cflag==0){
			recordClassID.push_back(classIDTemp);
			countAllClassID++;
		}
		int sflag=0;
		for(int i=0;i<countAllMajorID;i++){
			if(recordMajorID[i]==majorIDTemp){
				sflag=1;
				break;
			}
		}
		if(sflag==0){
			recordMajorID.push_back(majorIDTemp);
			countAllMajorID++;
		}
		int gflag=0;
		for(int i=0;i<countAllGrade;i++){
			if(recordGrade[i]==gradeTemp){
				gflag=1;
				break;
			}
		}
		if(gflag==0){
			recordGrade.push_back(gradeTemp);
			countAllGrade++;
		}
		recordID.push_back(IDTemp);
	}
	inU.close();

	sort(undergraduate.begin(),undergraduate.end(),compare_U);
	vector <Undergraduate> ::iterator pU=undergraduate.begin();
	int i=0;
	int j=0;
	int k=0;
	for(i=0;i<countAllClassID;i++){
		int rankClass=1;
		int firstFlag=1;
		for(j=0;j<undergraduate.size();j++){
			if(undergraduate[j].get_classID()==recordClassID[i]){
				if(firstFlag==1){
					undergraduate[j].get_classRank()=rankClass;
					pU=undergraduate.begin()+j;
					firstFlag=0;
					rankClass++;
				}
				else{ 
					if(undergraduate[j].get_sumScore()==pU->get_sumScore()){
						undergraduate[j].get_classRank()=pU->get_classRank();
						pU=undergraduate.begin()+j;
						rankClass++;
					}
					else{
						undergraduate[j].get_classRank()=rankClass;
						pU=undergraduate.begin()+j;
						rankClass++;
					}
				}
			}
		}
	}
	for(i=0;i<countAllMajorID;i++){
		for(j=0;j<countAllGrade;j++){
			int firstFlag=1;
			int rankGrade=1;
			for(k=0;k<undergraduate.size();k++){
				if(undergraduate[k].get_majorID()==recordMajorID[i] && undergraduate[k].get_grade()==recordGrade[j]){
					if(firstFlag==1){
						undergraduate[k].get_gradeRank()=rankGrade;
						pU=undergraduate.begin()+k;
						firstFlag=0;
						rankGrade++;
					}
					else {
						if(undergraduate[k].get_sumScore()==pU->get_sumScore()){
							undergraduate[k].get_gradeRank()=pU->get_gradeRank();
							pU=undergraduate.begin()+k;
							rankGrade++;
						}
						else{
							undergraduate[k].get_gradeRank()=rankGrade;
							pU=undergraduate.begin()+k;
							rankGrade++;
						}
					}
				}
			}
		}
	}
	for(int u=0;u<undergraduate.size();u++){
		manageStudent.set_student(&undergraduate[u],NULL);
	}
//---------------------------------------读取研究生文件---------------------------------------
	recordClassID.clear();
	countAllClassID=0;
	recordMajorID.clear();
	countAllMajorID=0;
	recordGrade.clear();
	countAllGrade=0;

	ifstream inG(g);

	if(!inG){
		cout<<"error\n";
		exit(0);
	}
	inG.peek();
	while(!inG.eof()){
		inG>>IDTemp>>nameTemp>>genderTemp>>gradeTemp>>majorIDTemp>>majorTemp>>classIDTemp>>classNameTemp>>researchTopicTemp>>tutorTemp>>scoreTemp[0]>>scoreTemp[1];
		Graduate gStu(IDTemp,nameTemp,genderTemp,gradeTemp,majorIDTemp,majorTemp,classIDTemp,classNameTemp,researchTopicTemp,tutorTemp,scoreTemp[0],scoreTemp[1]);
		graduate.push_back(gStu);
		int cflag=0;
		for(int i=0;i<countAllClassID;i++){
			if(recordClassID[i]==classIDTemp){
				cflag=1;
				break;
			}
		}
		if(cflag==0){
			recordClassID.push_back(classIDTemp);
			countAllClassID++;
		}
		int sflag=0;
		for(int i=0;i<countAllMajorID;i++){
			if(recordMajorID[i]==majorIDTemp){
				sflag=1;
				break;
			}
		}
		if(sflag==0){
			recordMajorID.push_back(majorIDTemp);
			countAllMajorID++;
		}

		int gflag=0;
		for(int i=0;i<countAllGrade;i++){
			if(recordGrade[i]==gradeTemp){
				gflag=1;
				break;
			}
		}
		if(gflag==0){
			recordGrade.push_back(gradeTemp);
			countAllGrade++;
		}
		recordID.push_back(IDTemp);
	}
	inG.close();
	
	sort(graduate.begin(),graduate.end(),compare_G);
	vector <Graduate> ::iterator pG=graduate.begin();

	for(i=0;i<countAllClassID;i++){
		int rankClass=1;
		int firstFlag=1;
		for(j=0;j<graduate.size();j++){
			if(graduate[j].get_classID()==recordClassID[i]){
				if(firstFlag==1){
					graduate[j].get_classRank()=rankClass;
					pG=graduate.begin()+j;
					firstFlag=0;
					rankClass++;
				}
				else{
					if(graduate[j].get_sumScore()==pG->get_sumScore()){
						graduate[j].get_classRank()=pG->get_classRank();
						pG=graduate.begin()+j;
						rankClass++;
					}
					else{
						graduate[j].get_classRank()=rankClass;
						pG=graduate.begin()+j;
						rankClass++;
					}
				}
			}
		}
	}
	for(i=0;i<countAllMajorID;i++){
		for(j=0;j<countAllGrade;j++){
			int firstFlag=1;
			int rankGrade=1;
			for(k=0;k<graduate.size();k++){
				if(graduate[k].get_majorID()==recordMajorID[i] && graduate[k].get_grade()==recordGrade[j]){
					if(firstFlag==1){
						graduate[k].get_gradeRank()=rankGrade;
						pG=graduate.begin()+j;
						firstFlag=0;
						rankGrade++;
					}
					else {
						if(graduate[k].get_sumScore()==pG->get_sumScore()){
							graduate[k].get_gradeRank()=pG->get_gradeRank();
							pG=graduate.begin()+j;
							rankGrade++;
						}
						else{
							graduate[k].get_gradeRank()=rankGrade;
							pG=graduate.begin()+j;
							rankGrade++;
						}
					}
				}
			}
		}
	}
	for(int g=0;g<graduate.size();g++){
		manageStudent.set_student(NULL,&graduate[g]);
	}
	for(int i=0;i<recordID.size();i++){
		manageStudent.set_recordID(recordID[i]);
	}
//---------------------------------------读取班级信息文件---------------------------------------
	recordClassID.clear();
	ifstream inC(c);
	if(!inC){
		cout<<"error\n";
		exit(0);
	}
	inC.peek();
	while(!inC.eof()){
		inC>>classIDTemp>>classNameTemp>>majorIDTemp;
		Class <Undergraduate> classTemp1(classIDTemp,classNameTemp,majorIDTemp);
		vector <Undergraduate> ::iterator pU=undergraduate.begin();
		if(classIDTemp/1000000==2){
			for(;pU!=undergraduate.end();pU++){
				if(classTemp1.get_classID()==pU->get_classID()){
					classTemp1.set_classmates(&(*pU));
				}
			}
			manageClass.set_class(&classTemp1,NULL);
			uClassTemp.push_back(classTemp1);
		}
		Class <Graduate> classTemp2(classIDTemp,classNameTemp,majorIDTemp);
		vector <Graduate> ::iterator pG=graduate.begin();
		if(classIDTemp/1000000==9){
			for(;pG!=graduate.end();pG++){
				if(classTemp2.get_classID()==pG->get_classID()){
					classTemp2.set_classmates(&(*pG));
				}
			}
			manageClass.set_class(NULL,&classTemp2);
			gClassTemp.push_back(classTemp2);
		}
		recordClassID.push_back(classIDTemp);
	}
	inC.close();
	for(int i=0;i<recordClassID.size();i++){
		manageClass.set_recordClassID(recordClassID[i]);
	}
	for(int i=0;i<recordID.size();i++){
		manageClass.set_recordID(recordID[i]);
	}
//---------------------------------------读取专业信息文件---------------------------------------
	recordMajorID.clear();
	ifstream inS(s);
	if(!inS){
		cout<<"error\n";
		exit(0);
	}
	inS.peek();
	while(!inS.eof()){
		inS>>majorIDTemp>>majorTemp;
		Speciality specialityTemp(majorIDTemp,majorTemp);	
		vector < Class <Undergraduate> > ::iterator pU=uClassTemp.begin();
		for(;pU!=uClassTemp.end();pU++){
			if(specialityTemp.get_majorID()==pU->get_majorID())
				specialityTemp.set_classes(&(*pU),NULL);		
		}
		vector <Class <Graduate> > ::iterator pG=gClassTemp.begin();
		for(;pG!=gClassTemp.end();pG++){
			if(specialityTemp.get_majorID()==pG->get_majorID())
				specialityTemp.set_classes(NULL,&(*pG));
		}
		manageSpeciality.set_speciality(specialityTemp);
		recordMajorID.push_back(majorIDTemp);
	}	
	inS.close();
	for(int i=0;i<recordMajorID.size();i++){
		manageSpeciality.set_recordMajorID(recordMajorID[i]);
	}
	for(int i=0;i<recordClassID.size();i++){
		manageSpeciality.set_recordClassID(recordClassID[i]);
	}
}

//保存信息
void Interface::save_file(char *u="本科生.txt",char *g="研究生.txt",char *c="班级.txt",char *s="专业.txt")
{
	ofstream outU(u);
	for(int i=0;i<manageStudent.get_countU();i++){
		outU.setf(ios::left);
		outU<<setw(2)<<manageStudent.get_undergraduate(i).get_ID()<<" "<<setw(6)<<manageStudent.get_undergraduate(i).get_name()<<" "<<manageStudent.get_undergraduate(i).get_gender()<<" "<<manageStudent.get_undergraduate(i).get_grade()<<" "<<manageStudent.get_undergraduate(i).get_majorID()<<" "<<setw(12)<<manageStudent.get_undergraduate(i).get_major()<<" "<<manageStudent.get_undergraduate(i).get_classID()<<" "<<setw(21)<<manageStudent.get_undergraduate(i).get_className()<<" "<<manageStudent.get_undergraduate(i).get_score(0)<<" "<<manageStudent.get_undergraduate(i).get_score(1)<<" "<<manageStudent.get_undergraduate(i).get_score(2);
		if(i!=manageStudent.get_countU()-1)
			outU<<"\n";
	}
	outU.close();

	ofstream outG(g);
	for(int i=0;i<manageStudent.get_countG();i++){
		outG.setf(ios::left);
		outG<<manageStudent.get_graduate(i).get_ID()<<" "<<manageStudent.get_graduate(i).get_name()<<" "<<manageStudent.get_graduate(i).get_gender()<<" "<<manageStudent.get_graduate(i).get_grade()<<" "<<manageStudent.get_graduate(i).get_majorID()<<" "<<manageStudent.get_graduate(i).get_major()<<" "<<manageStudent.get_graduate(i).get_classID()<<" "<<manageStudent.get_graduate(i).get_className()<<" "<<manageStudent.get_graduate(i).get_researchTopic()<<" "<<manageStudent.get_graduate(i).get_tutor()<<" "<<manageStudent.get_graduate(i).get_score(0)<<" "<<manageStudent.get_graduate(i).get_score(1);
		if(i!=manageStudent.get_countG()-1)
			outG<<"\n";
	}
	outG.close();

	ofstream outC(c);
	for(int i=0;i<manageClass.get_uCountClass();i++){
		outC.setf(ios::left);
		if(manageClass.get_gCountClass()!=0)
			outC<<manageClass.get_one_class_U(i).get_classID()<<" "<<setw(21)<<manageClass.get_one_class_U(i).get_className()<<" "<<manageClass.get_one_class_U(i).get_majorID()<<"\n";
		else{
			outC<<manageClass.get_one_class_U(i).get_classID()<<" "<<setw(21)<<manageClass.get_one_class_U(i).get_className()<<" "<<manageClass.get_one_class_U(i).get_majorID();
			if(i!=manageClass.get_uCountClass()-1)
				outC<<"\n";
		}
	}
	for(int i=0;i<manageClass.get_gCountClass();i++){
		outC.setf(ios::left);
		outC<<manageClass.get_one_class_G(i).get_classID()<<" "<<setw(21)<<manageClass.get_one_class_G(i).get_className()<<" "<<manageClass.get_one_class_G(i).get_majorID();
		if(i!=manageClass.get_gCountClass()-1)
			outC<<"\n";
	}
	outC.close();

	ofstream outS(s);
	for(int i=0;i<manageSpeciality.get_countSpeciality();i++){
		outS.setf(ios::left);
		outS<<manageSpeciality.get_a_speciality(i).get_majorID()<<" "<<manageSpeciality.get_a_speciality(i).get_major();
		if(i!=manageSpeciality.get_countSpeciality()-1)
			outS<<"\n";
	}
	outS.close();
}

//刷新数据
void Interface::refresh(int kind)
{
	if(kind==1){
		save_file("临时文件-本科生.txt","临时文件-研究生.txt","临时文件-班级.txt","临时文件-专业.txt");
		manageStudent.clear_all_students();
		manageClass.clear_all_classes();
		manageSpeciality.clear_all_specialities();
		read_file("临时文件-本科生.txt","临时文件-研究生.txt","临时文件-班级.txt","临时文件-专业.txt");
	}
	else if(kind == 2){
		int i=0;
		int j=0;
		manageStudent.clear_all_students();
		for(i=0;i<manageClass.get_uCountClass();i++){
			for(j=0;j<manageClass.get_one_class_U(i).get_countStudent();j++){
				manageStudent.set_student(&manageClass.get_one_class_U(i).get_a_classmate(j),NULL);
			}
		}
		for(i=0;i<manageClass.get_gCountClass();i++){
			for(j=0;j<manageClass.get_one_class_G(i).get_countStudent();j++){
				manageStudent.set_student(NULL,&manageClass.get_one_class_G(i).get_a_classmate(j));
			}
		}
		save_file("临时文件-本科生.txt","临时文件-研究生.txt","临时文件-班级.txt","临时文件-专业.txt");
		manageStudent.clear_all_students();
		manageClass.clear_all_classes();
		manageSpeciality.clear_all_specialities();
		read_file("临时文件-本科生.txt","临时文件-研究生.txt","临时文件-班级.txt","临时文件-专业.txt");
	}
	else if(kind == 3){
		int i=0;
		int j=0;
		manageClass.clear_all_classes();
		for(i=0;i<manageSpeciality.get_countSpeciality();i++){
			for(j=0;j<manageSpeciality.get_a_speciality(i).get_uCountClass();j++){
				manageClass.set_class(&manageSpeciality.get_a_speciality(i).get_a_uClass(j),NULL);
			}
			for(j=0;j<manageSpeciality.get_a_speciality(i).get_gCountClass();j++){
				manageClass.set_class(NULL,&manageSpeciality.get_a_speciality(i).get_a_gClass(j));
			}
		}
		save_file("临时文件-本科生.txt","临时文件-研究生.txt","临时文件-班级.txt","临时文件-专业.txt");
		manageStudent.clear_all_students();
		manageClass.clear_all_classes();
		manageSpeciality.clear_all_specialities();
		read_file("临时文件-本科生.txt","临时文件-研究生.txt","临时文件-班级.txt","临时文件-专业.txt");
	}
}

//运行函数
void Interface::run()
{
	int choiceManage=0;
	string strchoiceManage;

	read_file();

	do{
		if( choiceManage <= 3 && choiceManage >= 0 ){
			menu.management_mode_menu();
			cout<<"                                                          ->>请选择要执行的功能: ";
			cin>>strchoiceManage;
			choiceManage=calculateString.calculate_choice( strchoiceManage );
		}
		else{		
			menu.management_mode_menu();
			cout<<"                                                          ->>无此项功能,请重新选择要执行的功能: ";
			cin>>strchoiceManage;
			choiceManage=calculateString.calculate_choice( strchoiceManage );
		}
		switch(choiceManage){
			case 1:
				manage_student();
				refresh(1);
				break;
			case 2:
				manage_class();
				refresh(2);
				break;
			case 3:
				manage_speciality();
				refresh(3);
				break;
			case 0:
				break;
		}

	}while(choiceManage);

	menu.ending_menu();
	save_file();
}

//管理学生
void Interface::manage_student()
{
	int choiceStudent=0;
	string strChoiceStudent;
	int choice=0;
	string strChoice;
	
	do{
		if( choiceStudent <= 2 && choiceStudent >= 0 ){
			menu.student_type_menu();
			cout<<"                                                          ->>请选择要执行的功能: ";
			cin>>strChoiceStudent;
			choiceStudent=calculateString.calculate_choice( strChoiceStudent );
		}
		else{		
			menu.student_type_menu();
			cout<<"                                                         ->>无此项功能,请重新选择要执行的功能: ";
			cin>>strChoiceStudent;
			choiceStudent=calculateString.calculate_choice( strChoiceStudent );
		}
		switch(choiceStudent){
			case 1:
				do{
					if( choice <= 4 && choice >= 0 ){
						menu.manage_student_menu(1);
						cout<<"                                                          ->>请选择要执行的功能: ";
						cin>>strChoice;
						choice=calculateString.calculate_choice( strChoice );
					}
					else{		
						menu.manage_student_menu(1);
						cout<<"                                                          ->>无此项功能,请重新选择要执行的功能: ";
						cin>>strChoice;
						choice=calculateString.calculate_choice( strChoice );
					}
					switch(choice){
						case 1:
							manageStudent.add_student(1);
							refresh(1);
							break;
						case 2:		
							manageStudent.modify_student(1);
							refresh(1);
							break;
						case 3:
							manageStudent.delete_student(1);
							refresh(1);
							break;
						case 4:
							manageStudent.query_student(1);
							break;
						case 0:
							break;
					}	
				}while(choice);
				break;
			case 2:
				do{
					if( choice <= 4 && choice >= 0 ){
						menu.manage_student_menu(2);
						cout<<"                                                          ->>请选择要执行的功能: ";
						cin>>strChoice;
						choice=calculateString.calculate_choice( strChoice );
					}
					else{		
						menu.manage_student_menu(2);
						cout<<"                                                          ->>无此项功能,请重新选择要执行的功能: ";
						cin>>strChoice;
						choice=calculateString.calculate_choice( strChoice );
					}
					switch(choice){
						case 1:
							manageStudent.add_student(2);
							refresh(1);
							break;
						case 2:
							manageStudent.modify_student(2);
							refresh(1);
							break;
						case 3:
							manageStudent.delete_student(2);
							refresh(1);
							break;
						case 4:
							manageStudent.query_student(2);
							break;
						case 0:
							break;
					}
				}while(choice);
				break;
			case 0:
				break;
		}
	}while(choiceStudent);
}

//管理班级
void Interface::manage_class()
{
	int flag=0;
	int choice=0;
	string strChoice;
	
	do{
		if( choice <= 6 && choice >= 0 ){
			menu.manage_classes_menu();
			cout<<"                                                          ->>请选择要执行的功能: ";
			cin>>strChoice;
			choice=calculateString.calculate_choice( strChoice );
		}
		else{		
			menu.manage_classes_menu();
			cout<<"                                                          ->>无此项功能,请重新选择要执行的功能: ";
			cin>>strChoice;
			choice=calculateString.calculate_choice( strChoice );
		}
		switch(choice){
			case 1:
				manageClass.add_class();
				refresh(2);
				break;
			case 2:
				manageClass.modify_class();
				refresh(2);
				break;
			case 3:
				manageClass.delete_class();
				refresh(2);
				break;
			case 4:
				manageClass.query_class();
				break;
			case 5:
				manageClass.statistics_class();
				break;
			case 6:
				while(flag=manageClass.manage_class(flag)){
					refresh(2);
				}
				break;
			case 0:
				break;
		}
	}while(choice);
}

//管理专业
void Interface::manage_speciality()
{
	int choice=0;
	string strChoice;
	
	do{
		if( choice <= 5 && choice >= 0 ){
			menu.manage_speciality_menu();
			cout<<"                                                          ->>请选择要执行的功能: ";
			cin>>strChoice;
			choice=calculateString.calculate_choice( strChoice );
		}
		else{		
			menu.manage_speciality_menu();
			cout<<"                                                          ->>无此项功能,请重新选择要执行的功能: ";
			cin>>strChoice;
			choice=calculateString.calculate_choice( strChoice );
		}
		switch(choice){
			case 1:
				manageSpeciality.add_speciality();
				refresh(3);
				break;
			case 2:
				manageSpeciality.modify_speciality();
				refresh(3);
				break;
			case 3:
				manageSpeciality.delete_speciality();
				refresh(3);
				break;
			case 4:
				manageSpeciality.search_speciality();
				break;
			case 5:
				manageSpeciality.manage_speciality();
				refresh(3);
				break;
			case 0:
				break;
		}
	}while(choice);
}
