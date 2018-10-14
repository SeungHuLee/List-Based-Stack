#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
	T element;
	Node *next_node;

public:
	Node(T e = 0, Node *n = 0) : element(e), next_node(n) {}

	T retrieve() const {
		return element;
	}

	Node *next() const {
		return next_node;
	}
};

template <typename T>
class List {
private:
	Node<T> *list_head;
	Node<T> *list_tail;
public:
	List() : list_head(0), list_tail(0) {}

	bool empty() const {
		return (list_head == 0);
	}

	T front() const {
		if (empty()) {
			return -1;
		}
		return list_head->retrieve();
	}

	void push_front(T element) {
		list_head = new Node<T>(element, list_head);
	}

	T pop_front() {

		if (empty()) {
			cout << -1 << endl;
			return;
		}

		T pop = front();
		Node<T> *ptr = list_head;
		list_head = list_head->next();
		delete ptr;
		return pop;
	}
};


template <typename T>
class Stack {
private:
	List<T> list;
public:
	
	bool empty() const {
		return list.empty();
	}

	T top() const {
		return list.front();
	}

	void push(T e) {
		list.push_front(e);
	}

	T pop() {
		return list.pop_front();
	}
};

int main() {
	Stack<int> st;
	st.push(1);
	cout << st.top() << endl;
}


