#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100001];
//min, max
pair<int, int> tree[400004];
int mmin, mmax;
int tMax;

void make_tree(int node, int start, int end) {
	if (start == end) {
		tree[node] = { arr[start], arr[start]};
		if (node > tMax) {
			tMax = node;
		}
	}
	else {
		make_tree(node * 2, start, (start + end) / 2);
		make_tree(node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = { min(tree[node * 2].first, tree[node * 2 + 1].first), max(tree[node * 2].second, tree[node * 2 + 1].second) };
	}
}

void myfind(int node, int left, int right, int start, int end) {
	if (start > right || end < left) {
		return;
	}
	if (start >= left && right >= end) {
		if (mmin > tree[node].first) {
			mmin = tree[node].first;
		}
		if (mmax < tree[node].second) {
			mmax = tree[node].second;
		}
		return;
	}
	if (node * 2 <= tMax) {
		myfind(node * 2, left, right, start, (start + end) / 2);
	}
	if (node * 2 + 1 <= tMax) {
		myfind(node * 2 + 1, left, right, (start + end) / 2 + 1, end);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	make_tree(1, 1, n);
	int left, right;
	for (int i = 0; i < m; i++) {
		cin >> left >> right;
		mmin = 1000000001;
		mmax = -1;
		myfind(1, left, right, 1, n);
		cout << mmin << ' ' << mmax << '\n';
	}
}