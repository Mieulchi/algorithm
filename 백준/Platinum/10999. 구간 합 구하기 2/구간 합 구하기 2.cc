#include <iostream>
using namespace std;

int n, m, k;
long long arr[1000001];
long long tree[4000004];
long long lazy[4000004];

void make_tree(int node, int left, int right) {
    if (left == right) {
        tree[node] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    make_tree(node * 2, left, mid);
    make_tree(node * 2 + 1, mid + 1, right);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node] * (end - start + 1);

        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }
}

void update_tree(int node, int left, int right, int start, int end, long long value) {
    update_lazy(node, left, right);

    if (end < left || right < start) {
        return;
    }

    if (start <= left && right <= end) {
        tree[node] += value * (right - left + 1);

        if (left != right) {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }

        return;
    }

    int mid = (left + right) / 2;

    update_tree(node * 2, left, mid, start, end, value);
    update_tree(node * 2 + 1, mid + 1, right, start, end, value);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long get(int node, int left, int right, int start, int end) {
    update_lazy(node, left, right);

    if (end < left || start > right) {
        return 0;
    }
    if (left >= start && right <= end) {
        return tree[node];
    }

    int mid = (left + right) / 2;

    return get(node * 2, left, mid, start, end) + get(node * 2 + 1, mid + 1, right, start, end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    make_tree(1, 1, n);

    long long a, b, c, d;
    for (int i = 0; i < m + k; ++i) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update_tree(1, 1, n, b, c, d);
        }
        else {
            cin >> b >> c;
            cout << get(1, 1, n, b, c) << '\n';
        }
    }
}