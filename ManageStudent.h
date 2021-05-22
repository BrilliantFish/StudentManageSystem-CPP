#ifndef _MANAGESTUDENT
#define _MANAGESTUDENT
//ManageStudent管理学生类
class ManageStudent
{
protected:
	vector < Undergraduate > undergraduate;    //本科生容器
	vector < Graduate > graduate;              //研究生容器
	unsigned int countU;                       //本科生数目
	unsigned int countG;                       //研究生数目
	vector <int > recordID;                    //记录所有学生学号
	Menu menu; 
	CalculateString calculateString;
public:
	ManageStudent();                                          //ManageStudent类的构造函数
	void set_recordID(int IDtemp);                            //记录所有学生学号
	void clear_all_students();                                //清除所有学生
	void set_student(Undergraduate *uTemp,Graduate *gTemp);   //存放学生至向量
	int get_countU();                                         //获取本科生人数
	int get_countG();                                         //获取研究生人数
	Undergraduate &get_undergraduate( int number );           //获取一位本科生
	Graduate &get_graduate( int number);                      //获取一位研究生
	void add_student( int kindStudent );                      //添加学生
	void modify_student(int kindStudent);                     //修改学生
	void delete_student(int kindStudent);                     //删除学生
	void query_a_student(int kindStudent);                    //查询某位学生
	void query_student(int kindStudent);                      //查询学生
	void query_all_students(int kindStudent);                 //查询所有学生
};

#endif