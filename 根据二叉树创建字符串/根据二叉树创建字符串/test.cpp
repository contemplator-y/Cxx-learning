#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	void tree2str(TreeNode* t, string& str) {
		if (t) {
			stringstream ss;
			ss << t->val;
			str += ss.str();
			if (t->left == nullptr && t->right == nullptr)
				return;
			str.push_back('(');
			tree2str(t->left, str);
			str.push_back(')');

			if (t->right) {
				str.push_back('(');
				tree2str(t->right, str);
				str.push_back(')');
			}
		}
	}
	string tree2str(TreeNode* t) {
		string str;
		tree2str(t, str);

		return str;
	}
};

int main() {
	system("pause");
	return 0;
}