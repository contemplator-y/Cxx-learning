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
//ȱʡֵֻ�ܳ������������߶���ĵط�������ͬʱ�����������ط�
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

//���ú�int���Թ������أ����ǵ��õ�ʱ���������
int func(int& a) {
	return a;
}
int func(int a) {
	return a;
}
void test4() {

	//const ����ָ��const�ı������߳���
	const int a = 1;
	const int& ra = a;
	const int& rb = 200;
	double d = 2.0;
	const int& rc = d;
	/*
	���������д���˵�������ڲ���const���ε�ʱ�����ͱ���һ��
	������const���Ը�Ӱ������ת������ʱ��������һ�����á�
	int& rr = d;
	double& rd = a;
	*/
	

	//���1 200 2
	cout << ra << ' ' << rb << ' ' << rc << endl;
}
/*
���úͱ����໥��ֵ�������
����=���������������� �����õĶ����ʱ���Ƕ�ָ��ͬһ��ռ䣬������ʱ���ǽ�ָ������ݽ����˸�ֵ��

������=���� ����һ����ֵ�Ĺ��̡�

Ҳ����˵�������ö�����ʱ������ʱ���������ڸ�ֵ��
*/
int& fun2(int& a) {
	 a = 300;
	return a;
}
void test10() {
	int a = 1;
	int& ra = a;//ָ��ͬһ��ռ�
	int b = 2;
	ra = b; //��ָ������ݽ����˸�ֵ
	//2 2
	cout << ra << ' ' << b << endl;
	ra = 3;
	// 3 3
	b = ra; //��raָ������ݸ�ֵ��b
	cout << ra << ' ' << b << endl;

	int tmp = 0;
	tmp = fun2(a); // tmp = a��ֵ300
	//300 300  a�ں����ڱ��ĳ���300
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