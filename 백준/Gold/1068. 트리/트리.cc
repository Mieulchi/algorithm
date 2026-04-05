#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int trees[51];

void removeTree(int* tree, int key, int size) {
	tree[key] = -2;
	for (int i = 0; i < size; i++) {
		if (tree[i] == key) {
			removeTree(tree, i, size);
		}
	}
}

int main() {
	int k;
	cin >> k;

	int tmp;

	for (int i = 0; i < k; i++) {
		cin >> trees[i];
	}


	int remove;
	cin >> remove;

	removeTree(trees, remove, k);

	int leafcount = 0;

	for (int i = 0; i < k; i++) {
		int flag = 0;
		for (int j = 0; j < k; j++) {
			if (trees[j] == i || trees[i] == -2) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			leafcount++;
		}
	}
	cout << leafcount;
}