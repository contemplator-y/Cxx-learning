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

//List�ĵ�������
template<class T, class Ref, class Ptr>
struct ListIterator {
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;
	ListIterator(Node* node)
		:_node(node)
	{}

	//������ ����ȡ����ֵ
	Ref operator*() {
		return _node->_value;
	}

	//++�ƶ�����һ��Ԫ�ص�λ��
	Self& operator++() {
		_node = _node->next;
		return *this;
	}

	bool operator!=(const Self& it) {
		return _node != it._node;
	}

	//����->����������ڷ����Զ������͵ĳ�Ա
	Ptr operator->() {
		return &_node->_value;
	}

	//ǰ��--
	Self& operator--() {
		_node = _node->pre;
		return *this;
	}

public:
	Node* _node;
};


//�������¶���һ��const_iterator������
//template<class T>
//struct constListIterator {
//	typedef ListNode<T> Node;
//	typedef constListIterator<T> Self;
//	constListIterator(Node* node)
//		:_node(node)
//	{}
//
//	//������ ����ȡ����ֵ
//	const T& operator*() {
//		return _node->_value;
//	}
//
//	//++�ƶ�����һ��Ԫ�ص�λ��
//	Self& operator++() {
//		_node = _node->next;
//		return *this;
//	}
//
//	bool operator!=(const Self& it) {
//		return _node != it._node;
//	}
//
//	//����->����������ڷ����Զ������͵ĳ�Ա
//	const T* operator->() {
//		return &_node->_value;
//	}
//
//	//ǰ��--
//	Self& operator--() {
//		_node = _node->pre;
//		return *this;
//	}
//
//public:
//	Node* _node;
//};

//List�� 
template<class T>
class List {
	typedef ListNode<T> Node;
	typedef ListIterator<T, T&, T*> iterator;
	//typedef const ListIterator<T> const_iterator;
	//������ֱ�Ӽ�const���η������Ϊֻ������������Ϊ�����ᵼ�µ�������++�����޷�ִ��
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
		//ѭ���ṹ������Ҫ�жϵ������Ƿ���Ч
		Node* cur = new Node(val);

		Node* node = pos._node;
		Node* pre = node->pre;

		pre->next = cur;
		cur->pre = pre;
		cur->next = node;
		node->pre = cur;
	}

	//ɾ���ᵼ�µ�ǰ������ʧЧ
	iterator erase(iterator pos) {
		//����ɾ��ͷ���
		if (pos != end()) {
			Node* node = pos._node;
			Node* pre = node->pre;
			Node* next = node->next;

			delete node;

			pre->next = next;
			next->pre = pre;

			//������һ��Ԫ�صĵ�����
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

	//�ͷ����еĽ��
	~List() {
		if (_head) {
			clear();
			delete _head;
			_head = nullptr;
		}
	}
	
	//������еķ�ͷ���
	void clear() {
		Node* cur = _head->next;
		while (cur != _head) {
			Node* next = cur->next;
			delete cur;
			cur = next;
		}
		//���¹���ѭ���ṹ
		_head->next = _head->pre = _head;
	}

	//�������캯��
	List(const List<T>& lst) 
		:_head(new Node)
	{
		_head->pre = _head->next = _head;
		//���������Ԫ��
		for (const auto& e : lst) {
			pushBack(e);
		}
	}

	//��ֵ��������غ���
	List<T>& operator=(List<T> lst) {
		//ʵ�ε����˿������캯��
		//ֱ�ӽ���_head��Ա����˸�ֵ����
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