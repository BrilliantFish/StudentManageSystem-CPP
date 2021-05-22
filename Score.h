#ifndef _SCORE
#define _SCORE
//Score成绩类
class Score
{
protected:
	int countSubject;                     //学科数目      
	int *score;                           //学科成绩数组
	int sumScore;                         //总成绩
	CalculateString calculateString;        
public:
	Score(int countSubjectTemp);                   //Score的构造函数
	bool set_score(int a,int b,int c);             //设置分数的函数
	int get_countSubject();                        //获取学科数目的函数
	int &get_scores(int number );                  //获取某学科分数的函数
	int &get_sumScore();                           //获取总分数的函数
	Score(const Score&);                           //Score的拷贝构造函数
	void operator =(Score &s);                     //重载运算符=
	~Score();                                      //Score的析构函数
};
#endif