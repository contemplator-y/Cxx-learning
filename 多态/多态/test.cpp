#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//抽象类
class Test {
public:
	virtual void fun() = 0;
	 
};
//可以在抽象类的外定义纯虚函数，但是意义不大
void fun() {
	cout << "Test :: fun()" << endl;
}

class A {
public:
	virtual void fun() {
		cout << "A :: fun()" << endl;
	}
};

class B : public A {
private:
	virtual void fun() {
		cout << "B :: fun()" << endl;
		//在子类中重写虚函数的函数体中可以调用父类的虚函数
		//这里和同名隐藏是一样的，只是当函数参数和父类中的函数参数完全一致时，称构成了多态
	}
};

void test() {
	B b;
	A* pb = &b;
	//可以用子类对象调用虚函数
	//b.fun();
	pb->fun();
}

class T1 {
public:
	/*virtual void fun() final {}
	virtual void fun2()  {}*/

};
class T2 /*: public T1*/{
public:
	////virtual void fun() {} //无法重写父类中被final修饰的虚函数
	//virtual void fun2(int)  //override 必须重写父类中的某个函数
	//{
	//	cout << "T2 :: fun2()" << endl;
	//}
	virtual void fun(){}
private:
	int _a;
};

void testt() {
	cout << sizeof(T2) << endl;
}
int main() {
	testt();
	system("pause");
	return 0;

}