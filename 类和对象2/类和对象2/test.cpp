#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//��������  �������ڶ����������ڽ���ʱ�Զ����ã�����������Դ���������ٶ���

class Day {
private:
	int _hour;
	int _minte;
	int _second;
public:
	Day() {
		cout << "Day()" << endl;
	}
	~Day() {
		cout << "~Day()" << endl;
	}
};

class Time {
private:
	int _a;
public:
	Time(int a = 1)
		:_a(a)
	{}
};
class Date {
private:
	int _year;
	int _month;
	int _day;
	//Day _d;
	Time _time;
public:
	Date(int year = 2020, int month = 5, int day = 20)  
		//ʹ�ó�ʼ���б����Գ�Ա�������г�ʼ���������൱�ڳ�Ա�����Ķ��崦��private����ֻ��������Date�������Ǹ�ֵ
		// ��ʼ���б����д��ʽ�� ����Ա��ֵ���߱��ʽ��, ��Ա��ֵ���߱��ʽ��
		//�ڵ��ù��캯������Ա�������г�ʼ����ʱ�򣬳�ʼ����˳������д��˳���޹أ���ʼ����˳��Ϊ������Ա��˳��

		//��Ҫ�����ã��� �������͵ı�����const���͵ı������Զ������͵ı������г�ʼ��
		//����const���������͵ı����﷨Ҫ������ڶ����ʱ����г�ʼ��������ֻ���ó�ʼ���б���г�ʼ����
		//���Զ������͵ĳ�Ա����������ĺ������н��и�ֵ����������֮ǰ����øó�Ա���޲ι��캯����������
		//ֱ����������Զ������͵ĳ�Ա���г�ʼ����ֻ��Ҫ����һ�θó�Ա�Ĺ��캯��
		:_year(year)
		,_month(month)
		, _day(day)
		//
	{
		/*_year = year;
		_month = month;
		_day = day;*/

		//���ڳ�ʼ�������б���û�ж��Զ������͵ĳ�Ա���г�ʼ������Ҫ�����������и�ֵ
		_time = Time(10); // ������������Ȼ�����=����������غ����Գ�Ա����_time���и�ֵ
		cout << "Date()" << endl;
	}
	
	//�������캯��,��д�Ļ����������Զ����ɣ���ǳ������ֻ������Ա������
	Date( const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//�����=���أ�������Ҳ���Զ����ɣ���ǳ���ƣ�ֻ��ֵ��Ա������ֵ
	Date& operator=(const Date& d2) {
		//��������������ͬһ������
		if (this != &d2) {
			_year = d2._year;
			_month = d2._month;
			_day = d2._day;
		}
		return *this;
	}
	//�����==����
	bool operator==(const Date& d2) {
		return _year == d2._year
			&& _month == d2._month
			&& _day == d2._day;
	}
	//��������
	~Date() {
		cout << "~Date()" << endl;
	}

	void printDate() {
		cout << _year << ' ' << _month << " " << _day << endl;
	}

	//const��Ա����
	void printDate() const {
		cout << _year << ' ' << _month << " " << _day << endl;
	}
};

//���������Զ����Ա���ȵ����Զ����Ա�Ĺ��캯�����ٵ��ö���Ĺ��캯��
//�������������ڽ���֮ǰ���ȵ��ö���������������ٵ����Զ����Ա������������
void test() {
	Date d;
}

//volatile ��ֹ�������Ż���ÿ������ʵʵȥ�ڴ�ȡֵ
void test2() {
	volatile const int a = 10;
	int* pa = (int*)&a;
	*pa = 20;
	//û�� volatile�� 10 20  ����volatile �� 20 20
	cout << a << " " << *pa << endl;
}
//�������캯��
void test3() {
	Date d(2020, 5, 24);
	Date d2(Date(2020,1,2));
}

//�����=��==������
void test4() {
	Date d(2020, 5, 20);
	Date d2(2020, 3, 2);
	d2 = d;
	bool ret = d2 == d;
	cout << ret << endl;
}
//const ��Ա����
void test5() {
	Date d(2020, 5, 20);
	const Date d2 = d;
	d.printDate(); //��const������÷�const��Ա��������û�з�const��Ա������ʱ�򣬿��Ե���const��Ա����
	d2.printDate();//const����ֻ�ܵ���const��Ա��������û��const��Ա������ʱ�򣬲����Ե���const��Ա����
}

//ʹ�ó�ʼ���б�Գ�Ա�������г�ʼ��
void test6() {
	Date d(2020, 5, 20);
}
int main() {
	test6();
	system("pause");
	return 0;
}