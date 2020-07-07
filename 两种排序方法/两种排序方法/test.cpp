#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<string> v;
	string input;
	while (cin >> n) {
		v.reserve(n);
		int tmp = n;
		while (tmp--) {
			cin >> input;
			v.push_back(input);
		}
		int flag1 = 1, flag2 = 1; //��ǵ�ǰ�Ƿ��������򷽷���1��ʾ���㣬0��ʾ������
		for (int i = 0; i < n - 1; i++) {
			if (flag1 == 0 && flag2 == 0) {
				break;  //�Ѿ�ȷ�����ַ�����������
			}
			if (flag1 == 1 && v[i].compare(v[i + 1]) > 0)
				flag1 = 0;
			if (flag2 == 1 && v[i].size() > v[i + 1].size())
				flag2 = 0;
		}

		if (flag1 == 0 && flag2 == 0)
			cout << "none" << endl;
		else if (flag1 == 1 && flag2 == 1)
			cout << "both" << endl;
		else if (flag1 == 1)
			cout << "lexicographically" << endl;
		else
			cout << "lengths" << endl;

		v.clear();
	}
	return 0;
}