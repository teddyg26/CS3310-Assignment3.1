#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include "min_heap.h"
#include "node.h"
using namespace std;

// Contains frequencies for all of the letters
// in the English alphabet/language
// (freq -> letter)
map<int, char> freqs = {
	{77, 'A'}, {17, 'B'}, {32, 'C'}, {42, 'D'}, {120, 'E'},
	{24, 'F'}, {17, 'G'}, {50, 'H'}, {76, 'I'}, {4, 'J'},
	{7, 'K'}, {42, 'L'}, {24, 'M'}, {67, 'N'}, {67, 'O'},
	{20, 'P'}, {5, 'Q'}, {59, 'R'}, {67, 'S'}, {85, 'T'},
	{37, 'U'}, {12, 'V'}, {22, 'W'}, {4, 'X'}, {22, 'Y'},
	{2, 'Z'},
};
// Note: Because of how maps function in C++,
// this will be sorted by frequency in main.

// Generate Huffman codes from the Huffman tree
void generate_codes(Node* root, const string& prefix, unordered_map<char, string>& huffman_codes) {
	if(!root) return;

	// Leaf node
	if(isLeaf(root)) {
		// If single node, give "0"
		huffman_codes[root->letter] = prefix.empty() ? "0" : prefix;
		return;
	}

	generate_codes(root->left, prefix + "0", huffman_codes);
	generate_codes(root->right, prefix + "1", huffman_codes);
}

void free_tree(Node* root) {
	if(!root) return;
	free_tree(root->left);
	free_tree(root->right);
	delete root;
}

int main(int argc, char* argv[]) {
	vector<Node*> leaves;
	leaves.reserve(freqs.size());
	for(const auto& pair: freqs) {
		Node* n = new Node(pair.first, pair.second);
		leaves.push_back(n);
	}

	min_heap<Node*> heap(static_cast<int>(leaves.size()));;
	heap.build_heap(leaves);

	// Build Huffman Tree
	while(heap.get_size() > 1) {
		Node* left = heap.extract_min();;
		Node* right = heap.extract_min();

		Node* parent = new Node(left->num + right->num, '\0');
		parent->left = left;
		parent->right = right;
		heap.insert_node(parent);
	}

	// Set the root, but only if the heap isn't empty
	Node* root = nullptr;
	if(!heap.is_empty()) root = heap.extract_min();
	
	// Generate codes
	unordered_map<char, string> huffman_codes;
	generate_codes(root, "", huffman_codes);

	// Print heap for debugging
	// heap.print_heap();

	// Print codes
	cout << "Huffman Codes:\n";
	for(char c = 'A'; c <= 'Z'; c++) {
		if(huffman_codes.find(c) != huffman_codes.end()) {
			cout << c << ": " << huffman_codes[c] << endl;
		}
	}

	// Free tree memory
	free_tree(root);


	return EXIT_SUCCESS;
}

