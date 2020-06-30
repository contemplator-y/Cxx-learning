#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<class T>
struct ListNode {
	T _value;
	ListNode<T>* pre;
	ListNode<T>* next;

	ListNode(const T& value = T())
		:_value(value)
		, pre(nullptr)
		, next(nullptr)
	{}
};

//List的迭代器类
template<class T, class Ref, class Ptr>
struct ListIterator {
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;
	ListIterator(Node* node)
		:_node(node)
	{}

	//解引用 ：获取结点的值
	Ref operator*() {
		return _node->_value;
	}

	//++移动到下一个元素的位置
	Self& operator++() {
		_node = _node->next;
		return *this;
	}

	bool operator!=(const Self& it) {
		return _node != it._node;
	}

	//重载->运算符，用于访问自定义类型的成员
	Ptr operator->() {
		return &_node->_value;
	}

	//前置--
	Self& operator--() {
		_node = _node->pre;
		return *this;
	}

public:
	Node* _node;
};


//可以重新定义一个const_iterator迭代器
//template<class T>
//struct constListIterator {
//	typedef ListNode<T> Node;
//	typedef constListIterator<T> Self;
//	constListIterator(Node* node)
//		:_node(node)
//	{}
//
//	//解引用 ：获取结点的值
//	const T& operator*() {
//		return _node->_value;
//	}
//
//	//++移动到下一个元素的位置
//	Self& operator++() {
//		_node = _node->next;
//		return *this;
//	}
//
//	bool operator!=(const Self& it) {
//		return _node != it._node;
//	}
//
//	//重载->运算符，用于访问自定义类型的成员
//	const T* operator->() {
//		return &_node->_value;
//	}
//
//	//前置--
//	Self& operator--() {
//		_node = _node->pre;
//		return *this;
//	}
//
//public:
//	Node* _node;
//};

//List类 
template<class T>
class List {
	typedef ListNode<T> Node;
	typedef ListIterator<T, T&, T*> iterator;
	//typedef const ListIterator<T> const_iterator;
	//不可以直接加const修饰符将其变为只读迭代器，因为这样会导致迭代器的++操作无法执行
	typedef ListIterator<T, const T&, const T*> const_iterator;
public:
	iterator begin() {
		return iterator(_head->next);
	}

	iterator end() {
		return iterator(_head);
	}

	const_iterator begin() const{
		return const_iterator(_head->next);
	}

	const_iterator end() const{
		return const_iterator(_head);
	}
	List() 
		:_head(new Node)
	{
		_head->next = _head->pre = _head;
	}
	 
	void pushBack(const T& val) {
		Node* cur = new Node(val);

		Node* end = _head->pre;
		end->next = cur;
		cur->pre = end;
		cur->next = _head;
		_head->pre = cur;
	}

	void pushFront(const T& val) {
		insert(begin(), val);
	}

	void popBack() {
		erase(--end());
	}

	void popFront() {
		erase(begin());
	}

	void insert(iterator pos, const T& val) {
		//循环结构，不需要判断迭代器是否有效
		Node* cur = new Node(val);

		Node* node = pos._node;
		Node* pre = node->pre;

		pre->next = cur;
		cur->pre = pre;
		cur->next = node;
		node->pre = cur;
	}

	//删除会导致当前迭代器失效
	iterator erase(iterator pos) {
		//不能删除头结点
		if (pos != end()) {
			Node* node = pos._node;
			Node* pre = node->pre;
			Node* next = node->next;

			delete node;

			pre->next = next;
			next->pre = pre;

			//返回下一个元素的迭代器
			return iterator(next);
		}

		return pos;
	}

	size_t size() const {
		size_t size = 0;

		for (const auto& e : *this) {
			++size;
		}

		return size;
	}

	//释放所有的结点
	~List() {
		if (_head) {
			clear();
			delete _head;
			_head = nullptr;
		}
	}
	
	//清空所有的非头结点
	void clear() {
		Node* cur = _head->next;
		while (cur != _head) {
			Node* next = cur->next;
			delete cur;
			cur = next;
		}
		//重新构建循环结构
		_head->next = _head->pre = _head;
	}

	//拷贝构造函数
	List(const List<T>& lst) 
		:_head(new Node)
	{
		_head->pre = _head->next = _head;
		//深拷贝，插入元素
		for (const auto& e : lst) {
			pushBack(e);
		}
	}

	//赋值运算符重载函数
	List<T>& operator=(List<T> lst) {
		//实参调用了拷贝构造函数
		//直接交换_head成员完成了赋值操作
		swap(_head, lst._head);
		return *this;
	}
private:
	Node* _head;
};

class B {
public:
	int _a;
	int _b;

	B(int a = 1, int b = 1)
		:_a(a)
		, _b(b)
	{}
};
template<class T>
void printList(List<T>& lst) {
	auto it = lst.begin();
	while (it != lst.end()) {
		cout << *it << ' ';
		*it = 0;
		++it;
	}
	cout << endl;
}

template<class T>
void printListC(const List<T>& lst) {
	auto it = lst.begin();
	while (it != lst.end()) {
		cout << *it << ' ';
		//*it = 2;
		++it;
	}
	cout << endl;
}
void test2() {
	List<B> lst;
	lst.pushBack(B(1, 2));
	lst.pushBack(B(3, 4));
	lst.pushBack(B(5, 6));
	lst.pushBack(B(7, 8));

	auto it = lst.begin();
	while (it != lst.end()) {
 		cout << it->_a << ' ' << it->_b << endl;
		++it;
	}
	cout << endl;
}
void test() {
	List<int> lst;
	lst.pushBack(1);
	printList(lst);
	lst.pushBack(2);
	printList(lst);

	lst.pushBack(3);
	printList(lst);

	lst.pushBack(4);
	printList(lst);

	cout << "printListC:" << endl;
	printListC(lst);

}
void test3() {
	List<B> lst;
	lst.pushBack(B(1, 1));
	lst.pushBack(B(2, 2));
	lst.pushBack(B(3, 3));
	lst.pushBack(B(4, 4));
	auto it = lst.begin();
	while (it != lst.end()) {
		cout << it->_a << ' ' << it->_b << endl;
		++it;
	}
	cout << endl;

}

void test5() {
	List<int> lst;
	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);
	lst.pushBack(5);
	printListC(lst);
}

void test6() {
	List<int> lst;

	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);

	printListC(lst);

	lst.popBack();
	printListC(lst);

	lst.popFront();
	printListC(lst);

	lst.popBack();
	printListC(lst);

	lst.popFront();
	printListC(lst);

	lst.popBack();
	printListC(lst);

	lst.popFront();
	printListC(lst);

}
int main() {
	test6();
	system("pause");
	return 0;
}