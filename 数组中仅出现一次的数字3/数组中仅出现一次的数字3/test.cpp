#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> ret;

		int tmp = 0;
		for (const auto& e : nums) {
			tmp ^= e;
		}
		//根据异或的结果给其他的元素进行分组
		int pos = 0;
		for (; pos < 32; pos++) {
			if ((1 << pos) & tmp) {
				break;
			}
		}

		int r1 = 0, r2 = 0;
		for (const auto& e : nums) {
			if ((1 << pos) & e) {
				r1 ^= e;
			}
			else {
				r2 ^= e;
			}
		}
		ret.push_back(r1);
		ret.push_back(r2);

		return ret;
	}
};

int main() {
	system("pause");
	return 0;
}