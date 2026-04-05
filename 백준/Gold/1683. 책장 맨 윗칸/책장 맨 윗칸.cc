#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
struct book {
    int e;
    string s;
};
book books[2500];
book pBooks[2500];
int dp[2500][10];
int trace[2500][10];
int ansn, ans, last;
int bad[2505][2505];

bool cmp(book a, book b) {
    return a.s < b.s;
}

void parse() {
    for (int i = 0; i < n; ++i) {
        pBooks[i] = books[i];
        string s = books[i].s;
        string tmp;
        for (int j = 0; j < s.length(); ++j) {
            if (isalpha(s[j])) {
                tmp += tolower(s[j]);
            }
        }
        pBooks[i].s = tmp;
    }
}

int check(int a, int b) {
    const string& sA = pBooks[a].s;
    const string& sB = pBooks[b].s;

    int len = min(sA.length(), sB.length());
    for (int idx = 0; idx < len; ++idx) {
        if (sA[idx] == sB[idx]) {
            return 1;
        }
    }
    return 0;
}

void solve() {
    sort(books, books + n, cmp);
    parse();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (check(i, j)) {
                bad[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        dp[i][0] = pBooks[i].e;
        int idx = min(i, 9);
        if (dp[i][0] > ans) {
            ansn = 1;
            ans = dp[i][0];
            last = i;
        }
        for (int j = 1; j <= idx; ++j) {
            for (int k = 0; k < i; ++k) {
                if (!bad[i][k] && dp[k][j - 1]) {
                    if (dp[i][j] < dp[k][j - 1] + pBooks[i].e) {
                        trace[i][j] = k;
                        dp[i][j] = dp[k][j - 1] + pBooks[i].e;
                    }
                }
            }
            if (dp[i][j] > ans) {
                ansn = j + 1;
                ans = dp[i][j];
                last = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> books[i].e;
        getline(cin, books[i].s);
    }
    solve();
    cout << ansn << '\n';
    cout << ans << '\n';
    vector<string> v;
    while(ansn) {
        v.push_back(books[last].s);
        last = trace[last][--ansn];
    }
    for (int i = v.size() - 1; i >= 0; --i) {
        for (int j = 1; j < v[i].length(); ++j) {
            cout << v[i][j];
        }
        cout << '\n';
    }
}