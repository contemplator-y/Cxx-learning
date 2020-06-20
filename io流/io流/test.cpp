#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void test() {
	//�����ļ�������
	fstream fin("test.txt");
	if (!fin.is_open())
		cout << "�ļ���ʧ��" << endl;

	//�ı���
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

//�����ƶ�д�ļ�
void readFile(const char* filename) {
	//�������������󲢴��ļ�
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "���ļ�ʧ��" << endl;
		return;
	}

	Student st;
	fin.read((char*)&st, sizeof(Student));
	fin.close();
}
void writeFile(const char* filename) {
	ofstream fout(filename);
	if (!fout.is_open()) {
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	Student st;
	st._age = 20;
	strcpy(st._name, "caixukun");

	fout.write((char*)&st, sizeof(Student));
}

//�ı���д
void readTxtFile(const char* filename) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "���ļ�ʧ��" << endl;
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
		cout << "���ļ�ʧ��" << endl;
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
	//�ı���д
	writeTxtFile("test.text.txt");
	readTxtFile("test.text.txt");
	//�����ƶ�д
	writeFile("test.binary.txt");
	readFile("test.binary.txt");
}
//��stringstream ��������ת����string����
void test3() {
	//��itoa
	char str[10];
	_itoa(100, str, 10);
	_itoa(100, str, 16);
	_itoa(100, str, 8);
	_itoa(100, str, 2);

	//��sprintf
	sprintf(str, "%d", 100);

	//��stringstream��
	//ֱ�ӽ���������stringstream�����У�
	stringstream ss;
	ss << 100;
	string ret = ss.str(); //��ȡss�е�string��Ա

	ss.str(""); //����ss�е�string��Ա
	ss.clear(); //���ñ�־λ
	ss << "123";
	ss << 40;
	ret = ss.str();
}
int main() {
	test3();
	system("pause");
	return 0;
}