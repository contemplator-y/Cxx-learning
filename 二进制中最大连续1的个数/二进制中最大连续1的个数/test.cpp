#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


int main() {
	int num;
	while (cin >> num) {
		int count = 0; //最大连续1的个数
		int start = -1, end = -1; // 记录连续1的开始和结束位置
		for (int i = 0; i < 8; i++) {
			if (((1 << i) & num) != 0) {
				if (start == -1) //更新起始位置
					start = i;
			}
			else if (start != -1) {
				end = i - 1; //更新结束位置
				if (end - start + 1> count)
					count = end - start + 1; //与最大连续1个数比较

				start = -1;
			}
		}
		if ((1 << 7) & num) {  //若最高位为1，需要再更新1的结束位置并判断是否需要更新count
			end = 7;
			if (end - start + 1 > count)
				count = end - start + 1;
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}