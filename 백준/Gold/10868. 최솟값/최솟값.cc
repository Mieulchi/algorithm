#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9 + 7

int n, m;
int arr[100001];
int tree[400004];

void init_tree(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;

    init_tree(node * 2, l, mid);
    init_tree(node * 2 + 1, mid + 1, r);

    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) {
        return INF;
    }
    if (l <= s && e <= r) {
        return tree[node];
    }
    int mid = (s + e) / 2;
    int q1 = query(node * 2, s, mid, l, r);
    int q2 = query(node * 2 + 1, mid + 1, e, l, r);
    return min(q1, q2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    init_tree(1, 1, n);

    int a, b;
    while (m--) {
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << '\n';
    }

}