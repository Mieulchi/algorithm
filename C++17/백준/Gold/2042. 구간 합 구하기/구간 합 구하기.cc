#include <iostream>
using namespace std;

long long seq[1000001];
long long tree[4000001];

void make_segment_tree(int node, int start, int end) {
	if (start == end) {
		tree[node] = seq[start];
	}
	else {
		make_segment_tree(node * 2, start, (start + end) / 2);
		make_segment_tree(node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void update(int node, int start, int end, int index, long long diff) {
	if (start > index || end < index) {
		return;
	}
	if (start == end && start == index) {
		tree[node] += diff;
		return;
	}
	if (start <= index && index <= end) {
		tree[node] += diff;
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end,  index, diff);
	}
}

long long sum = 0;

void getSum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return;
	}
	if (start >= left && right >= end) {
		sum += tree[node];
		return;
	}
	getSum(node * 2, start, (start + end) / 2, left, right);
	getSum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	make_segment_tree(1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;

		if (a == 1) {
			long long diff = c - seq[b - 1];
			seq[b - 1] = c;
			update(1, 0, n - 1, b - 1, diff);
		}
		else {
			getSum(1, 0, n - 1, b - 1, c - 1);
			cout << sum << '\n';
			sum = 0;
		}
	}
}