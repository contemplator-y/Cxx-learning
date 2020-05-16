#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
using namespace std;

//由前size个丑数产生下一个丑叔
//由前size个丑数产生下一个丑叔
void getNextUglyNumber(int* arr, int size, int* f2, int* f3, int* f5) {
	int m2 = 0, m3 = 0, m5 = 0; //由前面的丑叔乘上2,3,5产生的大于当前最大丑叔的最小值
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
	int f2 = 0, f3 = 0, f5 = 0; //产生才一个丑叔的起始位置
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