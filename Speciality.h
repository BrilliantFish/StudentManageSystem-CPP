#ifndef _SPECIALITY
#define _SPECIALITY
class Speciality
{
protected:
	vector < Class <Undergraduate> > uClass;     //�������༶
	vector < Class <Graduate> > gClass;          //�о����༶
	unsigned int uCountClass;              //�������༶��	
	unsigned int gCountClass;              //�о����༶��	
	string major;                          //רҵ����
	int majorID;                           //רҵ���
	vector <long int> recordClassID ;      //��¼���а༶���
	CalculateString calculateString;
	Menu menu;
public:
	Speciality();               //Speciality����޲ι��캯��
	Speciality(int majorIDTemp,string majorTemp);           //Speciality��Ĺ��캯��
	void set_recordClassID(long int classIDTemp );          //��¼���а༶���
	void set_classes(Class <Undergraduate> *uClassTemp,Class <Graduate> *gClassTemp);           //��Ű༶����רҵ
	bool set_majorID();                   //����רҵ���             
	bool set_major();                     //����רҵ����
	void display_speciality();            //չʾרҵ��Ϣ
	void dispay_aLL_classes();            //չʾ��רҵ�����а༶��Ϣ
	int &get_majorID();                   //��ȡרҵ���
	string get_major();                   //��ȡרҵ����
	Class <Undergraduate> &get_a_uClass(int number);    //��ȡһ���������༶
	Class <Graduate> &get_a_gClass(int number);         //��ȡһ���о����༶
	int get_uCountClass();               //��ȡ�������༶��Ŀ
	int get_gCountClass();               //��ȡ�о����༶��Ŀ
	bool set_speciality_information();   //����רҵ��Ϣ
	void add_class();                    //��Ӱ༶
	void modify_class();                 //�޸İ༶��Ϣ
	void delete_class();                 //ɾ���༶
	void query_class();                  //��ѯ�༶
};

#endif