#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
	//�����ַ������
	string addString(string& num1, string& num2) {
		string sum;
		sum.reserve(num1.size() > num2.size() ? (num1.size() + 1) : (num2.size() + 1));

		int idx1 = num1.size() - 1, idx2 = num2.size() - 1;
		int carry = 0;
		while (idx1 >= 0 || idx2 >= 0) {
			int tmp = carry;
			if (idx1 >= 0) {
				tmp += num1[idx1--] - '0';
			}
			if (idx2 >= 0)
				tmp += num2[idx2--] - '0';
			if (tmp > 9) {
				carry = 1;
				tmp -= 10;
			}
			else {
				carry = 0;
			}
			sum += tmp + '0';
		}
		if (carry) {
			sum += '1';
		}

		reverse(sum.begin(), sum.end());

		return sum;

	}

	string multiply(string num1, string num2) {
		//ģ��˷���ʽ
		string ret;
		//�г���Ϊ0���߿մ�
		if (num1.size() == 0 || num2.size() == 0 || num1[0] == '0' || num2[0] == '0') {
			ret += '0';
			return ret;
		}
		ret.reserve(num1.size() + num2.size() + 1);
		for (int i = num2.size() - 1; i >= 0; i--) {
			//������ÿһλ�뱻�������
			int idx = num1.size() - 1;
			int carry = 0;
			string tmp; //���һλ�뱻������˵Ľ��
			while (idx >= 0) {
				int s = (num1[idx--] - '0') * (num2[i] - '0') + carry;
				tmp += s % 10 + '0';
				carry = s / 10;
			}
			if (carry) {
				tmp += carry + '0';
			}
			reverse(tmp.begin(), tmp.end());
			//�˻�������油�϶����0
			for (int j = 0; j < num2.size() - 1 - i; j++) {
				tmp += '0';
			}
			//��һλ��˵Ľ���ӵ��ܽ����
			ret = addString(ret, tmp);
		}

		return ret;
	}
};