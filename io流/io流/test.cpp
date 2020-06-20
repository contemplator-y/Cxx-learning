#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void test() {
	//输入文件流对象
	fstream fin("test.txt");
	if (!fin.is_open())
		cout << "文件打开失败" << endl;

	//文本读
	/*char str[100];
	fin >> str;
	cout << str << endl;
	char str2[4];
	fin.getline(str2, 4);
	cout << str2 << endl;*/
	char str[] = "qiaobiluo";
	fin << str;
}

struct Student {
	int _age;
	char _name[30];
};

//二进制读写文件
void readFile(const char* filename) {
	//创建输入流对象并打开文件
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "打开文件失败" << endl;
		return;
	}

	Student st;
	fin.read((char*)&st, sizeof(Student));
	fin.close();
}
void writeFile(const char* filename) {
	ofstream fout(filename);
	if (!fout.is_open()) {
		cout << "打开文件失败" << endl;
		return;
	}
	Student st;
	st._age = 20;
	strcpy(st._name, "caixukun");

	fout.write((char*)&st, sizeof(Student));
}

//文本读写
void readTxtFile(const char* filename) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "打开文件失败" << endl;
		return;
	}
	Student st;
	fin >> st._age;
	fin >> st._name;
	fin.close();
}

void writeTxtFile(const char* filename) {
	ofstream fout(filename);
	if (!fout.is_open()) {
		cout << "打开文件失败" << endl;
		return;
	}

	Student st;
	st._age = 20;
	strcpy(st._name, "caixukun");
	fout << st._age << endl;
	fout << st._name << endl;
	fout.close();
}
void test2() {
	//文本读写
	writeTxtFile("test.text.txt");
	readTxtFile("test.text.txt");
	//二进制读写
	writeFile("test.binary.txt");
	readFile("test.binary.txt");
}
//用stringstream 来将数据转换成string类型
void test3() {
	//用itoa
	char str[10];
	_itoa(100, str, 10);
	_itoa(100, str, 16);
	_itoa(100, str, 8);
	_itoa(100, str, 2);

	//用sprintf
	sprintf(str, "%d", 100);

	//用stringstream类
	//直接将数据流入stringstream对象中，
	stringstream ss;
	ss << 100;
	string ret = ss.str(); //获取ss中的string成员

	ss.str(""); //设置ss中的string成员
	ss.clear(); //设置标志位
	ss << "123";
	ss << 40;
	ret = ss.str();
}
int main() {
	test3();
	system("pause");
	return 0;
}