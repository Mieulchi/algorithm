#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long D[21];
    D[0] = 1;
    D[1] = 0;
    for (int n = 2; n <= 20; ++n) {
        D[n] = (long long)(n - 1) * (D[n - 1] + D[n - 2]);
    }

    int T; 
    cin >> T;
    while (T--) {
        int N; 
        cin >> N;
        cout << D[N] << '\n';
    }
    return 0;
}
