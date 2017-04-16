#include <iostream>
#include <string.h>
using namespace std;
class Tea;
class Stu
{
	private:
		char* name;
		int score;
	public:
		friend void print(Stu ,Tea);
		Stu(char *,int);
		~Stu();
		
};
class Tea
{
	private:
		char* name;
		char* pro;
	public:
		friend void print(Stu ,Tea);
		Tea(char*,char*);
		~Tea();
};
Stu::Stu(char*a,int b)
{
	if(a)
	{
		name=new char[strlen(a)+1];
		strcpy(name,a);
	}
	score=b;
}
Tea::Tea(char*a,char*b)
{
	if(a)
	{
		name=new char[strlen(a)+1];
		strcpy(name,a);
	}
	if(b)
	{
		pro=new char[strlen(b)+1];
		strcpy(pro,b);
	}
}
Stu::~Stu()
{
	delete[]name;
}
Tea::~Tea()
{
	delete[]name;
	delete[]pro;
}
void print(Stu S,Tea T)
{
	cout<<"student's name:"<<S.name<<"   "<<S.score<<endl;
	cout<<"Teacher's name:"<<T.name<<"   "<<T.pro<<endl;
}
int main()
{
	char stuname[20],teaname[20],teapro[20]; 
	cout<<"请输入学生姓名："<<endl; 
	cin>>stuname; 
	cout<<"请输入教师姓名："<<endl;
	cin>>teaname;
	cout<<"请输入教师职称："<<endl;  
	cin>>teapro;
	Stu student(stuname,88);
	Tea teacher(teaname,teapro);
	print(student,teacher);
	return 0;
}
