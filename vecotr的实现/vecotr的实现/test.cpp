#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<class T>
class Vector
{
public:
	// Vector的迭代器是一个原生指针
	typedef T* iterator;

	typedef const T* const_iterator;

	iterator begin() { return _start; }

	iterator end() { return _finish; }

	const_iterator cbegin() const { return _start; }

	const_iterator cend() const { return _finish; }

	// construct and destroy

	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
		{}
	Vector(int n, const T& value = T()) {
		_start = new T[n];
		for (int i = 0; i < n; i++) {
			*(_start + i) = value;
		}
		_endOfStorage = _finish = _start + n;
	}

	template<class InputIterator>

	Vector(InputIterator first, InputIterator last) {
		int size = last - first;
		_start = new T[size];
		InputIterator it = first;
		int i = 0;
		while (it != last) {
			*(_start + i) = *it;
			it++;
			i++;
		}
		_finish = _endOfStorage = _start + size;
	}

	Vector(const Vector<T>& v) {
		int size = v.size(), capacity = v.capacity();
		_start = new T[capacity];
		memcpy(_start, v._start, sizeof(T) * capacity);
		_finish = _start + size;
		_endOfStorage = _start + capacity;
	}

	Vector<T>& operator= (Vector<T> v) {
		swap(v);
		return *this;
	}

	~Vector() {
		delete[] _start;
		_start = _finish = _endOfStorage = nullptr;
	}

	// capacity

	size_t size() const { return _finish - _start; }

	size_t capacity() const { return _endOfStorage - _start; }

	void reserve(size_t n) {
		if (n > capacity()) {
			//开空间
			T* newst = new T[n];
			int sz = size();
			//拷贝元素
			// 浅拷贝 memcpy(newst, _start, sizeof(T) * size());
			
			for (int i = 0; i < sz; i++) {
				newst[i] = _start[i];
			}
			delete[] _start;
			_start = newst;
			_finish = _start + sz;
			_endOfStorage = _start + n;
		}
	}

	void resize(size_t n, const T& value = T()) {
		if (n > capacity()) {
			reserve(n);
		}
		if (n > size()) {
			iterator it = _finish, end = _start + n;
			while (it != end) {
				*it = value;
				it++;
			}
		}
		
		_finish = _start + n;
	}
	
	///////////////access///////////////////////////////

	T& operator[](size_t pos) { return *(_start + pos);}

	const T& operator[](size_t pos)const { return *(_start + pos); }

	///////////////modify/////////////////////////////

	void push_back(const T& x) {
		if (_finish == _endOfStorage) {
			int newC = capacity() == 0 ? 1 : 2 * capacity();
			reserve(newC);
		}
		*_finish = x;
		_finish++;
	}

	void pop_back() {
		if (size()) {
			_finish--;
		}
	}

	void swap(Vector<T>& v) {
		Swap(_start, v._start);
		Swap(_finish, v._finish);
		Swap(_endOfStorage, v._endOfStorage);
	}

	template <class T>
	void Swap(T& a, T& b) {
		T tmp;
		tmp = a;
		a = b;
		b = tmp;
	}

	iterator find(const T& val) {
		iterator it = _start;
		while (it != _finish) {
			if (*it == val)
				return it;
			it++;
		}
		return _finish;
	}
	iterator insert(iterator pos, const T& x) {
		if (pos >= _start && pos < _finish) {
			//检查容量,并更新迭代器
			if (_finish == _endOfStorage) {
				int len = pos - _start;
				int newC = capacity() == 0 ? 1 : 2 * capacity();
				reserve(newC);
				//更新迭代器
				pos = _start + len;
			}

			//从后往前依次向后移动
			iterator it = _finish - 1;
			while (it != pos) {
				*(it + 1) = *it;
				it--;
			}
			*(pos + 1) = *pos;
			*pos = x;

			_finish++;
		}
		
		return pos;
	}

	iterator erase(iterator pos) {
		if (pos >= _start && pos < _finish) {
			//从前往后向前移动元素
			iterator it = pos;
			while (it != _finish - 1) {
				*it = *(it + 1);
				it++;
			}

			_finish--;
		}
		return pos;
	}
private:
	iterator _start; // 指向数据块的开始
	iterator _finish; // 指向有效数据的尾
	iterator _endOfStorage; // 指向存储容量的尾
};
template<class T>
void printVector( Vector<T>& v) {
	cout << "iteraotr" << endl;
	Vector<T>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << ' ';
		it++;
	}
	cout << endl;
	cout << "[]" << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << endl;
}
void test() {
	Vector<int> v;
	printVector(v);

	Vector<int> v2(4, 2);
	printVector(v2);

	int arr[] = { 1, 2, 3, 4, 5 };
	Vector<int> v3(arr, arr + 5);
	printVector(v3);

	Vector<int> v4(v3);
	printVector(v4);

	v4 = v2;
	printVector(v4);
}

void test2() {
	Vector<int> v(10, 3);
	printVector(v);

	v.reserve(12);
	printVector(v);

	v.reserve(6);
	printVector(v);

	v.resize(12, 6);
	printVector(v);

	v.resize(5);
	printVector(v);

}
void test3() {
	Vector<int> v;
	v.push_back(1);
	printVector(v);
	v.push_back(2);
	printVector(v);

	v.push_back(3);
	printVector(v);

	v.push_back(4);
	printVector(v);

	v.push_back(5);
	printVector(v);

	v.pop_back();
	printVector(v);

	v.pop_back();
	printVector(v);

	v.pop_back();
	printVector(v);

	v.pop_back();
	printVector(v);

	v.pop_back();
	printVector(v);

}
void test4() {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	printVector(v);

	auto it = v.find(3);
	it = v.erase(it);
	printVector(v);

	v.insert(v.end(), 6);
	printVector(v);

	v.insert(it, 3);
	printVector(v);

	it = v.find(5);

	it = v.erase(it);
	printVector(v);

	v.insert(it, 5);
	printVector(v);

}
int main() {
	test4();
	system("pause");
	return 0;
}