#ifndef _STUDENT
#define _STUDENT
//Student学生类
class Student
{
protected:
	int ID;                    //学号
	string name;               //姓名
	string gender;             //性别
	int grade;                 //年级
	int majorID;               //专业编号
	string major;              //专业名称
	long int classID;          //班级编号
	string className;          //班级名称
	int classRank;             //班级排名
	int gradeRank;             //班级排名
	Score score;               //成绩
	CalculateString calculateString;
public:
	Student(char kindStudent,int countSubject);   //构造函数
	Student(int IDTemp,string nameTemp,string genderTemp,int gradeTemp,int majorIDTemp, string majorTemp,int classIDTemp, string classNameTemp,int countSubjectTemp);    //构造函数
	int &get_ID();                //获取学生学号
	string get_name();            //获取学生姓名
	string get_gender();          //获取学生性别
	int get_grade();              //获取学生年级
	int &get_majorID();           //获取学生专业编号
	string &get_major();          //获取学生专业
	long int &get_classID();      //获取学生班级编号
	string &get_className();      //获取学生班级
	int get_score(int subject);   //获取学生某科目分数
	int get_sumScore();           //获取总分
	int &get_classRank();         //获取学生班级排名 
	int &get_gradeRank();         //获取学生年级排名
	bool set_information(int kindStudent);           //设置学生信息
	bool set_ID();                //设置学号
	bool set_name();              //设置姓名
	bool set_gender();            //设置性别
	bool set_grade();             //设置年级
	bool set_major();             //设置专业
	bool set_class();             //设置班级
	bool set_score(int kindStudent,int number);      //设置分数
};
 
#endif