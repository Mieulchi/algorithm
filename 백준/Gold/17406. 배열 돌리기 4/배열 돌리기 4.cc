#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9

int n, m, k, ans = INF;
int origin[50][50];
int map[50][50];

int a[6];
int b[6];
int c[6];
int seq[6];

void rotate(int a, int b, int c) {
    
    for (int i = 1; i <= c; ++i) {

        int sr = a - i;
        int sc = b - i;

        int tr = sr + i * 2;
        int tc = sc + i * 2;

        int m1 = map[sr + 1][sc];
        int m2 = map[sr][tc - 1];
        int m3 = map[tr - 1][tc];
        int m4 = map[tr][sc + 1];

        for (int c = tc - 1; c >= sc + 1; --c) {
            map[sr][c] = map[sr][c - 1];
        }
        for (int c = sc + 1; c < tc; ++c) {
            map[tr][c] = map[tr][c + 1];
        }

        for (int r = tr - 1; r >= sr + 1; --r) {
            map[r][tc] = map[r - 1][tc];
        }
        for (int r = sr + 1; r < tr; ++r) {
            map[r][sc] = map[r + 1][sc];
        }
        map[sr][sc] = m1;
        map[sr][tc] = m2;
        map[tr][tc] = m3;
        map[tr][sc] = m4;
    }

}

void dfs(int depth, int bitmask) {
    if (depth != k) {
        for (int i = 0; i < k; ++i) {
            if ((bitmask >> i) & 1) {
                continue;
            }
            seq[depth] = i;
            dfs(depth + 1, bitmask | (1 << i));
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                map[i][j] = origin[i][j];
            }
        }

        for (int i = 0; i < k; ++i) {
            rotate(a[seq[i]] - 1, b[seq[i]] - 1, c[seq[i]]);
        }

        int cmp = INF;
        for (int r = 0; r < n; ++r) {
            int sum = 0;
            for (int c = 0; c < m; ++c) {
                sum += map[r][c];
            }
            cmp = min(cmp, sum);
        }
        ans = min(ans, cmp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> origin[r][c];
        }
    }

    for (int i = 0; i < k; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    dfs(0, 0);

    rotate(a - 1, b - 1, c);

    cout << ans;
}