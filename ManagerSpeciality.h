#ifndef _MANAGESPE
#define _MANAGESPE
class ManageSpeciality
{  
protected:
	unsigned int countSpeciality;              //专业数目
	vector <Speciality> speciality;            //专业容器
	vector <int > recordMajorID ;              //记录所有专业编号   
	vector <long int> recordClassID ;          //记录所有班级编号 
	CalculateString calculateString;           
	Menu menu;
public:
	ManageSpeciality();                              //构造函数
	void set_recordMajorID(int majorIDTemp);         //记录所有专业编号
	void set_recordClassID(int classIDTemp);         //记录所有班级编号 
	void set_speciality(Speciality &specialityTemp); //构造函数
	int get_countSpeciality();                       //获取专业数目
	Speciality &get_a_speciality(int number);        //获取某个专业
	void add_speciality();                           //添加专业
	void modify_speciality();                        //修改专业信息
	void delete_speciality();                        //删除专业
	void search_speciality();                        //查询专业信息
	void manage_speciality();                        //管理某个专业
	void clear_all_specialities();                   //清除所有专业
};
#endif