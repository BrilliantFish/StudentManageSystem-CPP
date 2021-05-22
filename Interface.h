#ifndef _INTERFACE
#define _INTERFACE
class Interface 
{
private:
	ManageStudent manageStudent;           //管理学生对象
	ManageClass manageClass;               //管理班级对象
	ManageSpeciality manageSpeciality;     //管理专业对象
	Menu menu;                             //菜单对象
	CalculateString calculateString;       //计算字符串对象
public:
	void read_file(char *,char *,char *c,char *s);  //读取文件
	void manage_student();                          //管理学生           
	void manage_class();                            //管理班级
	void manage_speciality();                       //管理专业
	void refresh(int kind);                         //刷新数据
	void save_file(char *,char *,char *,char *);    //保存信息
	void run();                                     //运行函数
};

#endif