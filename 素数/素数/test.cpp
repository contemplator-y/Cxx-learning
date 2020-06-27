#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <tgmath.h>
#include <vector>
using namespace std;

bool isPrime(int n) {
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 11; i < n; i += 10) {
		int tmp = isPrime(i);
		if (tmp)
			v.push_back(i);
	}
	if (v.empty()) {
		cout << -1 << endl;
	}
	else {
		for (int i = 0; i < v.size() - 1; i++) {
			cout << v[i] << ' ';
		}
		cout << v[v.size() - 1] << endl;
	}

	return 0;
}