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
	//暴力枚举
	if (s.empty())
		return string();
	int max = 0; // 当前回文子串长度的最大值
	int size = s.size(), start = -1; // 最大回文子串的起始位置
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