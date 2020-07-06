#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		int size1 = haystack.size(), size2 = needle.size();
		if (size1 < size2)
			return -1;
		int idx1 = 0, idx2 = 0, start = 0;
		while (idx1 < size1 && idx2 < size2) {
			if (haystack[idx1] == needle[idx2]) {
				idx1++;
				idx2++;
			}
			else {
				idx1 = ++start;
				idx2 = 0;
			}
		}
		if (idx2 == size2)
			return start;
		return -1;
	}
};