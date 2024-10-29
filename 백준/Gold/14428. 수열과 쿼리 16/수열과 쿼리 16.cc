#include <iostream>
#include <queue>
#include <climits>
using namespace std;

long long tree[400001];
long long seq[100001];

int tmax = 0;

void make_segment_tree(int node, int start, int end) {
	if (start == end) {
		if (node > tmax) {
			tmax = node;
		}
		tree[node] = seq[start]; // == seq[end];
	}
	else {
		make_segment_tree(node * 2, start, (start + end) / 2);
		make_segment_tree(node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

void update(long long val, int node, int start, int end, int index) {
	if (start <= index && index <= end) {
		if (start == end && start == index) {
			tree[node] = val;
		}
		if (start != end) {
			update(val, node * 2, start, (start + end) / 2, index);
			update(val, node * 2 + 1, (start + end) / 2 + 1, end, index);

			tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
		}
	}
	else {
		return;
	}
}

long long tmin = LLONG_MAX;
int index = INT_MAX;

void findIndex(int node, int start, int end, int left, int right, long long find) {
	if (left > end || right < start) {
		return;
	}
	if (left <= start && right >= end) {
		if (tree[node] == find) {
			while (true) {
				if (start == end) {
					if (start < index) {
						index = start;
					}
					break;
				}
				if (tree[node * 2] == find) {
					node *= 2;
					end = (start + end) / 2;
				}
				else {
					node = node * 2 + 1;
					start = (start + end) / 2 + 1;
				}
			}
			return;
		}
	}
	else {
		findIndex(node * 2, start, (start + end) / 2, left, right, find);
		findIndex(node * 2 + 1, (start + end) / 2 + 1, end, left, right, find);
	}
}


long long getMin(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return LLONG_MAX;
	}
	if (left <= start && right >= end) {
		return tree[node];
	}
	long long cmp1 = getMin(node * 2, start, (start + end) / 2, left, right);
	long long cmp2 = getMin(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

	return min(cmp1, cmp2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	make_segment_tree(1, 0, n - 1);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			seq[b - 1] = c;
			long long val = c;
			update(val, 1, 0, n - 1, b - 1);
		}
		else {
			long long find = getMin(1, 0, n - 1, b - 1, c - 1);
			findIndex(1, 0, n - 1, b - 1, c - 1, find);
			cout << index + 1 << '\n';
			tmin = LLONG_MAX;
			index = INT_MAX;
		}
	}
}