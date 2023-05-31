#pragma once
#include <initializer_list>
#include <limits>
#include <iostream>
namespace nc {
	template<typename T>
	class list
	{
		struct node_t
		{
			node_t(const T& value) : _value{ value } {}
			T _value;
			node_t* _next{ nullptr };
			node_t* _prev{ nullptr };
		};
	public:
		list() {}
		list(const std::initializer_list<T>& ilist);
		list(const list& other);
		//~list();
		list& operator = (const list& other);
		T& front() { return _head->_value; };
		const T& front() const { return _head->_value; };
		T& back() { return tail()->_value; };
		const T& back() const { return tail()->_value; };
		void push_front(const T& value);
		void pop_front();
		void push_back(const T& value);
		void pop_back();
		void remove(const T& value);
		void reverse(); // see references for implementation
		// not required
		//void resize(size_t count, const T& value = T{});
		void clear(); // search online for implementation
		bool empty() { return (size() == 0); }
		size_t size(); // see references for implementation
		// not required
		//size_t max_size() { return std::numeric_limits<size_t>::max(); }
		std::ostream& write(std::ostream& stream);
	private:
		node_t* tail();
		//node_t* head();
	private:
		node_t* _head{ nullptr }; //maybe replace w/head()
	};
	template<typename T>
	list<T>::list(const std::initializer_list<T>& ilist) {
		for (auto iter : ilist) {
			push_back(iter);
		}
	}
	template<typename T>
	list<T>& list<T>::operator = (const list& other) {
		clear();
		node_t* tempNode = other._head;
		while (tempNode) {
			push_back(tempNode->_value);
			tempNode = tempNode->_next;
		}
		return *this;
	}
	/////////
	template<typename T>
	typename list<T>::node_t* list<T>::tail() {
		node_t* node = _head;
		if (!_head) return nullptr;
		while (node->_next) {
			node = node->_next;
		}
		return node;
	}
	template<typename T>
	typename void list<T>::push_front(const T& value) {
		node_t* node = new node_t(value);
		_head->_prev = node;
		node->_next = _head;
		_head = node;
	}
	template<typename T>
	typename void list<T>::pop_front() {
		node_t* temp = _head;
		_head = _head->_next;
		delete temp;
	}
	template<typename T>
	typename void list<T>::push_back(const T& value) {
		node_t* node = new node_t(value);
		node_t* Ntail = tail();
		if (!tail()) {
			_head = node;
		}
		else {
			Ntail->_next = node;
			node->_prev = Ntail;
		}
	}
	template<typename T>
	typename void list<T>::pop_back() {
		node_t* Ntail = tail();
		Ntail->_prev->_next = nullptr;
		delete Ntail;
	}
	template<typename T>
	typename std::ostream& list<T>::write(std::ostream& stream) {
		node_t* tempNode = _head;
		while (tempNode) {
			stream << tempNode->_value << std::endl;
			tempNode = tempNode->_next;
		}
		return stream;
	}
	template<typename T>
	typename void list<T>::clear() {
		while (tail()) {
			delete tail();
		}
	}
	template<typename T>
	typename void list<T>::remove(const T& value) {
		node_t* tempNode = _head;
		while (tempNode->_value!=value && tempNode) {
			tempNode = tempNode->_next;
		}
		if (tempNode == _head) {
			_head = tempNode->_next;
		}
		else {
			node_t* behind = tempNode->_prev;
			node_t* front = tempNode->_next;
			behind->_next = front;
			front->_prev = behind;
		}
		delete tempNode;
	}
	template<typename T>
	typename void list<T>::reverse() {
		node_t* tempNode = _head;
		node_t* nextnode = _head->_next;
		node_t* lastnode = nullptr;
		while (tempNode) {
			lastnode = tempNode;
			nextnode = tempNode->_next;
			tempNode->_next = tempNode->_prev;
			tempNode->_prev = tempNode->_next;
			tempNode = nextnode;
		}
		_head = lastnode;
	}
	template<typename T>
	typename size_t list<T>::size() {
		size_t count = 0;
		node_t* tempNode = _head;
		while (tempNode) {
			count++;
			tempNode = tempNode->_next;
		}
		return count;
	}
}