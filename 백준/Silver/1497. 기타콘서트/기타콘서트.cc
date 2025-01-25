#include <iostream>
#include <cmath>
using namespace std;

int n, m;
pair<string, int[50]> s[10];
int scount;
int ans;

void solve() {
    int k = 1 << n; // 2^n
    for (int mask = 1; mask < k; mask++) {
        int check[50] = {0}; // 초기화
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { // i번째 항목이 선택되었는지 확인
                count++;
                for (int j = 0; j < m; j++) {
                    check[j] |= s[i].second[j];
                }
            }
        }

        int tmp = 0;
        for (int i = 0; i < m; i++) {
            if (check[i]) tmp++;
        }

        if (tmp > 0 && (scount < tmp || (scount == tmp && (ans == 0 || ans > count)))) {
            scount = tmp;
            ans = count;
        }
    }

    if (!ans) {
        ans = -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> s[i].first >> tmp;
        for (int j = 0; j < tmp.length(); j++) {
            s[i].second[j] = (tmp[j] == 'Y') ? 1 : 0;
        }
    }
    solve();

    cout << ans;
}
