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


//Speciality类的无参构造函数
Speciality::Speciality()
{
	uCountClass=0;
	gCountClass=0;
}

//Speciality类的构造函数
Speciality::Speciality(int majorIDTemp,string majorTemp)
{
	uCountClass=0;
	gCountClass=0;
	majorID=majorIDTemp;
	major=majorTemp;
}

//记录所有班级编号
void Speciality::set_recordClassID(long int classIDTemp )
{
	recordClassID.push_back(classIDTemp);
}

//存放班级到该专业
void Speciality::set_classes(Class <Undergraduate> *uClassTemp=NULL,Class <Graduate> *gClassTemp=NULL)
{
	if(uClassTemp!=NULL){
		uClass.push_back(*uClassTemp);
		uCountClass++;
	}
	else if(gClassTemp!=NULL){
		gClass.push_back(*gClassTemp);
		gCountClass++;
	}
}

//展示专业信息
void Speciality::display_speciality()
{
	cout<<endl;
	cout<<"                                                                       --------------------------------------\n";
	cout<<"                                                                          | 专业编号 |   专  业  名  称  |\n\n";
	cout.setf(ios::left);
	cout<<"                                                                              "<<setw(8)<<majorID<<"    "<<major<<endl;
}

//展示该专业中所有班级信息
void Speciality::dispay_aLL_classes()
{
	if( uCountClass!=0||gCountClass !=0 ){
		cout<<endl<<endl<<endl;
		cout<<"                                                                  ----------------------------------------------------\n";
		cout<<"                                                                   |  班级编号 |     班  级  名  称    |  专业编号  |\n\n";
		cout.setf(ios::left);
		if(uCountClass!=0){
			for(int i=0;i<uCountClass;i++)
				cout<<"                                                                       "<<setw(11)<<uClass[i].get_classID()<<setw(21)<<uClass[i].get_className()<<"     "<<uClass[i].get_majorID()<<endl<<endl;
		}
		if(gCountClass!=0){
			for(int i=0;i<gCountClass;i++)
				cout<<"                                                                       "<<setw(11)<<gClass[i].get_classID()<<setw(21)<<gClass[i].get_className()<<"     "<<gClass[i].get_majorID()<<endl<<endl;		}
	}
	cout<<endl<<endl<<"                                                                              -> 该专业的班级数目："<<uCountClass+gCountClass<<" <-"<<endl<<endl<<endl;

}

//获取专业编号
int &Speciality::get_majorID()
{
	return majorID;
}

//获取专业名称
string Speciality::get_major()
{
	return major;
}

//获取本科生班级数目
int Speciality::get_uCountClass()
{
	return uCountClass;
}

//获取研究生班级数目
int Speciality::get_gCountClass()
{
	return gCountClass;
}

//设置专业信息
bool Speciality::set_speciality_information()
{
	string temp;
	cout<<endl<<"                                                                             请输入专业编号：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		majorID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                             请输入专业名称：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		major=temp;
}

//设置专业编号
bool Speciality::set_majorID()
{
	string temp;
	cout<<endl<<"                                                                             请输入专业编号：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		majorID=calculateString.calculate_real_number(temp);
	return true;
}

//设置专业名称
bool Speciality::set_major()
{
	string temp;
	cout<<endl<<"                                                                             请输入专业名称：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		major=temp;
	return true;
}

//添加班级
void Speciality::add_class()
{
	string str;
	string ch;
	int count=0;
	int flag;
	do{
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  管  --  理  --  专  --  业   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      添    加    班    级     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		cout<<"                                                                                    【 注 意 】"<<endl<<endl;
		cout<<"                                                                                -> E-退出  S-跳过 <-  \n\n";
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
			uClassTemp.get_majorID()=majorID;
			if(uClassTemp.set_a_class_information()){	
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
			gClassTemp.get_majorID()=majorID;
			if(gClassTemp.set_a_class_information()){	
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
		else{
			cout<<endl;
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | 无该选项 |"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         是否继续添加班级 （Y-是，N-否）：";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//修改班级信息
void Speciality::modify_class()
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
		cout<<"  ******                                                             <<  --  管  --  理  --  专  --  业   --  >>                                                                    ******\n\n\n";
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
			pU->dispaly_class();
			cout<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                                    1.班级名称"<<endl;
			cout<<endl<<"                                                                                    2.班级编号"<<endl;
			cout<<endl<<"                                                                                    0.返    回"<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                   ->请输入修改项：";
			cin>>str;
			choice=calculateString.calculate_real_number(str);
			long int classIDTemp=pU->get_classID();
			switch(choice){
				case 1:
					if(pU->set_className()==false)
						return;
					break;
				case 2:		
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
				;
			pG->dispaly_class();
			cout<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                                    1.班级名称"<<endl;
			cout<<endl<<"                                                                                    2.班级编号"<<endl;
			cout<<endl<<"                                                                                    0.返    回"<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                   ->请输入修改项：";
			cin>>str;
			str=calculateString.calculate_real_number(str);
			long int classIDTemp=pG->get_classID();
			switch(choice){
				case 1:
					if(pG->set_className()==false)
						return;
					break;
				case 2:
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
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | 无该选项 |"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<endl<<"                                                                         是否继续修改班级 （Y-是，N-否）：";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//删除班级
void Speciality::delete_class()
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
void Speciality::query_class()
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

//获取一个本科生班级
Class <Undergraduate> &Speciality::get_a_uClass(int number)
{
	return uClass[number];
}

//获取一个研究生班级
Class <Graduate> &Speciality::get_a_gClass(int number)
{
	return gClass[number];
}
