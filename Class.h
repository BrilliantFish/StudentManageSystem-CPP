#ifndef _CLASS
#define _CLASS
template <class T>
class Class
{
protected:
	vector<T> classmates;              //ѧ������
	unsigned int countStudent;         //ѧ����
	long int classID;                  //�༶���
	string className;                  //�༶����
	int majorID;                       //רҵ���
	vector <int>  recordID;            //��¼����ѧ��ѧ��
	Menu menu;
	CalculateString calculateString;
public:
	Class();           //Class����޲ι��캯��
	Class(int classIDTemp,string classNameTemp,int majorIDTemp);//Class��Ĵ��ι��캯��
	void set_recordID(int IDTemp);           //��¼����ѧ��ѧ��
	T & get_a_classmate(int number);         //��ȡĳλѧ��
	long int &get_classID();                 //��ȡ�༶���
	string get_className();                  //��ȡ�༶����
	int &get_majorID();                      //��ȡרҵ���
	int get_countStudent();                  //��ȡ�༶ѧ������
	float get_averageScore(int subject);     //ͳ�Ƹð༶ĳѧ��ƽ����
	int get_max(int subject);                //ͳ��ĳѧ�Ƶ���߷�
	int get_min(int subject);                //ͳ��ĳѧ�Ƶ���ͷ�
	void get_score_rank( int subject);       //��ȡ��������
	void set_classmates(T *classmatesTemp);  //��Ÿð༶ѧ��
	bool set_class_information();            //���ð༶��Ϣ
	bool set_a_class_information();          //����רҵʱ��Ӱ༶ʱ���ð༶��Ϣ
	bool set_classID();                      //���ð༶���   
	bool set_className();                    //���ð༶����      
	bool set_majorID();                      //����רҵ���          
	void dispaly_class();                    //��ʾ�༶��Ϣ
	void dispaly_exceed_ave(int kindStudent);//չʾ����ƽ���ֵ�ѧ��������
	void display_fail(int kindStudent);      //չʾ������ѧ��������
	void dispay_classmates(int kindStudent); //չʾ�ð༶������ѧ��
	void add_classmate(int kindStudent);     //�ڸð༶���һλͬѧ
	void modify_classmate(int kindStudent);  //�ڸð༶�޸�һλͬѧ
	void delete_classmate(int kindStudent);  //�ڸð༶ɾ��һλͬѧ
	void query_classmate(int kindStudent);   //�ڸð༶����һλͬѧ
};

//Class����޲ι��캯��
template <class T>
Class<T>::Class<T>()
{
	countStudent=0;
}

//Class��Ĵ��ι��캯��
template <class T>
Class<T>::Class<T>(int classIDTemp,string classNameTemp,int majorIDTemp)
{
	classID=classIDTemp;
	className=classNameTemp;
	majorID=majorIDTemp;
	countStudent=0;
}

//��¼����ѧ��ѧ��
template <class T>
void Class<T>::set_recordID(int IDTemp)      
{
	recordID.push_back(IDTemp);
}

//��Ÿð༶ѧ��
template <class T>
void Class<T>::set_classmates(T *classmatesTemp)
{
	classmates.push_back(*classmatesTemp);
	countStudent++;
}

//��ȡ�༶ѧ������
template <class T>
int Class<T>::get_countStudent()
{
	return countStudent;
}

//��ȡ�༶���
template <class T>
long int &Class<T>::get_classID()
{
	return classID;
}

//��ȡ�༶����
template <class T>
string Class<T>::get_className()
{
	return className;
}

//��ȡרҵ���
template <class T>
int &Class<T>::get_majorID()
{
	return majorID;
}

