#ifndef _GRADUATE
#define _GRADUATE
//Graduate�о�����
class Graduate: public Student
{
protected:
	string researchTopic;      //�о�����
	string tutor;              //��ʦ
public:
	Graduate();                //�޲ι��캯��
	Graduate( int IDTemp,string nameTemp,string genderTemp,int gradeTemp,int majorIDTemp, string majorTemp,int classIDTemp, string classNameTemp,string researchTopicTemp,string tutorTemp,float lesson,float thesis);//���ι��캯��
	string get_researchTopic();      //��ȡ�о����о�����
	string get_tutor();              //��ȡ�о�����ʦ
	void display_a_student();        //չʾһλ�о�����Ϣ
	bool set_researchTopic();        //�����о�����
	bool set_tutor();                //���õ�ʦ
	bool set_information_to_class();  //�ڹ���ĳ���༶������ѧ����Ϣ
	void operator =( Graduate &g );  //���������=
};
#endif