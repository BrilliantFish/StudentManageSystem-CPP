#ifndef _CLASS
#define _CLASS
template <class T>
class Class
{
protected:
	vector<T> classmates;              //学生向量
	unsigned int countStudent;         //学生数
	long int classID;                  //班级编号
	string className;                  //班级名称
	int majorID;                       //专业编号
	vector <int>  recordID;            //记录所有学生学号
	Menu menu;
	CalculateString calculateString;
public:
	Class();           //Class类的无参构造函数
	Class(int classIDTemp,string classNameTemp,int majorIDTemp);//Class类的带参构造函数
	void set_recordID(int IDTemp);           //记录所有学生学号
	T & get_a_classmate(int number);         //获取某位学生
	long int &get_classID();                 //获取班级编号
	string get_className();                  //获取班级名称
	int &get_majorID();                      //获取专业编号
	int get_countStudent();                  //获取班级学生人数
	float get_averageScore(int subject);     //统计该班级某学科平均分
	int get_max(int subject);                //统计某学科的最高分
	int get_min(int subject);                //统计某学科的最低分
	void get_score_rank( int subject);       //获取分数评价
	void set_classmates(T *classmatesTemp);  //存放该班级学生
	bool set_class_information();            //设置班级信息
	bool set_a_class_information();          //管理专业时添加班级时设置班级信息
	bool set_classID();                      //设置班级编号   
	bool set_className();                    //设置班级名称      
	bool set_majorID();                      //设置专业编号          
	void dispaly_class();                    //显示班级信息
	void dispaly_exceed_ave(int kindStudent);//展示超过平均分的学生及人数
	void display_fail(int kindStudent);      //展示不及格学生及人数
	void dispay_classmates(int kindStudent); //展示该班级的所有学生
	void add_classmate(int kindStudent);     //在该班级添加一位同学
	void modify_classmate(int kindStudent);  //在该班级修改一位同学
	void delete_classmate(int kindStudent);  //在该班级删除一位同学
	void query_classmate(int kindStudent);   //在该班级查找一位同学
};

//Class类的无参构造函数
template <class T>
Class<T>::Class<T>()
{
	countStudent=0;
}

//Class类的带参构造函数
template <class T>
Class<T>::Class<T>(int classIDTemp,string classNameTemp,int majorIDTemp)
{
	classID=classIDTemp;
	className=classNameTemp;
	majorID=majorIDTemp;
	countStudent=0;
}

//记录所有学生学号
template <class T>
void Class<T>::set_recordID(int IDTemp)      
{
	recordID.push_back(IDTemp);
}

//存放该班级学生
template <class T>
void Class<T>::set_classmates(T *classmatesTemp)
{
	classmates.push_back(*classmatesTemp);
	countStudent++;
}

//获取班级学生人数
template <class T>
int Class<T>::get_countStudent()
{
	return countStudent;
}

//获取班级编号
template <class T>
long int &Class<T>::get_classID()
{
	return classID;
}

//获取班级名称
template <class T>
string Class<T>::get_className()
{
	return className;
}

//获取专业编号
template <class T>
int &Class<T>::get_majorID()
{
	return majorID;
}

//获取分数评价
template <class T>
void Class<T>::get_score_rank(int subject)
{
	int s=-1;
	int a=0;   //优秀人数。
	int b=0;   //良好人数。
	int c=0;   //中等人数。
	int d=0;   //合格人数。
	int e=0;   //不及格人数。

	for(int i=0;i<countStudent;i++){			
		s=classmates[i].get_score(subject);
		if(s!=-1){
			switch(s/10){
				case 10:							
					a++;
					break;
				case 9:
					a++;					
					break;
				case 8:
					b++;			
					break;
				case 7:
					c++;	
					break;
				case 6:
					d++;		
					break;
				default:
					e++;		
					break;
			}
		}
	}

	cout.setf(ios::left);
	cout<<"                         *---------------*-----------------------*-----------------------*-----------------------*-----------------------*-----------------------*\n";
	cout<<"                         |    分数段     |        [100,90]       |        (90,80]        |        (80,70]        |        (70,60]        |         (60,0]        |\n";
	cout<<"                         |    (等级)     |          优秀         |         良好          |         中等          |          及格         |         不及格        |\n";
	cout<<"                         *---------------*-----------------------*-----------------------*-----------------------*-----------------------*-----------------------*\n";
	cout<<"                         |     人数      |           "<<setw(4)<<a<<"        |          "<<setw(4)<<b<<"         |          "<<setw(4)<<c<<"         |           "<<setw(4)<<d<<"        |          "<<setw(4)<<e<<"         |\n";
	cout<<"                         *---------------*-----------------------*-----------------------*-----------------------*-----------------------*-----------------------*\n";
	
}

