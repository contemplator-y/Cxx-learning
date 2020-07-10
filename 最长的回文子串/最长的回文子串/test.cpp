#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string& str, int start, int end) {
	while (start < end) {
		if (str[start] != str[end])
			return false;
		start++;
		end--;
	}

	return true;
}
string longestPalindrome(string s) {
	//����ö��
	if (s.empty())
		return string();
	int max = 0; // ��ǰ�����Ӵ����ȵ����ֵ
	int size = s.size(), start = -1; // �������Ӵ�����ʼλ��
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (isPalindrome(s, i, j) && j - i + 1 > max) {
				max = j - i + 1;
				start = i;
			}
		}
	}
	if (start == -1)
		return string(1,s[0]);
	return string(s, start, max);
}

int main() {
	string s("ab");
	string str = longestPalindrome(s);
	cout << str << endl;
	system("pause");
	return 0;
}