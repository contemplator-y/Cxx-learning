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
//ģ����ػ�(��ʽҪ�ͻ���ģ��ĸ�ʽһģһ�������÷����ܶ���
template <>
char* add<char*>(char*& a, char*& b) {
	return strcat(a, b);

}

//����ģ�岻�ܴ�����������ͣ�һ��ᶨ��һ�������͵���ͨ����
//����ģ����ػ��Ƚ�����
//��Ӧ���͵���ͨ����
char* add(char*& a, char*& b) {
	return strcat(a, b);

}

//N�Ƿ�ģ���������ֵ���ͣ��ڱ����ʱ��ȷ������ֵ
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

//��ģ���ȫ�ػ�
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

//�����ػ�
//������������ʱ�����Ϳ���ͬʱ��ȫ�ػ��Ͳ����ػ��Ĳ���ƥ��
//����ȫ�ػ��İ汾�������Ѿ�ȫ��ȷ��������Ҫ�������Ƶ�����Ҳ��Ϊʲôȫ�ػ�֮�����ȫ�ػ��汾��

/*
����ģ�岻Ҫ������루�����Ͷ������ͬһ���ļ��У����ᵼ�����Ӵ���
*/

//����ģ��ƫ�ػ�
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
	////�������ָ�룬���뱨�����Խ���ģ���ػ�
	//add(ptr, ptr2);

	test2();
	system("pause");
	return 0;
}