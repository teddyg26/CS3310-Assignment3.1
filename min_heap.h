#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class min_heap {
private:
	vector<T> arr;
	int size;
	int capacity;

public:
	// Constructor
	min_heap(int capacity = 16): size(0), capacity(capacity) {
		if(capacity < 1) capacity = 16;
		arr.reserve(capacity); // Reserve memory but don't construct elements
	}

	// Destructor
	~min_heap() {
		arr.clear();
	}

	int get_size() const { return size; }
	bool is_empty() const { return size == 0; }

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
	void build_heap(const vector<T>& new_arr) {
        capacity = new_arr.size();
        size = capacity;
        arr = new_arr;
        
        // Heapify the (n-1)/2 nodes
        for(int i = (size - 1) / 2; i >= 0; i--) {
            heapify(i);
        }
    }

	// Insert a new element
	void insert_node(const T& node) {
		if(size == capacity) {
			capacity *= 2;
			arr.reserve(capacity);
		}

		arr.push_back(node);
		int i = size;
		size++;

		// Bubble up the new node
		while(i != 0 && arr[(i - 1) / 2] > arr[i]) {
			swap(arr[i], arr[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	// Get the top of the heap
	T peek() const {
		if(size <= 0) throw runtime_error("Heap is empty");
		return arr[0];
	}

	// Pop the min value from the heap
	T extract_min() {
		if(size <= 0) throw runtime_error("Heap is empty");
		if(size == 1) {
			T root = arr[0];
			arr.pop_back();
			size--;
			return root;
		}

		// Pop!
		T root = arr[0];
		arr[0] = arr[size - 1];
		arr.pop_back();
		size--;

		// Reset
		heapify(0);

		return root;
	}

	void delete_node(const T& key) {
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
			arr.pop_back();
			size--;
			return;
		}

		// Move the last element to the found index
		arr[index] = arr[size - 1];
		arr.pop_back();
		size--;

		// Reset
		heapify(index);
	}

	void print_heap() const {
		for(int i = 0; i < size; i++) {
			// assume T is Node* or similar; guard if needed
            if constexpr (is_pointer<T>::value) {
                if (arr[i]) {
					cout << arr[i]->num << ":" << arr[i]->letter << " | ";
				} else cout << "null | ";
            } else {
                cout << arr[i].num << ":" << arr[i].letter << " | ";
            }
		}
		cout << endl;
	}
};

#endif // MIN_HEAP_H