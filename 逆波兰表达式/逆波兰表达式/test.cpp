#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	int calc(int left, int right, const string& str) {
		if (str == "+")
			return left + right;
		if (str == "-")
			return left - right;
		if (str == "*")
			return left * right;

		return left / right;
	}
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (const auto& str : tokens) {
			if (str == "+" || str == "-"
				|| str == "*" || str == "/") {
				int r = st.top();
				st.pop();
				int l = st.top();
				st.pop();
				st.push(calc(l, r, str));
			}
			else {
				st.push(stoi(str));
			}
		}

		return st.top();
	}
};
int main() {
	system("pause");
	return 0;
}