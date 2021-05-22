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


//ManageClass��Ĺ��캯��
ManageClass::ManageClass()
{
	uCountClass=0;
	gCountClass=0;
}

//��¼���а༶���
void ManageClass::set_recordClassID(long int classIDTemp)
{
	recordClassID.push_back(classIDTemp);
	
}

//��¼����ѧ��ѧ�� 
void ManageClass::set_recordID(long int IDTemp)
{
	for(int i=0;i<uClass.size();i++)
		uClass[i].set_recordID(IDTemp);
	for(int i=0;i<gClass.size();i++)
		gClass[i].set_recordID(IDTemp);
}

//�½��༶����Ű༶��Ϣ
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

//������а༶
void ManageClass::clear_all_classes()
{
	uClass.clear();
	uCountClass=0;
	gClass.clear();
	gCountClass=0;
}

//��ȡĳ���������༶�������Ϣ
Class <Undergraduate> &ManageClass::get_one_class_U(int number)
{
	return uClass[number];
}

//��ȡĳ���о����༶�������Ϣ
Class <Graduate> &ManageClass::get_one_class_G(int number)
{
	return gClass[number];
}

//��ȡ�������༶����
int ManageClass::get_uCountClass()
{
	return uCountClass;
}

//��ȡ�о����༶����
int ManageClass::get_gCountClass()
{
	return gCountClass;
}

