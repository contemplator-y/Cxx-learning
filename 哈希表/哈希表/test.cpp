#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

enum State {
	EXIST,  
	EMPTY,
	DELETE
};

template<class K, class V>
struct HashNode {
	pair<K, V> _value;
	State _state = EMPTY;
};

template<class K, class V>
class HashTable {
private:
	vector<HashNode<K,V>> _table;
	size_t _size; // ��ϣ����ʵ�ʴ�ŵĽ�����

public:
	HashTable(size_t n = 10) {
		_table.resize(n);
		_size = 0;
	}

	bool insert(const pair<K, V>& value) {
		// �������
		checkCapacity();

		// �����ŵ�λ��
		int idx = value.first % _table.size();
		while (_table[idx]._state == EXIST) {
			// �жϴ�����Ԫ���Ƿ��Ѿ�����
			if (_table[idx]._value.first == value.first)
				return false;
			idx++;
			if (idx == _table.size())
				idx = 0;
		}
		//����Ԫ��
		_table[idx]._value = value;
		_table[idx]._state = EXIST;
		_size++;
		return true;
	}

	// ����
	HashNode<K, V>* find(const K& key) {
		int idx = key % _table.size();
		while (_table[idx]._state != EMPTY) {
			if (_table[idx]._state == EXIST && _table[idx]._value.first == key)
				return &_table[idx];
			idx++;
			if (idx == _table.size())
				idx = 0;
		}

		return nullptr;
	}

	// ɾ�����
	bool erase(const K& key) {
		HashNode<K, V>* p = find(key);
		if (p) {
			p->_state = DELETE;
			--_size;
			return true;
		}
		return false;
	}
	void checkCapacity() {
		// �ж��Ƿ񳬹��˸�������
		if (_size * 10 / _table.size() >= 7) {
			HashTable tmp(_table.size() * 2);
			// ��ԭ���д��ڵ�Ԫ�ؿ������±���
			for (int i = 0; i < _table.size(); i++) {
				if (_table[i]._state == EXIST)
					tmp.insert(_table[i]._value);
			}
			
			// ���ɱ��滻���±�
			swap(_table, tmp._table);
		}
	}
};

void test() {
	HashTable<int, int> h;
	h.insert(make_pair(1, 1));
	h.insert(make_pair(11, 11));
	h.insert(make_pair(2, 2));
	h.insert(make_pair(4, 4));
	h.insert(make_pair(14, 14));
	h.insert(make_pair(26, 14));
	h.insert(make_pair(92, 14));
	h.insert(make_pair(15, 14));
	h.insert(make_pair(33, 14));

	HashNode<int,int>* p = h.find(16);
	if (p)
		cout << p->_value.second << endl;
	else
		cout << "�����ڸý��" << endl;

	bool ret = h.erase(92);
	cout << ret << endl;
	ret = h.erase(424);
	cout << ret << endl;
}
int main() {
	test();
	system("pause");
	return 0;
}