#include <iostream>
using namespace std;

int n;
char arr[5][5];
int ans1, ans2;
int flag1, flag2;

void dfs(int r, int c, int v, char ch) {
    char tmp;
    int next;
    if ((r + c) % 2) {
        tmp = arr[r][c];
        next = v;
    }
    else {
        if (ch == '+') {
            next = v + (arr[r][c] - '0');
        }
        else if (ch == '-') {
            next = v - (arr[r][c] - '0');
        }
        else {
            next = v * (arr[r][c] - '0');
        }
        tmp = ch;
    }
    if (r == n - 1 && c == n - 1) {
        if (!flag1 || next > ans1) {
            ans1 = next;
            flag1 = 1;
        }
        if (!flag2 || next < ans2) {
            ans2 = next;
            flag2 = 1;
        }
    }
    if (r + 1 < n) {
        dfs(r + 1, c, next, tmp);
    }
    if (c + 1 < n) {
        dfs(r, c + 1, next, tmp);
    }
}

void solve() {
    dfs(0, 0, 1, '*');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    solve();
    cout << ans1 << ' ' << ans2;
}