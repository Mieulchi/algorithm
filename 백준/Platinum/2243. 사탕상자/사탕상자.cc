#include <iostream>
#define SIZE 1000001
using namespace std;

int n, m;
int tree[4000004];
int ans;

void update(int node, int s, int e, int a, int b) {
	if (s > a || e < a) {
		return;
	}
	tree[node] += b;
	if (s == e) {
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, a, b);
	update(node * 2 + 1, mid + 1, e, a, b);
}

void myfind(int node, int s, int e, int b) {
	if (s == e) {
		ans = s;
		return;
	}
	int mid = (s + e) / 2;
	if (tree[node * 2] >= b) {
		myfind(node * 2, s, mid, b);
	}
	else {
		myfind(node * 2 + 1, mid + 1, e, b - tree[node * 2]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			myfind(1, 1, SIZE, b);
			update(1, 1, SIZE, ans, -1);
			cout << ans << '\n';
		}
		else {
			cin >> b >> c;
			update(1, 1, SIZE, b, c);
		}
	}
}