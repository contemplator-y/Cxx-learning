#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class Person {
public :
	void show() {
		cout << _name << ' ' << _age << endl;
	}
	Person(int ag = 21)
		:_age(ag)
		, _name("cai xu kun")
	{
		
	}
private:
	int _age;
protected:
	string _name;
};

class Student : public Person {
	//void setAge(int age) {
	//	//父类中的private成员子类不能访问
	//	_age = age;
	//}
public :
	void show(int a) {
		cout << _name << ' ' << endl;
	}
};
void test() {
	Student st;
	st.show();
}
int main() {
	test();
	system("pause");
	return 0;
}