//��ȡ��������
template <class T>
void Class<T>::get_score_rank(int subject)
{
	int s=-1;
	int a=0;   //����������
	int b=0;   //����������
	int c=0;   //�е�������
	int d=0;   //�ϸ�������
	int e=0;   //������������

	for(int i=0;i<countStudent;i++){			
		s=classmates[i].get_score(subject);
		if(s!=-1){
			switch(s/10){
				case 10:							
					a++;
					break;
				case 9:
					a++;					
					break;
				case 8:
					b++;			
					break;
				case 7:
					c++;	
					break;
				case 6:
					d++;		
					break;
				default:
					e++;		
					break;
			}
		}
	}

	cout.setf(ios::left);
	cout<<"                         *---------------*-----------------------*-----------------------*-----------------------*-----------------------*-----------------------*\n";
	cout<<"                         |    ������     |        [100,90]       |        (90,80]        |        (80,70]        |        (70,60]        |         (60,0]        |\n";
	cout<<"                         |    (�ȼ�)     |          ����         |         ����          |         �е�          |          ����         |         ������        |\n";
	cout<<"                         *---------------*-----------------------*-----------------------*-----------------------*-----------------------*-----------------------*\n";
	cout<<"                         |     ����      |           "<<setw(4)<<a<<"        |          "<<setw(4)<<b<<"         |          "<<setw(4)<<c<<"         |           "<<setw(4)<<d<<"        |          "<<setw(4)<<e<<"         |\n";
	cout<<"                         *---------------*-----------------------*-----------------------*-----------------------*-----------------------*-----------------------*\n";
	
}

//ͳ�Ƹð༶ĳѧ��ƽ����
template <class T>
float Class<T>:: get_averageScore(int subject)
{
	float sumScore=0;
	int effectiveCount=0;
	for(int i=0;i<countStudent;i++){
		if(classmates[i].get_score(subject)!=-1){
			sumScore+=classmates[i].get_score(subject);
			effectiveCount++;
		}
	}
	if(effectiveCount==0)
		return 0;
	else
		return sumScore/effectiveCount;
}

//ͳ��ĳѧ�Ƶ���߷�
template <class T>
int Class<T>:: get_max(int subject)
{
	int i=0;
	int maxScore=0;

	if(countStudent==0)
		return -1;
	for(i=0;i<countStudent;i++){
		if(maxScore<classmates[i].get_score(subject))
			maxScore=classmates[i].get_score(subject);
	}
	return maxScore;
}

//ͳ��ĳѧ�Ƶ���ͷ�
template <class T>
int Class<T>:: get_min(int subject)
{
	int i=0;
	int minScore=101;

	if(countStudent==0)
		return -1;
	for(i=0;i<countStudent;i++){
		if(minScore>classmates[i].get_score(subject))
			minScore=classmates[i].get_score(subject);
	}
	return minScore;
}

//���ð༶��Ϣ
template <class T>
bool Class<T>::set_class_information()
{
	string temp;
	cout<<endl;
	cout<<endl<<"                                                                   --------------------------------------------\n";
	cout<<endl<<"                                                                             ������רҵ��ţ�";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		majorID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                             ������༶���ƣ�";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		className=temp;
	cout<<endl<<"                                                                             ������༶��ţ�";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		classID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                   --------------------------------------------\n\n";
	return true;
}

//����רҵʱ��Ӱ༶ʱ���ð༶��Ϣ
template <class T>
bool Class<T>::set_a_class_information()
{
	string temp;
	cout<<endl;
	cout<<endl<<"                                                                   --------------------------------------------\n";
	cout<<endl<<"                                                                             ������༶���ƣ�";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		className=temp;
	cout<<endl<<"                                                                             ������༶��ţ�";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		classID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                   --------------------------------------------\n\n";
}

//���ð༶���
template <class T>
bool Class<T>::set_classID()
{
	string temp;
	cout<<endl<<"                                                                             ������༶��ţ�";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		classID=calculateString.calculate_real_number(temp);
	return true;
}

//���ð༶����
template <class T>
bool Class<T>::set_className()
{
	string temp;
	cout<<endl<<"                                                                             ������༶���ƣ�";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		className=temp;
	return true;
}

//����רҵ���
template <class T>
bool Class<T>::set_majorID()
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

