/*
 tree.cpp
 Julio Sandino
 March 23
  */

#include "tree.h"
#include <string>
using std::string;
typedef tree::node node;

//tree::node* find(node* root, int value) {
//	if (root == nullptr || root->key == value)
//		return root;
//	else if (root->key < value)
//		return find(root->left, value);
//	else //return root->right
//		return find(root->right, value);
//}

void tree::insert(node* root, int value) {
	if (root == nullptr)
		_root = new node {value, nullptr, nullptr, root, 1};
	else {
		if (value > root->key) {
			if (root->right == nullptr)
				root->right = new node {value, nullptr, nullptr, root, root->height + 1};
			else
				insert(root->right, value);
		}
		else if (value < root->key) {
			if (root->left == nullptr)
				root->left = new node {value, nullptr, nullptr, root, root->height + 1};
			else
				insert(root->left, value);
		}
	}
}

void remove(node*& root, int value) {
	return;
}

void print(std::ostream& out, node* root) {
	return;
}

node* merge(node* t1, node* t2) {
	return new node();
}

bool check(node* root) {
	return true;
}