//统计该班级某学科平均分
template <class T>
float Class<T>:: get_averageScore(int subject)
{
	float sumScore=0;
	int effectiveCount=0;
	for(int i=0;i<countStudent;i++){
		if(classmates[i].get_score(subject)!=-1){
			sumScore+=classmates[i].get_score(subject);
			effectiveCount++;
		}
	}
	if(effectiveCount==0)
		return 0;
	else
		return sumScore/effectiveCount;
}

//统计某学科的最高分
template <class T>
int Class<T>:: get_max(int subject)
{
	int i=0;
	int maxScore=0;

	if(countStudent==0)
		return -1;
	for(i=0;i<countStudent;i++){
		if(maxScore<classmates[i].get_score(subject))
			maxScore=classmates[i].get_score(subject);
	}
	return maxScore;
}

//统计某学科的最低分
template <class T>
int Class<T>:: get_min(int subject)
{
	int i=0;
	int minScore=101;

	if(countStudent==0)
		return -1;
	for(i=0;i<countStudent;i++){
		if(minScore>classmates[i].get_score(subject))
			minScore=classmates[i].get_score(subject);
	}
	return minScore;
}

//设置班级信息
template <class T>
bool Class<T>::set_class_information()
{
	string temp;
	cout<<endl;
	cout<<endl<<"                                                                   --------------------------------------------\n";
	cout<<endl<<"                                                                             请输入专业编号：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		majorID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                             请输入班级名称：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		className=temp;
	cout<<endl<<"                                                                             请输入班级编号：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		classID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                   --------------------------------------------\n\n";
	return true;
}

//管理专业时添加班级时设置班级信息
template <class T>
bool Class<T>::set_a_class_information()
{
	string temp;
	cout<<endl;
	cout<<endl<<"                                                                   --------------------------------------------\n";
	cout<<endl<<"                                                                             请输入班级名称：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		className=temp;
	cout<<endl<<"                                                                             请输入班级编号：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		classID=calculateString.calculate_real_number(temp);
	cout<<endl<<"                                                                   --------------------------------------------\n\n";
}

//设置班级编号
template <class T>
bool Class<T>::set_classID()
{
	string temp;
	cout<<endl<<"                                                                             请输入班级编号：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		classID=calculateString.calculate_real_number(temp);
	return true;
}

//设置班级名称
template <class T>
bool Class<T>::set_className()
{
	string temp;
	cout<<endl<<"                                                                             请输入班级名称：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		className=temp;
	return true;
}

//设置专业编号
template <class T>
bool Class<T>::set_majorID()
{
	string temp;
	cout<<endl<<"                                                                             请输入专业编号：";
	cin>>temp;
	if(temp.compare("E")==0)
		return false;
	else
		majorID=calculateString.calculate_real_number(temp);
	return true;

}

//显示班级信息
template <class T>
void Class<T>::dispaly_class()
{
	cout<<endl<<endl;
	cout<<"                                                                  --------------------------------------------------\n";
	cout<<"                                                                   |  班级编号 |    班  级  名  称   |  专业编号  |\n\n";
	cout.setf(ios::left);
	cout<<"                                                                       "<<setw(9)<<classID<<setw(21)<<className<<"      "<<majorID<<endl;
}

