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


//ManageSpeciality��Ĺ��캯��
ManageSpeciality::ManageSpeciality()
{
	countSpeciality=0;
}

//��¼����רҵ��� 
void ManageSpeciality::set_recordMajorID(int majorIDTemp)
{
	recordMajorID.push_back(majorIDTemp);
	
}

//��¼���а༶���
void ManageSpeciality::set_recordClassID(int classIDTemp)
{
	for(int i=0;i<speciality.size();i++)
		speciality[i].set_recordClassID(classIDTemp);
}

//���רҵ��Ϣ
void ManageSpeciality::set_speciality(Speciality &specialityTemp)
{
	speciality.push_back(specialityTemp);
	countSpeciality++;
}

//�������רҵ
void ManageSpeciality::clear_all_specialities()
{
	speciality.clear();
	countSpeciality=0;
}

//��ȡרҵ��Ŀ
int ManageSpeciality::get_countSpeciality()
{
	return countSpeciality;
}

//��ȡĳ��רҵ
Speciality &ManageSpeciality::get_a_speciality(int number)
{
	return speciality[number];
}

//���רҵ
void ManageSpeciality::add_speciality()
{
	string str;
	int count=0;
	string ch;

	do{
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ר  --  ҵ   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ��    ��    ר    ҵ     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		cout<<"                                                                             ->       E-��  ��       <-  \n\n";
		cout<<"                                                                                 ||��ӵ�"<<count+1<<"��רҵ||"<<endl<<endl;
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
				cout<<"                                                                                   |  ��ӳɹ�  |\n";
				cout<<"                                                                                   --------------"<<endl<<endl<<endl;
			}
			else{
				cout<<"                                                                              --------------------------"<<endl;
				cout<<"                                                                              | ���ʧ�ܣ�רҵ����ظ� |\n";
				cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
			}
		}
		cout<<"                                                                ***************************************************\n"<<endl;	
		cout<<"                                                                         �Ƿ�������רҵ ��Y-�ǣ�N-�񣩣�";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//�޸�רҵ��Ϣ
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
		cout<<"                                                                        !!!!!!!!  ���κ�רҵ��Ϣ   !!!!!!!!                  \n\n\n";
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
		cout<<"  -----------------------------------------------------------------------|      ��    ��    ר    ҵ     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		vector < Speciality > ::iterator p= speciality.begin();
		for(;p!=speciality.end();p++){
			cout<<"                                                                                  "<<i<<" : "<<p->get_major()<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-�˳�) ��ѡ��רҵ��";
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
			cout<<endl<<"                                                                                    1.רҵ���"<<endl;
			cout<<endl<<"                                                                                    2.רҵ����"<<endl;
			cout<<endl<<"                                                                                    0.��    ��"<<endl;
			cout<<endl<<"                                                                   --------------------------------------------\n";
			cout<<endl<<"                                                                   ->�������޸��";
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
							cout<<"                                                                              | �޸�ʧ�ܣ�רҵ����ظ� |\n";
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
					cout<<"                                                                                   |  �޴˹���  |\n";
					cout<<"                                                                                   --------------"<<endl<<endl<<endl;
					break;
			}
		}
		else{
			cout<<endl<<endl<<endl;
			cout<<"                                                                                   --------------"<<endl;
			cout<<"                                                                                   |  �޴˹���  |\n";
			cout<<"                                                                                   --------------"<<endl<<endl<<endl;
		}
		cout<<endl<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         �Ƿ�����޸�רҵ ��Y-�ǣ�N-�񣩣�";
		cin>>ch;
	}while(ch.compare("E")==0);
}

//ɾ��רҵ
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
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ר  --  ҵ   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ɾ    ��    ר    ҵ     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(countSpeciality==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  ���κ�רҵ��Ϣ   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ������������һҳ,";
			system("pause");
			return;
		}
		cout<<"                                                                                     �� ע �� �� \n\n";
		cout<<"                                                                          ɾ��רҵ��Ӧ�İ༶��ѧ��Ҳ�ᱻɾ��\n\n";
		vector < Speciality > ::iterator p= speciality.begin();
		for(;p!=speciality.end();p++){
			cout<<"                                                                                  "<<i<<" : "<<p->get_major()<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-�˳�) ��ѡ��רҵ��";
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
			cout<<"                                                                                  | �ɹ�ɾ�� |\n";
			cout<<"                                                                                  ------------\n\n";
		}
		else{			
			cout<<endl;
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | �޸�ѡ�� |\n"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         �Ƿ����ɾ��רҵ ��Y-�ǣ�N-�񣩣�";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//��ѯרҵ��Ϣ
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
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ר  --  ҵ   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ��    ѯ    ר    ҵ     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(countSpeciality==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  ���κ�רҵ��Ϣ   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ������������һҳ,";
			system("pause");
			return;
		}
		vector < Speciality > ::iterator p= speciality.begin();
		for(;p!=speciality.end();p++){
			cout<<"                                                                                  "<<i<<" : "<<p->get_major()<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                               (E-�˳�) ��ѡ��רҵ��";
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
			cout<<"                                                                                  | �޸�ѡ�� |"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
		}
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         �Ƿ������ѯרҵ ��Y-�ǣ�N-�񣩣�";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//����ĳ��רҵ
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
		cout<<"  ******                                                             <<  --  ��  --  ��  --  ר  --  ҵ   --  >>                                                                    ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ��    ��    ר    ҵ     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";	
		if(countSpeciality==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  ���κ�רҵ��Ϣ   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ������������һҳ,";
			system("pause");
			return;
		}
		vector < Speciality > ::iterator p= speciality.begin();
		for(;p!=speciality.end();p++){
			cout<<"                                                                                  "<<i<<" : "<<p->get_major()<<endl<<endl;
			i++;
		}
		cout<<"                                                                ***************************************************\n\n";	
		cout<<"                                                                              (E-�˳�) ��ѡ���רҵ��";
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
					cout<<"                                                          ->>��ѡ��Ҫִ�еĹ���: ";
					cin>>strChoice;
					choice=calculateString.calculate_choice( strChoice );
				}
				else{		
					menu.manage_one_speciality_menu(pS->get_uCountClass()+pS->get_gCountClass());
					cout<<"                                                          ->>�޴����,������ѡ��Ҫִ�еĹ���: ";
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
			cout<<"                                                                                  | �޸�ѡ�� |"<<endl;
			cout<<"                                                                                  ------------\n"<<endl<<endl;
			cout<<"                                                                              ˢ�£�";
			system("pause");
		}
	}while(option==-1);
}

