#ifndef _INTERFACE
#define _INTERFACE
class Interface 
{
private:
	ManageStudent manageStudent;           //����ѧ������
	ManageClass manageClass;               //����༶����
	ManageSpeciality manageSpeciality;     //����רҵ����
	Menu menu;                             //�˵�����
	CalculateString calculateString;       //�����ַ�������
public:
	void read_file(char *,char *,char *c,char *s);  //��ȡ�ļ�
	void manage_student();                          //����ѧ��           
	void manage_class();                            //����༶
	void manage_speciality();                       //����רҵ
	void refresh(int kind);                         //ˢ������
	void save_file(char *,char *,char *,char *);    //������Ϣ
	void run();                                     //���к���
};

#endif