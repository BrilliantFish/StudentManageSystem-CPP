#ifndef _MENU
#define _MENU
class Menu
{
public:
	void management_mode_menu();                       //选择管理模式的菜单
	void student_type_menu();                          //选择学生种类的菜单
	void manage_student_menu(int choice);              //对学生进行管理的功能菜单
	void query_menu();                                 //管理学生时的查询功能菜单
	void manage_classes_menu();                        //对班级进行管理的功能菜单
	void manage_speciality_menu();                     //对专业进行管理的功能菜单
	void manage_one_class_menu(int countStudent);      //对某个班级进行管理的功能菜单
	void manage_one_speciality_menu(int countStudent); //对某个专业进行管理的功能菜单
	void ending_menu();               //系统结束的界面
	void statistics_menu();           //管理班级时的统计功能
};

#endif

