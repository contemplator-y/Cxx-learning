#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Date {
private:
	int _year;
	int _month;
	int _day;
public:
	//��ȡ��ǰ�·ݵ�����
	int getMonthDays(int year, int month) {
		int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int ret = days[month];
		if (month == 2 &&  (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) ) {
			ret++;
		}

		return ret;
	}
	Date(int year, int month, int day) {
		if (year > 0 && month > 0 && month < 13 && day > 0 && day <= getMonthDays(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			cout << "���ڲ��Ϸ�,������ΪĬ��ֵ��2000-1-1)" << endl;
			_year = 2000;
			_month = _day = 1;
		}
	}
	//�������캯��
	Date(const Date& d2) {
		_year = d2._year;
		_month = d2._month;
		_day = d2._day;
	}
	//����+= �����
	Date& operator+=(int day) {
		_day += day;
		//�ж������Ƿ����
		while (_day > getMonthDays(_year, _month)) {
			_day -= getMonthDays(_year, _month);
			//�·ݼ�1
			_month++;
			//�ж��·��Ƿ����
			if (_month == 13) {
				_month = 1;
				_year++;
			}
		}

		return *this;
	}
	//����ǰ��++�����
	Date& operator++() {
		return *this += 1;
	}
	//���ú���++����� 
	Date operator++(int) {
		//����++֮ǰ��ֵ
		Date ret(*this);
		//++
		*this += 1;
		//����++֮ǰ��ֵ
		return ret;
	}
	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	// ����+����
	Date operator+(int day) {
		Date ret(*this);
		return ret += day;
	}
	// ����-����
	Date operator-(int day) {
		Date ret(*this);
		ret._day -= day;
		while (ret._day <= 0) {
			ret._month--;
			if (ret._month == 0) {
				ret._month = 12;
				ret._year--;
			}
			ret._day += getMonthDays(ret._year, ret._month);
		}
		return ret;
	}
	// ����-=����
	Date& operator-=(int day) {
		_day -= day;
		while (_day <= 0) {
			_month--;
			if (_month == 0) {
				_month = 12;
				_year--;
			}
			_day += getMonthDays(_year, _month);
		}
		return *this;
	}
	// ����--
	Date operator--(int) {
		Date ret(*this);
		*this -= 1;
		return ret;
	}
	// ǰ��--
	Date& operator--() {
		return *this -= 1;
	}
	// >���������
	bool operator>(const Date& d) {
		if (_year > d._year) {
			return true;
		} else if (_year == d._year) {
			if (_month > d._month) {
				return true;
			} else if (_month == d._month) {
				if (_day > d._day) {
					return true;
				}
			}
		}

		return false;
	}
	// ==���������
	bool operator==(const Date& d) {
		return _year == d._year
		&& _month == d._month
		&& _day == d._day;
	}
	// >=���������
	inline bool operator >= (const Date& d) {
		return *this > d || *this == d;
	}
	// <���������
	bool operator < (const Date& d) {
		return !(*this >= d);
	}
	// <=���������
	bool operator <= (const Date& d) {
		return *this < d || *this == d;
	}
	// !=���������
	bool operator != (const Date& d) {
		return !(*this == d);
	}
	// ����-���� ��������
	int operator-(const Date& d) {
		Date tmp(d);
		Date* max = &tmp;
		Date* min = this;
		if (tmp < *this) {
			max = this;
			min = &tmp;
		}
		int ret = 0;
		//��С������++ֱ���ͽϴ���������
		while (*min < *max) {
			ret++;
			(*min)++;
		}

		return ret;
	}
	void printDate() {
		cout << _year << '-' << _month << '-' << _day << endl;
	}

	/*~Date() {
		cout << "~Date" << endl;
	}*/
};

void test() {
	/*Date d(2020, 5, 20);
	d += 20;
	d.printDate();
	d += 60;
	d.printDate();
	d++;
	d.printDate();
	++d;
	d.printDate();*/
	
	////+-������=.,-=����
	Date d(2020, 5, 20);
	d = d + 10;
	d.printDate();
	d = d + 10;
	d.printDate();
	d = d - 10;
	d.printDate();
	d = d - 10;
	d.printDate();
	d -= 10;
	d.printDate();
	d -= 60;
	d.printDate();
	cout << "ǰ��--�ͺ���--" << endl;
	d--;
	d.printDate();
	--d;
	d.printDate();
	cout << "> == >=" << endl;
	Date d2(2019, 3, 9);
	cout << "d:";
	d.printDate();
	cout << "d2:";
	d2.printDate();
	cout << (d > d2) << (d == d2) << (d >= d2) << endl;
	cout << "������������֮���м���" << endl;
	cout << (d - d2) << endl;
}
int main() {
	test();
	system("pause");
	return 0;
}