#ifndef _UNDERGRADUATE
#define _UNDERGRADUATE
//Undergraduate本科生类
class Undergraduate: public Student
{
public:
	Undergraduate();                        //无参构造函数
	Undergraduate(int IDTemp,string nameTemp,string genderTemp,int gradeTemp,int majorIDTemp, string majorTemp,int classIDTemp, string classNameTemp,float higherMath,float english,float c); //带参构造函数
	void display_a_student();               //显示一位本科生信息
	bool set_information_to_class();  //在管理某个班级中设置学生信息
	void operator =( Undergraduate &u );    //重载运算符=
};
#endif