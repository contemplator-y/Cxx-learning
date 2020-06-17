#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

//用deque实现stack
template<class T, class Con = deque<T>>
class Stack

{
public:
	void push(const T& x) {
		_c.push_back(x);
	}

	void pop() {
		_c.pop_back();
	}

	T& top() {
		return _c.back();
	}

	const T& top()const {
		return _c.back();
	}

	size_t size()const {
		return _c.size();
	}

	bool empty()const {
		return _c.empty();
	}

private:
	Con _c;
};


//用deque实现queue
template<class T, class Con = deque<T>>
class Queue
{
public:
	void push(const T& x) {
		_c.push_back(x);
	}

	void pop() {
		_c.pop_front();
	}

	T& back() {
		return _c.back();
	}

	const T& back()const {
		return _c.back();
	}

	T& front() {
		return _c.front();
	}

	const T& front()const {
		return _c.front();
	}

	size_t size()const {
		return _c.size();
	}

	bool empty()const {
		return _c.empty();
	}
private:
	Con _c;
};

template <class T>
struct Less {
	bool operator() (const T& a, const T& b) {
		return a < b;
	}
};

template <class T>
struct Greater {
	bool operator() (const T& a, const T& b) {
		return a > b;
	}
};

//用vector实现priority_queue(默认建大堆）
template <class T, class Container = vector<T>, class Compare = Less<T> >
class Priority_queue
{
public:
	bool empty() const {
		return _c.empty();
	}

	size_t size() const {
		return _c.size();
	}

	const T& top() const {
		return _c.front();
	}

	void push(const T& x) {
		_c.push_back(x);
		shiftUp(size() - 1);
	}

	void pop() {
		swap(_c[0], _c[size() - 1]);
		_c.pop_back();
		shiftDown(0);
	}

	void shiftDown(int parent) {
		//从当前位置开始向下调整
		int child = 2 * parent + 1;
		while (child < (int)size()) {
			if (child + 1 < (int)size() && _cmp(_c[child], _c[child + 1]))
				child++;

			if (_cmp(_c[parent],_c[child])) {
				swap(_c[parent], _c[child]);
				parent = child;
				child = 2 * parent + 1;
			}
			else {
				break;
			}
		}
	}

	void shiftUp(int chi) {
		int par = (chi - 1) / 2;
		while (par >= 0) {
			if (_cmp(_c[par], _c[chi])) {
				swap(_c[par], _c[chi]);
				chi = par;
				par = (chi - 1) / 2;
			}
			else {
				break;
			}
		}
	}

private:
	Container _c;
	Compare _cmp;
};

void testS() {
	//Stack<int> st;
	Stack<int, vector<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	while (!st.empty()) {
		int top = st.top();
		cout << top << ' ';
		st.pop();
	}
	cout << endl;
}

void testQ() {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	while (!q.empty()) {
		int f = q.front();
		cout << f << ' ';
		q.pop();
	}
	cout << endl;
}

void testP() {
	Priority_queue<int, deque<int>, Greater<int>> pq;
	pq.push(10);
	pq.push(2);
	pq.push(6);
	pq.push(5);
	pq.push(9);
	pq.push(3);
	while (!pq.empty()) {
		int top = pq.top();
		cout << top << ' ';
		pq.pop();
	}
	cout << endl;
}

int main() {
	testP();
	system("pause");
	return 0;
}