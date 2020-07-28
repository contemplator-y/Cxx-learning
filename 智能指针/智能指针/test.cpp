#define _CRT_SECURE_NO_WARNINGS 1
#include <memory>
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

template<class T>
class SmartPtr {
private:
	T* _ptr;
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	SmartPtr(SmartPtr<T>& sp) {
		_ptr = sp._ptr;
		sp._ptr = nullptr;
	}

	SmartPtr<T>& operator=( SmartPtr<T>& sp) {
		if (sp._ptr != _ptr) {
			if (_ptr)
				delete _ptr;
			_ptr = sp._ptr;
			sp._ptr = nullptr;
		}

		return *this; 
	}

	~SmartPtr() {
		if (_ptr) {
			cout << "~SmartPtr" << endl;
			delete _ptr;
		}
	}

	T& operator*() {
		return *_ptr;
	}

	T* operator->() {
		return _ptr;
	}

};

struct Date {
	int _year = 1;
};

void test() {
	auto_ptr<int> ap(new int);
	*ap = 100;
	cout << *ap << endl;
	auto_ptr<int> ap2(ap);
	cout << *ap2 << endl;
	// cout << *ap << endl;  ap已经将整型变量的空间的管理权转移给了ap2，解引用异常
}

void test2() {
	SmartPtr<int> ap(new int);
	*ap = 100;
	cout << *ap << endl;
	SmartPtr<int> ap2(ap);
	//cout << *ap << endl;
	cout << *ap2 << endl;
}

// 将拷贝构造和赋值函数删除
template<class T>
class UniquePtr {
private:
	T* _ptr;
public:
	UniquePtr(T* ptr)
		:_ptr(ptr)
	{}

	UniquePtr(UniquePtr<T>& sp) = delete;

	UniquePtr<T>& operator=(UniquePtr<T>& sp) = delete;
	

	~UniquePtr() {
		if (_ptr) {
			cout << "~UniquePtr" << endl;
			delete _ptr;
		}
	}

	T& operator*() {
		return *_ptr;
	}

	T* operator->() {
		return _ptr;
	}

};

template<class T, class deletor>
class SharedPtr {
private:
	T* _ptr;
	int* _useCount;
	mutex* _mtx;
	deletor _del;
public:
	SharedPtr(T* ptr, const deletor& del)
		:_ptr(ptr)
		, _useCount(new int(1))
		, _mtx(new mutex)
		, _del(del)
	{}

	void addRef() {
		_mtx->lock();
		++(*_useCount);
		_mtx->unlock();
	}

	int delRef() {
		_mtx->lock();
		--(*_useCount);
		_mtx->unlock();
		return *_useCount;
	}

	SharedPtr(SharedPtr<T, deletor>& sp) {
		_ptr = sp._ptr;
		_mtx = sp._mtx;
		_useCount = sp._useCount;
		addRef();
	}
	
	SharedPtr<T, deletor>& operator=(SharedPtr<T, deletor>& sp) {
		if (_ptr != sp._ptr) {
			if (*_useCount == 1)
				delete _ptr;

			_ptr = sp._ptr;
			_useCount = sp._useCount;
			addRef();
		}

		return *this;
	}

	~SharedPtr() {
		if (delRef() == 0) {
			cout << "~SharedPtr" << endl;
			_del(_ptr);
		}
	}

	T& operator*() {
		return *_ptr;
	}

	T* operator->() {
		return _ptr;
	}

	int getUseCount() { return *_useCount; }
};

//void test4() {
//	SharedPtr<Date> sp(new Date);
//	sp->_year = 2020;
//	cout << sp->_year << endl;
//
//	SharedPtr<Date> sp2(sp);
//	cout << sp2->_year << endl;
//
//	SharedPtr<Date> sp3(new Date);
//	sp3->_year = 2019;
//	sp3 = sp;
//	cout << sp3->_year << endl;
//}
//void test3() {
//	UniquePtr<Date> up(new Date);
//	up->_year = 2020;
//	cout << up->_year << endl;
//	//UniquePtr<Date> up2(up);
//	//UniquePtr<Date> up3(new Date);
//	//up3 = up;
//
//}

//void fun(int n) {
//	SharedPtr<Date> sp(new Date);
//	for (int i = 0; i < n; i++) {
//		SharedPtr<Date> sp2(sp);
//	}
//
//	cout << sp.getUseCount() << endl;
//}
//
//void fun2(int n) {
//	shared_ptr<Date> sp(new Date);
//	for (int i = 0; i < n; i++) {
//		shared_ptr<Date> sp2(sp);
//	}
//
//	cout << sp.use_count() << endl;
//}
//
//void func3(SharedPtr<Date>& sp, int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		SharedPtr<Date> copy(sp);
//	}
//}
//
//void testSharedPtr3()
//{
//	SharedPtr<Date> sp(new Date);
//	cout << sp.getUseCount() << endl;
//	int n;
//	cin >> n;
//	thread t1(func3, sp, n);
//	thread t2(func3, sp, n);
//
//
//	t1.join();
//	t2.join();
//
//	cout << sp.getUseCount() << endl;
//
//}

template<class T>
struct freeM {
	void operator()(T* ptr) {
		free(ptr);
		cout << "freeM" << endl;
	}
};

template<class T>
struct delArr {
	void operator()(T* ptr) {
		delete[] ptr;
		cout << "DelArr" << endl;
	}
};

void test6() {
	SharedPtr<int, delArr<int> > sp(new int[100], delArr<int>());
	SharedPtr<int, freeM<int> > sp2(new int, freeM<int>());

}
int main() {
	//test4();
	//int n;
	//cin >> n;
	//thread t1(fun2, n);
	//thread t2(fun2, n);
	//thread t3(fun2, n);
	//thread t4(fun2, n);
	//thread t5(fun2, n);

	//t1.join();
	//t2.join();
	//t3.join();
	//t4.join();
	//t5.join();

	//testSharedPtr3();
	test6();
	system("pause");
	return 0;
}