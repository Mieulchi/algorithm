#include <iostream>
#include <algorithm>
using namespace std;

int arr[5];
int ans;

void f(int idx, int num, int sum, int cost) {

    if (sum > 15) {
        return;
    }

    if ((num <= 3 && sum <= 10) || (num >= 4 && sum <= 15)) {
        ans = max(ans, cost);
    }

    for (int i = idx; i < 5; ++i) {
        for (int j = 1; j <= 15; ++j) {
            f(i, num + j, sum + (i + 1) * j, cost + arr[i] * j);
        }
    }

}

void solve() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 1; j <= 15; ++j) {
            f(i + 1, j, (i + 1) * j, arr[i] * j);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; ++i) {
        cin >> arr[i];
    }
    solve();

    cout << ans;
}