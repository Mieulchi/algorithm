#include <iostream>
#include <vector>
using namespace std;

int n, m;
char arr[1000][1000];
int visited[1000][1000];
int r, c;
string s;
char ans[1000][1000];

void dfs(int r, int c, char key) {
    ans[r][c] = '.';
    visited[r][c] = 1;
    if (r + 1 < n && !visited[r + 1][c] && arr[r + 1][c] == key) {
        dfs(r + 1, c, key);
    }
    if (r - 1 >= 0 && !visited[r - 1][c] && arr[r - 1][c] == key) {
        dfs(r - 1, c, key);
    }
    if (c + 1 < m && !visited[r][c + 1] && arr[r][c + 1] == key) {
        dfs(r, c + 1, key);
    }
    if (c - 1 >= 0 && !visited[r][c - 1] && arr[r][c - 1] == key) {
        dfs(r, c - 1, key);
    }
}

void solve() {
    r--; c--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = '#';
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'U') {
            r--;
        }
        else if (s[i] == 'D') {
            r++;
        }
        else if (s[i] == 'L') {
            c--;
        }
        else if (s[i] == 'R') {
            c++;
        }
        else {
            dfs(r, c, arr[r][c]);
        }
    }
    ans[r][c] = '.';
    if (r + 1 < n) {
        ans[r + 1][c] = '.';
    }
    if (r - 1 >= 0) {
        ans[r - 1][c] = '.';
    }
    if (c + 1 < m) {
        ans[r][c + 1] = '.';
    }
    if (c - 1 >= 0) {
        ans[r][c - 1] = '.';
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
    cin >> r >> c;
    cin >> s;
    solve();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}   