//展示超过平均分的学生及人数
template <class T>
void  Class<T>::dispaly_exceed_ave(int kindStudent)
{
	int count=0;
	if(kindStudent==1){
		for(int j=0;j<3;j++){
			if(j==0){
				cout<<endl;
				cout<<"                                                                         |-------------------------------| \n";
				cout<<"  -----------------------------------------------------------------------|            高   数            |--------------------------------------------------------------------------------\n";
				cout<<"                                                                         |-------------------------------| \n\n\n";				
			}
			else if(j==1){
				cout<<endl;
				cout<<"                                                                         |-------------------------------| \n";
				cout<<"  -----------------------------------------------------------------------|            英   语            |--------------------------------------------------------------------------------\n";
				cout<<"                                                                         |-------------------------------| \n\n\n";
					
			}
			else if(j==2){
				cout<<endl;
				cout<<"                                                                         |-------------------------------| \n";
				cout<<"  -----------------------------------------------------------------------|            C 语 言            |--------------------------------------------------------------------------------\n";
				cout<<"                                                                         |-------------------------------| \n\n\n";					
			}
			cout<<endl<<endl;
			cout<<"                                            基本资料数据                                                                             成绩数据                                            \n\n";
			cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n\n";
			for(int i=0;i<countStudent;i++){
				if(classmates[i].get_score(j)>get_averageScore(j)){
					classmates[i].display_a_student();
					count++;
				}
			}
			cout<<endl<<endl<<"                                                                              -> 超过平均分的人数："<<count<<" <-"<<endl<<endl<<endl;

		}
	}
	else if(kindStudent==2){
		for(int j=0;j<2;j++){
			if(j==0){
				cout<<endl;
				cout<<"                                                                         |-------------------------------| \n";
				cout<<"  -----------------------------------------------------------------------|            课   程            |--------------------------------------------------------------------------------\n";
				cout<<"                                                                         |-------------------------------| \n\n\n";
					
			}
			else if(j==1){
				cout<<endl;
				cout<<"                                                                         |-------------------------------| \n";
				cout<<"  -----------------------------------------------------------------------|            论   文            |--------------------------------------------------------------------------------\n";
				cout<<"                                                                         |-------------------------------| \n\n\n";
					
			}
			cout<<endl<<endl;
			cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n\n";
			cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
			for(int i=0;i<countStudent;i++){
				if(classmates[i].get_score(j)>get_averageScore(j)){
					classmates[i].display_a_student();
					count++;
				}
			}
			cout<<endl<<endl<<"                                                                              -> 超过平均分的人数："<<count<<" <-"<<endl<<endl<<endl;
		}
	}
}

//展示不及格学生及人数
template <class T>
void Class<T>::display_fail(int kindStudent)
{
	int count=0;
	if(kindStudent==1){
		for(int j=0;j<3;j++){
			if(j==0){
				cout<<endl;
				cout<<"                                                                         |-------------------------------| \n";
				cout<<"  -----------------------------------------------------------------------|            高   数            |--------------------------------------------------------------------------------\n";
				cout<<"                                                                         |-------------------------------| \n\n\n";
					
			}
			else if(j==1){
				cout<<endl;
				cout<<"                                                                         |-------------------------------| \n";
				cout<<"  -----------------------------------------------------------------------|            英   语            |--------------------------------------------------------------------------------\n";
				cout<<"                                                                         |-------------------------------| \n\n\n";
					
			}
			else if(j==2){
				cout<<endl;
				cout<<"                                                                         |-------------------------------| \n";
				cout<<"  -----------------------------------------------------------------------|            C 语 言            |--------------------------------------------------------------------------------\n";
				cout<<"                                                                         |-------------------------------| \n\n\n";
					
			}
			cout<<endl<<endl;
			cout<<"                                            基本资料数据                                                                             成绩数据                                            \n\n";
			cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n\n";
			for(int i=0;i<countStudent;i++){
				if(classmates[i].get_score(j)<60){
					classmates[i].display_a_student();
					count++;
				}
			}
			cout<<endl<<endl<<"                                                                               -> 不及格的人数："<<count<<" <-"<<endl<<endl<<endl;

		}
	}
	else if(kindStudent==2){
		for(int j=0;j<2;j++){
			if(j==0){
				cout<<endl;
				cout<<"                                                                         |-------------------------------| \n";
				cout<<"  -----------------------------------------------------------------------|            课   程            |--------------------------------------------------------------------------------\n";
				cout<<"                                                                         |-------------------------------| \n\n\n";
					
			}
			else if(j==1){
				cout<<endl;
				cout<<"                                                                         |-------------------------------| \n";
				cout<<"  -----------------------------------------------------------------------|            论   文            |--------------------------------------------------------------------------------\n";
				cout<<"                                                                         |-------------------------------| \n\n\n";
					
			}
			cout<<endl<<endl;
			cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n\n";
			cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
			for(int i=0;i<countStudent;i++){
				if(classmates[i].get_score(j)<60){
					classmates[i].display_a_student();
					count++;
				}
			}
			cout<<endl<<endl<<"                                                                               -> 不及格的人数："<<count<<" <-"<<endl<<endl<<endl;

		}
	}
}

