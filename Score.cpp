#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;
#include "Menu.h"
#include "Calculate String.h"
#include "Score.h"
//--------------------------------Score类的函数实现--------------------------------------
//Score的构造函数
Score::Score(int countSubjectTemp=0)       
{
	sumScore=-1;
	countSubject=countSubjectTemp;
	if(countSubjectTemp!=0){
		score=new int[countSubject];
		for(int i=0;i<countSubject;i++)
			score[i]=-1;
	}
	else
		score=NULL;
}

//设置分数的函数
bool Score::set_score(int a=-1,int b=-1,int c=-1)
{
	score[0]=a;
	score[1]=b;
	if(countSubject==3){
		score[2]=c;
		if( a!=-1 && b!=-1 && c !=-1 )
			sumScore=score[0]+score[1]+score[2];
	}
	else{
		if( a!=-1 && b!=-1 )
			sumScore=score[0]+score[1];
	}
	return true;
}

//获取学科数目的函数
int Score::get_countSubject()
{
	return countSubject;
}

//获取某学科分数的函数
int &Score::get_scores(int no)
{
	return score[no];
}

//获取总分数的函数
int& Score::get_sumScore()
{
	return sumScore;
}

//Score的拷贝构造函数
Score::Score(const Score &s)
{
	countSubject=s.countSubject;
	if(s.score){
		score=new int[countSubject];
		for(int i=0;i<countSubject;i++)
			score[i]=s.score[i];
	}
	else
		score=NULL;
	sumScore=s.sumScore;
}

//Score的析构函数
Score::~Score()
{
	if(score){
		delete []score;
		score=NULL;
	}
}

//重载运算符=
void Score::operator =(Score &s)
{
	countSubject=s.countSubject;
	if(score){
		delete []score;
		score=NULL;
	}
	score=new int[s.countSubject];

	for(int i=0;i<countSubject;i++){
		score[i]=s.score[i];
	}
	sumScore=s.sumScore;
}


