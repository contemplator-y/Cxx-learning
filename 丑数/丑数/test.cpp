#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
using namespace std;

//��ǰsize������������һ������
//��ǰsize������������һ������
void getNextUglyNumber(int* arr, int size, int* f2, int* f3, int* f5) {
	int m2 = 0, m3 = 0, m5 = 0; //��ǰ��ĳ������2,3,5�����Ĵ��ڵ�ǰ���������Сֵ
	while (*f2 < size) {
		if (arr[(*f2)] * 2 <= arr[size - 1]) {
			(*f2)++;
			continue;
		}
		break;
	}
	m2 = arr[(*f2)] * 2;

	while (*f3 < size) {
		if (arr[(*f3)] * 3 <= arr[size - 1]) {
			(*f3)++;
			continue;
		}
		break;
	}
	m3 = arr[(*f3)] * 3;

	while (*f5 < size) {
		if (arr[(*f5)] * 5 <= arr[size - 1]) {
			(*f5)++;
			continue;
		}
		break;
	}
	m5 = arr[(*f5)] * 5;

	if (m3 > m5) {
		m3 = m5;
	}
	if (m3 < m2) {
		arr[size] = m3;
	}
	else {
		arr[size] = m2;
	}
}
int nthUglyNumber(int n){
	int* res = (int*)malloc(sizeof(int) * n);
	res[0] = 1;
	int f2 = 0, f3 = 0, f5 = 0; //������һ���������ʼλ��
	for (int i = 1; i < n; i++) {
		getNextUglyNumber(res, i, &f2, &f3, &f5);
	}

	return res[n - 1];
}
int main() {
	int n = 4;
	int res = nthUglyNumber(n);
	cout << res << endl;

	system("pause");
	return 0;
}