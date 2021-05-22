#ifndef _MANAGECLASS
#define _MANAGECLASS
class ManageClass
{
protected:
	vector < Class <Undergraduate> > uClass;//本科生班级容器
	unsigned int uCountClass;               //本科生班级数目
	vector < Class <Graduate> > gClass;     //研究生班级容器   
	unsigned int gCountClass;               //研究生班级数目
	vector <long int> recordClassID ;       //记录所有班级编号    
	vector <int>  recordID;                 //记录所有学生学号
	Menu menu;
	CalculateString calculateString;
public:
	ManageClass();            //构造函数
	void set_recordClassID(long int classIDTemp);           //记录所有班级编号  
	void set_recordID(long int IDTemp);                     //记录所有学生学号 
	void set_class(Class <Undergraduate> *uClassTemp,Class <Graduate> *gClassTemp);//新建班级，存放班级信息
	void clear_all_classes();      //清除所有班级
	Class <Undergraduate> &get_one_class_U(int number);     //获取某个本科生班级来存放信息
	Class <Graduate> &get_one_class_G(int number);          //获取某个研究生班级来存放信息
	int get_uCountClass();         //获取本科生班级数量
	int get_gCountClass();         //获取研究生班级数量
	void add_class();              //添加班级
	void modify_class();           //修改班级信息
	void delete_class();           //删除班级
	void query_class();            //查询班级
	void statistics_class();          //统计班级信息
	void statistic_average_max_min(); //管理班级学生
	void statistic_score_rank();      //统计某个班级各科的平均分、最高分、最低分
	void statistic_exceed_average();  //统计某班级的超过课程平均成绩的学生及人数
	void statistic_fail();            //统计某班级的不及格学生名单及人数
	int  manage_class(int choice);    //统计某班级的不同等级的学生人数
};
#endif