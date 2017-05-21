/*
	ĳ��˾������Ҫ����һ���������Ա���ʵĳ��򣬸ù�˾��3��Ա�������˵Ĺ���ΪÿСʱ���ʶͨ����Ա�����趨�����Ե��¹���ʱ����ͨ����Ա�����趨���ټ��Ϲ��乤�ʣ�����Ա����ΪÿСʱ���ʶͨ����Ա�����趨�����Ե��¹���ʱ����ͨ����Ա�����趨���������۶�����ټ��Ϲ��乤�ʣ��������۶���ɵ��ڸ�����Ա�����۳���Ʒ��ͨ����Ա�����趨����1%��������Ա����Ϊ��������1000Ԫ�ټ��Ϲ��乤�ʣ����乤�ʾ��ǹ�Ա�ڸù�˾�����Ĺ���ÿ����һ�꣬�¹��ʾ�����35Ԫ������������󷽷����������������򣬲���C++����д����������
��ƻ���Employee���������£�

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
��Employee����������Worker,SalesPerson ��Manager.
��Worker����������ݳ�Ա
		double pay_per_hour;
		int work_time;
��Ա������
		double count_pay();
		void SetWorktime(int wt);
		void Setpay_per_hour(int x);
��SalesPerson����������ݳ�Ա��
		double pay_per_hour;
		double saleroom;
		int work_time; ��Manager.
��Ա������
		double count_pay();
		void SetWorktime(int wt);
		void Setpay_per_hour(int x);
		void Setsalesroom(double sr);
��Manager������ӳ�Ա������
		double count_pay();
ʹ�����µ�main�����������븴��ʹ�ã�
int main()
{
	Worker work("zhangqiang",3,200);
	cout<<"����="<<work.count_pay()<<endl;
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
���н�����£�
����=10105
zhangqiang 5750
wangjun 7875
sunchao 1700
*/ 
#include <iostream>
#include <string.h>
using namespace std;

class Employee  //��Ա�� 
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
		void Setpay_per_hour(int x=50)// ΪʲôĬ��ֵ�ŵ����ﲻ���ԣ� 
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
	cout<<"����="<<work.count_pay()<<endl;
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

