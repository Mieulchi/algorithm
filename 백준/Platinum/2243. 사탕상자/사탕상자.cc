#include <iostream>
using namespace std;

#define SIZE 1000000

int n;
int tree[4000004];

int find(int node, int s, int e, int b) {
	tree[node]--;
	if (s == e) {
		return s;
	}
	int mid = (s + e) / 2;
	int ret;
	if (tree[node * 2] >= b) {
		ret = find(node * 2, s, mid, b);
	}
	else {
		ret = find(node * 2 + 1, mid + 1, e, b - tree[node * 2]);
	}
	return ret;
}

void add(int node, int s, int e, int b, int c) {
	if (s > b || e < b) {
		return;
	}
    
	tree[node] += c;
    if (s == e) {
		return;
	}
	int mid = (s + e) / 2;
	add(node * 2, s, mid, b, c);
	add(node * 2 + 1, mid + 1, e, b, c);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int a, b, c;
	while (n--) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			cout << find(1, 1, SIZE, b) << '\n';
		}
		else {
			cin >> b >> c;
			add(1, 1, SIZE, b, c);
		}
	}
}