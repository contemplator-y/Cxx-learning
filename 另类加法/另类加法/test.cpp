#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int addAB(int A, int B) {
	 int  res = A ^ B; // ��Ӧ��λ���
	int ov = A & B; // ��λ
	while (ov != 0) {
		ov <<= 1;
		int tmp = res;
		res = res ^ ov;
		ov = tmp & ov;
	}

	return res;
}

int main() {
	int res = addAB(3, 2);
	cout << res << endl;
	int a = (4 & 1) << 1;
	cout << a << endl;

	system("pause");
	return 0;
}