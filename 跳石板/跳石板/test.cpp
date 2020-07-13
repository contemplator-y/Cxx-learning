#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void getAllFact(vector<int>& v, int n) {
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0)
			v.push_back(i);
	}
}

bool isPrime(int n) {
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}

int canMove(int n, int m) {
	if (n == m) {
		return 0;
	}

	vector<int> fa;
	getAllFact(fa, n); // 获取n的所有因数
	if (n > m || fa.empty() || isPrime(m)) { // 不能到达
		return -1;
	}
	// 分治
	int min = m; //存放最小步数
	while (!fa.empty()) {
		int b = fa.back();
		int ret = canMove(n + b, m);
		if (ret != -1) {
			if (ret == 0)
				return 1;
			if (ret + 1 < min) //更新最小步数
				min = ret + 1;
		}
		fa.pop_back();
	}

	return min == m ? -1 : min;
}
int main() {
	int n, m;
	cin >> n >> m;
	cout << canMove(n, m) << endl;
	system("pause");
	return 0;
}