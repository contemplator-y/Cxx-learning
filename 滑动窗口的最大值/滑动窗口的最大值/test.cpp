#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int getMax(vector<int>& arr, int start, int end) {
		int max = arr[start];
		for (int i = start + 1; i <= end; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}

		return max;
	}
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ret;
		if (nums.size() == 0 || k == 0) {
			return ret;
		}
		for (int i = 0; i <= nums.size() - k; i++) {
			int max = getMax(nums, i, i + k - 1);
			ret.push_back(max);
		}

		return ret;
	}
};
int main() {
	system("pause");
	return 0;
}