//展示该班级的所有学生
template <class T>
void Class<T>::dispay_classmates(int kindStudent)
{
	if(kindStudent==1){
		cout<<endl<<endl;
		cout<<"                                            基本资料数据                                                                             成绩数据                                            \n\n";
		cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n";
		
		for(int i=0;i<countStudent;i++){
			classmates[i].display_a_student();
		}
		cout<<endl<<endl<<"                                                                                  "<<"<< 共有"<<countStudent<<"位学生 >>"<<endl<<endl<<endl;
	}
	if(kindStudent==2){
		cout<<endl<<endl;
		cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n\n";
		cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
		for(int i=0;i<countStudent;i++){
			classmates[i].display_a_student();
		}
		cout<<endl<<endl<<"                                                                                  "<<"<< 共有"<<countStudent<<"位学生 >>"<<endl<<endl<<endl;
	}
}

//在该班级添加一位同学
template <class T>
void Class<T>:: add_classmate(int kindStudent)
{
	string ch;
	int count=0;
	do{
		system("cls");
		cout<<"\n\n";
		cout<<"                                                                         |-------------------------------| \n";
		cout<<"  -----------------------------------------------------------------------|      添    加    学    生     |--------------------------------------------------------------------------------\n";
		cout<<"                                                                         |-------------------------------| \n\n\n\n";
		cout<<"                                                                                    【 注 意 】"<<endl<<endl;
		cout<<"                                                                                   -> E-退出 <-  \n\n";
		cout<<"                                                                                 ||添加第"<<count+1<<"位学生||"<<endl;
		cout<<"                                                                ***************************************************\n";
		T temp;	
		temp.get_majorID()=majorID;
		temp.get_classID()=classID;
		temp.get_className()=className;
		temp.get_major()=className.substr(6,className.size()-6-3);
		if(temp.set_information_to_class()){
			int flag=0;
			for(int i=0;i<recordID.size();i++){
				if(recordID[i]==temp.get_ID()){
					break;
					flag=1;
				}
			}
			if(flag==0){
				classmates.push_back(temp);
				count++;
				countStudent++;
				cout<<endl<<endl;
				cout<<"                                                                                   --------------"<<endl;
				cout<<"                                                                                   |  添加成功  |\n";
				cout<<"                                                                                   --------------"<<endl<<endl<<endl;
			}
			else{
				cout<<"                                                                              --------------------------"<<endl;
				cout<<"                                                                              |   添加失败，学号重复    |\n";
				cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
			}
		}
		else
			return;
		cout<<"                                                                ***************************************************\n";	
		cout<<endl<<"                                                                         是否继续添加学生 （Y-是，N-否）：";
		cin>>ch;
	}while(ch.compare("Y")==0);
}

