#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());

	int tmp[3] = { 0 };
	for (int i = 0; i < nums.size(); i++) {
		vector<int> ele;
		tmp[0] = nums[i];
		for (int j = i + 1; j < nums.size(); j++) {
			tmp[1] = nums[j];
			for (int k = j + 1; k < nums.size(); k++) {
				if (nums[k] + tmp[0] + tmp[1] == 0) {
					ele.push_back(tmp[0]);
					ele.push_back(tmp[1]);
					ele.push_back(nums[k]);
					res.push_back(ele);
					ele.pop_back();
					ele.pop_back();
					ele.pop_back();

					//跳过后面重复的元素
					while (k + 1 < nums.size() && nums[k + 1] == nums[k])
						k++;
				}
			}
			//跳过之后重复的元素
			while (j + 1 < nums.size() && nums[j + 1] == nums[j])
				j++;
		}
		//跳过之后重复的元素
		while (i + 1 < nums.size() && nums[i + 1] == nums[i])
			i++;
	}

	return res;
}

int main() {
	system("pause");
	return 0;
}