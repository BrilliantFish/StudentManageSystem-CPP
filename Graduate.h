#ifndef _GRADUATE
#define _GRADUATE
//Graduate研究生类
class Graduate: public Student
{
protected:
	string researchTopic;      //研究课题
	string tutor;              //导师
public:
	Graduate();                //无参构造函数
	Graduate( int IDTemp,string nameTemp,string genderTemp,int gradeTemp,int majorIDTemp, string majorTemp,int classIDTemp, string classNameTemp,string researchTopicTemp,string tutorTemp,float lesson,float thesis);//带参构造函数
	string get_researchTopic();      //获取研究生研究课题
	string get_tutor();              //获取研究生导师
	void display_a_student();        //展示一位研究生信息
	bool set_researchTopic();        //设置研究课题
	bool set_tutor();                //设置导师
	bool set_information_to_class();  //在管理某个班级中设置学生信息
	void operator =( Graduate &g );  //重载运算符=
};
#endif