#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int StrToInt(string str) {
	int idx = 0;
	int sign = 1;
	long long num = 0;
	//确定符号
	if (str[idx] == '+' || str[idx] == '-') {
		if (str[idx++] == '-') {
			sign = -1;
		}
	}
	else if (str[idx] > '9' || str[idx] < '0') {
		return 0;
	}

	for (; idx < str.size(); idx++) {
		if (str[idx] <= '9' && str[idx] >= '0') {
			num = num * 10 + str[idx] - '0';
			if (sign == 1 && num > INT_MAX || sign == -1 && num - 1 > INT_MAX)
				return 0; //数字越界
		}
		else {
			return 0;
		}
	}

	return (int)(sign * num);
}

int main() {
	string s("+21412345645674651");
	int num = StrToInt(s);
	cout << num << endl;

	system("pause");
	return 0;
}