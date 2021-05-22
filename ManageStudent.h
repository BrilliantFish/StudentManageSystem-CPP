#ifndef _MANAGESTUDENT
#define _MANAGESTUDENT
//ManageStudent����ѧ����
class ManageStudent
{
protected:
	vector < Undergraduate > undergraduate;    //����������
	vector < Graduate > graduate;              //�о�������
	unsigned int countU;                       //��������Ŀ
	unsigned int countG;                       //�о�����Ŀ
	vector <int > recordID;                    //��¼����ѧ��ѧ��
	Menu menu; 
	CalculateString calculateString;
public:
	ManageStudent();                                          //ManageStudent��Ĺ��캯��
	void set_recordID(int IDtemp);                            //��¼����ѧ��ѧ��
	void clear_all_students();                                //�������ѧ��
	void set_student(Undergraduate *uTemp,Graduate *gTemp);   //���ѧ��������
	int get_countU();                                         //��ȡ����������
	int get_countG();                                         //��ȡ�о�������
	Undergraduate &get_undergraduate( int number );           //��ȡһλ������
	Graduate &get_graduate( int number);                      //��ȡһλ�о���
	void add_student( int kindStudent );                      //���ѧ��
	void modify_student(int kindStudent);                     //�޸�ѧ��
	void delete_student(int kindStudent);                     //ɾ��ѧ��
	void query_a_student(int kindStudent);                    //��ѯĳλѧ��
	void query_student(int kindStudent);                      //��ѯѧ��
	void query_all_students(int kindStudent);                 //��ѯ����ѧ��
};

#endif