//��ʾ�༶��Ϣ
template <class T>
void Class<T>::dispaly_class()
{
	cout<<endl<<endl;
	cout<<"                                                                  --------------------------------------------------\n";
	cout<<"                                                                   |  �༶��� |    ��  ��  ��  ��   |  רҵ���  |\n\n";
	cout.setf(ios::left);
	cout<<"                                                                       "<<setw(9)<<classID<<setw(21)<<className<<"      "<<majorID<<endl;
}

//չʾ����ƽ���ֵ�ѧ��������
template <class T>
void  Class<T>::dispaly_exceed_ave(int kindStudent)
{
	int count=0;
	if(kindStudent==1){
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
			cout<<endl<<endl;
			cout<<"                                            ������������                                                                             �ɼ�����                                            \n\n";
			cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n\n";
			for(int i=0;i<countStudent;i++){
				if(classmates[i].get_score(j)>get_averageScore(j)){
					classmates[i].display_a_student();
					count++;
				}
			}
			cout<<endl<<endl<<"                                                                              -> ����ƽ���ֵ�������"<<count<<" <-"<<endl<<endl<<endl;

		}
	}
	else if(kindStudent==2){
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
			cout<<endl<<endl;
			cout<<"                                              ������������                                                                                           �ɼ�����                                 \n\n";
			cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
			for(int i=0;i<countStudent;i++){
				if(classmates[i].get_score(j)>get_averageScore(j)){
					classmates[i].display_a_student();
					count++;
				}
			}
			cout<<endl<<endl<<"                                                                              -> ����ƽ���ֵ�������"<<count<<" <-"<<endl<<endl<<endl;
		}
	}
}

//չʾ������ѧ��������
template <class T>
void Class<T>::display_fail(int kindStudent)
{
	int count=0;
	if(kindStudent==1){
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
			cout<<endl<<endl;
			cout<<"                                            ������������                                                                             �ɼ�����                                            \n\n";
			cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n\n";
			for(int i=0;i<countStudent;i++){
				if(classmates[i].get_score(j)<60){
					classmates[i].display_a_student();
					count++;
				}
			}
			cout<<endl<<endl<<"                                                                               -> �������������"<<count<<" <-"<<endl<<endl<<endl;

		}
	}
	else if(kindStudent==2){
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
			cout<<endl<<endl;
			cout<<"                                              ������������                                                                                           �ɼ�����                                 \n\n";
			cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
			for(int i=0;i<countStudent;i++){
				if(classmates[i].get_score(j)<60){
					classmates[i].display_a_student();
					count++;
				}
			}
			cout<<endl<<endl<<"                                                                               -> �������������"<<count<<" <-"<<endl<<endl<<endl;

		}
	}
}

//չʾ�ð༶������ѧ��
template <class T>
void Class<T>::dispay_classmates(int kindStudent)
{
	if(kindStudent==1){
		cout<<endl<<endl;
		cout<<"                                            ������������                                                                             �ɼ�����                                            \n\n";
		cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n";
		
		for(int i=0;i<countStudent;i++){
			classmates[i].display_a_student();
		}
		cout<<endl<<endl<<"                                                                                  "<<"<< ����"<<countStudent<<"λѧ�� >>"<<endl<<endl<<endl;
	}
	if(kindStudent==2){
		cout<<endl<<endl;
		cout<<"                                              ������������                                                                                           �ɼ�����                                 \n\n";
		cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
		for(int i=0;i<countStudent;i++){
			classmates[i].display_a_student();
		}
		cout<<endl<<endl<<"                                                                                  "<<"<< ����"<<countStudent<<"λѧ�� >>"<<endl<<endl<<endl;
	}
}

