#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>

using namespace std;

namespace yang {
	int a;
	int b;
	void fun() {
		cout << "fun()" << '\n';
	}
}
using namespace yang;
void test() {
	//cin >> a;
	double c = 0.0;
	cin >> c;
	cout << a << '\n' << c << endl;
}
void test2() {
	int a = 1;
	char str[] = "124";
	cout << &a << endl << str << endl;
	char* p = str;
	cout << p << endl;
}
void test3(int a, int b = 2, int c = 3) {
	cout << a << b << c << endl;
}
//缺省值只能出现在声明或者定义的地方，不能同时出现在两个地方
void fun4(int a = 1, int b = 2, int c = 3);
void fun4(int a, int b , int c) {
	cout << a << b << c << endl;

}

int add(int a, int b, int c = 0) {
	return a + b + c;
}
int add(int a, int b) {
	return a + b;
}

//引用和int可以构成重载，但是调用的时候会有歧义
int func(int& a) {
	return a;
}
int func(int a) {
	return a;
}
void test4() {

	//const 引用指向const的变量或者常量
	const int a = 1;
	const int& ra = a;
	const int& rb = 200;
	double d = 2.0;
	const int& rc = d;
	/*
	这两个都有错误，说明引用在不加const修饰的时候类型必须一致
	而加上const可以给影视类型转换的临时变量定义一个引用。
	int& rr = d;
	double& rd = a;
	*/
	

	//输出1 200 2
	cout << ra << ' ' << rb << ' ' << rc << endl;
}
/*
引用和变量相互赋值的情况：
引用=变量名（引用名） 在引用的定义的时候是都指向同一块空间，在其他时候是将指向的内容进行了赋值。

变量名=引用 这是一个赋值的过程。

也就是说除了引用定义在时候其他时候都是内容在赋值。
*/
int& fun2(int& a) {
	 a = 300;
	return a;
}
void test10() {
	int a = 1;
	int& ra = a;//指向同一块空间
	int b = 2;
	ra = b; //将指向的内容进行了赋值
	//2 2
	cout << ra << ' ' << b << endl;
	ra = 3;
	// 3 3
	b = ra; //将ra指向的内容赋值给b
	cout << ra << ' ' << b << endl;

	int tmp = 0;
	tmp = fun2(a); // tmp = a的值300
	//300 300  a在函数内被改成了300
	cout << tmp << ' ' << a << endl;


}
int main() {
	//test();
	/*char* p = "234";
	test3(1);
	test3(100);
	test3(100, 200);*/
	//fun4();
	//int res = add(1, 2);
	//printf("%d\n", res);
	test10();
	system("pause");
	return 0;
}