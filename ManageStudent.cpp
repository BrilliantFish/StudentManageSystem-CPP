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

//ManageStudent类的构造函数
ManageStudent::ManageStudent()
{
	countU=0;     //将学生人数初始化为0
	countG=0;
}

//记录所有学生学号
void ManageStudent::set_recordID(int IDtemp)
{
	recordID.push_back(IDtemp);
}

//存放学生至向量
void ManageStudent::set_student(Undergraduate *uTemp=NULL,Graduate *gTemp=NULL)
{
	if(uTemp){
		undergraduate.push_back(*uTemp);
		countU++;
	}
	if(gTemp){
		graduate.push_back(*gTemp);
		countG++;
	}
}

//清除所有学生
void ManageStudent::clear_all_students()
{
	undergraduate.clear();
	countU=0;
	graduate.clear();
	countG=0;
}

//获取本科生人数
int ManageStudent::get_countU()
{
	return countU;
}

//获取研究生人数
int ManageStudent::get_countG()
{
	return countG;
}

//获取一位本科生
Undergraduate &ManageStudent::get_undergraduate( int number )
{
	return undergraduate[number];
}

//获取一位研究生
Graduate &ManageStudent::get_graduate( int number )
{
	return graduate[number];
}

//添加学生
void ManageStudent::add_student(int kindStudent)
{
	int count=0;
	string ch;
	int n;
	if(kindStudent==1){
		do{
			system("cls");
			cout<<"\n";
			cout<<"  ******                                                              <<   --   本  --   科  --   生  --   >>                                                                         ******\n\n\n";
			cout<<"                                                                         |-------------------------------| \n";
			cout<<"  -----------------------------------------------------------------------|      添    加    学    生     |--------------------------------------------------------------------------------\n";
			cout<<"                                                                         |-------------------------------| \n\n\n\n";
			cout<<"                                                                                    【 注 意 】"<<endl<<endl;
			cout<<"                                                                                    -> E-退出 <-  \n\n";
			cout<<"                                                                                 ||添加第"<<count+1<<"位学生||"<<endl;
			cout<<"                                                                ***************************************************\n";	
			Undergraduate uTemp;
			if(uTemp.set_information(1)){
				int flag=0;
				for(int i=0;i<recordID.size();i++){
					if(recordID[i]==uTemp.get_ID()){
						flag=1;
						break;
					}
				}
				if(flag==0){
					undergraduate.push_back(uTemp);
					count++;
					countG++;
					cout<<endl<<endl;
					cout<<"                                                                                   --------------"<<endl;
					cout<<"                                                                                   |  添加成功  |\n";
					cout<<"                                                                                   --------------"<<endl<<endl<<endl;
				}
				else{
					cout<<"                                                                              --------------------------"<<endl;
					cout<<"                                                                              |   添加失败，学号重复    |\n";
					cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
				}
			}
			else
				return;
			cout<<"                                                                ***************************************************\n";	
			cout<<endl<<"                                                                         是否继续添加学生 （Y-是，N-否）：";
			cin>>ch;
		}while(ch.compare("Y")==0);
	}
	else if(kindStudent==2){
		do{
			system("cls");
			cout<<"\n";
			cout<<"  ******                                                              <<   --   研  --   究  --   生  --   >>                                                                         ******\n\n\n";
			cout<<"                                                                         |-------------------------------| \n";
			cout<<"  -----------------------------------------------------------------------|      添    加    学    生     |--------------------------------------------------------------------------------\n";
			cout<<"                                                                         |-------------------------------| \n\n\n\n";
			cout<<"                                                                                    【 注 意 】"<<endl<<endl;
			cout<<"                                                                                    -> E-退出 <-  \n\n";
			cout<<"                                                                                 ||添加第"<<count+1<<"位学生||"<<endl;
			cout<<"                                                                ***************************************************\n\n";	
			Graduate gTemp;
			if(gTemp.set_information(2)){
				int flag=0;
				for(int i=0;i<recordID.size();i++){
					if(recordID[i]==gTemp.get_ID()){
						flag=1;
						break;
					}
				}
				if(flag==0){
					graduate.push_back(gTemp);
					count++;
					countG++;
					cout<<endl<<endl;
					cout<<"                                                                                   --------------"<<endl;
					cout<<"                                                                                   |  添加成功  |\n";
					cout<<"                                                                                   --------------"<<endl<<endl<<endl;
				}
				else{
					cout<<"                                                                              --------------------------"<<endl;
					cout<<"                                                                              |   添加失败，学号重复    |\n";
					cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
				}
			}
			else 
				return;
			cout<<"                                                                ***************************************************";	
			cout<<"                                                                         是否继续添加学生 （Y-是，N-否）：";
			cin>>ch;
		}while(ch.compare("Y")==0);
	}
}

