#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

void test(){
	vector<int> v;
	vector<int> v2(3, 12);
	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(v3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
}

void test2() {
	vector<int> v;
	//resize�Ĺ���ʱ�޸�vector�е�Ԫ�ظ���
	//��n����capacity����������ݣ�Ȼ������Ԫ��Ĭ�ϲ�0��
	//���߲��ϴ����ֵ�����޸�size��ֵ
	//���Ǵ���size��������Ԫ�أ��޸�size��ֵ
	//��С��size��ֻ�޸�size��ֵ
	v.resize(10);
	v.resize(20, 6);
	v.resize(3);
}

void test3() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	//v.pop_back();
	//v.pop_back();
	//v.pop_back();
	//v.pop_back();
	//v.pop_back();
	
	//vector��find�Ĳ���Ϊ������������������
	vector<int> ::iterator pos = find(v.begin(), v.end(), 3);
	//�Ҳ�����Ԫ��,����ֵΪend������
	vector<int> ::iterator pos2 = v.end();
	
	//�����ɾ��
	v.insert(pos, 10);
	pos = find(v.begin(), v.end(), 10);
	v.erase(pos);
}
void test4() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
	auto it = v.begin();
	while (it != v.end()) {
		if (*it % 2 == 0)
			it = v.erase(it);
		//else
			it++;  //���������дelse����ᵼ�³��������ԭ������ɾ���������һ��Ԫ�أ�it
			//������erase�ķ���ֵָ����Ǳ�ɾ��Ԫ�ص���һ��λ�ã�Ҳ����end��������λ������ִ��++������֮��
			//��Զ�����end��������ȣ�Ϊ�˱��������������������Ϊ������ʧЧ�����³��������
	}
	
	//vector<int> v2;
	////��������vector������
	//v2.swap(v);
}
int main() {
	test4();
	system("pause");
	return 0;
}