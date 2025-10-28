#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <vector>
#include "min_heap.h"
#include "node.h"
using namespace std;

// Contains frequencies for all of the letters
// in the English alphabet/language
map<int, char> freqs = {
	{77, 'A'},
	{17, 'B'},
	{32, 'C'},
	{42, 'D'},
	{120, 'E'},
	{24, 'F'},
	{17, 'G'},
	{50, 'H'},
	{76, 'I'},
	{4, 'J'},
	{7, 'K'},
	{42, 'L'},
	{24, 'M'},
	{67, 'N'},
	{67, 'O'},
	{20, 'P'},
	{5, 'Q'},
	{59, 'R'},
	{67, 'S'},
	{85, 'T'},
	{37, 'U'},
	{12, 'V'},
	{22, 'W'},
	{4, 'X'},
	{22, 'Y'},
	{2, 'Z'},
};
// Note: Because of how maps function in C++,
// this will be sorted by frequency in main.

int main(int argc, char* argv[]) {
	vector<Node> arr;
	for(const auto& pair: freqs) {
		// cout << "Key: [" << pair.first << "], Value: [" << pair.second << "]" << endl;

		Node curr = Node(pair.first, pair.second);
		arr.push_back(curr);
	}

	min_heap<Node> heap = min_heap<Node>(arr.size());
	heap.build_heap(arr);

	heap.print_heap();

	return EXIT_SUCCESS;
}

