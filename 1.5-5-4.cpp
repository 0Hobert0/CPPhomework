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

