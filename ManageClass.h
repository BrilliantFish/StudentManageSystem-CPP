#ifndef _MANAGECLASS
#define _MANAGECLASS
class ManageClass
{
protected:
	vector < Class <Undergraduate> > uClass;//�������༶����
	unsigned int uCountClass;               //�������༶��Ŀ
	vector < Class <Graduate> > gClass;     //�о����༶����   
	unsigned int gCountClass;               //�о����༶��Ŀ
	vector <long int> recordClassID ;       //��¼���а༶���    
	vector <int>  recordID;                 //��¼����ѧ��ѧ��
	Menu menu;
	CalculateString calculateString;
public:
	ManageClass();            //���캯��
	void set_recordClassID(long int classIDTemp);           //��¼���а༶���  
	void set_recordID(long int IDTemp);                     //��¼����ѧ��ѧ�� 
	void set_class(Class <Undergraduate> *uClassTemp,Class <Graduate> *gClassTemp);//�½��༶����Ű༶��Ϣ
	void clear_all_classes();      //������а༶
	Class <Undergraduate> &get_one_class_U(int number);     //��ȡĳ���������༶�������Ϣ
	Class <Graduate> &get_one_class_G(int number);          //��ȡĳ���о����༶�������Ϣ
	int get_uCountClass();         //��ȡ�������༶����
	int get_gCountClass();         //��ȡ�о����༶����
	void add_class();              //��Ӱ༶
	void modify_class();           //�޸İ༶��Ϣ
	void delete_class();           //ɾ���༶
	void query_class();            //��ѯ�༶
	void statistics_class();          //ͳ�ư༶��Ϣ
	void statistic_average_max_min(); //����༶ѧ��
	void statistic_score_rank();      //ͳ��ĳ���༶���Ƶ�ƽ���֡���߷֡���ͷ�
	void statistic_exceed_average();  //ͳ��ĳ�༶�ĳ����γ�ƽ���ɼ���ѧ��������
	void statistic_fail();            //ͳ��ĳ�༶�Ĳ�����ѧ������������
	int  manage_class(int choice);    //ͳ��ĳ�༶�Ĳ�ͬ�ȼ���ѧ������
};
#endif