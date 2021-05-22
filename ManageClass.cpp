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


//ManageClass类的构造函数
ManageClass::ManageClass()
{
	uCountClass=0;
	gCountClass=0;
}

//记录所有班级编号
void ManageClass::set_recordClassID(long int classIDTemp)
{
	recordClassID.push_back(classIDTemp);
	
}

//记录所有学生学号 
void ManageClass::set_recordID(long int IDTemp)
{
	for(int i=0;i<uClass.size();i++)
		uClass[i].set_recordID(IDTemp);
	for(int i=0;i<gClass.size();i++)
		gClass[i].set_recordID(IDTemp);
}

//新建班级，存放班级信息
void ManageClass::set_class(Class <Undergraduate> *uClassTemp=NULL,Class <Graduate> *gClassTemp=NULL)
{
	if(uClassTemp){
		uClass.push_back(*uClassTemp);
		uCountClass++;
	}
	if(gClassTemp){
		gClass.push_back(*gClassTemp);
		gCountClass++;
	}
}

//清除所有班级
void ManageClass::clear_all_classes()
{
	uClass.clear();
	uCountClass=0;
	gClass.clear();
	gCountClass=0;
}

//获取某个本科生班级来存放信息
Class <Undergraduate> &ManageClass::get_one_class_U(int number)
{
	return uClass[number];
}

//获取某个研究生班级来存放信息
Class <Graduate> &ManageClass::get_one_class_G(int number)
{
	return gClass[number];
}

//获取本科生班级数量
int ManageClass::get_uCountClass()
{
	return uCountClass;
}

//获取研究生班级数量
int ManageClass::get_gCountClass()
{
	return gCountClass;
}