//在该班级修改一位同学
template <class T>
void Class<T>:: modify_classmate(int kindStudent)
{
	string str;
	string ch;
	int choice;
	int n;
	system("cls");
	cout<<"\n";
	cout<<"                                                                         |-------------------------------| \n";
	cout<<"  -----------------------------------------------------------------------|      修    改    学    生     |--------------------------------------------------------------------------------\n";
	cout<<"                                                                         |-------------------------------| \n\n\n\n";
	if(classmates.size()==0){
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                        !!!!!!!!  无任何学生信息   !!!!!!!!                  \n\n\n";
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                           ！！！返回上一页,";
		system("pause");
		return;
	}
	else{
		cout<<"                                                                                    【 注 意 】"<<endl<<endl;
		cout<<"                                                                                   -> E- 退出 <-  \n\n";
		cout<<"                                                                ***************************************************\n\n\n";	
		cout<<"                                                                              请输入要修改的学生学号：";
		cin>>str;
		if(str.compare("E")==0)
			return;
		vector <T> ::iterator p=classmates.begin();
		n=calculateString.calculate_real_number(str);
		for(p=classmates.begin();p!=classmates.end()&& n!=p->get_ID() ;p++)
			;
		if(p!=classmates.end()){
			;
		}
		else{
			cout<<"\n\n\n";
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | 无此学生 |\n";
			cout<<"                                                                                  ------------\n\n";
			system("pause");
			return;
		}
		do{
			system("cls");
			if(kindStudent==1){
				cout<<endl<<endl;
				cout<<"                                            基本资料数据                                                                             成绩数据                                            \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n";	
			}
			else if(kindStudent==2){
				cout<<endl<<endl;
				cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n\n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
			}
			p->display_a_student();		
			cout<<"                                                                ***************************************************\n\n";
			cout<<"                                                                                   1.学    号"<<endl<<endl;
			cout<<"                                                                                   2.姓    名"<<endl<<endl;   
			cout<<"                                                                                   3.性    别"<<endl<<endl;
			cout<<"                                                                                   4.年    级"<<endl<<endl;
			cout<<"                                                                                   5.专    业"<<endl<<endl;
			cout<<"                                                                                   6.班    级"<<endl<<endl;
			if(kindStudent==1){
				cout<<"                                                                                   7.高等数学"<<endl<<endl;
				cout<<"                                                                                   8.英    语"<<endl<<endl;
				cout<<"                                                                                   9.C  语 言"<<endl<<endl;
			}
			else if(kindStudent==2){
				cout<<"                                                                                   7.综合课程"<<endl<<endl;
				cout<<"                                                                                   8.论    文"<<endl<<endl;
			}
			cout<<"                                                                                   0.返    回"<<endl<<endl;
			cout<<"                                                                ***************************************************\n";
			cout<<"                                                                -> 请选择修改项：";
			cin>>choice;
			int IDTemp=p->get_ID();
			switch(choice){
				case 1:			
					if((p->set_ID())==false)
						return;
					else{
						int flag=0;
						for(int i=0;i<recordID.size();i++){
							if(recordID[i]==p->get_ID()){
								flag=1;
								break;
							}
						}
						if(flag==1){
							p->get_ID()=IDTemp;
							cout<<endl<<endl;
							cout<<"                                                                              --------------------------"<<endl;
							cout<<"                                                                              |   修改失败，学号重复    |\n";
							cout<<"                                                                              ---------------------------"<<endl<<endl<<endl;
						}
					}
					break;
				case 2:
					if((p->set_name())==false)
						return;
					break;
				case 3:
					if((p->set_gender())==false)
						return;
					break;
				case 4:
					if((p->set_grade())==false)
						return;
					break;
				case 5:
					if((p->set_major())==false)
						return;
					break;
				case 6:
					if((p->set_class())==false)
						return ;
					break;
				case 7:
					if((p->set_score(1,1))==false)
						return ;
					break;
				case 8:
					if((p->set_score(1,2))==false)
						return ;
					break;
				case 9:
					if(kindStudent==1){
						if((p->set_score(1,3))==false)
							return ;
					}
					break;
				case 0:
					return ;
			}
			cout<<endl<<"                                                                      是否继续修改该学生信息（Y-是，N-否）：";
			cin>>ch;
		}while(ch.compare("Y")==0);
	}
}

