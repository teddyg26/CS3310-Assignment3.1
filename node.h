#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

struct Node {
	int num;
	char letter;
	Node *left;
	Node *right;
	
	// Constructor
	Node(int num, char letter) : num(num), letter(letter), left(nullptr), right(nullptr) {}

	// Overload comparison operators for Node
	bool operator<(const Node& other) const { return this->num < other.num; }
	bool operator==(const Node& other) const { return this->num == other.num && this->letter == other.letter; }
	bool operator>(const Node& other) const { return this->num > other.num; }
};

bool isLeaf(Node *node) {
	return node && node->left == nullptr && node->right == nullptr;
}

#endif // NODE_H