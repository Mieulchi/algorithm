#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int key;
	TreeNode* left, * right;
};

TreeNode* getNode(int data) {
	TreeNode* tmp = new TreeNode;
	tmp->key = data;
	tmp->right = NULL;
	tmp->left = NULL;

	return tmp;
}

void insert_node(TreeNode* node, int data) {
	if (node ->key > data) { 
		if (node->left == NULL) {
			node->left = getNode(data);
			return;
		}
		else {
			insert_node(node->left, data);
		}
	}
	else if (node->key < data) {
		if (node->right == NULL) {
			node->right = getNode(data);
			return;
		}
		else {
			insert_node(node->right, data);
		}
	}
}

void gndnl(TreeNode* root) {
	if (root->left) {
		gndnl(root->left);
	}
	if (root->right) {
		gndnl(root->right);
	}
	cout << root->key << '\n';
}

int main() {
	TreeNode* root = NULL; 
	int key;
	while (cin >> key){	

		if (root == NULL) {
			root = new TreeNode;
			root->left = NULL;
			root->right= NULL;
			root->key = key;
		}
		else {
			insert_node(root, key);
		}
	}


	gndnl(root);
}