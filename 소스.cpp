#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
	T element;
	Node<T> *prev_node;
	Node<T> *next_node;
	template <typename T> friend class List;
public:
	Node(T element = NULL, Node<T> *_prev = NULL, Node<T> *_next = NULL) :
		element(element), prev_node(_prev), next_node(_next) {}
	Node<T> *prev() {
		return prev_node;
	}
	Node<T> *next() {
		return next_node;
	}
	T retrieve() {
		return element;
	}
};

template <typename T>
class List {
private:
	Node<T> *list_head;
	Node<T> *list_tail;
	int count = 0;
public:
	List() {
		list_head = new Node<T>();
		list_tail = new Node<T>();
		list_head->next_node = list_tail;
		list_tail->prev_node = list_head;
	}
	~List() {
		delete list_head;
		delete list_tail;
	}
	bool empty() {
		return (list_head->next_node == list_tail);
	}
	void push_front(T e) {
		list_head->next_node = new Node<T>(e, list_head, list_head->next());
		list_head->next()->next()->prev_node = list_head->next();
	}
	T front()
	{
		if (empty()) return -1;
		return list_head->next()->retrieve();
	}
	T back() {
		if (empty()) return -1;
		return list_tail->prev()->retrieve();
	}
	T pop_front() {
		if (empty()) return -1;
		T pop = front();
		list_head->next_node = list_head->next()->next_node;
		list_head->next()->prev_node = list_head;
		return pop;
	}
};

int main() {
	List<int> list;
	cout << boolalpha;

	cout << list.empty() << endl;

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);

	cout << list.front() << endl;		// 3
	cout << list.empty() << endl;		// false

	cout << list.back() << endl;		// 1

	cout << list.pop_front() << endl;	// 3
	cout << list.empty() << endl;		// false
	cout << list.pop_front() << endl;	// 2
	cout << list.empty() << endl;		// false
	cout << list.pop_front() << endl;	// 1
	cout << list.empty() << endl;		// true

}