//��Ӱ༶
void ManageClass::add_class()
{
	string str;
	int count=0;
	string ch;

	do{
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ��  --  ��   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ��    ��    ��    ��     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
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
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         �Ƿ������Ӱ༶ ��Y-�ǣ�N-�񣩣�";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//�޸İ༶��Ϣ
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
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ��  --  ��   --  >>                                                                    ******\n\n\n";
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
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                                    1.רҵ���"<<endl;
			cout<<endl<<"                                                                                    2.�༶����"<<endl;
			cout<<endl<<"                                                                                    3.�༶���"<<endl;
			cout<<endl<<"                                                                                    0.��    ��"<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                   ->�������޸��";
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
			cout<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                                    1.רҵ���"<<endl;
			cout<<endl<<"                                                                                    2.�༶����"<<endl;
			cout<<endl<<"                                                                                    3.�༶���"<<endl;
			cout<<endl<<"                                                                                    0.��    ��"<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                   ->�������޸��";
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
			cout<<"                                                                                   ------------\n";
			cout<<"                                                                                   | �޸�ѡ�� |"<<endl;
			cout<<"                                                                                   ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<endl<<"                                                                         �Ƿ�����޸İ༶ ��Y-�ǣ�N-�񣩣�";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//ɾ���༶
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
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ��  --  ��   --  >>                                                                    ******\n\n\n";
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
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ��  --  ��   --  >>                                                                    ******\n\n\n";
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

//ͳ�ư༶��Ϣ
void ManageClass::statistics_class()
{
	int choice=0;
	string strChoice;	
	do{
		if( choice <= 4 && choice >= 0 ){
			menu.statistics_menu();
			cout<<"                                                          ->>��ѡ��Ҫִ�еĹ���: ";
			cin>>strChoice;
			choice=calculateString.calculate_choice( strChoice );
		}
		else{		
			menu.statistics_menu();
			cout<<"                                                          ->>�޴����,������ѡ��Ҫִ�еĹ���: ";
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

//����༶ѧ��
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
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ��  --  ��   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ��    ��    ��    ��     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(gCountClass==0&&uCountClass==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  ���κΰ༶��Ϣ   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ������������һҳ,";
			system("pause");
			return false;
		}
		vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
		if(n==0){
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
			cout<<"                                                                              (E-�˳�) ��ѡ��ð༶��";
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
					cout<<"                                                          ->>��ѡ��Ҫִ�еĹ���: ";
					cin>>strChoice;
					choice=calculateString.calculate_choice( strChoice );
				}
				else{		
					menu.manage_one_class_menu(pU->get_countStudent());
					cout<<"                                                          ->>�޴����,������ѡ��Ҫִ�еĹ���: ";
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
					cout<<"                                                          ->>��ѡ��Ҫִ�еĹ���: ";
					cin>>strChoice;
					choice=calculateString.calculate_choice( strChoice );
				}
				else{		
					menu.manage_one_class_menu(pG->get_countStudent());
					cout<<"                                                          ->>�޴����,������ѡ��Ҫִ�еĹ���: ";
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
			cout<<"                                                                                  | �޸�ѡ�� |"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
			cout<<"                                                                              ˢ�£�";
			system("pause");
		}
	}while(option==-1);
}

//ͳ��ĳ���༶���Ƶ�ƽ���֡���߷֡���ͷ�
void ManageClass::statistic_average_max_min()
{
	string str;
	int choice;
	int i=1;
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ��  --  ��   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ͳ    ��    ��    ��     |--------------------------------------------------------------------------------\n";
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
			cout<<"                                                                            "<<i<<" : "<<pU->get_className()<<" -������"<<endl<<endl;
			i++;
		}
		vector < Class <Graduate> > ::iterator pG= gClass.begin();
		for(;pG!=gClass.end();pG++){
			cout<<"                                                                            "<<i<<" : "<<pG->get_className()<<" -�о���"<<endl<<endl;
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
			for(int j=0;j<3;j++){
				if(j==0){
					cout<<endl;
					cout<<"                                                                         |-------------------------------| \n";
					cout<<"  -----------------------------------------------------------------------|            ��   ��            |--------------------------------------------------------------------------------\n";
					cout<<"                                                                         |-------------------------------| \n\n\n";		
				}
				else if(j==1){
					cout<<endl;
					cout<<"                                                                         |-------------------------------| \n";
					cout<<"  -----------------------------------------------------------------------|            Ӣ   ��            |--------------------------------------------------------------------------------\n";
					cout<<"                                                                         |-------------------------------| \n\n\n";
					
				}
				else if(j==2){
					cout<<endl;
					cout<<"                                                                         |-------------------------------| \n";
					cout<<"  -----------------------------------------------------------------------|            C �� ��            |--------------------------------------------------------------------------------\n";
					cout<<"                                                                         |-------------------------------| \n\n\n";
					
				}
				cout<<"                         *---------------------------------------------------------------------------------------------------------------------------------------*\n";
				cout<<"                         |       ƽ���ɼ���"<<setiosflags(ios::fixed)<<setw(7)<<pU->get_averageScore(j)<<"                               ��߳ɼ���"<<setw(4)<<pU->get_max(j)<<"                                  ��ͳɼ���"<<setw(4)<<pU->get_min(j)<<"                |\n";
				cout<<"                         *---------------------------------------------------------------------------------------------------------------------------------------*\n\n\n\n\n";
				
			}
			cout<<"                                                                         ������������һҳ,";
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
					cout<<"  -----------------------------------------------------------------------|            ��   ��            |--------------------------------------------------------------------------------\n";
					cout<<"                                                                         |-------------------------------| \n\n\n";
					
				}
				else if(j==1){
					cout<<endl;
					cout<<"                                                                         |-------------------------------| \n";
					cout<<"  -----------------------------------------------------------------------|            ��   ��            |--------------------------------------------------------------------------------\n";
					cout<<"                                                                         |-------------------------------| \n\n\n";
					
				}
				cout<<"                         *---------------------------------------------------------------------------------------------------------------------------------------*\n";
				cout<<"                         |       ƽ���ɼ���"<<setiosflags(ios::fixed)<<setw(7)<<pG->get_averageScore(j)<<"                               ��߳ɼ���"<<setw(4)<<pG->get_max(j)<<"                                  ��ͳɼ���"<<setw(4)<<pG->get_min(j)<<"                 |\n";
				cout<<"                         *---------------------------------------------------------------------------------------------------------------------------------------*\n\n\n\n\n";
			}
			cout<<"                                                                         ������������һҳ,";
			system("pause");
		}	
		else{
			cout<<endl;
			cout<<"                                                                                   ------------\n";
			cout<<"                                                                                   | �޸�ѡ�� |"<<endl;
			cout<<"                                                                                   ------------\n"<<endl<<endl;
			cout<<"                                                                              ˢ�£�";
			system("pause");
		}
	}while(choice==-1);
}

//ͳ��ĳ�༶�ĳ����γ�ƽ���ɼ���ѧ��������
void ManageClass::statistic_exceed_average()
{
	string str;
	int choice;
	int i=1;
	do{
		i=1;
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ��  --  ��   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ͳ    ��    ��    ��     |--------------------------------------------------------------------------------\n";
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
			vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
			for(int i=0; i<choice-1 ;i++,pU++)
				;		
			pU->dispaly_exceed_ave(1);
			cout<<endl<<endl<<"                                                                         ������������һҳ,";
			system("pause");
		}
		else if(choice>0&&choice<=uCountClass+gCountClass){
			vector < Class <Graduate> > ::iterator pG= gClass.begin();
			for(int i=0;i<choice-uCountClass-1;i++,pG++)
				;
			pG->dispaly_exceed_ave(2);
			cout<<endl<<endl<<"                                                                         ������������һҳ,";
			system("pause");
		}	
		else{
			cout<<endl;
			cout<<"                                                                                   ------------\n";
			cout<<"                                                                                   | �޸�ѡ�� |"<<endl;
			cout<<"                                                                                   ------------\n"<<endl<<endl;
			cout<<"                                                                              ˢ�£�";
			system("pause");
		}
	}while(choice==-1);
}

