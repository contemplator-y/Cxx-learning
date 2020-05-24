#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//析构函数  编译器在对象生命周期结束时自动调用，用于清理资源而不是销毁对象

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
		//使用初始化列表来对成员变量进行初始化，这里相当于成员变量的定义处，private那里只是声明，Date函数里是赋值
		// 初始化列表的书写格式： ：成员（值或者表达式）, 成员（值或者表达式）
		//在调用构造函数给成员变量进行初始化的时候，初始化的顺序与书写的顺序无关，初始化的顺序为声明成员的顺序

		//主要的作用：给 引用类型的变量、const类型的变量、自定义类型的变量进行初始化
		//其中const和引用类型的变量语法要求必须在定义的时候进行初始化，所以只能用初始化列表进行初始化，
		//而自定义类型的成员可以在下面的函数体中进行赋值，但是在这之前会调用该成员的无参构造函数，因此最好
		//直接在这里对自定义类型的成员进行初始化，只需要调用一次该成员的构造函数
		:_year(year)
		,_month(month)
		, _day(day)
		//
	{
		/*_year = year;
		_month = month;
		_day = day;*/

		//若在初始化参数列表中没有对自定义类型的成员进行初始化，需要在这里对其进行赋值
		_time = Time(10); // 创建匿名对象，然后调用=运算符的重载函数对成员变量_time进行赋值
		cout << "Date()" << endl;
	}
	
	//拷贝构造函数,不写的话编译器会自动生成，是浅拷贝，只拷贝成员变量。
	Date( const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//运算符=重载，编译器也会自动生成，是浅复制，只赋值成员变量的值
	Date& operator=(const Date& d2) {
		//两个操作数不是同一个对象
		if (this != &d2) {
			_year = d2._year;
			_month = d2._month;
			_day = d2._day;
		}
		return *this;
	}
	//运算符==重载
	bool operator==(const Date& d2) {
		return _year == d2._year
			&& _month == d2._month
			&& _day == d2._day;
	}
	//析构函数
	~Date() {
		cout << "~Date()" << endl;
	}

	void printDate() {
		cout << _year << ' ' << _month << " " << _day << endl;
	}

	//const成员函数
	void printDate() const {
		cout << _year << ' ' << _month << " " << _day << endl;
	}
};

//当类中有自定义成员，先调用自定义成员的构造函数，再调用对象的构造函数
//当对象生命周期结束之前，先调用对象的析构函数，再调用自定义成员的析构函数。
void test() {
	Date d;
}

//volatile 防止编译器优化，每次老老实实去内存取值
void test2() {
	volatile const int a = 10;
	int* pa = (int*)&a;
	*pa = 20;
	//没加 volatile： 10 20  加上volatile ： 20 20
	cout << a << " " << *pa << endl;
}
//拷贝构造函数
void test3() {
	Date d(2020, 5, 24);
	Date d2(Date(2020,1,2));
}

//运算符=、==的重载
void test4() {
	Date d(2020, 5, 20);
	Date d2(2020, 3, 2);
	d2 = d;
	bool ret = d2 == d;
	cout << ret << endl;
}
//const 成员函数
void test5() {
	Date d(2020, 5, 20);
	const Date d2 = d;
	d.printDate(); //非const对象调用非const成员函数，在没有非const成员函数的时候，可以调用const成员函数
	d2.printDate();//const对象只能调用const成员函数，在没有const成员函数的时候，不可以调用const成员函数
}

//使用初始化列表对成员变量进行初始化
void test6() {
	Date d(2020, 5, 20);
}
int main() {
	test6();
	system("pause");
	return 0;
}