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

	bool operator<(const Node& other) const;
	bool operator==(const Node& other) const;
	bool operator>(const Node& other) const;
};

bool isLeaf(Node node);