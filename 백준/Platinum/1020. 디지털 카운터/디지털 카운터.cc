#include <iostream>

using namespace std;

int n;
int cnt[11] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };
string s;

int sum;
bool dp[16][106];
string ans;
long long ansL;

void printDiff() {
    bool isBigger = (ans > s);

    long long mul = 1;
    long long from = 0;
    long long to = 0;
    for (int i = 0; i < n; ++i) {
        to += mul * (ans[n - i - 1] - '0');
        from += mul * (s[n - i - 1] - '0');
        mul *= 10;
    }

    if (isBigger) {
        cout << to - from;
    }
    else {
        cout << (mul - from) + to;
    }
}

void solve() {

    for(int i = 0; i < 10; ++i) {
        dp[1][cnt[i]] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 106; ++j) {
            for (int k = 0; k < 10; ++k) {
                if (j - cnt[k] >= 0 && dp[i - 1][j - cnt[k]]) {
                    dp[i][j] = 1;
                }
            }
        }
    }

    ans = s;

    int fill = 0;

    int idx = 0;

    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        int p = s[n - i] - '0';
        int now = p;

        fill += cnt[p];
        while (now < 9) {
            ++now;
            if (i == 1) {
                if (fill == cnt[now]) {
                    ans[n - i] = now + '0';
                    idx = n - i + 1;
                    fill -= cnt[now];
                    flag = true;
                    break;
                }
            }
            else {
                if (fill >= cnt[now] && dp[i - 1][fill - cnt[now]]) {
                    ans[n - i] = now + '0';
                    idx = n - i + 1;
                    fill -= cnt[now];
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            break;
        }
    }

    for (int i = idx; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == n - 1) {
                if (cnt[j] == fill) {
                    ans[i] = j + '0';
                    fill -= cnt[j];
                    break;
                }
            }
            else {
                if (fill >= cnt[j] && dp[n - i - 1][fill - cnt[j]]) {
                    ans[i] = j + '0';
                    fill -= cnt[j];
                    break;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    n = s.length();
    for (int i = 0; i < n; ++i) {
        sum += cnt[s[i] - '0'];
    }
    solve();
    printDiff();
}