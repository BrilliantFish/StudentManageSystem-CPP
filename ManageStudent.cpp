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

//ManageStudent��Ĺ��캯��
ManageStudent::ManageStudent()
{
	countU=0;     //��ѧ��������ʼ��Ϊ0
	countG=0;
}

//��¼����ѧ��ѧ��
void ManageStudent::set_recordID(int IDtemp)
{
	recordID.push_back(IDtemp);
}

//���ѧ��������
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

//�������ѧ��
void ManageStudent::clear_all_students()
{
	undergraduate.clear();
	countU=0;
	graduate.clear();
	countG=0;
}

//��ȡ����������
int ManageStudent::get_countU()
{
	return countU;
}

//��ȡ�о�������
int ManageStudent::get_countG()
{
	return countG;
}

//��ȡһλ������
Undergraduate &ManageStudent::get_undergraduate( int number )
{
	return undergraduate[number];
}

//��ȡһλ�о���
Graduate &ManageStudent::get_graduate( int number )
{
	return graduate[number];
}

//���ѧ��
void ManageStudent::add_student(int kindStudent)
{
	int count=0;
	string ch;
	int n;
	if(kindStudent==1){
		do{
			system("cls");
			cout<<"\n";
			cout<<"  ******                                                              <<   --   ��  --   ��  --   ��  --   >>                                                                         ******\n\n\n";
			cout<<"                                                                         |-------------------------------| \n";
			cout<<"  -----------------------------------------------------------------------|      ��    ��    ѧ    ��     |--------------------------------------------------------------------------------\n";
			cout<<"                                                                         |-------------------------------| \n\n\n\n";
			cout<<"                                                                                    �� ע �� ��"<<endl<<endl;
			cout<<"                                                                                    -> E-�˳� <-  \n\n";
			cout<<"                                                                                 ||��ӵ�"<<count+1<<"λѧ��||"<<endl;
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
					cout<<"                                                                                   |  ��ӳɹ�  |\n";
					cout<<"                                                                                   --------------"<<endl<<endl<<endl;
				}
				else{
					cout<<"                                                                              --------------------------"<<endl;
					cout<<"                                                                              |   ���ʧ�ܣ�ѧ���ظ�    |\n";
					cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
				}
			}
			else
				return;
			cout<<"                                                                ***************************************************\n";	
			cout<<endl<<"                                                                         �Ƿ�������ѧ�� ��Y-�ǣ�N-�񣩣�";
			cin>>ch;
		}while(ch.compare("Y")==0);
	}
	else if(kindStudent==2){
		do{
			system("cls");
			cout<<"\n";
			cout<<"  ******                                                              <<   --   ��  --   ��  --   ��  --   >>                                                                         ******\n\n\n";
			cout<<"                                                                         |-------------------------------| \n";
			cout<<"  -----------------------------------------------------------------------|      ��    ��    ѧ    ��     |--------------------------------------------------------------------------------\n";
			cout<<"                                                                         |-------------------------------| \n\n\n\n";
			cout<<"                                                                                    �� ע �� ��"<<endl<<endl;
			cout<<"                                                                                    -> E-�˳� <-  \n\n";
			cout<<"                                                                                 ||��ӵ�"<<count+1<<"λѧ��||"<<endl;
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
					cout<<"                                                                                   |  ��ӳɹ�  |\n";
					cout<<"                                                                                   --------------"<<endl<<endl<<endl;
				}
				else{
					cout<<"                                                                              --------------------------"<<endl;
					cout<<"                                                                              |   ���ʧ�ܣ�ѧ���ظ�    |\n";
					cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
				}
			}
			else 
				return;
			cout<<"                                                                ***************************************************";	
			cout<<"                                                                         �Ƿ�������ѧ�� ��Y-�ǣ�N-�񣩣�";
			cin>>ch;
		}while(ch.compare("Y")==0);
	}
}

