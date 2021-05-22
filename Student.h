#ifndef _STUDENT
#define _STUDENT
//Studentѧ����
class Student
{
protected:
	int ID;                    //ѧ��
	string name;               //����
	string gender;             //�Ա�
	int grade;                 //�꼶
	int majorID;               //רҵ���
	string major;              //רҵ����
	long int classID;          //�༶���
	string className;          //�༶����
	int classRank;             //�༶����
	int gradeRank;             //�༶����
	Score score;               //�ɼ�
	CalculateString calculateString;
public:
	Student(char kindStudent,int countSubject);   //���캯��
	Student(int IDTemp,string nameTemp,string genderTemp,int gradeTemp,int majorIDTemp, string majorTemp,int classIDTemp, string classNameTemp,int countSubjectTemp);    //���캯��
	int &get_ID();                //��ȡѧ��ѧ��
	string get_name();            //��ȡѧ������
	string get_gender();          //��ȡѧ���Ա�
	int get_grade();              //��ȡѧ���꼶
	int &get_majorID();           //��ȡѧ��רҵ���
	string &get_major();          //��ȡѧ��רҵ
	long int &get_classID();      //��ȡѧ���༶���
	string &get_className();      //��ȡѧ���༶
	int get_score(int subject);   //��ȡѧ��ĳ��Ŀ����
	int get_sumScore();           //��ȡ�ܷ�
	int &get_classRank();         //��ȡѧ���༶���� 
	int &get_gradeRank();         //��ȡѧ���꼶����
	bool set_information(int kindStudent);           //����ѧ����Ϣ
	bool set_ID();                //����ѧ��
	bool set_name();              //��������
	bool set_gender();            //�����Ա�
	bool set_grade();             //�����꼶
	bool set_major();             //����רҵ
	bool set_class();             //���ð༶
	bool set_score(int kindStudent,int number);      //���÷���
};
 
#endif