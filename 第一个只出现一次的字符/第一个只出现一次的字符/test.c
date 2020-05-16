#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

char firstUniqChar(char* s){
	if (s == NULL || *s == NULL) {
		return ' ';
	}
	//开空间，用于记录每个字符出现的次数
	int* tmp = (int*)malloc(sizeof(int) * 127);
	memset(tmp, 0, sizeof(int) * 127);
	for (char* cur = s; *cur; cur++) {
		tmp[*cur]++;
	}
	for (char* cur = s; *cur; cur++) {
		if (tmp[*cur] == 1) {
			return *cur;
		}
	}

	return ' ';
}

int main() {
	return 0;
}