//添加班级
void ManageClass::add_class()
{
	string str;
	int count=0;
	string ch;

	do{
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  班  --  级   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      添    加    班    级     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		cout<<"                                                                                 ||添加第"<<count+1<<"个班级||"<<endl;
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                              -> 1-本科生  2-研究生 <-  "<<endl<<endl;
		cout<<"                                                                              ->       E-退  出     <-  \n\n";
		cout<<"                                                                                 请选择该班级类型:";
		cin>>str;
		if(str.compare("E")==0)
			return;
		if(str.compare("1")==0){
			Class <Undergraduate> uClassTemp;
			if(uClassTemp.set_class_information()){
				int flag=0;
				for(int i=0;i<recordClassID.size();i++){
					if(recordClassID[i]==uClassTemp.get_classID()){
						flag=1;
						break;
					}
				}
				if(flag==0){
					uClass.push_back(uClassTemp);
					count++;
					uCountClass++;
					cout<<endl<<endl;
					cout<<"                                                                                   --------------"<<endl;
					cout<<"                                                                                   |  添加成功  |\n";
					cout<<"                                                                                   --------------"<<endl<<endl<<endl;
				}
				else{
					cout<<"                                                                              --------------------------"<<endl;
					cout<<"                                                                              |   添加失败，班号重复    |\n";
					cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
				}
			}
			else
				return;
		}
		else if(str.compare("2")==0){
			Class <Graduate> gClassTemp;
			if(gClassTemp.set_class_information()){
				int flag=0;
				for(int i=0;i<recordClassID.size();i++){
					if(recordClassID[i]==gClassTemp.get_classID()){
						flag=1;
						break;
					}
				}
				if(flag==0){
					gClass.push_back(gClassTemp);
					count++;
					gCountClass++;
					cout<<endl<<endl;
					cout<<"                                                                                   --------------"<<endl;
					cout<<"                                                                                   |  添加成功  |\n";
					cout<<"                                                                                   --------------"<<endl<<endl<<endl;
				}
				else{
					cout<<"                                                                              --------------------------"<<endl;
					cout<<"                                                                              |   添加失败，班号重复    |\n";
					cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
				}
			}
			else
				return;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         是否继续添加班级 （Y-是，N-否）：";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//修改班级信息
void ManageClass::modify_class()
{
	string str;
	bool flag;
	int choice;
	int count=0;
	int i=1;
	string ch;
	if(gCountClass==0&&uCountClass==0){
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                        !!!!!!!!  无任何班级信息   !!!!!!!!                  \n\n\n";
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                           ！！！返回上一页,";
		system("pause");
		return;
	}
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  班  --  级   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      修    改    班    级     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
		for(;pU!=uClass.end();pU++){
			cout<<"                                                                         "<<i<<" : "<<pU->get_className()<<"-本科生"<<endl<<endl;
			i++;
		}
		vector < Class <Graduate> > ::iterator pG= gClass.begin();
		for(;pG!=gClass.end();pG++){
			cout<<"                                                                         "<<i<<" : "<<pG->get_className()<<"-研究生"<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-退出) 请选择班级：";
		cin>>str;
		if(str.compare("E")==0)
			return;
		choice=calculateString.calculate_real_number(str);
		if(choice>0&&choice<=uCountClass){
			vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
			for(int i=0; i<choice-1 ;i++,pU++)
				;
			cout<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                                    1.专业编号"<<endl;
			cout<<endl<<"                                                                                    2.班级名称"<<endl;
			cout<<endl<<"                                                                                    3.班级编号"<<endl;
			cout<<endl<<"                                                                                    0.返    回"<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                   ->请输入修改项：";
			cin>>str;
			choice=calculateString.calculate_real_number(str);
			long int classIDTemp=pU->get_classID();
			switch(choice){
				case 1:
					if(pU->set_majorID()==false)
						return;
					break;
				case 2:
					if(pU->set_className()==false)
						return;
					break;
				case 3:
					if((pU->set_classID())==false)
						return;
					else{
						int flag=0;
						for(int i=0;i<recordClassID.size();i++){
							if(recordClassID[i]==pU->get_classID()){
								flag=1;
								break;
							}
						}
						if(flag==1){
							pU->get_classID()=classIDTemp;
							cout<<endl<<endl;
							cout<<"                                                                              --------------------------"<<endl;
							cout<<"                                                                              |   修改失败，班号重复    |\n";
							cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
						}
					}
					break;
				case 0:
					return;
			}
		}
		else if(choice>0&&choice<=uCountClass+gCountClass){
			vector < Class <Graduate> > ::iterator pG= gClass.begin();
			for(int i=0;i<choice-uCountClass-1;i++,pG++)
			cout<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                                    1.专业编号"<<endl;
			cout<<endl<<"                                                                                    2.班级名称"<<endl;
			cout<<endl<<"                                                                                    3.班级编号"<<endl;
			cout<<endl<<"                                                                                    0.返    回"<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                   ->请输入修改项：";
			cin>>str;
			choice=calculateString.calculate_real_number(str);
			long int classIDTemp=pG->get_classID();
			switch(choice){
				case 1:
					if(pG->set_majorID()==false)
						return;
					break;
				case 2:
					if(pG->set_className()==false)
						return;
					break;
				case 3:
					if((pG->set_classID())==false)
						return;
					else{
						int flag=0;
						for(int i=0;i<recordClassID.size();i++){
							if(recordClassID[i]==pG->get_classID()){
								flag=1;
								break;
							}
						}
						if(flag==1){
							pG->get_classID()=classIDTemp;
							cout<<endl<<endl;
							cout<<"                                                                              --------------------------"<<endl;
							cout<<"                                                                              |   修改失败，班号重复    |\n";
							cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
						}
					}
					break;
				case 0:
					return;
			}
		}	
		else{
			cout<<endl;
			cout<<"                                                                                   ------------\n";
			cout<<"                                                                                   | 无该选项 |"<<endl;
			cout<<"                                                                                   ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<endl<<"                                                                         是否继续修改班级 （Y-是，N-否）：";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//删除班级
void ManageClass::delete_class()
{
	string str;
	int choice;
	int i=1;
	string ch;
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  班  --  级   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      删    除    班    级     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(gCountClass==0&&uCountClass==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何班级信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		cout<<"                                                                                     【 注 意 】 \n\n";
		cout<<"                                                                             删除班级对应的学生也会被删除\n\n";
		vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
		for(;pU!=uClass.end();pU++){
			cout<<"                                                                         "<<i<<" : "<<pU->get_className()<<" -本科生"<<endl<<endl;
			i++;
		}
		vector < Class <Graduate> > ::iterator pG= gClass.begin();
		for(;pG!=gClass.end();pG++){
			cout<<"                                                                         "<<i<<" : "<<pG->get_className()<<" -研究生"<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-退出) 请选择班级：";
		cin>>str;
		if(str.compare("E")==0)
			return;
		choice=calculateString.calculate_real_number(str);
		if(choice>0&&choice<=uCountClass){
			vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
			for(int i=0; i<choice-1 ;i++,pU++)
				;
			uClass.erase(pU);
			uCountClass--;
			cout<<endl;
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | 成功删除 |\n";
			cout<<"                                                                                  ------------\n\n";
		}
		else if(choice>0&&choice<=uCountClass+gCountClass){
			vector < Class <Graduate> > ::iterator pG= gClass.begin();
			for(int i=0;i<choice-uCountClass-1;i++,pG++)
				;
			gClass.erase(pG);
			gCountClass--;
			cout<<endl;
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | 成功删除 |\n";
			cout<<"                                                                                  ------------\n\n";
		}	
		else{			
			cout<<endl;
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | 无该选项 |"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         是否继续删除班级 （Y-是，N-否）：";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//查询班级
void ManageClass::query_class()
{
	string str;
	int choice;
	int i=1;
	string ch;
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  班  --  级   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      查    询    班    级     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(gCountClass==0&&uCountClass==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何班级信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
		for(;pU!=uClass.end();pU++){
			cout<<"                                                                         "<<i<<" : "<<pU->get_className()<<" -本科生"<<endl<<endl;
			i++;
		}
		vector < Class <Graduate> > ::iterator pG= gClass.begin();
		for(;pG!=gClass.end();pG++){
			cout<<"                                                                         "<<i<<" : "<<pG->get_className()<<" -研究生"<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-退出) 请选择班级：";
		cin>>str;
		if(str.compare("E")==0)
			return;
		choice=calculateString.calculate_real_number(str);
		if(choice>0&&choice<=uCountClass){
			system("cls");
			vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
			for(int i=0; i<choice-1 ;i++,pU++)
				;
			pU->dispaly_class();
			pU->dispay_classmates(1);
		}
		else if(choice>0&&choice<=uCountClass+gCountClass){
			system("cls");
			vector < Class <Graduate> > ::iterator pG= gClass.begin();
			for(int i=0;i<choice-uCountClass-1;i++,pG++)
				;
			pG->dispaly_class();
			pG->dispay_classmates(2);
		}	
		else{
			cout<<endl;
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | 无该选项 |"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         是否继续查询班级 （Y-是，N-否）：";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//统计班级信息
void ManageClass::statistics_class()
{
	int choice=0;
	string strChoice;	
	do{
		if( choice <= 4 && choice >= 0 ){
			menu.statistics_menu();
			cout<<"                                                          ->>请选择要执行的功能: ";
			cin>>strChoice;
			choice=calculateString.calculate_choice( strChoice );
		}
		else{		
			menu.statistics_menu();
			cout<<"                                                          ->>无此项功能,请重新选择要执行的功能: ";
			cin>>strChoice;
			choice=calculateString.calculate_choice( strChoice );
		}
		switch(choice){
			case 1:
				statistic_average_max_min();
				break;
			case 2:
				statistic_exceed_average();
				break;
			case 3:
				statistic_fail();
				break;
			case 4:
				statistic_score_rank();
				break;
			case 0:
				break;
		}
	}while(choice);
}

//管理班级学生
int  ManageClass::manage_class(int n)
{
	string str;
	int option;
	int choice=0;
	string strChoice;
	int i=1;
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  班  --  级   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      管    理    班    级     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(gCountClass==0&&uCountClass==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何班级信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return false;
		}
		vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
		if(n==0){
			for(;pU!=uClass.end();pU++){
				cout<<"                                                                         "<<i<<" : "<<pU->get_className()<<" -本科生"<<endl<<endl;
				i++;
			}
			vector < Class <Graduate> > ::iterator pG= gClass.begin();
			for(;pG!=gClass.end();pG++){
				cout<<"                                                                         "<<i<<" : "<<pG->get_className()<<" -研究生"<<endl<<endl;
				i++;
			}
			cout<<"                                                                ***************************************************\n\n";	
			cout<<"                                                                              (E-退出) 请选择该班级：";
			cin>>str;
			if(str.compare("E")==0)
				return 0;
			option=calculateString.calculate_real_number(str);
			n=option;
		}
		else
			option=n;
		if(option>0&&option<=uCountClass){
			vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
			for(int i=0; i<option-1 ;i++,pU++)
				;	
			do{
				if( choice <= 4 && choice >= 0 ){
					menu.manage_one_class_menu(pU->get_countStudent());
					cout<<"                                                          ->>请选择要执行的功能: ";
					cin>>strChoice;
					choice=calculateString.calculate_choice( strChoice );
				}
				else{		
					menu.manage_one_class_menu(pU->get_countStudent());
					cout<<"                                                          ->>无此项功能,请重新选择要执行的功能: ";
					cin>>strChoice;
					choice=calculateString.calculate_choice( strChoice );
				}
				switch(choice){
					case 1:
						pU->add_classmate(1);
						return n;
						break;
					case 2:
						pU->modify_classmate(1);
						return n;
						break;
					case 3:
						pU->delete_classmate(1);
						return n;
						break;
					case 4:
						pU->query_classmate(1);
						return n;
						break;
					case 0:
						return 0;
						break;
				}
			}while(choice);
		}
		else if(option>0&&option<=uCountClass+gCountClass){
			vector < Class <Graduate> > ::iterator pG= gClass.begin();
			for(int i=0;i<option-uCountClass-1;i++,pG++)
				;
			do{
				if( choice <= 4 && choice >= 0 ){
					menu.manage_one_class_menu(pG->get_countStudent());
					cout<<"                                                          ->>请选择要执行的功能: ";
					cin>>strChoice;
					choice=calculateString.calculate_choice( strChoice );
				}
				else{		
					menu.manage_one_class_menu(pG->get_countStudent());
					cout<<"                                                          ->>无此项功能,请重新选择要执行的功能: ";
					cin>>strChoice;
					choice=calculateString.calculate_choice( strChoice );
				}
				switch(choice){
					case 1:
						pG->add_classmate(2);
						return n;
						break;
					case 2:
						pG->modify_classmate(2);
						return n;
						break;
					case 3:
						pG->delete_classmate(2);
						return n;
						break;
					case 4:
						pG->query_classmate(2);
						return n;
						break;
					case 0:
						return 0;
						break;
				}
			}while(choice);
		}	
		else{
			cout<<endl;
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | 无该选项 |"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
			cout<<"                                                                              刷新：";
			system("pause");
		}
	}while(option==-1);
}

//统计某个班级各科的平均分、最高分、最低分
void ManageClass::statistic_average_max_min()
{
	string str;
	int choice;
	int i=1;
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  班  --  级   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      统    计    班    级     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(gCountClass==0&&uCountClass==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何班级信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
		for(;pU!=uClass.end();pU++){
			cout<<"                                                                            "<<i<<" : "<<pU->get_className()<<" -本科生"<<endl<<endl;
			i++;
		}
		vector < Class <Graduate> > ::iterator pG= gClass.begin();
		for(;pG!=gClass.end();pG++){
			cout<<"                                                                            "<<i<<" : "<<pG->get_className()<<" -研究生"<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-退出) 请选择班级：";
		cin>>str;
		if(str.compare("E")==0)
			return;
		choice=calculateString.calculate_real_number(str);
		if(choice>0&&choice<=uCountClass){
			vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
			for(int i=0; i<choice-1 ;i++,pU++)
				;
			for(int j=0;j<3;j++){
				if(j==0){
					cout<<endl;
					cout<<"                                                                         |-------------------------------| \n";
					cout<<"  -----------------------------------------------------------------------|            高   数            |--------------------------------------------------------------------------------\n";
					cout<<"                                                                         |-------------------------------| \n\n\n";		
				}
				else if(j==1){
					cout<<endl;
					cout<<"                                                                         |-------------------------------| \n";
					cout<<"  -----------------------------------------------------------------------|            英   语            |--------------------------------------------------------------------------------\n";
					cout<<"                                                                         |-------------------------------| \n\n\n";
					
				}
				else if(j==2){
					cout<<endl;
					cout<<"                                                                         |-------------------------------| \n";
					cout<<"  -----------------------------------------------------------------------|            C 语 言            |--------------------------------------------------------------------------------\n";
					cout<<"                                                                         |-------------------------------| \n\n\n";
					
				}
				cout<<"                         *---------------------------------------------------------------------------------------------------------------------------------------*\n";
				cout<<"                         |       平均成绩："<<setiosflags(ios::fixed)<<setw(7)<<pU->get_averageScore(j)<<"                               最高成绩："<<setw(4)<<pU->get_max(j)<<"                                  最低成绩："<<setw(4)<<pU->get_min(j)<<"                |\n";
				cout<<"                         *---------------------------------------------------------------------------------------------------------------------------------------*\n\n\n\n\n";
				
			}
			cout<<"                                                                         ！！！返回上一页,";
			system("pause");
		}
		else if(choice>0&&choice<=uCountClass+gCountClass){
			vector < Class <Graduate> > ::iterator pG= gClass.begin();
			for(int i=0;i<choice-uCountClass-1;i++,pG++)
				;
			for(int j=0;j<2;j++){
				if(j==0){
					cout<<endl;
					cout<<"                                                                         |-------------------------------| \n";
					cout<<"  -----------------------------------------------------------------------|            课   程            |--------------------------------------------------------------------------------\n";
					cout<<"                                                                         |-------------------------------| \n\n\n";
					
				}
				else if(j==1){
					cout<<endl;
					cout<<"                                                                         |-------------------------------| \n";
					cout<<"  -----------------------------------------------------------------------|            论   文            |--------------------------------------------------------------------------------\n";
					cout<<"                                                                         |-------------------------------| \n\n\n";
					
				}
				cout<<"                         *---------------------------------------------------------------------------------------------------------------------------------------*\n";
				cout<<"                         |       平均成绩："<<setiosflags(ios::fixed)<<setw(7)<<pG->get_averageScore(j)<<"                               最高成绩："<<setw(4)<<pG->get_max(j)<<"                                  最低成绩："<<setw(4)<<pG->get_min(j)<<"                 |\n";
				cout<<"                         *---------------------------------------------------------------------------------------------------------------------------------------*\n\n\n\n\n";
			}
			cout<<"                                                                         ！！！返回上一页,";
			system("pause");
		}	
		else{
			cout<<endl;
			cout<<"                                                                                   ------------\n";
			cout<<"                                                                                   | 无该选项 |"<<endl;
			cout<<"                                                                                   ------------\n"<<endl<<endl;
			cout<<"                                                                              刷新：";
			system("pause");
		}
	}while(choice==-1);
}

//统计某班级的超过课程平均成绩的学生及人数
void ManageClass::statistic_exceed_average()
{
	string str;
	int choice;
	int i=1;
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  班  --  级   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      统    计    班    级     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(gCountClass==0&&uCountClass==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何班级信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
		for(;pU!=uClass.end();pU++){
			cout<<"                                                                         "<<i<<" : "<<pU->get_className()<<" -本科生"<<endl<<endl;
			i++;
		}
		vector < Class <Graduate> > ::iterator pG= gClass.begin();
		for(;pG!=gClass.end();pG++){
			cout<<"                                                                         "<<i<<" : "<<pG->get_className()<<" -研究生"<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-退出) 请选择班级：";
		cin>>str;
		if(str.compare("E")==0)
			return;
		choice=calculateString.calculate_real_number(str);
		if(choice>0&&choice<=uCountClass){
			vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
			for(int i=0; i<choice-1 ;i++,pU++)
				;		
			pU->dispaly_exceed_ave(1);
			cout<<endl<<endl<<"                                                                         ！！！返回上一页,";
			system("pause");
		}
		else if(choice>0&&choice<=uCountClass+gCountClass){
			vector < Class <Graduate> > ::iterator pG= gClass.begin();
			for(int i=0;i<choice-uCountClass-1;i++,pG++)
				;
			pG->dispaly_exceed_ave(2);
			cout<<endl<<endl<<"                                                                         ！！！返回上一页,";
			system("pause");
		}	
		else{
			cout<<endl;
			cout<<"                                                                                   ------------\n";
			cout<<"                                                                                   | 无该选项 |"<<endl;
			cout<<"                                                                                   ------------\n"<<endl<<endl;
			cout<<"                                                                              刷新：";
			system("pause");
		}
	}while(choice==-1);
}

//统计某班级的不及格学生名单及人数
void ManageClass::statistic_fail()
{
	string str;
	int choice;
	int i=1;
	char ch;
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  班  --  级   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      统    计    班    级     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(gCountClass==0&&uCountClass==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何班级信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
		for(;pU!=uClass.end();pU++){
			cout<<"                                                                         "<<i<<" : "<<pU->get_className()<<" -本科生"<<endl<<endl;
			i++;
		}
		vector < Class <Graduate> > ::iterator pG= gClass.begin();
		for(;pG!=gClass.end();pG++){
			cout<<"                                                                         "<<i<<" : "<<pG->get_className()<<" -研究生"<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-退出) 请选择班级：";
		cin>>str;
		if(str.compare("E")==0)
			return;
		choice=calculateString.calculate_real_number(str);
		if(choice>0&&choice<=uCountClass){
			vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
			for(int i=0; i<choice-1 ;i++,pU++)
				;		
			pU->display_fail(1);
			cout<<endl<<endl<<"                                                                         ！！！返回上一页,";
			system("pause");
		}
		else if(choice>0&&choice<=uCountClass+gCountClass){
			vector < Class <Graduate> > ::iterator pG= gClass.begin();
			for(int i=0;i<choice-uCountClass-1;i++,pG++)
				;
			pG->display_fail(2);
			cout<<endl<<endl<<"                                                                         ！！！返回上一页,";
			system("pause");
		}	
		else{
			cout<<endl;
			cout<<"                                                                                   ------------\n";
			cout<<"                                                                                   | 无该选项 |"<<endl;
			cout<<"                                                                                   ------------\n"<<endl<<endl;
			cout<<"                                                                              刷新：";
			system("pause");
		}
	}while(choice==-1);
}

//统计某班级的不同等级的学生人数
void ManageClass::statistic_score_rank()
{
	int i=1;
	string str ;
	int k;
	int choice;
	system("cls");
	cout<<"\n";
	cout<<"  ******                                                             <<  --  管  --  理  --  班  --  级   --  >>                                                                    ******\n\n\n";
	cout<<"                                                                         |-------------------------------| \n";
	cout<<"  -----------------------------------------------------------------------|      统    计    班    级     |--------------------------------------------------------------------------------\n";
	cout<<"                                                                         |-------------------------------| \n\n\n\n";	
	cout<<"                                                                 -------------------------------------------------               \n\n";
	cout<<"\n";
	vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
	for(;pU!=uClass.end();pU++){
		cout<<"                                                                         "<<i<<" : "<<pU->get_className()<<" -本科生"<<endl<<endl;
		i++;
	}
	vector < Class <Graduate> > ::iterator pG= gClass.begin();
	for(;pG!=gClass.end();pG++){
		cout<<"                                                                         "<<i<<" : "<<pG->get_className()<<" -研究生"<<endl<<endl;
		i++;
	}
	cout<<"                                                                 -------------------------------------------------               \n\n\n";
	cout<<"                                                                               (E-退出) 请选择班级：";
	cin>>str; 
	if(str.compare("E")==0)
		return ;
	system("cls");
	cout<<"\n";
	cout<<"                                                                         |-------------------------------| \n";
	cout<<"  -----------------------------------------------------------------------|     班  级  成  绩  分  析    |--------------------------------------------------------------------------------\n";
	cout<<"                                                                         |-------------------------------| \n\n\n";
	choice=choice=calculateString.calculate_real_number(str);
	if(choice>0&&choice<=uCountClass){
		vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
		for(int i=0; i<choice-1 ;i++,pU++)
			;
		for(k=0;k<3;k++){
			if(k==0)
				cout<<"                                                                               #####高数成绩分析#####\n";
			else if(k==1)
				cout<<"                                                                               #####英语成绩分析#####\n";
			else if(k==2)
				cout<<"                                                                               #####C语言成绩分析#####\n";
			cout<<"\n";
			pU->get_score_rank(k);
		cout<<endl<<endl<<"                                                      *************************************************************************   \n\n\n";
		}
		cout<<"                                                                         ！！！返回上一页,";
		system("pause");
	}
	else if(choice>0&&choice<=uCountClass+gCountClass){
		vector < Class <Graduate> > ::iterator pG= gClass.begin();
		for(int i=0; i<choice-uCountClass-1 ;i++,pG++)
			;
		for(k=0;k<2;k++){
			if(k==0)
				cout<<"                                                                               #####课程成绩分析#####\n\n";
			else if(k==1)
				cout<<"                                                                               #####论文成绩分析#####\n\n";
			pG->get_score_rank(k);
		}
		cout<<endl<<endl<<"                                                      *************************************************************************   \n\n\n";
		cout<<"                                                                         ！！！返回上一页,";
		system("pause");
	}
	else{
		cout<<endl<<endl;
		cout<<"                                                                                  ------------\n";
		cout<<"                                                                                  | 无该选项 |"<<endl;
		cout<<"                                                                                  ------------\n"<<endl<<endl;
		cout<<"                                                                         ！！！返回上一页,";
		system("pause");
	}
}