#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <vector>
#include "node.h"
using namespace std;


class min_heap {
private:
	vector<Node> arr;
	int size;
	int capacity;

public:
	// Constructor
	min_heap(int capacity) {
		this->size = 0;
		this->capacity = capacity;
		this->arr.resize(capacity);
	}

	// Destructor
	~min_heap() {
		arr.clear();
	}

	// Heapify a subtree with root at given index
	void heapify(int i) {
		// smallest will be the root
		int smallest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		// If left child is smaller than root
		if(left < size && arr[left] < arr[smallest])
			smallest = left;

		// If right child is smaller than the smallest so far
		if(right < size && arr[right] < arr[smallest])
			smallest = right;

		// If smallest is not root
		if(smallest != i) {
			swap(arr[i], arr[smallest]);  
			heapify(smallest);
		}
	}

	// Build heap from an existing array
	void build_heap(const vector<Node>& new_arr) {
        capacity = new_arr.size();
        size = capacity;
        arr = new_arr;
        
        // Heapify the (n-1)/2 nodes
        for(int i = (size - 1) / 2; i >= 0; i--) {
            heapify(i);
        }
    }

	// Insert a new element
	void insert_node(Node new_node) {
		if(size == capacity) {
			capacity *= 2;
			arr.resize(capacity);
		}

		size++;
		int i = size - 1;
		arr[i] = new_node;

		while(i != 0 && arr[(i - 1) / 2] > arr[i]) {
			swap(arr[i], arr[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	// Get the top of the heap
	Node peek() {
		if(size <= 0) return Node(-1, '\0'); // Heap is empty

		return arr[0];
	}

	// Pop the min value from the heap
	Node extract_min() {
		if(size <= 0) return Node(-1, '\0'); // Heap is empty
		if(size == 1) {
			size--;
			return arr[0];
		}

		// Pop!
		Node root = arr[0];
		arr[0] = arr[size - 1];
		size--;

		// Reset
		heapify(0);

		return root;
	}

	void delete_node(Node key) {
		int index = -1;

		// Find the index of the key to be deleted
		for(int i = 0; i < size; i++) {
			if(arr[i] == key) {
				index = i;
				break;
			}
		}

		if(index == -1) return; // Key not found

		// If the key is at the end
		if(index == size - 1) {
			size--;
			return;
		}

		// Move the last element to the found index
		arr[index] = arr[size - 1];
		size--;

		// Reset
		heapify(index);
	}

	void print_heap() {
		for(int i = 0; i < size; i++) {
			cout << arr[i].num << " " << arr[i].letter << " | ";
		}
		cout << endl;
	}
};

