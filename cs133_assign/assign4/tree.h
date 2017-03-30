#include <iostream>

class tree {
	public:
		struct node{
			int key;
			node* left;
			node* right;
			node* parent;
			int height;
		};

		node* find(node* root, int value){	
			if (root == nullptr || root->key == value) 
				return root;
			
			if (root->key < value) {
				return find(root->right, value);
			}
			else {
				return find(root->left, value);
			}
		}
		void insert(node* root, int value);
		void remove(node* root, int value);
		void print_tree(node* root);
		friend std::ostream& operator <<(std::ostream& out, node* root);
		node* merge(node* t1, node* t2);
		bool check(node* root);
		node* root() { return _root; }
	
	private:
		node* _root = nullptr;
};
