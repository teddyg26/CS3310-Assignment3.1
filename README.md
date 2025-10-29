# CS3310-Assignment3.1

## Determine Huffman Codes with a Min Heap
- Develop min heap
- Implement Huffman Codes

Note: This README is effectively useless. min_heap.h implements the min_heap
as expected. node.h contains all of the necessary logic for a tree data struct.
huffman.cpp contains the main() function as well as the logic for making
the huffman codes and printing the expected output.

This assignment was made on macOS Tahoe 26.0.1 with an M1 Mac (ARM Architecture)
so there could be problems for compiling the code on your machine. That said,
I structured the makefile this time to be (somewhat) OS agnostic. The exception
to that is the memcheck target, which uses leaks, a built-in macOS memory checking
application (an equivalent to valgrind).
<hr>
Additionally, several online resources were used in addition to the provided textbook material through Canva. That includes:
<ul>
	<li>
		geeksforgeeks: <span>[<a href="https://www.geeksforgeeks.org/cpp/min-heap-in-cpp/">Min Heap Documentation</a>]</span>
		<span>[<a href="https://www.geeksforgeeks.org/cpp/vector-in-cpp-stl/">C++ Vector Documentation</a>]</span>
	</li>
	<li>
		w3schools: <span>[<a href="https://www.w3schools.com/cpp/cpp_data_structures.asp">C++ Data Structures</a>]</span>
		<span>[<a href="https://www.w3schools.com/cpp/cpp_maps.asp">C++ Maps</a>]</span>
	</li>
	<li>
		And the ever prevalent ChatGPT 5 (which no doubt stole from all sorts of sources 🤷‍♂️)
	</li>
</ul>