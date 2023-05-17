#pragma once
#include <initializer_list>
#include <limits>
namespace nc {
	template<typename T>
	class vector
	{
	public:
		//Constructors
		vector();
		vector(size_t capacity);
		vector(const std::initializer_list<T>& ilist);
		vector(const vector& other);
		//Destructor
		//~vector();
		//Operators
		vector& operator = (const vector& other) {
			_size = other.size();
			_capacity = other.capacity();
			_elements = new T[_capacity];
			for (size_t i = 0; i < _size; i++) {
				_elements[i] = other[i];
			}
			return *this;
		};
		T& operator [] (size_t position) { return _elements[position]; };
		const T& operator [] (size_t position) const { return _elements[position]; };
		//Methods
		T& at(size_t position) { return _elements[position]; }; //later
		const T& at(size_t position) const { return _elements[position]; };
		T& front() { return _elements[0]; }; //first record
		T& back() { return _elements[_size - 1]; }; //last record
		T* data() {
			return _elements;
		};
		void push_back(const T& value); //add a record and maybe increase the capacity
		void pop_back() { if (_size > 0) { _size--; } };
		void reserve(size_t capacity); //increase the size of the array
		void resize(size_t new_size, const T& value = T{}) {
			bool add = new_size > _size;
			_size = new_size;
			_elements[new_size] = value;
		};
		void clear() { _size = 0; }; //set so no values are in the list
		void swap(vector& other) {
			vector temp = *this;
			*this = other;
			other = temp;
		};
		bool empty() const { return _size == 0; }; //is the list empty
		size_t size() const { return _size; }; //number of cells with data
		size_t capacity() const { return _capacity; }; //current capacity
		size_t max_size() const { return std::numeric_limits<size_t>::max() / sizeof(T); }
	private:
		//Properties
		T* _elements{ nullptr };
		size_t _size{};
		size_t _capacity{};
	};
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	template<typename T>
	vector<T>::vector() {
		_capacity = 0;
		_size = 0;
	}
	template<typename T>
	vector<T>::vector(size_t capacity) {
		_capacity = capacity;
		_size = 0;
		_elements = new T[_capacity];
	}
	template<typename T>
	vector<T>::vector(const std::initializer_list<T>& ilist) {
		_size = ilist.size();
		_capacity = _size;
		_elements = new T[_capacity];

		//Copy all values to our array
		/*for (size_t i = 0; i < _size; i++) {
			*_elements[i] = ilist[i];
		}*/
		size_t count = 0;
		for (auto iter = ilist.begin(); iter != ilist.end(); iter++) {
			_elements[count] = *iter;
			count++;
		}
	}
	template<typename T>
	vector<T>::vector(const vector& other) {
		_size = other.size();
		_capacity = other.capacity();
		_elements = new T[_capacity];
		for (size_t i = 0; i < _size; i++) {
			_elements[i] = other[i];
		}
	}
	template<typename T>
	void vector<T>::push_back(const T& value) {
		if (_size == _capacity) {
			reserve(_capacity + 5);
		}
		_elements[_size] = value;
		_size++;
	}
	template<typename T>
	void vector<T>::reserve(size_t capacity) {
		if (capacity <= _capacity) return;
		
		T* new_elements = new T[capacity];
		for (size_t i = 0; i < _size; i++) {
			new_elements[i] = _elements[i];
		}
		//delete[] _elements;
		_elements = new_elements;
		_capacity = capacity;
	}
}