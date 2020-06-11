#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Solution {
public:
	void reverse(string& s, int start, int end) {
		while (start < end) {
			char tmp = s[start];
			s[start] = s[end];
			s[end] = tmp;
			start++;
			end--;
		}
	}
	string reverseWords(string s) {
		if (s.size() == 0)
			return s;
		int start = 0;
		while (start < s.size()) {
			size_t pos = s.find(' ', start);
			if (pos != s.npos) {
				reverse(s, start, pos - 1);
				start = pos + 1;
			}
			else {
				reverse(s, start, s.size() - 1);
				start = s.size();
			}
		}

		return s;
	}
};
int main() {
	system("pause");
	return 0;
}