#include <iostream>
using namespace std;

int n, k;
int arr[100001];
int tree[400004];
int idx;
int f;

void find(int node, int s, int e, int f) {
	tree[node]--;
	if (s == e) {
		arr[idx++] = s;
	}
	else {
		int mid = (s + e) / 2;
		if (tree[node * 2] >= f) {
			find(node * 2, s, mid, f);
		}
		else {
			find(node * 2 + 1, mid + 1, e, f - tree[node * 2]);
		}
	}
}

void init(int node, int s, int e) {
	if (s == e) {
		tree[node]++;
		return;
	}
	int mid = (s + e) / 2;
	init(node * 2, s, mid);
	init(node * 2 + 1, mid + 1, e);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void solve() {
	init(1, 1, n);
	f = k;
	for (int i = 0; i < n; i++) {
		find(1, 1, n, f);
		f += (k - 1);
		if (i < n - 1 && f > tree[1]) {
			f %= tree[1];
			if (f == 0) {
				f = tree[1];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	solve();
	cout << "<";
	for (int i = 0; i < n; i++) {
		cout << arr[i];
		if (i < n - 1) {
			cout << ", ";
		}
	}
	cout << ">";
}