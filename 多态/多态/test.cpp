#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//������
class Test {
public:
	virtual void fun() = 0;
	 
};
//�����ڳ�������ⶨ�崿�麯�����������岻��
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
		//����������д�麯���ĺ������п��Ե��ø�����麯��
		//�����ͬ��������һ���ģ�ֻ�ǵ����������͸����еĺ���������ȫһ��ʱ���ƹ����˶�̬
	}
};

void test() {
	B b;
	A* pb = &b;
	//�����������������麯��
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
	////virtual void fun() {} //�޷���д�����б�final���ε��麯��
	//virtual void fun2(int)  //override ������д�����е�ĳ������
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