//�޸�ѧ��
void ManageStudent::modify_student(int kindStudent)
{
	string str;
	string ch;
	int choice;
	int n;
	if(kindStudent==1){
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                              <<   --   ��  --   ��  --   ��  --   >>                                                                         ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ��    ��    ѧ    ��     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		if(undergraduate.size()==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  ���κα�������Ϣ   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ������������һҳ,";
			system("pause");
			return;
		}
		else{

			cout<<"                                                                                    �� ע �� ��"<<endl<<endl;
			cout<<"                                                                                   -> E- �˳� <-  \n\n";
			cout<<"                                                                ***************************************************\n\n\n";	
			cout<<"                                                                               ������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
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
				cout<<"                                                                                  | �޴�ѧ�� |\n";
				cout<<"                                                                                  ------------\n\n";
				system("pause");
				return;
			}
			do{
				system("cls");
				cout<<endl<<endl;
				cout<<"                                            ������������                                                                             �ɼ�����                                            \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n\n";
				p->display_a_student();
				cout<<"                                                                ***************************************************\n\n";
				cout<<"                                                                                   1.ѧ    ��"<<endl<<endl;
				cout<<"                                                                                   2.��    ��"<<endl<<endl;   
				cout<<"                                                                                   3.��    ��"<<endl<<endl;
				cout<<"                                                                                   4.��    ��"<<endl<<endl;
				cout<<"                                                                                   5.ר    ҵ"<<endl<<endl;
				cout<<"                                                                                   6.��    ��"<<endl<<endl;
				cout<<"                                                                                   7.�ߵ���ѧ"<<endl<<endl;
				cout<<"                                                                                   8.Ӣ    ��"<<endl<<endl;
				cout<<"                                                                                   9.C  �� ��"<<endl<<endl;
				cout<<"                                                                                   0.��    ��"<<endl<<endl;
				cout<<"                                                                ***************************************************\n";
				cout<<"                                                                -> ��ѡ���޸��";
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
								cout<<"                                                                              |   �޸�ʧ�ܣ�ѧ���ظ�    |\n";
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
				cout<<endl<<"                                                                      �Ƿ�����޸ĸ�ѧ����Ϣ��Y-�ǣ�N-�񣩣�";
				cin>>ch;
			}while(ch.compare("Y")==0);
		}
	}
	else if(kindStudent==2){
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                              <<   --   ��  --   ��  --   ��  --   >>                                                                         ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ��    ��    ѧ    ��     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		if(graduate.size()==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  ���κ��о�����Ϣ   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ������������һҳ,";
			system("pause");
			return;
		}
		else{
			cout<<"                                                                                    �� ע �� ��"<<endl<<endl;
			cout<<"                                                                                   -> E- �˳� <-  \n\n";
			cout<<"                                                                ***************************************************\n\n\n";	
			cout<<"                                                                              ������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
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
				cout<<"                                                                                  | �޴�ѧ�� |\n";
				cout<<"                                                                                  ------------\n\n";
				system("pause");
				return;
			}
			do{
				system("cls");
				cout<<endl<<endl;
				cout<<"                                              ������������                                                                                           �ɼ�����                                 \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
				p->display_a_student();
				cout<<"                                                                ***************************************************\n\n";
				cout<<"                                                                                   1.ѧ    ��"<<endl<<endl;
				cout<<"                                                                                   2.��    ��"<<endl<<endl;   
				cout<<"                                                                                   3.��    ��"<<endl<<endl;
				cout<<"                                                                                   4.��    ��"<<endl<<endl;
				cout<<"                                                                                   5.ר    ҵ"<<endl<<endl;
				cout<<"                                                                                   6.��    ��"<<endl<<endl;
				cout<<"                                                                                   7.�о�����"<<endl<<endl;
				cout<<"                                                                                   8.��    ʦ"<<endl<<endl;
				cout<<"                                                                                   9.�γ��ۺ�"<<endl<<endl;
				cout<<"                                                                                  10.��    ��"<<endl<<endl;
				cout<<"                                                                                   0.��    ��"<<endl<<endl;
				cout<<"                                                                ***************************************************\n";
				cout<<"                                                                -> ��ѡ���޸��";
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
								cout<<"                                                                              |   �޸�ʧ�ܣ�ѧ���ظ�    |\n";
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
				cout<<endl<<"                                                                      �Ƿ�����޸ĸ�ѧ����Ϣ��Y-�ǣ�N-�񣩣�";
				cin>>ch;
			}while(ch.compare("Y")==0);
		}
	}
}

