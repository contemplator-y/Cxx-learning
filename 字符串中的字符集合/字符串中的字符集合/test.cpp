#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

void getCharOfString(string str) {
	int cnt[255] = { 0 };
	for (int i = 0; i < str.size(); i++) {
		if (cnt[str[i]] == 0)
			cnt[str[i]]++;
	}

	for (int i = 0; i < str.size(); i++) {
		if (cnt[str[i]]) {
			cout << str[i];
			cnt[str[i]]--;
		}
	}
	cout << endl;
}
 int main() {
	system("pause");
	return 0;
}