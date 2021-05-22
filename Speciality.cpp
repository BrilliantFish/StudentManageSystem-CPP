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


//Speciality����޲ι��캯��
Speciality::Speciality()
{
	uCountClass=0;
	gCountClass=0;
}

//Speciality��Ĺ��캯��
Speciality::Speciality(int majorIDTemp,string majorTemp)
{
	uCountClass=0;
	gCountClass=0;
	majorID=majorIDTemp;
	major=majorTemp;
}

//��¼���а༶���
void Speciality::set_recordClassID(long int classIDTemp )
{
	recordClassID.push_back(classIDTemp);
}

//��Ű༶����רҵ
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

//չʾרҵ��Ϣ
void Speciality::display_speciality()
{
	cout<<endl;
	cout<<"                                                                       --------------------------------------\n";
	cout<<"                                                                          | רҵ��� |   ר  ҵ  ��  ��  |\n\n";
	cout.setf(ios::left);
	cout<<"                                                                              "<<setw(8)<<majorID<<"    "<<major<<endl;
}

//չʾ��רҵ�����а༶��Ϣ
void Speciality::dispay_aLL_classes()
{
	if( uCountClass!=0||gCountClass !=0 ){
		cout<<endl<<endl<<endl;
		cout<<"                                                                  ----------------------------------------------------\n";
		cout<<"                                                                   |  �༶��� |     ��  ��  ��  ��    |  רҵ���  |\n\n";
		cout.setf(ios::left);
		if(uCountClass!=0){
			for(int i=0;i<uCountClass;i++)
				cout<<"                                                                       "<<setw(11)<<uClass[i].get_classID()<<setw(21)<<uClass[i].get_className()<<"     "<<uClass[i].get_majorID()<<endl<<endl;
		}
		if(gCountClass!=0){
			for(int i=0;i<gCountClass;i++)
				cout<<"                                                                       "<<setw(11)<<gClass[i].get_classID()<<setw(21)<<gClass[i].get_className()<<"     "<<gClass[i].get_majorID()<<endl<<endl;		}
	}
	cout<<endl<<endl<<"                                                                              -> ��רҵ�İ༶��Ŀ��"<<uCountClass+gCountClass<<" <-"<<endl<<endl<<endl;

}

//��ȡרҵ���
int &Speciality::get_majorID()
{
	return majorID;
}

//��ȡרҵ����
string Speciality::get_major()
{
	return major;
}

//��ȡ�������༶��Ŀ
int Speciality::get_uCountClass()
{
	return uCountClass;
}

//��ȡ�о����༶��Ŀ
int Speciality::get_gCountClass()
{
	return gCountClass;
}

//����רҵ��Ϣ
bool Speciality::set_speciality_information()
{
	string temp;
	cout<<endl<<"                                                                             ������רҵ��ţ�";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		majorID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                             ������רҵ���ƣ�";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		major=temp;
}

//����רҵ���
bool Speciality::set_majorID()
{
	string temp;
	cout<<endl<<"                                                                             ������רҵ��ţ�";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		majorID=calculateString.calculate_real_number(temp);
	return true;
}

//����רҵ����
bool Speciality::set_major()
{
	string temp;
	cout<<endl<<"                                                                             ������רҵ���ƣ�";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		major=temp;
	return true;
}

