#include <iostream>
#include <algorithm>
using namespace std;

int t;
int n, m;
int tree[800008];
int idx[100001];
int ans;

void make_tree(int node, int l, int r, int s, int e) {
    if (r < s || e < l) {
        return;
    }
    if (l == r) {
        tree[node] = 1;
        return;
    }
    int mid = (l + r) / 2;
    make_tree(node * 2, l, mid, s, e);
    make_tree(node * 2 + 1, mid + 1, r, s, e);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int find(int node, int l, int r, int s, int e) {
    if (r < s || e < l) {
        return 0;
    }
    if (s <= l && r <= e) {
        return tree[node];
    }
    int mid = (l + r) / 2;
    return find(node * 2, l, mid, s, e) + find(node * 2 + 1, mid + 1, r, s, e);
}

void update(int node, int l, int r, int key, int t) {
    if (l == r) {
        tree[node] = t;
        return;
    }
    int mid = (l + r) / 2;
    if (key <= mid) {
        update(node * 2, l, mid, key, t);
    }
    else {
        update(node * 2 + 1, mid + 1, r, key, t);
    }
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void solve() {
    for (int i = 1; i <= n; i++) {
        idx[i] = n - i + 1;
    }
    make_tree(1, 1, n + m, 1, n);
    int k;
    for (int i = n + 1; i <= n + m; i++) {
        cin >> k;
        ans = find(1, 1, n + m, idx[k] + 1, i - 1);
        cout << ans << ' ';
        update(1, 1, n + m, idx[k], 0);
        update(1, 1, n + m, i, 1);
        idx[k] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        solve();
        cout << '\n';
    }
}