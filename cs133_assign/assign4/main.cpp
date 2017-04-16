/*
 main.cpp
 Julio Sandino
 March 23
 */

#include "tree.cpp"
using std::cout;
using std::cin;

int main() {
	tree test;
	test.insert(test.root(), 5);
	test.insert(test.root(), 7);
	test.insert(test.root(), 3);
	test.insert(test.root(), 6);
	test.insert(test.root(), 8);
	test.insert(test.root(), 4);
	test.insert(test.root(), 1);

//	test.remove(test.root(), 8);
//	node* test_node = test.find(test.root(), 8);
//	std::cout << test_node << std::endl;
	
	test.print_tree(test.root());
	
	return 0;
}