//��Ӱ༶
void Speciality::add_class()
{
	string str;
	string ch;
	int count=0;
	int flag;
	do{
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ר  --  ҵ   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ��    ��    ��    ��     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		cout<<"                                                                                    �� ע �� ��"<<endl<<endl;
		cout<<"                                                                                -> E-�˳�  S-���� <-  \n\n";
		cout<<"                                                                                 ||��ӵ�"<<count+1<<"���༶||"<<endl;
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                              -> 1-������  2-�о��� <-  "<<endl<<endl;
		cout<<"                                                                              ->       E-��  ��     <-  \n\n";
		cout<<"                                                                                 ��ѡ��ð༶����:";
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
					cout<<"                                                                                   |  ��ӳɹ�  |\n";
					cout<<"                                                                                   --------------"<<endl<<endl<<endl;
				}
				else{
					cout<<"                                                                              --------------------------"<<endl;
					cout<<"                                                                              |   ���ʧ�ܣ�����ظ�    |\n";
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
					cout<<"                                                                                   |  ��ӳɹ�  |\n";
					cout<<"                                                                                   --------------"<<endl<<endl<<endl;
				}
				else{
					cout<<"                                                                              --------------------------"<<endl;
					cout<<"                                                                              |   ���ʧ�ܣ�����ظ�    |\n";
					cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
				}
			}
			else
				return;
		}
		else{
			cout<<endl;
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | �޸�ѡ�� |"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         �Ƿ������Ӱ༶ ��Y-�ǣ�N-�񣩣�";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//�޸İ༶��Ϣ
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
		cout<<"                                                                        !!!!!!!!  ���κΰ༶��Ϣ   !!!!!!!!                  \n\n\n";
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                           ������������һҳ,";
		system("pause");
		return;
	}
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ר  --  ҵ   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ��    ��    ��    ��     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
		for(;pU!=uClass.end();pU++){
			cout<<"                                                                         "<<i<<" : "<<pU->get_className()<<"-������"<<endl<<endl;
			i++;
		}
		vector < Class <Graduate> > ::iterator pG= gClass.begin();
		for(;pG!=gClass.end();pG++){
			cout<<"                                                                         "<<i<<" : "<<pG->get_className()<<"-�о���"<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-�˳�) ��ѡ��༶��";
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
			cout<<endl<<"                                                                                    1.�༶����"<<endl;
			cout<<endl<<"                                                                                    2.�༶���"<<endl;
			cout<<endl<<"                                                                                    0.��    ��"<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                   ->�������޸��";
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
							cout<<"                                                                              |   �޸�ʧ�ܣ�����ظ�    |\n";
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
			cout<<endl<<"                                                                                    1.�༶����"<<endl;
			cout<<endl<<"                                                                                    2.�༶���"<<endl;
			cout<<endl<<"                                                                                    0.��    ��"<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                   ->�������޸��";
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
							cout<<"                                                                              |   �޸�ʧ�ܣ�����ظ�    |\n";
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
			cout<<"                                                                                  | �޸�ѡ�� |"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<endl<<"                                                                         �Ƿ�����޸İ༶ ��Y-�ǣ�N-�񣩣�";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//ɾ���༶
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
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ר  --  ҵ   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ɾ    ��    ��    ��     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(gCountClass==0&&uCountClass==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  ���κΰ༶��Ϣ   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ������������һҳ,";
			system("pause");
			return;
		}
		cout<<"                                                                                     �� ע �� �� \n\n";
		cout<<"                                                                             ɾ���༶��Ӧ��ѧ��Ҳ�ᱻɾ��\n\n";
		vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
		for(;pU!=uClass.end();pU++){
			cout<<"                                                                         "<<i<<" : "<<pU->get_className()<<" -������"<<endl<<endl;
			i++;
		}
		vector < Class <Graduate> > ::iterator pG= gClass.begin();
		for(;pG!=gClass.end();pG++){
			cout<<"                                                                         "<<i<<" : "<<pG->get_className()<<" -�о���"<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-�˳�) ��ѡ��༶��";
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
			cout<<"                                                                                  | �ɹ�ɾ�� |\n";
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
			cout<<"                                                                                  | �ɹ�ɾ�� |\n";
			cout<<"                                                                                  ------------\n\n";
		}	
		else{			
			cout<<endl;
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | �޸�ѡ�� |"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         �Ƿ����ɾ���༶ ��Y-�ǣ�N-�񣩣�";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//��ѯ�༶
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
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ר  --  ҵ   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ��    ѯ    ��    ��     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(gCountClass==0&&uCountClass==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  ���κΰ༶��Ϣ   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ������������һҳ,";
			system("pause");
			return;
		}
		vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
		for(;pU!=uClass.end();pU++){
			cout<<"                                                                         "<<i<<" : "<<pU->get_className()<<" -������"<<endl<<endl;
			i++;
		}
		vector < Class <Graduate> > ::iterator pG= gClass.begin();
		for(;pG!=gClass.end();pG++){
			cout<<"                                                                         "<<i<<" : "<<pG->get_className()<<" -�о���"<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-�˳�) ��ѡ��༶��";
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
			cout<<"                                                                                  | �޸�ѡ�� |"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         �Ƿ������ѯ�༶ ��Y-�ǣ�N-�񣩣�";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//��ȡһ���������༶
Class <Undergraduate> &Speciality::get_a_uClass(int number)
{
	return uClass[number];
}

//��ȡһ���о����༶
Class <Graduate> &Speciality::get_a_gClass(int number)
{
	return gClass[number];
}
