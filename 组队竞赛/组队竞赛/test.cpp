#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	v.reserve(3 * n);
	int tmp;
	while (cin >> tmp) {
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	long long ret = 0;
	int idx = 3 * n - 2;
	while (n) {
		ret += v[idx];
		idx -= 2;
		n--;
	}

	cout << ret << endl;
	return 0;
}