//修改学生
void ManageStudent::modify_student(int kindStudent)
{
	string str;
	string ch;
	int choice;
	int n;
	if(kindStudent==1){
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                              <<   --   本  --   科  --   生  --   >>                                                                         ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      修    改    学    生     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		if(undergraduate.size()==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何本科生信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		else{

			cout<<"                                                                                    【 注 意 】"<<endl<<endl;
			cout<<"                                                                                   -> E- 退出 <-  \n\n";
			cout<<"                                                                ***************************************************\n\n\n";	
			cout<<"                                                                               请输入要修改的学生学号：";
			cin>>str;
			if(str.compare("E")==0)
				return;
			vector <Undergraduate> ::iterator p=undergraduate.begin();
			n=calculateString.calculate_real_number(str);
			for(p=undergraduate.begin();p!=undergraduate.end()&& n!=p->get_ID() ;p++)
				;
			if(p!=undergraduate.end()){
				;
			}
			else{
				cout<<"\n\n\n";
				cout<<"                                                                                  ------------\n";
				cout<<"                                                                                  | 无此学生 |\n";
				cout<<"                                                                                  ------------\n\n";
				system("pause");
				return;
			}
			do{
				system("cls");
				cout<<endl<<endl;
				cout<<"                                            基本资料数据                                                                             成绩数据                                            \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n\n";
				p->display_a_student();
				cout<<"                                                                ***************************************************\n\n";
				cout<<"                                                                                   1.学    号"<<endl<<endl;
				cout<<"                                                                                   2.姓    名"<<endl<<endl;   
				cout<<"                                                                                   3.性    别"<<endl<<endl;
				cout<<"                                                                                   4.年    级"<<endl<<endl;
				cout<<"                                                                                   5.专    业"<<endl<<endl;
				cout<<"                                                                                   6.班    级"<<endl<<endl;
				cout<<"                                                                                   7.高等数学"<<endl<<endl;
				cout<<"                                                                                   8.英    语"<<endl<<endl;
				cout<<"                                                                                   9.C  语 言"<<endl<<endl;
				cout<<"                                                                                   0.返    回"<<endl<<endl;
				cout<<"                                                                ***************************************************\n";
				cout<<"                                                                -> 请选择修改项：";
				cin>>choice;
				int IDTemp=p->get_ID();
				switch(choice){
					case 1:				
						if((p->set_ID())==false)
							return;
						else{
							int flag=0;
							for(int i=0;i<recordID.size();i++){
								if(recordID[i]==p->get_ID()){
									flag=1;
									break;
								}
							}
							if(flag==1){
								p->get_ID()=IDTemp;
								cout<<endl<<endl;
								cout<<"                                                                              --------------------------"<<endl;
								cout<<"                                                                              |   修改失败，学号重复    |\n";
								cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
							}
						}
						break;
					case 2:
						if((p->set_name())==false)
							return;
						break;
					case 3:
						if((p->set_gender())==false)
							return;
						break;
					case 4:
						if((p->set_grade())==false)
							return;
						break;
					case 5:
						if((p->set_major())==false)
							return;
						break;
					case 6:
						if((p->set_class())==false)
							return ;
						break;
					case 7:
						if((p->set_score(1,1))==false)
							return ;
						break;
					case 8:
						if((p->set_score(1,2))==false)
							return ;
						break;
					case 9:
						if((p->set_score(1,3))==false)
							return ;
						break;
					case 0:
						return ;
				}
				cout<<endl<<"                                                                      是否继续修改该学生信息（Y-是，N-否）：";
				cin>>ch;
			}while(ch.compare("Y")==0);
		}
	}
	else if(kindStudent==2){
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                              <<   --   研  --   究  --   生  --   >>                                                                         ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      修    改    学    生     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		if(graduate.size()==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何研究生信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		else{
			cout<<"                                                                                    【 注 意 】"<<endl<<endl;
			cout<<"                                                                                   -> E- 退出 <-  \n\n";
			cout<<"                                                                ***************************************************\n\n\n";	
			cout<<"                                                                              请输入要修改的学生学号：";
			cin>>str;
			if(str.compare("E")==0)
				return;
			vector <Graduate> ::iterator p=graduate.begin();
			n=calculateString.calculate_real_number(str);
			for(p=graduate.begin();p!=graduate.end()&& n!=p->get_ID() ;p++)
				;
			if(p!=graduate.end())
				;

			else{
				cout<<"\n\n\n";
				cout<<"                                                                                  ------------\n";
				cout<<"                                                                                  | 无此学生 |\n";
				cout<<"                                                                                  ------------\n\n";
				system("pause");
				return;
			}
			do{
				system("cls");
				cout<<endl<<endl;
				cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
				p->display_a_student();
				cout<<"                                                                ***************************************************\n\n";
				cout<<"                                                                                   1.学    号"<<endl<<endl;
				cout<<"                                                                                   2.姓    名"<<endl<<endl;   
				cout<<"                                                                                   3.性    别"<<endl<<endl;
				cout<<"                                                                                   4.年    级"<<endl<<endl;
				cout<<"                                                                                   5.专    业"<<endl<<endl;
				cout<<"                                                                                   6.班    级"<<endl<<endl;
				cout<<"                                                                                   7.研究课题"<<endl<<endl;
				cout<<"                                                                                   8.导    师"<<endl<<endl;
				cout<<"                                                                                   9.课程综合"<<endl<<endl;
				cout<<"                                                                                  10.论    文"<<endl<<endl;
				cout<<"                                                                                   0.返    回"<<endl<<endl;
				cout<<"                                                                ***************************************************\n";
				cout<<"                                                                -> 请选择修改项：";
				cin>>choice;
				int IDTemp=p->set_ID();
				switch(choice){
					case 1:		
						if((p->set_ID())==false)
							return;
						else{
							int flag=0;
							for(int i=0;i<recordID.size();i++){
								if(recordID[i]==p->get_ID()){
									flag=1;
									break;
								}
							}
							if(flag==1){
								p->get_ID()=IDTemp;
								cout<<endl<<endl;
								cout<<"                                                                              --------------------------"<<endl;
								cout<<"                                                                              |   修改失败，学号重复    |\n";
								cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
							}
						}
						break;
					case 2:
						if((p->set_name())==false)
							return;
						break;
					case 3:
						if((p->set_gender())==false)
							return;
						break;
					case 4:
						if((p->set_grade())==false)
							return;
						break;
					case 5:
						if((p->set_major())==false)
							return;
						break;
					case 6:
						if((p->set_class())==false)
							return ;
						break;
					case 7:
						if((p->set_researchTopic())==false)
							return ;
						break;
					case 8:
						if((p->set_tutor())==false)
							return ;
						break;
					case 9:
						if((p->set_score(2,0))==false)
							return ;
						break;
					case 10:
						if((p->set_score(2,1))==false)
							return ;
						break;
					case 0:
						return ;
				}
				cout<<endl<<"                                                                      是否继续修改该学生信息（Y-是，N-否）：";
				cin>>ch;
			}while(ch.compare("Y")==0);
		}
	}
}

//删除学生
void ManageStudent::delete_student(int kindStudent)
{
	string str;
	int n;
	if(kindStudent==1){
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                              <<   --   本  --   科  --   生  --   >>                                                                         ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      删    除    学    生     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		if(undergraduate.size()==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何本科生信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		else{
			cout<<"                                                                                    【 注 意 】"<<endl<<endl;
			cout<<"                                                                                   -> E- 退出 <-  \n\n";
			cout<<"                                                                ***************************************************\n\n\n";	
			cout<<"                                                                              请输入要删除的学生学号：";
			cin>>str;
			if(str.compare("E")==0)
				return;
			vector <Undergraduate> ::iterator p=undergraduate.begin();
			
			n=calculateString.calculate_real_number(str);
			for(p=undergraduate.begin();p!=undergraduate.end()&& n!=p->get_ID() ;p++)
				;
			if(p!=undergraduate.end()){
				undergraduate.erase(p);
				cout<<"\n\n\n";
				cout<<"                                                                                    ------------\n";
				cout<<"                                                                                    | 成功删除 |\n";
				cout<<"                                                                                    ------------\n\n";
				countU--;
			}
			else{
				cout<<endl<<endl<<endl;
				cout<<"                                                                                   --------------"<<endl;
				cout<<"                                                                                   |  无此学生  |\n";
				cout<<"                                                                                   --------------"<<endl<<endl<<endl;
				cout<<"                                                                                 ";
				system("pause");
				return;
			}
			
		}
	}
	else if(kindStudent==2){
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                              <<   --   研  --   究  --   生  --   >>                                                                         ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      删    除    学    生     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		if(graduate.size()==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何研究生信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		else{
			cout<<"                                                                                    【 注 意 】"<<endl<<endl;
			cout<<"                                                                                   -> E- 退出 <-  \n\n";
			cout<<"                                                                ***************************************************\n\n\n";	
			cout<<"                                                                               请输入要删除的学生学号：";
			cin>>str;
			if(str.compare("E")==0)
				return;
			vector <Graduate> ::iterator p=graduate.begin();
			n=calculateString.calculate_real_number(str);
			for(p=graduate.begin();p!=graduate.end()&& n!=p->get_ID() ;p++)
				;
			if(p!=graduate.end()){
				graduate.erase(p);
				cout<<"\n\n\n";
				cout<<"                                                                                    ------------\n";
				cout<<"                                                                                    | 成功删除 |\n";
				cout<<"                                                                                    ------------\n\n";
				countG--;
			}
			else{
				cout<<endl<<endl<<endl;
				cout<<"                                                                                   --------------"<<endl;
				cout<<"                                                                                   |  无此学生  |\n";
				cout<<"                                                                                   --------------"<<endl<<endl<<endl;
				cout<<"                                                                                ";
				system("pause");  
				return;
			}
			
		}
	}
	cout<<endl<<endl<<"                                                                ***************************************************\n\n\n";	
	cout<<"                                                                         ！！！返回上一页,";
	system("pause");

}

//查询某位学生
void ManageStudent::query_a_student(int kindStudent)
{
	string str;
	int n;
	if(kindStudent==1){
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                              <<   --   本  --   科  --   生  --   >>                                                                         ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      查    询    学    生     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		if(undergraduate.size()==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何本科生信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		else{
			cout<<"                                                                                    【 注 意 】"<<endl<<endl;
			cout<<"                                                                                   -> E- 退出 <-  \n\n";
			cout<<"                                                                ***************************************************\n\n\n";	
			cout<<"                                                                        请输入要查询的学生学号或姓名：";
			cin>>str;
			if(str.compare("E")==0)
				return;
			vector <Undergraduate> ::iterator p=undergraduate.begin();
			for(p=undergraduate.begin();p!=undergraduate.end()&& str!=p->get_name() ;p++)
				;
			if(p!=undergraduate.end()){
				cout<<endl<<endl;
				cout<<"                                            基本资料数据                                                                             成绩数据                                            \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n\n";
				for(p=undergraduate.begin();p!=undergraduate.end() ;p++){
					if(p->get_name()==str)
						p->display_a_student();
				}
			}
			else{
				n=calculateString.calculate_real_number(str);
				for(p=undergraduate.begin();p!=undergraduate.end()&& n!=p->get_ID() ;p++)
					;
				if(p!=undergraduate.end()){
					cout<<endl<<endl;
					cout<<"                                            基本资料数据                                                                             成绩数据                                            \n\n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n\n";
					p->display_a_student();
				}
				else{
					cout<<"\n\n\n";
					cout<<"                                                                                  ------------\n";
					cout<<"                                                                                  | 无此学生 |\n";
					cout<<"                                                                                  ------------\n\n";
					cout<<"                                                                           ";
					system("pause");
					return;
				}
			}
		}
	}
	else if(kindStudent==2){
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                              <<   --   研  --   究  --   生  --   >>                                                                         ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      查    询    学    生     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		if(graduate.size()==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何研究生信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		else{
			cout<<"                                                                                    【 注 意 】"<<endl<<endl;
			cout<<"                                                                                   -> E- 退出 <-  \n\n";
			cout<<"                                                                ***************************************************\n\n\n";	
			cout<<"                                                                        请输入要查询的学生学号或姓名：";
			cin>>str;
			if(str.compare("E")==0)
				return;
			vector <Graduate> ::iterator p=graduate.begin();
			for(p=graduate.begin();p!=graduate.end()&& str!=p->get_className() ;p++)
				;
			if(p!=graduate.end()){
				cout<<endl<<endl;
				cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
				for(p=graduate.begin();p!=graduate.end() ;p++){
					if(p->get_name()==str)
						p->display_a_student();
				}
			}
			else{
				n=calculateString.calculate_real_number(str);
				for(p=graduate.begin();p!=graduate.end()&& n!=p->get_ID() ;p++)
					;
				if(p!=graduate.end()){
					cout<<endl<<endl;
					cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n\n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
					p->display_a_student();
				}
				else{
					cout<<"\n\n\n";
					cout<<"                                                                                  ------------\n";
					cout<<"                                                                                  | 无此学生 |\n";
					cout<<"                                                                                  ------------\n\n";
					cout<<"                                                                           ";
					system("pause");
					return;
				}
			}
		}
	}
	cout<<endl<<endl<<"                                                          ***************************************************************\n\n\n";
	cout<<"                                                                         ！！！返回上一页,";
	system("pause");

}

bool compare_U_ID(Undergraduate &p1,Undergraduate &p2){
	return p1.get_ID()<p2.get_ID();  //升序
}

bool compare_G_ID(Graduate &p1,Graduate &p2){
	return p1.get_ID()<p2.get_ID();  //升序
}

//查询所有学生
void ManageStudent::query_all_students(int kindStudent)
{
	int pageCur=1;
	int choice=1;
	string strChoice;
	int i=0;
	int j=0;
	string strPage;
	int page;
	int clearFlag=0;        //清屏的标志，清屏过则为1，没有则为0，保证在选择后，选项的菜单在屏幕中只出现1次。
	
	if(kindStudent==1){
		page=1;
		if(undergraduate.size()==0){	
			cout<<"\n\n\n";
			cout<<"                                                                                  -----------\n";
			cout<<"                                                                                  |  无学生 |\n";
			cout<<"                                                                                  -----------\n\n";
			cout<<"                                                                        ";
			system("pause");
			return;
		}
		sort(undergraduate.begin(),undergraduate.end(),compare_U_ID);
		int countPageU=0;     //每次计算页数时都要将countPage_U置为0，避免下次使用的countPage_U保留着上次的值。
		vector <Undergraduate> ::iterator p1=undergraduate.begin();
		vector <Undergraduate> ::iterator p2=undergraduate.begin();
		vector <vector <Undergraduate> ::iterator> pointPageU;
		while( p1!= undergraduate.end()){
			i++;
			if(i%10==1){
				pointPageU.push_back(p1);
				countPageU++;
			}
			p1++;
		}
		do{
			if(choice==1){
				system("cls");
				clearFlag=1;
				cout<<endl<<endl;
				cout<<"                                            基本资料数据                                                                             成绩数据                                            \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n\n";
				pageCur=1;
				p2=pointPageU[pageCur-1];
				for( j = 0 ; p2 != undergraduate.end() && j<10 ;p2++, j++){
					p2->display_a_student();
				}
			}
			else if( choice == 2){
				if( pageCur == 1 ){
					clearFlag=0;					
					cout<<endl<<"                                                                  |+|+|+|+|-  当前为首页，无上一页内容！ -|+|+|+|+|  \n"<<endl;					
				}
				else{
					system("cls");
					clearFlag=1;
					cout<<endl<<endl;
					cout<<"                                            基本资料数据                                                                             成绩数据                                            \n\n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n\n";
					pageCur--;
					p2=pointPageU[pageCur-1];
					for( j = 0 ; p2 != undergraduate.end() && j<10 ;p2++, j++){
						p2->display_a_student();
					}
				}
			}

			else if( choice == 3 ){
				if( pageCur == countPageU ){
					clearFlag=0;
					cout<<endl<<"                                                                  |+|+|+|+|-  当前为尾页，无下一页内容！ -|+|+|+|+|  \n"<<endl;
				}
				else{
					system("cls");
					clearFlag=1;
					cout<<endl<<endl;
					cout<<"                                            基本资料数据                                                                             成绩数据                                            \n\n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n\n";
					pageCur++;
					p2=pointPageU[pageCur-1];
					for( j = 0 ; p2 != undergraduate.end() && j<10 ;p2++, j++){
						p2->display_a_student();
					}
				}
			}
			else if( choice == 4 ){
				system("cls");
				clearFlag=1;
				cout<<endl<<endl;
				cout<<"                                            基本资料数据                                                                             成绩数据                                            \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n\n";
				pageCur=countPageU;
				p2=pointPageU[pageCur-1];
				for( j = 0 ; p2 != undergraduate.end() && j<10 ;p2++, j++){
					p2->display_a_student();
				}
			}
			else if( choice == 5){
				do{
					if( page == -1 ){
						clearFlag=0;					  
						cout<<endl<<"                                                                            (无此页码, 请重新选择)-->>";
						cin>>strPage;
						page=calculateString.calculate_real_number(strPage);
					}
					else{
						clearFlag=0;
						cout<<endl<<endl<<"                                            -------------------------------------------------------------------------------------------- \n"<<endl;
						cout<<"                                                                                  ->  选    页  <-\n\n";
						cout<<"                                                                            (请 选 择 跳 转 页 码)-->>";
						cin>>strPage;
						page=calculateString.calculate_real_number(strPage);
					}
					if(page<=0||page>countPageU)
						page = -1;
				}while( page == -1);
				system("cls");
				clearFlag=1;
				cout<<endl<<endl;
				cout<<"                                            基本资料数据                                                                             成绩数据                                            \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n\n";
				pageCur=page;
				p2=pointPageU[pageCur-1];
				for( j = 0 ; p2 != undergraduate.end() && j<10 ;p2++, j++){
					p2->display_a_student();
				}
			}
			do{
				if( choice == -1 ){					
					cout<<"                                                                            (无此选项，请重新选择)-->>";					
					cin>>strChoice;
					choice=calculateString.calculate_real_number(strChoice);
				}
				else{
					if(clearFlag==1){
						cout<<endl<<endl<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
						cout<<endl<<"                                                                 ->> 总 共 有 “"<<countPageU<<"” 页, 当 前 位 于 第 “"<<pageCur<<"” 页<<-"<<endl<<endl;						
						cout<<"                                                            ********1-首页  2-上一页  3-下一页  4-尾页  5-选页********\n";
						cout<<"                                                            ********0-退           出           显          示********\n"<<endl;
						cout<<"                                                                            (请       选       择)-->>";						
						cin>>strChoice;
						choice=calculateString.calculate_real_number(strChoice);
					}
					else{
						cout<<"                                                                            (请   重  新  选   择)-->>";					
						cin>>strChoice;
						choice=calculateString.calculate_real_number(strChoice);
					}
				
				}
				if( choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 0 ){
					break;
				}			
			}while(choice);
		}while(choice);
	}
	else if(kindStudent==2){
		page=1;
		if(graduate.size()==0){	
			cout<<"\n\n\n";
			cout<<"                                                                                  -----------\n";
			cout<<"                                                                                  |  无学生 |\n";
			cout<<"                                                                                  -----------\n\n";
			cout<<"                                                                        ";
			system("pause");
			return;
		}
		sort(graduate.begin(),graduate.end(),compare_G_ID);
		int countPageG=0;     //每次计算页数时都要将countPage_G置为0，避免下次使用的countPage_G保留着上次的值。
		vector <Graduate> ::iterator p1=graduate.begin();
		vector <Graduate> ::iterator p2=graduate.begin();
		vector <vector <Graduate> ::iterator> pointPageG;
		while( p1!= graduate.end()){
			i++;
			if(i%10==1){
				pointPageG.push_back(p1);
				countPageG++;
			}
			p1++;
		}
		do{
			if(choice==1){
				system("cls");
				clearFlag=1;
				cout<<endl<<endl;
				cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
				pageCur=1;
				p2=pointPageG[pageCur-1];
				for( j = 0 ; p2 != graduate.end() && j<10 ;p2++, j++){
					p2->display_a_student();
				}
			}
			else if( choice == 2){
				if( pageCur == 1 ){
					clearFlag=0;
					printf("\n");					
					printf("                                                                  |+|+|+|+|-  当前为首页，无上一页内容！ -|+|+|+|+|  \n");					
					printf("\n");
				}
				else{
					system("cls");
					clearFlag=1;
					cout<<endl<<endl;
					cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n\n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
					pageCur--;
					p2=pointPageG[pageCur-1];
					for( j = 0 ; p2 != graduate.end() && j<10 ;p2++, j++){
						p2->display_a_student();
					}
				}
			}

			else if( choice == 3 ){
				if( pageCur == countPageG ){
					clearFlag=0;
					cout<<endl<<"                                                                  |+|+|+|+|-  当前为首页，无下一页内容！ -|+|+|+|+|  \n"<<endl;					
				}
				else{
					system("cls");
					clearFlag=1;
					cout<<endl<<endl;
					cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n\n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
					pageCur++;
					p2=pointPageG[pageCur-1];
					for( j = 0 ; p2 != graduate.end() && j<10 ;p2++, j++){
						p2->display_a_student();
					}
				}
			}
			else if( choice == 4 ){
				system("cls");
				clearFlag=1;
				cout<<endl<<endl;
				cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
				pageCur=countPageG;
				p2=pointPageG[pageCur-1];
				for( j = 0 ; p2 != graduate.end() && j<10 ;p2++, j++){
					p2->display_a_student();
				}
			}
			else if( choice == 5){
				do{
					if( page == -1 ){
						clearFlag=0;					  
						cout<<endl<<"                                                                            (无此页码, 请重新选择)-->>";
						cin>>strPage;
						page=calculateString.calculate_real_number(strPage);
					}
					else{
						clearFlag=0;
						cout<<endl<<"                                            -------------------------------------------------------------------------------------------- \n"<<endl;
						cout<<"                                                                                  ->  选    页  <-\n"<<endl;
						cout<<"                                                                            (请 选 择 跳 转 页 码)-->>";
						cin>>strPage;
						page=calculateString.calculate_real_number(strPage);
					}
					if(page<=0||page>countPageG)
						page = -1;
				}while( page == -1);
				system("cls");
				clearFlag=1;
				cout<<endl<<endl;
				cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
				pageCur=page;
				p2=pointPageG[pageCur-1];
				for( j = 0 ; p2 != graduate.end() && j<10 ;p2++, j++){
					p2->display_a_student();
				}
			}
			do{
				if( choice == -1 ){					
					cout<<"                                                                            (无此选项，请重新选择)-->>";					
					cin>>strChoice;
					choice=calculateString.calculate_real_number(strChoice);
				}
				else{
					if(clearFlag==1){
						cout<<endl<<endl<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
						cout<<endl<<endl<<"                                                                 ->> 总 共 有 “"<<countPageG<<"” 页, 当 前 位 于 第 “"<<pageCur<<"” 页<<-"<<endl<<endl;											
						cout<<"                                                            ********1-首页  2-上一页  3-下一页  4-尾页  5-选页********\n";
						cout<<"                                                            ********0-退           出           显          示********\n"<<endl;
						cout<<"                                                                            (请       选       择)-->>";						
						cin>>strChoice;
						choice=calculateString.calculate_real_number(strChoice);
					}
					else{
						printf("                                                                            (请   重  新  选   择)-->>");					
						cin>>strChoice;
						choice=calculateString.calculate_real_number(strChoice);
					}	
				}
				if( choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 0 ){
					break;
				}			
			}while(choice);
		}while(choice);
	}
}

//查询学生
void ManageStudent::query_student(int kindStudent)
{
	int choice=0;
	string strChoice;
	
	do{
		if( choice <= 2 && choice >= 0 ){
			menu.query_menu();
			cout<<"                                                          ->>请选择要执行的功能: ";
			cin>>strChoice;
			choice=calculateString.calculate_choice( strChoice );
		}
		else{		
			menu.query_menu();
			cout<<"                                                          ->>无此项功能,请重新选择要执行的功能: ";
			cin>>strChoice;
			choice=calculateString.calculate_choice( strChoice );
		}
		switch(choice){
			case 1:
				query_a_student(kindStudent);
				break;
			case 2:
				query_all_students(kindStudent);
				break;
			case 0:
				break;
		}
	}while(choice);
}