//ɾ��ѧ��
void ManageStudent::delete_student(int kindStudent)
{
	string str;
	int n;
	if(kindStudent==1){
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                              <<   --   ��  --   ��  --   ��  --   >>                                                                         ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ɾ    ��    ѧ    ��     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		if(undergraduate.size()==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  ���κα�������Ϣ   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ������������һҳ,";
			system("pause");
			return;
		}
		else{
			cout<<"                                                                                    �� ע �� ��"<<endl<<endl;
			cout<<"                                                                                   -> E- �˳� <-  \n\n";
			cout<<"                                                                ***************************************************\n\n\n";	
			cout<<"                                                                              ������Ҫɾ����ѧ��ѧ�ţ�";
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
				cout<<"                                                                                    | �ɹ�ɾ�� |\n";
				cout<<"                                                                                    ------------\n\n";
				countU--;
			}
			else{
				cout<<endl<<endl<<endl;
				cout<<"                                                                                   --------------"<<endl;
				cout<<"                                                                                   |  �޴�ѧ��  |\n";
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
		cout<<"  ******                                                              <<   --   ��  --   ��  --   ��  --   >>                                                                         ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ɾ    ��    ѧ    ��     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		if(graduate.size()==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  ���κ��о�����Ϣ   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ������������һҳ,";
			system("pause");
			return;
		}
		else{
			cout<<"                                                                                    �� ע �� ��"<<endl<<endl;
			cout<<"                                                                                   -> E- �˳� <-  \n\n";
			cout<<"                                                                ***************************************************\n\n\n";	
			cout<<"                                                                               ������Ҫɾ����ѧ��ѧ�ţ�";
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
				cout<<"                                                                                    | �ɹ�ɾ�� |\n";
				cout<<"                                                                                    ------------\n\n";
				countG--;
			}
			else{
				cout<<endl<<endl<<endl;
				cout<<"                                                                                   --------------"<<endl;
				cout<<"                                                                                   |  �޴�ѧ��  |\n";
				cout<<"                                                                                   --------------"<<endl<<endl<<endl;
				cout<<"                                                                                ";
				system("pause");  
				return;
			}
			
		}
	}
	cout<<endl<<endl<<"                                                                ***************************************************\n\n\n";	
	cout<<"                                                                         ������������һҳ,";
	system("pause");

}

//��ѯĳλѧ��
void ManageStudent::query_a_student(int kindStudent)
{
	string str;
	int n;
	if(kindStudent==1){
		system("cls");
		cout<<"\n";
		cout<<"  ******                                                              <<   --   ��  --   ��  --   ��  --   >>                                                                         ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ��    ѯ    ѧ    ��     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		if(undergraduate.size()==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  ���κα�������Ϣ   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ������������һҳ,";
			system("pause");
			return;
		}
		else{
			cout<<"                                                                                    �� ע �� ��"<<endl<<endl;
			cout<<"                                                                                   -> E- �˳� <-  \n\n";
			cout<<"                                                                ***************************************************\n\n\n";	
			cout<<"                                                                        ������Ҫ��ѯ��ѧ��ѧ�Ż�������";
			cin>>str;
			if(str.compare("E")==0)
				return;
			vector <Undergraduate> ::iterator p=undergraduate.begin();
			for(p=undergraduate.begin();p!=undergraduate.end()&& str!=p->get_name() ;p++)
				;
			if(p!=undergraduate.end()){
				cout<<endl<<endl;
				cout<<"                                            ������������                                                                             �ɼ�����                                            \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n\n";
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
					cout<<"                                            ������������                                                                             �ɼ�����                                            \n\n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n\n";
					p->display_a_student();
				}
				else{
					cout<<"\n\n\n";
					cout<<"                                                                                  ------------\n";
					cout<<"                                                                                  | �޴�ѧ�� |\n";
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
		cout<<"  ******                                                              <<   --   ��  --   ��  --   ��  --   >>                                                                         ******\n\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ��    ѯ    ѧ    ��     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		if(graduate.size()==0){
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                        !!!!!!!!  ���κ��о�����Ϣ   !!!!!!!!                  \n\n\n";
			cout<<"                                                       *********************************************************************   \n\n\n";
			cout<<"                                                                           ������������һҳ,";
			system("pause");
			return;
		}
		else{
			cout<<"                                                                                    �� ע �� ��"<<endl<<endl;
			cout<<"                                                                                   -> E- �˳� <-  \n\n";
			cout<<"                                                                ***************************************************\n\n\n";	
			cout<<"                                                                        ������Ҫ��ѯ��ѧ��ѧ�Ż�������";
			cin>>str;
			if(str.compare("E")==0)
				return;
			vector <Graduate> ::iterator p=graduate.begin();
			for(p=graduate.begin();p!=graduate.end()&& str!=p->get_className() ;p++)
				;
			if(p!=graduate.end()){
				cout<<endl<<endl;
				cout<<"                                              ������������                                                                                           �ɼ�����                                 \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
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
					cout<<"                                              ������������                                                                                           �ɼ�����                                 \n\n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
					p->display_a_student();
				}
				else{
					cout<<"\n\n\n";
					cout<<"                                                                                  ------------\n";
					cout<<"                                                                                  | �޴�ѧ�� |\n";
					cout<<"                                                                                  ------------\n\n";
					cout<<"                                                                           ";
					system("pause");
					return;
				}
			}
		}
	}
	cout<<endl<<endl<<"                                                          ***************************************************************\n\n\n";
	cout<<"                                                                         ������������һҳ,";
	system("pause");

}

