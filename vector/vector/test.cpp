#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

void test(){
	vector<int> v;
	vector<int> v2(3, 12);
	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(v3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
}

void test2() {
	vector<int> v;
	//resize的功能时修改vector中的元素个数
	//若n大于capacity，会进行增容，然后多余的元素默认补0，
	//或者补上传入的值，并修改size的值
	//若是大于size则填补空余的元素，修改size的值
	//若小于size则只修改size的值
	v.resize(10);
	v.resize(20, 6);
	v.resize(3);
}

void test3() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	//v.pop_back();
	//v.pop_back();
	//v.pop_back();
	//v.pop_back();
	//v.pop_back();
	
	//vector的find的参数为迭代器，而不是索引
	vector<int> ::iterator pos = find(v.begin(), v.end(), 3);
	//找不到该元素,返回值为end迭代器
	vector<int> ::iterator pos2 = v.end();
	
	//插入和删除
	v.insert(pos, 10);
	pos = find(v.begin(), v.end(), 10);
	v.erase(pos);
}
void test4() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
	auto it = v.begin();
	while (it != v.end()) {
		if (*it % 2 == 0)
			it = v.erase(it);
		//else
			it++;  //这里如果不写else，则会导致程序崩溃，原因是若删除的是最后一个元素，it
			//接受了erase的返回值指向的是被删除元素的下一个位置，也就是end迭代器的位置若在执行++操作则之后
			//永远不会和end迭代器相等，为了避免这种情况，编译器认为迭代器失效而导致程序崩溃。
	}
	
	//vector<int> v2;
	////交换两个vector的内容
	//v2.swap(v);
}
int main() {
	test4();
	system("pause");
	return 0;
}