#ifndef _UNDERGRADUATE
#define _UNDERGRADUATE
//Undergraduate��������
class Undergraduate: public Student
{
public:
	Undergraduate();                        //�޲ι��캯��
	Undergraduate(int IDTemp,string nameTemp,string genderTemp,int gradeTemp,int majorIDTemp, string majorTemp,int classIDTemp, string classNameTemp,float higherMath,float english,float c); //���ι��캯��
	void display_a_student();               //��ʾһλ��������Ϣ
	bool set_information_to_class();  //�ڹ���ĳ���༶������ѧ����Ϣ
	void operator =( Undergraduate &u );    //���������=
};
#endif