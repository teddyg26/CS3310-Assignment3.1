#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <vector>
#include "node.h"
using namespace std;

template <typename T>
class min_heap {
private:
	vector<T> arr;
	int size;
	int capacity;
public:
	min_heap(int capacity);

	void heapify(int i);

	void build_heap(const vector<T>& new_arr);

	void insert_node(T node);

	T peek();

	T extract_min();

	void delete_node(T key);

	void print_heap();
};
#endif // MIN_HEAP_H