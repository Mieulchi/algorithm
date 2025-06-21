#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;                       // N: 1 … 200 000
    if (!(cin >> N)) return 0;

    vector<int64> A(N + 1), F(N + 1);
    for (int i = 0; i <= N; ++i) cin >> A[i] >> F[i];

    /* 누적 충전량 pref[i] = F0 + … + Fi */
    vector<int64> pref(N + 1);
    pref[0] = F[0];
    for (int i = 1; i <= N; ++i) pref[i] = pref[i - 1] + F[i];

    /* 0→i (마법사 없이) 도달 가능 여부 */
    vector<char> reachable(N + 1, 0);
    reachable[0] = 1;
    int64 energy = 0;
    for (int j = 0; j < N; ++j) {
        energy += F[j];                          // 충전
        int64 dist = A[j + 1] - A[j];
        if (energy < dist) break;                // 더 이상 전진 불가
        energy -= dist;                          // 이동
        reachable[j + 1] = 1;
    }

    /* bestVal = max(Ax - pref[x-1]), bestIdx = x (가장 큰 인덱스로 갱신) */
    int64 bestVal = 0;          // x = 0 일 때 (A0 - pref[-1]=0)
    int   bestIdx = 0;

    for (int i = 1; i <= N; ++i) {
        /* 후보 x = i-1 의 ② 값 갱신 (가능한 경우에만) */
        if (reachable[i - 1]) {
            int64 prevPref = (i >= 2 ? pref[i - 2] : 0);
            int64 curVal   = A[i - 1] - prevPref;
            if (curVal > bestVal || (curVal == bestVal && (i - 1) > bestIdx)) {
                bestVal = curVal;
                bestIdx = i - 1;
            }
        }

        if (!reachable[i]) {                // i 번에 처음부터 못 도달
            cout << -1 << ' ' << -1 << '\n';
            continue;
        }

        /* yi = ① + bestVal */
        int64 yi = (pref[i - 1] - A[i]) + bestVal;
        cout << bestIdx << ' ' << yi << '\n';
    }
    return 0;
}
