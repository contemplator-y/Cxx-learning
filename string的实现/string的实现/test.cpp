#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;

class
	String
{
public:
	typedef char* iterator;
public:
	String()
		:_str(new char[16])
		, _size(0)
		, _capacity(15)
	{
		_str[_size] = '\0';
	}
	String(const char* str) {
		_size = _capacity = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);
	}

	String(const String& s) {
		_size = s._size;
		_capacity = s._capacity;
		_str = new char[_capacity + 1];
		strcpy(_str, s._str);
	}

	String& operator=(const String &s) {
		delete[] _str;
		_size = s._size;
		_capacity = s._capacity;
		_str = new char[_capacity + 1];
		strcpy(_str, s._str);
		
		return *this;
	}

	~String() {
		delete[] _str;
		_size = _capacity = 0;
	}
	// iterator

	iterator begin() {	return _str; }

	iterator end() { return _str + _size; }

	// modify

	void PushBack(char c) {
		if (_size == _capacity) {
			int newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		_str[_size] = c;
		_str[++_size] = '\0';
	}

	
	String& operator+=(char c) {
		if (_size == _capacity) {
			int newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		_str[_size] = c;
		_str[++_size] = '\0';

		return *this;
	}

	void Append(const char* str) {
		int len = strlen(str);
		if (_size + len -1 == _capacity) {
			int newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		strcpy(_str + _size, str);
		_size += len;
	}

	String& operator+=(const char* str) {
		int len = strlen(str);
		if (_size + len - 1 == _capacity) {
			int newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		strcpy(_str + _size, str);
		_size += len;

		return *this;
	}

	void clear() {	_size = 0; }

	void swap(String& s) {
		char* tmp = _str;
		_str = s._str;
		s._str = tmp;

		size_t t = _size;
		_size = s._size;
		s._size = t;

		t = _capacity;
		_capacity = s._capacity;
		s._capacity = t;
	}

	const char* c_str()const {
		return _str;
	}

	// capacity

	size_t size() const{
		return _size;
	}

	size_t capacity() const { return _capacity; }

	bool empty()const { return _size == 0; }

	void resize(size_t newSize, char c = '\0') {
		if (newSize > _capacity) {
			int newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		if (newSize > _size) {
			for (int i = _size; i < newSize; i++) {
				_str[i] = c;
			}
		}
		_size = newSize;
		_str[_size] = '\0';
	}

	void reserve(size_t newCapacity) {
		if (newCapacity > _capacity) {
			char* newStr = new char[newCapacity + 1];
			//拷贝元素
			strcpy(newStr, _str);
			_capacity = newCapacity;
			delete[] _str;
			_str = newStr;
		}
	}

	// access

	char& operator[](size_t index) {
			return _str[index];
	}

	const char& operator[](size_t index)const { 
			return _str[index];
	}



	//relational operators

	bool operator<(const String& s) {
		return strcmp(_str, s._str) < 0;
	}

	bool operator<=(const String& s) { return  strcmp(_str, s._str) <= 0; }

	bool operator>(const String& s) { return strcmp(_str, s._str) > 0; }

	bool operator>=(const String& s) { return strcmp(_str, s._str) >= 0; }

	bool operator==(const String& s) { return strcmp(_str, s._str) == 0; }

	bool operator!=(const String& s) { return strcmp(_str, s._str) != 0; }

	// 返回c在String中第一次出现的位置

	size_t find(char c, size_t pos = 0) const {
		for (int i = pos; i < _size; i++) {
			if (_str[i] == c)
				return i;
		}

		return npos;
	}

	// 返回子串s在String中第一次出现的位置

	size_t find(const char* s, size_t pos = 0) const {
		char* tmp = strstr(_str + pos, s);

		return tmp - _str;
	}

	// 在pos位置上插入字符c/字符串str，并返回该字符的位置

	iterator insert(size_t pos, char c) {
		if (_size == _capacity) {
			int newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		if (pos > _size)
			return nullptr;
		for (int i = _size + 1; i > pos; i--) {
			_str[i] = _str[i - 1];
		}
		_str[pos] = c;
		_size++;

		return _str + pos + 1;
	}

	iterator insert(size_t pos, const char* str) {
		int len = strlen(str);
		if (_size + len - 1 == _capacity) {
			int newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}

		for (int i = _size + len; i > pos + len - 1; i--) {
			_str[i] = _str[i - len];
		}
		memcpy(_str + pos, str, len); 
		_size += len;

		return _str + pos;
	}

	// 删除pos位置上的元素，并返回该元素的下一个位置

	iterator erase(size_t pos, size_t len) {
		if (_size - pos < len)
			len = _size - pos;
		for (int i = pos + len; i <= _size; i++) {
			_str[i - len] = _str[i];
		}
		_size -= len;

		return _str + pos;
	}

private:
	char* _str;
	size_t _capacity;
	size_t _size;
	static const size_t npos = -1;
};

void test() {
	String str("cai xu kun");
	String str2(str);
	String str3;
	str3 = str2;
}
void test2() {
	String str("caixukun");
	String::iterator it = str.begin();
	while (it != str.end()) {
		cout << *it << ' ';
		it++;
	}
	cout << endl;
}
void printString( String& s) {
	String::iterator it = s.begin();
	while (it != s.end()) {
		cout << *it << ' ';
		it++;
	}
	cout << endl;
}
void test3() {
	String s;
	s.PushBack('a');
	s.PushBack('b');
	s.PushBack('c');
	s.PushBack('d');
	s.PushBack('e');
	s.PushBack('f');
	s += 'g';
	s += 'h';
	s.Append("caixu");
	s += "kun";
	printString(s);
}
void test4() {
	String s("caixukun");
	cout << s.c_str() << endl;
	String s2("qiaobiluo");
	s.swap(s2);
	printString(s);
	printString(s2);

}
void test5() {
	String s;
	s.resize(2, 'a');
	s.resize(10,'x');
	s.resize(5, 'b');
	s.reserve(100);
	s.reserve(50);

}
void test6() {
	String s("yang");
	String s2("yant");
	cout << (s < s2) << endl;
}
void test7() {
	String s("caixukun");
	int pos = s.find('c');
	pos = s.find('x');
	pos = s.find('k');
	pos = s.find('n');
	pos = s.find("xu");
}
void test8() {
	String s("01234567");
	s.insert(0, 'a');
	s.insert(3, '9');
	s.insert(5, 'b');
	s.insert(7, "yang");
	
	s.erase(2, 100);
}
void test9() {
	String s("caixukun");
	String::iterator it = s.begin();
	while (it != s.end()) {
		cout << *it << ' ';
		it = s.erase(it - s.begin(), 1);
	}
	cout << endl;
}
int main() {
	test9();
	system("pause");
	return 0;
}