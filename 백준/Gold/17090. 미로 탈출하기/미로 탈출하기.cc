#include <iostream>
using namespace std;

int n, m, ans;
char arr[500][500];
int visited[500][500];

void dfs(int r, int c) {
    if (!visited[r][c]) {
        visited[r][c] = 1;
        ans++;
        if (r + 1 < n && arr[r + 1][c] == 'U') {
            dfs(r + 1, c);
        }
        if (r - 1 >= 0 && arr[r - 1][c] == 'D') {
            dfs(r - 1, c);
        }
        if (c + 1 < m && arr[r][c + 1] == 'L') {
            dfs(r, c + 1);
        }
        if (c - 1 >= 0 && arr[r][c - 1] == 'R') {
            dfs(r, c - 1);
        }
    }
}

void solve() {
    for (int i = 0; i < n; ++i) {
        if (arr[i][0] == 'L' || (i == 0 && arr[i][0] == 'U') || (i == n - 1 && arr[i][0] == 'D')) {
            dfs(i, 0);
        }
        if (arr[i][m - 1] == 'R' || (i == 0 && arr[i][m - 1] == 'U') || (i == n - 1 && arr[i][m - 1] == 'D')) {
            dfs(i, m - 1);
        }
    }
    for (int i = 0; i < m; i++) {
        if (arr[0][i] == 'U' || (i == 0 && arr[0][i] == 'L') || (i == m - 1 && arr[0][i] == 'R')) {
            dfs(0, i);
        }
        if (arr[n - 1][i] == 'D' || (i == 0 && arr[n - 1][i] == 'L') || (i == m - 1 && arr[n - 1][i] == 'R')) {
            dfs(n - 1, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            arr[i][j] = s[j];
        }
    }
    solve();
    cout << ans;
}