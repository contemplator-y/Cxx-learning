#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


int main() {
	int num;
	while (cin >> num) {
		int count = 0; //�������1�ĸ���
		int start = -1, end = -1; // ��¼����1�Ŀ�ʼ�ͽ���λ��
		for (int i = 0; i < 8; i++) {
			if (((1 << i) & num) != 0) {
				if (start == -1) //������ʼλ��
					start = i;
			}
			else if (start != -1) {
				end = i - 1; //���½���λ��
				if (end - start + 1> count)
					count = end - start + 1; //���������1�����Ƚ�

				start = -1;
			}
		}
		if ((1 << 7) & num) {  //�����λΪ1����Ҫ�ٸ���1�Ľ���λ�ò��ж��Ƿ���Ҫ����count
			end = 7;
			if (end - start + 1 > count)
				count = end - start + 1;
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}