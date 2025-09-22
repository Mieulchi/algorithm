#include <iostream>
#include <vector>
using namespace std;

int n, m, k, ans = 1000000007;
vector<pair<int, int>> skill;

typedef pair<int, vector<pair<int, int>>> iv;
//dp[i][j] = i번째 스킬 사용 시 j만큼 줄수있는 데미지의 최소 비용
iv dp[100][101];

void solve() {
    for (int i = 0; i < n; ++i) {
        int cost = skill[i].first;
        int dmg = skill[i].second;
        vector<pair<int, int>> cpy = skill;
        cpy[i].first += k;
        dp[0][dmg] = { cost, cpy };
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 1; l < 101; ++l) {
                iv prev = dp[i - 1][l];
                if (prev.first) {
                    int cost = prev.second[j].first;
                    int dmg = prev.second[j].second;
                    if (l + dmg < 101) {
                        iv pres = dp[i][l + dmg];
                        if (!pres.first || pres.first > cost + prev.first) {
                            vector<pair<int, int>> cpy = prev.second;
                            cpy[j].first += k;
                            dp[i][l + dmg] = { cost + prev.first, cpy };
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (dp[i][m].first) {
            ans = min(ans, dp[i][m].first);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        skill.push_back({ a,b });
    }
    solve();
    cout << ans;
}