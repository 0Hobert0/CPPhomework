/*
	
��Ŀ����



������ʼվ����ֹվ�ͺ�·�̣��Ʒѷ�ʽ���𲽼�8Ԫ�����к�3������ã��Ժ�ÿ�빫���շ�0.7Ԫ������빫�ﰴ�빫��ơ�
���Զ���һ��Station�࣬һ��Mile�࣬����Station���Mile��Ϊ���๫������Price�ࡣ��д����ʵ����Price���еĹ��캯��Price()��void disp()�������ܲ���������������Price��Ķ��󣨡����顱����ģ����·����23.8����ͬʱ��ʾ��������Ϣ��
�����ʾ��
Station�࣬���а����������ݣ�
�������ݳ�Ա��char from[20] //��ʾ��ʼ����
char to[20] //��ʾĿ�����
���г�Ա���������캯�� //�ṩ��ʵ��Ŀ�����
 ���� void disp() //��ʾ��ֹ����
Mile�࣬���а����������ݣ�
�������ݳ�Ա��double mile //��ʾ����֮��ľ��룬�ù�������ʾ
���г�Ա���������캯�� //�ṩ����֮��ľ���
 ���� void disp() //��ʾ�����
Price�࣬��Station���Mile�๫�м̳У��������������ݣ�
˽�����ݳ�Ա��double price //����֮��򳵵��ܷ���
���г�Ա���������캯�� //���û��๹�캯�����������
 ���� void disp() //��ʾ�ܷ���
�������ж���һ������Price��Ķ��󣬲�������Ӧ�������������Ϣ���������صĵ��������̡��ܷ��á�



��������



��ֹ�����������



�������



��ֹ�����������������



��������1:

���� ģ����· 23.8


�������1:

���� ģ����· 23.8 37.4


��������2:

�½ֿ� �������� 27.2


�������2:

�½ֿ� �������� 27.2 42.3

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
		Station(char *fr,char *t)//���캯�� 
		{
			strcpy(from,fr);
			strcpy(to,t);			
		}
		void disp()//�����ʼ�ص���յ� 
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
			int a;//���ж�С��������Ҫ�˼� 
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
