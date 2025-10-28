#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <vector>
using namespace std;

struct Node {
	int num;
	char letter;
	void *left;
	void *right;

	Node(int num, char letter) : num(num), letter(letter), left(nullptr), right(nullptr) {}

	// Comparison operators for min-heap functionality
	bool operator<(const Node& other) const {
		return this->num < other.num;
	}

	bool operator==(const Node& other) const {
		return this->num == other.num && this->letter == other.letter;
	}

	bool operator>(const Node& other) const {
		return this->num > other.num;
	}
};

bool isLeaf(Node node) {
	return (node.left == nullptr) && (node.right == nullptr);
}
#endif // NODE_H