//在该班级删除一位同学
template <class T>
void Class<T>:: delete_classmate(int kindStudent)
{
	string str;
	int n;
	system("cls");
	cout<<"\n";
	cout<<"  ******                                                              <<   --   本  --   科  --   生  --   >>                                                                         ******\n\n\n";
	cout<<"                                                                         |-------------------------------| \n";
	cout<<"  -----------------------------------------------------------------------|      删    除    学    生     |--------------------------------------------------------------------------------\n";
	cout<<"                                                                         |-------------------------------| \n\n\n\n";
	if(classmates.size()==0){
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                        !!!!!!!!  无任何学生信息   !!!!!!!!                  \n\n\n";
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                           ！！！返回上一页,";
		system("pause");
		return;
	}
	else{
		cout<<"                                                                                    【 注 意 】"<<endl<<endl;
		cout<<"                                                                                   -> E- 退出 <-  \n\n";
		cout<<"                                                                ***************************************************\n\n\n";	
		cout<<"                                                                             请输入要删除的学生学号：";
		cin>>str;
		if(str.compare("E")==0)
			return;
		vector <T> ::iterator p=classmates.begin();
		n=calculateString.calculate_real_number(str);
		for(p=classmates.begin();p!=classmates.end()&& n!=p->get_ID() ;p++)
			;
		if(p!=classmates.end()){
			classmates.erase(p);
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | 成功删除 |\n";
			cout<<"                                                                                  ------------\n\n";
			countStudent--;
		}
		else{
			cout<<"                                                                                  ------------\n";
			cout<<"                                                                                  | 无该学号 |\n";
			cout<<"                                                                                  ------------\n\n";
			cout<<"                                                                             ";
			system("pause");
			return;
		}
	}
}

//在该班级查找一位同学
template <class T>
void Class<T>:: query_classmate(int kindStudent)
{
	string str;
	int n;
	system("cls");
	cout<<"\n\n";
	cout<<"                                                                         |-------------------------------| \n";
	cout<<"  -----------------------------------------------------------------------|      查    询    学    生     |--------------------------------------------------------------------------------\n";
	cout<<"                                                                         |-------------------------------| \n\n\n\n";
	if(classmates.size()==0){
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                        !!!!!!!!  无任何学生信息   !!!!!!!!                  \n\n\n";
		cout<<"                                                       *********************************************************************   \n\n\n";
		cout<<"                                                                           ！！！返回上一页,";
		system("pause");
		return;
	}
	else{
		cout<<"                                                                                    【 注 意 】"<<endl<<endl;
		cout<<"                                                                                   -> E- 退出 <-  \n\n";
		cout<<"                                                                ***************************************************\n\n\n";	
		cout<<"                                                                        请输入要查询的学生学号或姓名：";
		cin>>str;
		if(str.compare("E")==0)
			return;
		vector <T> ::iterator p=classmates.begin();
		for(p=classmates.begin();p!=classmates.end()&& str!=p->get_name() ;p++)
			;
		if(p!=classmates.end()){
			cout<<endl<<endl;
			if(kindStudent==1){
				cout<<"                                            基本资料数据                                                                             成绩数据                                            \n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n";	
			}
			else if(kindStudent==2){
				cout<<endl<<endl;
				cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n";
				cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
			}
			for(p=classmates.begin();p!=classmates.end();p++){
				if(str==p->get_name())
					p->display_a_student();
			}
			cout<<endl<<endl<<endl<<endl<<"                                                                         ！！！返回上一页,";
			system("pause");
		}
		else{
			n=calculateString.calculate_real_number(str);
			for(p=classmates.begin();p!=classmates.end()&& n!=p->get_ID() ;p++)
				;
			if(p!=classmates.end()){
				if(kindStudent==1){
					cout<<"                                            基本资料数据                                                                             成绩数据                                            \n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"    | 学号 |  姓 名  | 性 别 | 年 级 |     专 业     |     班      级     |       #       |    高等数学   |      英语     |     C语言     |     总成绩    |    班级排名   |    年级排名   |        \n";	
				}
				else if(kindStudent==2){
					cout<<endl<<endl;
					cout<<"                                              基本资料数据                                                                                           成绩数据                                 \n";
					cout<<"  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
					cout<<"  | 学号 | 姓 名 | 性别 | 年级 |    专      业    |    班       级    |    研    究    方    向   |   导  师   |      #      | 课程综合 |  论 文  |    总成绩   |   班级排名  |   年级排名  |        \n";
				}
				p->display_a_student();
				cout<<endl<<endl<<endl<<endl<<"                                                                         ！！！返回上一页,";
				system("pause");
			}
			else{
				cout<<endl<<endl;
				cout<<"                                                                                  ------------\n";
				cout<<"                                                                                  | 无该学生 |\n";
				cout<<"                                                                                  ------------\n\n";
				cout<<"                                                                              ";
				system("pause");
				return;
			}
		}
	}
}

//获取某位学生
template <class T>
T &Class<T>:: get_a_classmate(int number)
{
	return classmates[number];
}
#endif