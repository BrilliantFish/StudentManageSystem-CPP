#ifndef _MANAGESPE
#define _MANAGESPE
class ManageSpeciality
{  
protected:
	unsigned int countSpeciality;              //רҵ��Ŀ
	vector <Speciality> speciality;            //רҵ����
	vector <int > recordMajorID ;              //��¼����רҵ���   
	vector <long int> recordClassID ;          //��¼���а༶��� 
	CalculateString calculateString;           
	Menu menu;
public:
	ManageSpeciality();                              //���캯��
	void set_recordMajorID(int majorIDTemp);         //��¼����רҵ���
	void set_recordClassID(int classIDTemp);         //��¼���а༶��� 
	void set_speciality(Speciality &specialityTemp); //���캯��
	int get_countSpeciality();                       //��ȡרҵ��Ŀ
	Speciality &get_a_speciality(int number);        //��ȡĳ��רҵ
	void add_speciality();                           //���רҵ
	void modify_speciality();                        //�޸�רҵ��Ϣ
	void delete_speciality();                        //ɾ��רҵ
	void search_speciality();                        //��ѯרҵ��Ϣ
	void manage_speciality();                        //����ĳ��רҵ
	void clear_all_specialities();                   //�������רҵ
};
#endif