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


//ManageSpeciality类的构造函数
ManageSpeciality::ManageSpeciality()
{
	countSpeciality=0;
}

//记录所有专业编号 
void ManageSpeciality::set_recordMajorID(int majorIDTemp)
{
	recordMajorID.push_back(majorIDTemp);
	
}

//记录所有班级编号
void ManageSpeciality::set_recordClassID(int classIDTemp)
{
	for(int i=0;i<speciality.size();i++)
		speciality[i].set_recordClassID(classIDTemp);
}

//存放专业信息
void ManageSpeciality::set_speciality(Speciality &specialityTemp)
{
	speciality.push_back(specialityTemp);
	countSpeciality++;
}

//清除所有专业
void ManageSpeciality::clear_all_specialities()
{
	speciality.clear();
	countSpeciality=0;
}

//获取专业数目
int ManageSpeciality::get_countSpeciality()
{
	return countSpeciality;
}

//获取某个专业
Speciality &ManageSpeciality::get_a_speciality(int number)
{
	return speciality[number];
}

//添加专业
void ManageSpeciality::add_speciality()
{
	string str;
	int count=0;
	string ch;

	do{
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  专  --  业   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      添    加    专    业     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		cout<<"                                                                             ->       E-退  出       <-  \n\n";
		cout<<"                                                                                 ||添加第"<<count+1<<"个专业||"<<endl<<endl;
		cout<<"                                                                ***************************************************\n";	
		Speciality specialityTemp;
		if(specialityTemp.set_speciality_information()==false){
			return;
		}
		else{
			int flag=0;
			for(int i=0;i<recordMajorID.size();i++){
				if(recordMajorID[i]==specialityTemp.get_majorID()){
					flag=1;
					break;
				}
			}
			if(flag==0){
				speciality.push_back(specialityTemp);
				count++;
				countSpeciality++;
				cout<<endl<<endl;
				cout<<"                                                                                   --------------"<<endl;
				cout<<"                                                                                   |  添加成功  |\n";
				cout<<"                                                                                   --------------"<<endl<<endl<<endl;
			}
			else{
				cout<<"                                                                              --------------------------"<<endl;
				cout<<"                                                                              | 添加失败，专业编号重复 |\n";
				cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
			}
		}
		cout<<"                                                                ***************************************************\n"<<endl;	
		cout<<"                                                                         是否继续添加专业 （Y-是，N-否）：";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//修改专业信息
void ManageSpeciality::modify_speciality()
{
	string str;
	bool flag;
	int choice;
	int count=0;
	int i=1;
	string ch;
	if(countSpeciality==0){
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                        !!!!!!!!  无任何专业信息   !!!!!!!!                  \n\n\n";
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                           ！！！返回上一页,";
		system("pause");
		return;
	}
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  专  --  业   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      修    改    专    业     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		vector < Speciality > ::iterator p= speciality.begin();
		for(;p!=speciality.end();p++){
			cout<<"                                                                                  "<<i<<" : "<<p->get_major()<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-退出) 请选择专业：";
		cin>>str;
		if(str.compare("E")==0)
			return;
		choice=calculateString.calculate_real_number(str);

		if(choice>0 && choice<=countSpeciality){
			vector < Speciality > ::iterator pS= speciality.begin();
			for(int i=0; i<choice-1 ;i++,pS++)
				;
			cout<<endl;
			pS->display_speciality();
			cout<<endl<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                                    1.专业编号"<<endl;
			cout<<endl<<"                                                                                    2.专业名称"<<endl;
			cout<<endl<<"                                                                                    0.返    回"<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                   ->请输入修改项：";
			cin>>str;
			choice=calculateString.calculate_real_number(str);
			int majorIDTemp=p->get_majorID();
			switch(choice){
				case 1:			
					if(pS->set_majorID()==false)
						return;
					else{
						int flag=0;
						for(int i=0;i<recordMajorID.size();i++){
							if(recordMajorID[i]==p->get_majorID()){
								flag=1;
								break;
							}
						}
						if(flag==1){
							pS->get_majorID()=majorIDTemp;
							cout<<endl<<endl;
							cout<<"                                                                              --------------------------"<<endl;
							cout<<"                                                                              | 修改失败，专业编号重复 |\n";
							cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
						}
					}
					break;
				case 2:
					if(pS->set_major()==false)
						return;
					break;
				case 0:
					return;
				default:
					cout<<endl<<endl<<endl;
					cout<<"                                                                                   --------------"<<endl;
					cout<<"                                                                                   |  无此功能  |\n";
					cout<<"                                                                                   --------------"<<endl<<endl<<endl;
					break;
			}
		}
		else{
			cout<<endl<<endl<<endl;
			cout<<"                                                                                   --------------"<<endl;
			cout<<"                                                                                   |  无此功能  |\n";
			cout<<"                                                                                   --------------"<<endl<<endl<<endl;
		}
		cout<<endl<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         是否继续修改专业 （Y-是，N-否）：";
		cin>>ch;
	}while(ch.compare("E")==0);
}

//删除专业
void ManageSpeciality::delete_speciality()
{
	string str;
	int choice;
	int i=1;
	string ch;
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  专  --  业   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      删    除    专    业     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(countSpeciality==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何专业信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		cout<<"                                                                                     【 注 意 】 \n\n";
		cout<<"                                                                          删除专业对应的班级、学生也会被删除\n\n";
		vector < Speciality > ::iterator p= speciality.begin();
		for(;p!=speciality.end();p++){
			cout<<"                                                                                  "<<i<<" : "<<p->get_major()<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-退出) 请选择专业：";
		cin>>str;
		if(str.compare("E")==0)
			return;
		choice=calculateString.calculate_real_number(str);

		if(choice>0&&choice<=countSpeciality){
			vector < Speciality > ::iterator pS= speciality.begin();
			for(int i=0; i<choice-1 ;i++,pS++)
				;
			speciality.erase(pS);
			countSpeciality--;
			cout<<endl;
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | 成功删除 |\n";
			cout<<"                                                                                  ------------\n\n";
		}
		else{			
			cout<<endl;
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | 无该选项 |\n"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         是否继续删除专业 （Y-是，N-否）：";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//查询专业信息
void ManageSpeciality::search_speciality()
{
	string str;
	int choice;
	int i=1;
	string ch;
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  专  --  业   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      查    询    专    业     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(countSpeciality==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何专业信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		vector < Speciality > ::iterator p= speciality.begin();
		for(;p!=speciality.end();p++){
			cout<<"                                                                                  "<<i<<" : "<<p->get_major()<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-退出) 请选择专业：";
		cin>>str;
		if(str.compare("E")==0)
			return;
		choice=calculateString.calculate_real_number(str);

		if(choice>0&&choice<=countSpeciality){
			system("cls");
			vector < Speciality > ::iterator pS= speciality.begin();
			for(int i=0; i<choice-1 ;i++,pS++)
				;
			pS->display_speciality();
			pS->dispay_aLL_classes();
		}
		
		else{
			cout<<endl;
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | 无该选项 |"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         是否继续查询专业 （Y-是，N-否）：";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//管理某个专业
void ManageSpeciality::manage_speciality()
{
	string str;
	int option=0;
	int choice=0;
	string strChoice;
	int i=1;
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  专  --  业   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      管    理    专    业     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(countSpeciality==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  无任何专业信息   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ！！！返回上一页,";
			system("pause");
			return;
		}
		vector < Speciality > ::iterator p= speciality.begin();
		for(;p!=speciality.end();p++){
			cout<<"                                                                                  "<<i<<" : "<<p->get_major()<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                              (E-退出) 请选择该专业：";
		cin>>str;
		if(str.compare("E")==0)
			return;
		option=calculateString.calculate_real_number(str);
		if(option>0&&option<=countSpeciality){
			system("cls");
			vector < Speciality > ::iterator pS= speciality.begin();
			for(int i=0; i<option-1 ;i++,pS++)
				;	
			do{
				if( choice <= 4 && choice >= 0 ){
					menu.manage_one_speciality_menu(pS->get_uCountClass()+pS->get_gCountClass());
					cout<<"                                                          ->>请选择要执行的功能: ";
					cin>>strChoice;
					choice=calculateString.calculate_choice( strChoice );
				}
				else{		
					menu.manage_one_speciality_menu(pS->get_uCountClass()+pS->get_gCountClass());
					cout<<"                                                          ->>无此项功能,请重新选择要执行的功能: ";
					cin>>strChoice;
					choice=calculateString.calculate_choice( strChoice );
				}
				switch(choice){
					case 1:
						pS->add_class();
						break;
					case 2:
						pS->modify_class();
						break;
					case 3:
						pS->delete_class();
						break;
					case 4:
						pS->query_class();
						break;
					case 0:
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

