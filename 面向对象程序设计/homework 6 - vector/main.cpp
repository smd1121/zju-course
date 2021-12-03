#include "pch.h"
#include <iostream>
#include <string>
#include <exception>
#define DEFAULT_CAPA 20;

using namespace std;

template <class T>
class Vector {
public:
	// creates an empty vector 
	Vector() : m_pElements(nullptr), m_nSize(0), m_nCapacity(0) {}

	// creates a vector for holding 'size' elements 
	Vector(int size) : m_nSize(0), m_nCapacity(size) {
		m_pElements = new T[size];
	}

	// the copy ctor 
	Vector(const Vector& r) : m_nSize(r.size()), m_nCapacity(r.size()) {
		m_pElements = new T[r.size()];
		for (int i = 0; i < r.size(); i++)
			//*(m_pElements + i) = *(r.m_pElements + i);
			this->push_back(r.at(i));
	}

	// destructs the vector 
	~Vector() {
		if (m_pElements != nullptr)
			delete[] m_pElements;
	}

	// accesses the specified element without bounds checking
	T& operator[](int index) {
		return *(m_pElements + index);
	}

	// accesses the specified element, throws an exception of type 'std::out_of_range' when index <0 or >=m_nSize
	T& at(int index) {
		std::cout << "at is called" << std::endl;
		if (index < 0 || index >= m_nSize)
			throw std::out_of_range("index out of range");
		return *(m_pElements + index);
	}

	T& at(int index) const {
		std::cout << "at-const is called" << std::endl;
		if (index < 0 || index >= m_nSize)
			throw std::out_of_range("index out of range");
		return *(m_pElements + index);
	}

	// return the size of the container
	int size() const {
		return m_nSize;
	}

	// adds an element to the end 
	void push_back(const T& x) {
		if (m_nSize >= m_nCapacity)
			inflate();
		m_pElements[m_nSize] = x;
		m_nSize++;
	}

	// clears the contents 
	void clear() {
		m_nSize = 0;
	}

	// checks whether the container is empty 
	bool empty() const {
		return 0 == m_nSize;
	}

private:
	// expand the storage of the container to a new capacity, e.g. 2*m_nCapacity
	void inflate() {
		m_nCapacity *= 2;
		if (m_nCapacity == 0)	m_nCapacity = DEFAULT_CAPA;

		T *oldPointer = m_pElements;
		m_pElements = new T[m_nCapacity];

		for (int i = 0; i < m_nSize; i++)
			*(m_pElements + i) = *(oldPointer + i);
	}

	T *m_pElements;				// pointer to the dynamically allocated storage
	int m_nSize;				// the number of elements in the container
	int m_nCapacity;			// the number of elements that can be held in currently allocated storage
};

int main() {
	Vector<int> vec1;					/* test: ctor 1 */
	for (int i = 0; i <= 2; i++)
		vec1.push_back(i);				/* test: push_back */

	Vector<string> vec2(10);			/* test: ctor 2 & string class */
	string str[4] = { "Hello,", "world!", "~~~" };
	for (int i = 0; i < 2; i++)
		vec2.push_back(str[i]);

	cout << "----" << endl;
	Vector<int> vec3(vec1);				/* test: copy ctor */
	cout << "----" << endl;

	vec1.clear();						/* test: clear & empty & size */
	cout << vec1.empty() << " " << vec1.size() << endl;
	for (int i = 0; i <= 150; i += 10)
		vec1.push_back(i);

	vec1.at(3) = 10;

	cout << vec1[3] << " " << vec2[1] << " " << vec3[165] << endl;
										/* test: at & operator[] */
	return 0;
}