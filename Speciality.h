#ifndef _SPECIALITY
#define _SPECIALITY
class Speciality
{
protected:
	vector < Class <Undergraduate> > uClass;     //本科生班级
	vector < Class <Graduate> > gClass;          //研究生班级
	unsigned int uCountClass;              //本科生班级数	
	unsigned int gCountClass;              //研究生班级数	
	string major;                          //专业名称
	int majorID;                           //专业编号
	vector <long int> recordClassID ;      //记录所有班级编号
	CalculateString calculateString;
	Menu menu;
public:
	Speciality();               //Speciality类的无参构造函数
	Speciality(int majorIDTemp,string majorTemp);           //Speciality类的构造函数
	void set_recordClassID(long int classIDTemp );          //记录所有班级编号
	void set_classes(Class <Undergraduate> *uClassTemp,Class <Graduate> *gClassTemp);           //存放班级到该专业
	bool set_majorID();                   //设置专业编号             
	bool set_major();                     //设置专业名称
	void display_speciality();            //展示专业信息
	void dispay_aLL_classes();            //展示该专业中所有班级信息
	int &get_majorID();                   //获取专业编号
	string get_major();                   //获取专业名称
	Class <Undergraduate> &get_a_uClass(int number);    //获取一个本科生班级
	Class <Graduate> &get_a_gClass(int number);         //获取一个研究生班级
	int get_uCountClass();               //获取本科生班级数目
	int get_gCountClass();               //获取研究生班级数目
	bool set_speciality_information();   //设置专业信息
	void add_class();                    //添加班级
	void modify_class();                 //修改班级信息
	void delete_class();                 //删除班级
	void query_class();                  //查询班级
};

#endif