#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

char firstUniqChar(char* s){
	if (s == NULL || *s == NULL) {
		return ' ';
	}
	//���ռ䣬���ڼ�¼ÿ���ַ����ֵĴ���
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