#ifndef _SCORE
#define _SCORE
//Score�ɼ���
class Score
{
protected:
	int countSubject;                     //ѧ����Ŀ      
	int *score;                           //ѧ�Ƴɼ�����
	int sumScore;                         //�ܳɼ�
	CalculateString calculateString;        
public:
	Score(int countSubjectTemp);                   //Score�Ĺ��캯��
	bool set_score(int a,int b,int c);             //���÷����ĺ���
	int get_countSubject();                        //��ȡѧ����Ŀ�ĺ���
	int &get_scores(int number );                  //��ȡĳѧ�Ʒ����ĺ���
	int &get_sumScore();                           //��ȡ�ܷ����ĺ���
	Score(const Score&);                           //Score�Ŀ������캯��
	void operator =(Score &s);                     //���������=
	~Score();                                      //Score����������
};
#endif