//ͳ��ĳ�༶�Ĳ�����ѧ������������
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
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ��  --  ��   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ͳ    ��    ��    ��     |--------------------------------------------------------------------------------\n";
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
			vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
			for(int i=0; i<choice-1 ;i++,pU++)
				;		
			pU->display_fail(1);
			cout<<endl<<endl<<"                                                                         ������������һҳ,";
			system("pause");
		}
		else if(choice>0&&choice<=uCountClass+gCountClass){
			vector < Class <Graduate> > ::iterator pG= gClass.begin();
			for(int i=0;i<choice-uCountClass-1;i++,pG++)
				;
			pG->display_fail(2);
			cout<<endl<<endl<<"                                                                         ������������һҳ,";
			system("pause");
		}	
		else{
			cout<<endl;
			cout<<"                                                                                   ------------\n";
			cout<<"                                                                                   | �޸�ѡ�� |"<<endl;
			cout<<"                                                                                   ------------\n"<<endl<<endl;
			cout<<"                                                                              ˢ�£�";
			system("pause");
		}
	}while(choice==-1);
}

//ͳ��ĳ�༶�Ĳ�ͬ�ȼ���ѧ������
void ManageClass::statistic_score_rank()
{
	int i=1;
	string str ;
	int k;
	int choice;
	system("cls");
	cout<<"\n";
	cout<<"  ******                                                             <<  --  ��  --  ��  --  ��  --  ��   --  >>                                                                    ******\n\n\n";
	cout<<"                                                                         |-------------------------------| \n";
	cout<<"  -----------------------------------------------------------------------|      ͳ    ��    ��    ��     |--------------------------------------------------------------------------------\n";
	cout<<"                                                                         |-------------------------------| \n\n\n\n";	
	cout<<"                                                                 -------------------------------------------------               \n\n";
	cout<<"\n";
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
	cout<<"                                                                 -------------------------------------------------               \n\n\n";
	cout<<"                                                                               (E-�˳�) ��ѡ��༶��";
	cin>>str; 
	if(str.compare("E")==0)
		return ;
	system("cls");
	cout<<"\n";
	cout<<"                                                                         |-------------------------------| \n";
	cout<<"  -----------------------------------------------------------------------|     ��  ��  ��  ��  ��  ��    |--------------------------------------------------------------------------------\n";
	cout<<"                                                                         |-------------------------------| \n\n\n";
	choice=choice=calculateString.calculate_real_number(str);
	if(choice>0&&choice<=uCountClass){
		vector < Class <Undergraduate> > ::iterator pU= uClass.begin();
		for(int i=0; i<choice-1 ;i++,pU++)
			;
		for(k=0;k<3;k++){
			if(k==0)
				cout<<"                                                                               #####�����ɼ�����#####\n";
			else if(k==1)
				cout<<"                                                                               #####Ӣ��ɼ�����#####\n";
			else if(k==2)
				cout<<"                                                                               #####C���Գɼ�����#####\n";
			cout<<"\n";
			pU->get_score_rank(k);
		cout<<endl<<endl<<"                                                      *************************************************************************   \n\n\n";
		}
		cout<<"                                                                         ������������һҳ,";
		system("pause");
	}
	else if(choice>0&&choice<=uCountClass+gCountClass){
		vector < Class <Graduate> > ::iterator pG= gClass.begin();
		for(int i=0; i<choice-uCountClass-1 ;i++,pG++)
			;
		for(k=0;k<2;k++){
			if(k==0)
				cout<<"                                                                               #####�γ̳ɼ�����#####\n\n";
			else if(k==1)
				cout<<"                                                                               #####���ĳɼ�����#####\n\n";
			pG->get_score_rank(k);
		}
		cout<<endl<<endl<<"                                                      *************************************************************************   \n\n\n";
		cout<<"                                                                         ������������һҳ,";
		system("pause");
	}
	else{
		cout<<endl<<endl;
		cout<<"                                                                                  ------------\n";
		cout<<"                                                                                  | �޸�ѡ�� |"<<endl;
		cout<<"                                                                                  ------------\n"<<endl<<endl;
		cout<<"                                                                         ������������һҳ,";
		system("pause");
	}
}