//�ڸð༶���һλͬѧ
template <class T>
void Class<T>:: add_classmate(int kindStudent)
{
	string ch;
	int count=0;
	do{
		system("cls");
		cout<<"\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      ��    ��    ѧ    ��     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		cout<<"                                                                                    �� ע �� ��"<<endl<<endl;
		cout<<"                                                                                   -> E-�˳� <-  \n\n";
		cout<<"                                                                                 ||��ӵ�"<<count+1<<"λѧ��||"<<endl;
		cout<<"                                                                ***************************************************\n";
		T temp;	
		temp.get_majorID()=majorID;
		temp.get_classID()=classID;
		temp.get_className()=className;
		temp.get_major()=className.substr(6,className.size()-6-3);
		if(temp.set_information_to_class()){
			int flag=0;
			for(int i=0;i<recordID.size();i++){
				if(recordID[i]==temp.get_ID()){
					break;
					flag=1;
				}
			}
			if(flag==0){
				classmates.push_back(temp);
				count++;
				countStudent++;
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

//�ڸð༶�޸�һλͬѧ
template <class T>
void Class<T>:: modify_classmate(int kindStudent)
{
	string str;
	string ch;
	int choice;
	int n;
	system("cls");
	cout<<"\n";
	cout<<"                                                                         |-------------------------------| \n";
	cout<<"  -----------------------------------------------------------------------|      ��    ��    ѧ    ��     |--------------------------------------------------------------------------------\n";
	cout<<"                                                                         |-------------------------------| \n\n\n\n";
	if(classmates.size()==0){
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                        !!!!!!!!  ���κ�ѧ����Ϣ   !!!!!!!!                  \n\n\n";
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
		vector <T> ::iterator p=classmates.begin();
		n=calculateString.calculate_real_number(str);
		for(p=classmates.begin();p!=classmates.end()&& n!=p->get_ID() ;p++)
			;
		if(p!=classmates.end()){
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
			if(kindStudent==1){
				cout<<endl<<endl;
				cout<<"                                            ������������                                                                             �ɼ�����                                            \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n";	
			}
			else if(kindStudent==2){
				cout<<endl<<endl;
				cout<<"                                              ������������                                                                                           �ɼ�����                                 \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
			}
			p->display_a_student();		
			cout<<"                                                                ***************************************************\n\n";
			cout<<"                                                                                   1.ѧ    ��"<<endl<<endl;
			cout<<"                                                                                   2.��    ��"<<endl<<endl;   
			cout<<"                                                                                   3.��    ��"<<endl<<endl;
			cout<<"                                                                                   4.��    ��"<<endl<<endl;
			cout<<"                                                                                   5.ר    ҵ"<<endl<<endl;
			cout<<"                                                                                   6.��    ��"<<endl<<endl;
			if(kindStudent==1){
				cout<<"                                                                                   7.�ߵ���ѧ"<<endl<<endl;
				cout<<"                                                                                   8.Ӣ    ��"<<endl<<endl;
				cout<<"                                                                                   9.C  �� ��"<<endl<<endl;
			}
			else if(kindStudent==2){
				cout<<"                                                                                   7.�ۺϿγ�"<<endl<<endl;
				cout<<"                                                                                   8.��    ��"<<endl<<endl;
			}
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
					if(kindStudent==1){
						if((p->set_score(1,3))==false)
							return ;
					}
					break;
				case 0:
					return ;
			}
			cout<<endl<<"                                                                      �Ƿ�����޸ĸ�ѧ����Ϣ��Y-�ǣ�N-�񣩣�";
			cin>>ch;
		}while(ch.compare("Y")==0);
	}
}

//�ڸð༶ɾ��һλͬѧ
template <class T>
void Class<T>:: delete_classmate(int kindStudent)
{
	string str;
	int n;
	system("cls");
	cout<<"\n";
	cout<<"  ******                                                              <<   --   ��  --   ��  --   ��  --   >>                                                                         ******\n\n\n";
	cout<<"                                                                         |-------------------------------| \n";
	cout<<"  -----------------------------------------------------------------------|      ɾ    ��    ѧ    ��     |--------------------------------------------------------------------------------\n";
	cout<<"                                                                         |-------------------------------| \n\n\n\n";
	if(classmates.size()==0){
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                        !!!!!!!!  ���κ�ѧ����Ϣ   !!!!!!!!                  \n\n\n";
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                           ������������һҳ,";
		system("pause");
		return;
	}
	else{
		cout<<"                                                                                    �� ע �� ��"<<endl<<endl;
		cout<<"                                                                                   -> E- �˳� <-  \n\n";
		cout<<"                                                                ***************************************************\n\n\n";	
		cout<<"                                                                             ������Ҫɾ����ѧ��ѧ�ţ�";
		cin>>str;
		if(str.compare("E")==0)
			return;
		vector <T> ::iterator p=classmates.begin();
		n=calculateString.calculate_real_number(str);
		for(p=classmates.begin();p!=classmates.end()&& n!=p->get_ID() ;p++)
			;
		if(p!=classmates.end()){
			classmates.erase(p);
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | �ɹ�ɾ�� |\n";
			cout<<"                                                                                  ------------\n\n";
			countStudent--;
		}
		else{
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | �޸�ѧ�� |\n";
			cout<<"                                                                                  ------------\n\n";
			cout<<"                                                                             ";
			system("pause");
			return;
		}
	}
}

//�ڸð༶����һλͬѧ
template <class T>
void Class<T>:: query_classmate(int kindStudent)
{
	string str;
	int n;
	system("cls");
	cout<<"\n\n";
	cout<<"                                                                         |-------------------------------| \n";
	cout<<"  -----------------------------------------------------------------------|      ��    ѯ    ѧ    ��     |--------------------------------------------------------------------------------\n";
	cout<<"                                                                         |-------------------------------| \n\n\n\n";
	if(classmates.size()==0){
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                        !!!!!!!!  ���κ�ѧ����Ϣ   !!!!!!!!                  \n\n\n";
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
		vector <T> ::iterator p=classmates.begin();
		for(p=classmates.begin();p!=classmates.end()&& str!=p->get_name() ;p++)
			;
		if(p!=classmates.end()){
			cout<<endl<<endl;
			if(kindStudent==1){
				cout<<"                                            ������������                                                                             �ɼ�����                                            \n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n";	
			}
			else if(kindStudent==2){
				cout<<endl<<endl;
				cout<<"                                              ������������                                                                                           �ɼ�����                                 \n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
			}
			for(p=classmates.begin();p!=classmates.end();p++){
				if(str==p->get_name())
					p->display_a_student();
			}
			cout<<endl<<endl<<endl<<endl<<"                                                                         ������������һҳ,";
			system("pause");
		}
		else{
			n=calculateString.calculate_real_number(str);
			for(p=classmates.begin();p!=classmates.end()&& n!=p->get_ID() ;p++)
				;
			if(p!=classmates.end()){
				if(kindStudent==1){
					cout<<"                                            ������������                                                                             �ɼ�����                                            \n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"    | ѧ�� |  �� ��  | �� �� | �� �� |     ר ҵ     |     ��      ��     |       #       |    �ߵ���ѧ   |      Ӣ��     |     C����     |     �ܳɼ�    |    �༶����   |    �꼶����   |        \n";	
				}
				else if(kindStudent==2){
					cout<<endl<<endl;
					cout<<"                                              ������������                                                                                           �ɼ�����                                 \n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"  | ѧ�� | �� �� | �Ա� | �꼶 |    ר      ҵ    |    ��       ��    |    ��    ��    ��    ��   |   ��  ʦ   |      #      | �γ��ۺ� |  �� ��  |    �ܳɼ�   |   �༶����  |   �꼶����  |        \n";
				}
				p->display_a_student();
				cout<<endl<<endl<<endl<<endl<<"                                                                         ������������һҳ,";
				system("pause");
			}
			else{
				cout<<endl<<endl;
				cout<<"                                                                                  ------------\n";
				cout<<"                                                                                  | �޸�ѧ�� |\n";
				cout<<"                                                                                  ------------\n\n";
				cout<<"                                                                              ";
				system("pause");
				return;
			}
		}
	}
}

//��ȡĳλѧ��
template <class T>
T &Class<T>:: get_a_classmate(int number)
{
	return classmates[number];
}
#endif