#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/*
��һ���������飬ɾ�����������е��ظ�Ԫ�أ�һ��Ԫ�������Գ�������

�������飬ɨ����ЧԪ�أ�ֵ��ͬ��Ԫ��ǰ��������Ч�ģ�֮���Ԫ������Ч����Ҫɾ�������ƶ������鿪ͷ����
*/
int removeDuplicates1(int arr[], int n) {
	if (n <= 2) return n;

	int idx = 2; //��һ����ЧԪ�صĴ��λ��
	for (int i = 2; i < n; i++) {
		//�͵�ǰ�����ڶ�����ЧԪ�ز������һ�������ظ�Ԫ���еĵ���������������������һ������Ч��
		//�ƶ������鿪ͷ
		if (arr[i] != arr[idx - 2])
			arr[idx++] = arr[i];
	}

	return idx;
}
int removeDuplicates2(int arr[], int n) {
	if (n <= 2) return n;

	int idx = 0; //��һ����ЧԪ�صĴ��λ��
	for (int i = 0; i < n; i++) {
		//���ظ�Ԫ���еĵ�һ�������һ��������ЧԪ���ƶ�����ͷ
		//��βԪ��һ����Ч����һ����ЧԪ�ز�����if��������������if��������һ�������ظ�Ԫ���е����һ��
		if (i > 0 && i < n - 1 && arr[i] == arr[i - 1] && arr[i] == arr[i + 1])
			continue;
		arr[idx++] = arr[i];
	}

	return idx;
}
int main() {
	int arr[] = { 1, 1, 1 ,1, 2, 3, 4, 4, 4, 5, 5 , 6, 6, 6, 6, 6, 6, 6, 7, 7, 7};
	int n = removeDuplicates2(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}