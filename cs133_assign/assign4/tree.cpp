/*
 tree.cpp
 Julio Sandino
 March 23
  */

#include "tree.h"
#include <string>
using std::string;
typedef tree::node node;

void tree::insert(node*& root, int value) {
	if (root == nullptr)
		_root = new  node{value, nullptr, nullptr, nullptr, 1}; //if tree is empty
	else {
		if (value > root->key) { //if value is greater than the key
			if (root->right == nullptr) //
				root->right = new node {value, nullptr, nullptr, root, root->height + 1};
			else
				insert(root->right, value);
		}
		else if (value < root->key) { //if value is less than key
			if (root->left == nullptr) 
				root->left = new node {value, nullptr, nullptr, root, root->height + 1};
			else
				insert(root->left, value);
		}
	}
}

void tree::remove(node*& root, int value) {
	node* node_removed = tree::find(root, value);

	if (node_removed->right == nullptr && node_removed->left == nullptr)
		delete node_removed;
	else if (node_removed->right == nullptr && node_removed->left) {
		node* temp = node_removed->left;
		node_removed = node_removed->left;
		delete temp;
	}
	else if (node_removed->left == nullptr && node_removed->right) {
		node* temp = node_removed->right;
		node_removed = node_removed->right;
		delete temp;
	}
}

std::ostream& operator << (std::ostream& out, node* root) {
	out << root->key;
	return out;	
}

void tree::print_tree(node* root) {
	if (root) {
		std::cout << root;
		print_tree(root->right);
		print_tree(root->left);
	}
}

node* tree::merge(node* t1, node* t2) {
	return new node();
}

bool tree::check(node* root) {
	return true;
}
