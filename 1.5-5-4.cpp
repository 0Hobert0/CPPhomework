/*
	某公司财务部需要开发一个计算机雇员工资的程序，该公司有3类员工，工人的工资为每小时工资额（通过成员函数设定）乘以当月工作时数（通过成员函数设定）再加上工龄工资；销售员工资为每小时工资额（通过成员函数设定）乘以当月工作时数（通过成员函数设定）加上销售额提成再加上工龄工资，其中销售额提成等于该销售员当月售出商品金额（通过成员函数设定）的1%；管理人员工资为基本工资1000元再加上工龄工资，工龄工资就是雇员在该公司工作的工龄每增加一年，月工资就增加35元。请用面向对象方法分析、设计这个程序，并用C++语言写出完整程序。
设计基类Employee，定义如下：

class Employee
{
	protected:
		char name[30];
		int working_years;
	public:
		Employee(const char nm[30]="unnamed",int wy=0);
		char *Getname();
		double ComputePay(); 
		void SetWorkyears(int wy);
};  
由Employee派生三个类Worker,SalesPerson 和Manager.
在Worker类中添加数据成员
		double pay_per_hour;
		int work_time;
成员函数：
		double count_pay();
		void SetWorktime(int wt);
		void Setpay_per_hour(int x);
在SalesPerson类中添加数据成员：
		double pay_per_hour;
		double saleroom;
		int work_time; 和Manager.
成员函数：
		double count_pay();
		void SetWorktime(int wt);
		void Setpay_per_hour(int x);
		void Setsalesroom(double sr);
在Manager类中添加成员函数：
		double count_pay();
使用如下的main（）函数，请复制使用：
int main()
{
	Worker work("zhangqiang",3,200);
	cout<<"工资="<<work.count_pay()<<endl;
	work.SetWorktime(180);
	work.SetWorkyears(10);
	work.Setpay_per_hour(30);
	cout<<work.Getname()<<"  "<<work.count_pay()<<endl;
	
	SalesPerson sales("wangjun",5,300000,25);
	
	sales.SetWorktime(40);
	sales.Setpay_per_hour(80);
	sales.Setsalesroom(450000);
	cout<<sales.Getname()<<"  "<<sales.count_pay()<<endl; 
	
	Manager mana("sunchao",20);
	cout<<mana.Getname()<<"  "<<mana.count_pay()<<endl;
	return 0;
}
运行结果如下：
工资=10105
zhangqiang 5750
wangjun 7875
sunchao 1700
*/ 
#include <iostream>
#include <string.h>
using namespace std;

class Employee  //雇员类 
{
	protected:
		char name[30];
		int working_years;
	public:
		Employee(const char nm[30]="unnamed",int wy=0)
		{
//			name = new char[30];
			strcpy(name,nm);
			working_years = wy;
		}
		char *Getname()
		{
//			name = new char[strlen(nm)+1];
			return name;	
		}
		double ComputePay()
		{
			return 35*working_years;
		}
		void SetWorkyears(int wy)
		{
			working_years = wy;
		}
}; 
class Worker: public Employee
{
	protected:
		double pay_per_hour;
		int work_time;	
	
	public:
		Worker(char *nm,int year,int hour)
		{
//			name = new char[strlen(nm)+1];
			strcpy(name,nm);
			working_years = year;
			work_time = hour;
			pay_per_hour= 50;
		}
		double count_pay()
		{
		//	double a=ComputePay();
			return ComputePay()+pay_per_hour*work_time;
		}
		void SetWorktime(int wt)
		{
			work_time = wt;
		}
		void Setpay_per_hour(int x=50)// 为什么默认值放到这里不可以？ 
		{
			pay_per_hour = x;
		}
};
class SalesPerson : public Employee
{
	private:
		double pay_per_hour;
		double saleroom;
		int work_time; 
	public:
		SalesPerson(char* nm,int year,double sale,int hour)
		{
			strcpy(name,nm);
			working_years = year;
			work_time = hour;
			pay_per_hour= 50;
			saleroom = sale;
		}
		double count_pay()
		{
			return ComputePay()+pay_per_hour*work_time+saleroom*0.01;
		}
		void SetWorktime(int wt)
		{
			work_time = wt;
		}
		void Setpay_per_hour(int x)
		{
			pay_per_hour= x;
		}
		void Setsalesroom(double sr)
		{
			saleroom = sr;
		}
};
class Manager : public Employee
{
	public:
		Manager(char *nm,int year)
		{
			strcpy(name,nm);
			working_years = year;
		}
		double count_pay()
		{
			return 1000+ComputePay();
		}
}; 
int main()
{
	Worker work("zhangqiang",3,200);
	cout<<"工资="<<work.count_pay()<<endl;
	work.SetWorktime(180);
	work.SetWorkyears(10);
	work.Setpay_per_hour(30);
	cout<<work.Getname()<<"  "<<work.count_pay()<<endl;
	
	SalesPerson sales("wangjun",5,300000,25);
	
	sales.SetWorktime(40);
	sales.Setpay_per_hour(80);
	sales.Setsalesroom(450000);
	cout<<sales.Getname()<<"  "<<sales.count_pay()<<endl; 
	
	Manager mana("sunchao",20);
	cout<<mana.Getname()<<"  "<<mana.count_pay()<<endl; 
	return 0;
}

