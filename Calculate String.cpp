#include <iostream>
#include <string>
using namespace std;
#include "Calculate String.h"

//计算输入的选项内容对应的整型数字选项
int CalculateString::calculate_choice(string choice)
{
	if( choice.size() == 1){
		if( choice.compare("1") == 0)
			return 1;
		else if( choice.compare("2") == 0 )
			return 2;		
		else if( choice.compare("3") == 0 )
			return 3;		
		else if( choice.compare("4") == 0 )
			return 4;		
		else if( choice.compare("5") == 0 )
			return 5;	
		else if( choice.compare("6") == 0 )
			return 6;
		else if( choice.compare("0") == 0 )
			return 0;
		else
			return -1;
	}
	else
		return -1;
}

//计算真实的数字
int CalculateString::calculate_real_number(string strNum)
{
	int countStr=strNum.size();   //计算字符串字符数
	int realCount=0;
	int i;
	char ch;

	for(i=0;i<countStr;i++){
		ch=strNum[i];
		if( ch <= '9' && ch >= '0' ){
			if(i==0)
				realCount=(ch-48);
			else 
				realCount=realCount*10+(ch-48);
		}
		else
			return -1;
	}

	return realCount;
}