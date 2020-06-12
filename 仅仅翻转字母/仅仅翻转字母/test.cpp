#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isLetter(char ch) {
		return (ch >= 'A' && ch <= 'Z')
			|| (ch >= 'a' && ch <= 'z');
	}
	string reverseOnlyLetters(string S) {
		int start = 0, end = S.size() - 1;
		while (start < end) {
			while (start < end && !isLetter(S[start]))
				start++;
			while (start < end && !isLetter(S[end]))
				end--;
			if (start < end) {
				swap(S[start], S[end]);
				end--;
				start++;
			}
		}

		return S;
	}
};
int main() {
	system("pause");
	return 0;
}