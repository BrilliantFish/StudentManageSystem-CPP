#ifndef _MENU
#define _MENU
class Menu
{
public:
	void management_mode_menu();                       //ѡ�����ģʽ�Ĳ˵�
	void student_type_menu();                          //ѡ��ѧ������Ĳ˵�
	void manage_student_menu(int choice);              //��ѧ�����й���Ĺ��ܲ˵�
	void query_menu();                                 //����ѧ��ʱ�Ĳ�ѯ���ܲ˵�
	void manage_classes_menu();                        //�԰༶���й���Ĺ��ܲ˵�
	void manage_speciality_menu();                     //��רҵ���й���Ĺ��ܲ˵�
	void manage_one_class_menu(int countStudent);      //��ĳ���༶���й���Ĺ��ܲ˵�
	void manage_one_speciality_menu(int countStudent); //��ĳ��רҵ���й���Ĺ��ܲ˵�
	void ending_menu();               //ϵͳ�����Ľ���
	void statistics_menu();           //����༶ʱ��ͳ�ƹ���
};

#endif

