#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/*
给一个排序数组，删除排序数组中的重复元素，一个元素最多可以出现两次

遍历数组，扫描有效元素（值相同的元素前两个是有效的，之后的元素是无效的需要删除），移动至数组开头即可
*/
int removeDuplicates1(int arr[], int n) {
	if (n <= 2) return n;

	int idx = 2; //下一个有效元素的存放位置
	for (int i = 2; i < n; i++) {
		//和当前倒数第二个有效元素不相等则一定不是重复元素中的第三个，由于数组有序则一定是有效的
		//移动到数组开头
		if (arr[i] != arr[idx - 2])
			arr[idx++] = arr[i];
	}

	return idx;
}
int removeDuplicates2(int arr[], int n) {
	if (n <= 2) return n;

	int idx = 0; //下一个有效元素的存放位置
	for (int i = 0; i < n; i++) {
		//将重复元素中的第一个和最后一个当成有效元素移动至开头
		//首尾元素一定有效，第一个有效元素不满足if的条件，若满足if的条件则一定不是重复元素中的最后一个
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