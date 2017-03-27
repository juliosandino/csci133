/*
 main.cpp
 Julio Sandino
 March 23
 */

#include "tree.cpp"
using std::cout;
using std::cin;

int main() {
	tree* test = new tree;
	test->insert(test->root(), 5);
	test->insert(test->root(), 8);
	test->insert(test->root(), 4);
	test->insert(test->root(), 6);

	try {
		node* test_node = test->find(test->root(), 8);
		if (!test_node)
			throw test_node;
		std::cout << test_node->key << std::endl;
	} catch (node* e) {
		cout << "twas a nullptr" << std::endl;
	}
	return 0;
}