bool compare_U_ID(Undergraduate &p1,Undergraduate &p2){
	return p1.get_ID()<p2.get_ID();  //����
}

bool compare_G_ID(Graduate &p1,Graduate &p2){
	return p1.get_ID()<p2.get_ID();  //����
}

//��ѯ����ѧ��
void ManageStudent::query_all_students(int kindStudent)
{
	int pageCur=1;
	int choice=1;
	string strChoice;
	int i=0;
	int j=0;
	string strPage;
	int page;
	int clearFlag=0;        //�����ı�־����������Ϊ1��û����Ϊ0����֤��ѡ���ѡ��Ĳ˵�����Ļ��ֻ����1�Ρ�
	
	if(kindStudent==1){
		page=1;
		if(undergraduate.size()==0){	
			cout<<"\n\n\n";
			cout<<"                                                                                  -----------\n";
			cout<<"                                                                                  |  ��ѧ�� |\n";
			cout<<"                                                                                  -----------\n\n";
			cout<<"                                                                        ";
			system("pause");
			return;
		}
		sort(undergraduate.begin(),undergraduate.end(),compare_U_ID);
		int countPageU=0;     //ÿ�μ���ҳ��ʱ��Ҫ��countPage_U��Ϊ0�������´�ʹ�õ�countPage_U�������ϴε�ֵ��
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
				cout<<"                                            ������������                                                                             �ɼ�����                                            \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n\n";
				pageCur=1;
				p2=pointPageU[pageCur-1];
				for( j = 0 ; p2 != undergraduate.end() && j<10 ;p2++, j++){
					p2->display_a_student();
				}
			}
			else if( choice == 2){
				if( pageCur == 1 ){
					clearFlag=0;					
					cout<<endl<<"                                                                  |+|+|+|+|-  ��ǰΪ��ҳ������һҳ���ݣ� -|+|+|+|+|  \n"<<endl;					
				}
				else{
					system("cls");
					clearFlag=1;
					cout<<endl<<endl;
					cout<<"                                            ������������                                                                             �ɼ�����                                            \n\n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n\n";
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
					cout<<endl<<"                                                                  |+|+|+|+|-  ��ǰΪβҳ������һҳ���ݣ� -|+|+|+|+|  \n"<<endl;
				}
				else{
					system("cls");
					clearFlag=1;
					cout<<endl<<endl;
					cout<<"                                            ������������                                                                             �ɼ�����                                            \n\n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n\n";
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
				cout<<"                                            ������������                                                                             �ɼ�����                                            \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n\n";
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
						cout<<endl<<"                                                                            (�޴�ҳ��, ������ѡ��)-->>";
						cin>>strPage;
						page=calculateString.calculate_real_number(strPage);
					}
					else{
						clearFlag=0;
						cout<<endl<<endl<<"                                            -------------------------------------------------------------------------------------------- \n"<<endl;
						cout<<"                                                                                  ->  ѡ    ҳ  <-\n\n";
						cout<<"                                                                            (�� ѡ �� �� ת ҳ ��)-->>";
						cin>>strPage;
						page=calculateString.calculate_real_number(strPage);
					}
					if(page<=0||page>countPageU)
						page = -1;
				}while( page == -1);
				system("cls");
				clearFlag=1;
				cout<<endl<<endl;
				cout<<"                                            ������������                                                                             �ɼ�����                                            \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n\n";
				pageCur=page;
				p2=pointPageU[pageCur-1];
				for( j = 0 ; p2 != undergraduate.end() && j<10 ;p2++, j++){
					p2->display_a_student();
				}
			}
			do{
				if( choice == -1 ){					
					cout<<"                                                                            (�޴�ѡ�������ѡ��)-->>";					
					cin>>strChoice;
					choice=calculateString.calculate_real_number(strChoice);
				}
				else{
					if(clearFlag==1){
						cout<<endl<<endl<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
						cout<<endl<<"                                                                 ->> �� �� �� ��"<<countPageU<<"�� ҳ, �� ǰ λ �� �� ��"<<pageCur<<"�� ҳ<<-"<<endl<<endl;						
						cout<<"                                                            ********1-��ҳ  2-��һҳ  3-��һҳ  4-βҳ  5-ѡҳ********\n";
						cout<<"                                                            ********0-��           ��           ��          ʾ********\n"<<endl;
						cout<<"                                                                            (��       ѡ       ��)-->>";						
						cin>>strChoice;
						choice=calculateString.calculate_real_number(strChoice);
					}
					else{
						cout<<"                                                                            (��   ��  ��  ѡ   ��)-->>";					
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
			cout<<"                                                                                  |  ��ѧ�� |\n";
			cout<<"                                                                                  -----------\n\n";
			cout<<"                                                                        ";
			system("pause");
			return;
		}
		sort(graduate.begin(),graduate.end(),compare_G_ID);
		int countPageG=0;     //ÿ�μ���ҳ��ʱ��Ҫ��countPage_G��Ϊ0�������´�ʹ�õ�countPage_G�������ϴε�ֵ��
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
				cout<<"                                              ������������                                                                                           �ɼ�����                                 \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
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
					printf("                                                                  |+|+|+|+|-  ��ǰΪ��ҳ������һҳ���ݣ� -|+|+|+|+|  \n");					
					printf("\n");
				}
				else{
					system("cls");
					clearFlag=1;
					cout<<endl<<endl;
					cout<<"                                              ������������                                                                                           �ɼ�����                                 \n\n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
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
					cout<<endl<<"                                                                  |+|+|+|+|-  ��ǰΪ��ҳ������һҳ���ݣ� -|+|+|+|+|  \n"<<endl;					
				}
				else{
					system("cls");
					clearFlag=1;
					cout<<endl<<endl;
					cout<<"                                              ������������                                                                                           �ɼ�����                                 \n\n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
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
				cout<<"                                              ������������                                                                                           �ɼ�����                                 \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
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
						cout<<endl<<"                                                                            (�޴�ҳ��, ������ѡ��)-->>";
						cin>>strPage;
						page=calculateString.calculate_real_number(strPage);
					}
					else{
						clearFlag=0;
						cout<<endl<<"                                            -------------------------------------------------------------------------------------------- \n"<<endl;
						cout<<"                                                                                  ->  ѡ    ҳ  <-\n"<<endl;
						cout<<"                                                                            (�� ѡ �� �� ת ҳ ��)-->>";
						cin>>strPage;
						page=calculateString.calculate_real_number(strPage);
					}
					if(page<=0||page>countPageG)
						page = -1;
				}while( page == -1);
				system("cls");
				clearFlag=1;
				cout<<endl<<endl;
				cout<<"                                              ������������                                                                                           �ɼ�����                                 \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
				pageCur=page;
				p2=pointPageG[pageCur-1];
				for( j = 0 ; p2 != graduate.end() && j<10 ;p2++, j++){
					p2->display_a_student();
				}
			}
			do{
				if( choice == -1 ){					
					cout<<"                                                                            (�޴�ѡ�������ѡ��)-->>";					
					cin>>strChoice;
					choice=calculateString.calculate_real_number(strChoice);
				}
				else{
					if(clearFlag==1){
						cout<<endl<<endl<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
						cout<<endl<<endl<<"                                                                 ->> �� �� �� ��"<<countPageG<<"�� ҳ, �� ǰ λ �� �� ��"<<pageCur<<"�� ҳ<<-"<<endl<<endl;											
						cout<<"                                                            ********1-��ҳ  2-��һҳ  3-��һҳ  4-βҳ  5-ѡҳ********\n";
						cout<<"                                                            ********0-��           ��           ��          ʾ********\n"<<endl;
						cout<<"                                                                            (��       ѡ       ��)-->>";						
						cin>>strChoice;
						choice=calculateString.calculate_real_number(strChoice);
					}
					else{
						printf("                                                                            (��   ��  ��  ѡ   ��)-->>");					
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

//��ѯѧ��
void ManageStudent::query_student(int kindStudent)
{
	int choice=0;
	string strChoice;
	
	do{
		if( choice <= 2 && choice >= 0 ){
			menu.query_menu();
			cout<<"                                                          ->>��ѡ��Ҫִ�еĹ���: ";
			cin>>strChoice;
			choice=calculateString.calculate_choice( strChoice );
		}
		else{		
			menu.query_menu();
			cout<<"                                                          ->>�޴����,������ѡ��Ҫִ�еĹ���: ";
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