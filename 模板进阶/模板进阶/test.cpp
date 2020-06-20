#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

template <class T>
T add(T& a, T& b);

template <class T>
T add( T& a,  T& b) {
	return a + b;
}
//模板的特化(格式要和基础模板的格式一模一样，引用符号能丢）
template <>
char* add<char*>(char*& a, char*& b) {
	return strcat(a, b);

}

//函数模板不能处理的特殊类型，一半会定义一个此类型的普通函数
//函数模板的特化比较少用
//对应类型的普通函数
char* add(char*& a, char*& b) {
	return strcat(a, b);

}

//N是非模板参数（数值类型）在编译的时候确定它的值
template <class T, size_t N>
class Array {
private:
	T _array[N];
};

template <class T1, class T2>
class Test {
public:
	Test() {
		cout  << " Test(T1, T2)" << endl;
	}
private:
	T1 _t1;
	T2 _t2;
};

//类模板的全特化
template <>
class Test<int, char> {
public:
	Test() {
		cout << " Test(int, char)" << endl;
	}
private:
	int _t1;
	char _t2;
};
void test() {
	Test<int, int> a;
	Test<int, char> b;
}

//部分特化
//如果创建对象的时候，类型可以同时和全特化和部分特化的参数匹配
//会走全特化的版本（类型已经全部确定，不需要编译器推导，这也是为什么全特化之后会走全特化版本）

/*
函数模板不要分离编译（声明和定义放在同一个文件中），会导致链接错误
*/

//函数模板偏特化
template<class T1, class T2>
T1& sub(T1& a, T2& b) {
	cout << "sub(T1, T2)" << endl;
	return a;
}

template <class T>
//template<>
T& sub<T,int>(T& a, int& b) {
	cout << "sub(T, int)" << endl;
	return a;
}

void test2() {
	int a = 1, b = 2;
	sub(a, b);
}
int main() {
	//int a = 1, b = 2;
	//float c = 1.2, d = 2.5;
	//char e = 'a', f = 'b';

	//char* ptr = new char[100];
	//strcpy(ptr, "123");
	//char* ptr2 = new char[100];
	//strcpy(ptr2, "abc");

	//add(a, b);
	//add(c, d);
	//add(e, f);
	////相加两个指针，编译报错，可以进行模板特化
	//add(ptr, ptr2);

	test2();
	system("pause");
	return 0;
}