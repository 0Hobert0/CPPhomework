/*
	
题目描述



输入起始站、终止站和和路程，计费方式是起步价8元，其中含3公里费用，以后每半公里收费0.7元，不足半公里按半公里计。
可以定义一个Station类，一个Mile类，利用Station类和Mile类为基类公有派生Price类。编写程序实现在Price类中的构造函数Price()和void disp()函数功能并在主函数中生成Price类的对象（“仙灵”，“模范马路”，23.8），同时显示完整的信息。
编程提示：
Station类，其中包括如下内容：
保护数据成员：char from[20] //表示起始地名
char to[20] //表示目标地名
公有成员函数：构造函数 //提供其实和目标地名
 函数 void disp() //显示起止地名
Mile类，其中包括如下内容：
保护数据成员：double mile //表示两地之间的距离，用公里数表示
公有成员函数：构造函数 //提供两地之间的距离
 函数 void disp() //显示里程数
Price类，从Station类和Mile类公有继承，再增加如下内容：
私有数据成员：double price //两地之间打车的总费用
公有成员函数：构造函数 //调用基类构造函数并计算费用
 函数 void disp() //显示总费用
主函数中定义一个或多个Price类的对象，并调用相应函数输出所有信息，包括两地的地名、历程、总费用。



输入描述



起止地名，里程数



输出描述



起止地名，里程数，费用



样例输入1:

仙林 模范马路 23.8


样例输出1:

仙林 模范马路 23.8 37.4


样例输入2:

新街口 仙林中心 27.2


样例输出2:

新街口 仙林中心 27.2 42.3

*/
#include <iostream>
#include <string.h>
using namespace std;

class Station 
{
	protected:
		char from[20];
		char to[20];
	public:
		Station(char *fr,char *t)//构造函数 
		{
			strcpy(from,fr);
			strcpy(to,t);			
		}
		void disp()//输出起始地点和终点 
		{
			cout<<from<<" "<<to<<" ";
		}
};

class Mile
{
	protected:
		double mile;
	public:
		Mile(double mi)
		{
			mile = mi;
		}
		void disp()
		{
			cout<<mile<<" ";
		}
};
class Price: public Station, public Mile
{
	private:
		double price;
	public:
		Price(char from[20],char to[20],double mile):Station(from,to),Mile(mile)
		{
			//Station(from,to);Mile(mile);
			int a;//来判断小数部分需要乘几 
			if( mile - int(mile) == 0 )
			{
				a=0;
			} else if (mile - int(mile)>0 && mile - int(mile) <= 0.5 )
			{
				a=1;
			}else
			{
				a=2;
			}
			if (mile <= 3)
			{
				price = 8;	
			} else if(mile >3)
			{
				price = 8 + (int(mile-3)*1.4+a*0.7);
			}
		}
		void disp()
		{
			cout<<price<<" ";
		}
};

int main()
{
	char from[20];
	char to[20];
	double mile;
	cin>>from>>to>>mile;
	Price x(from,to,mile);
	x.Station::disp();
	x.Mile::disp();
	x.Price::disp();
}
