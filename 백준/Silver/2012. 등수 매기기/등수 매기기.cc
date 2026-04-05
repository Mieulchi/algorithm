#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[500001];
long long ans;

int abs(int n) {
    return n > 0 ? n : n * -1;
}

void solve() {
    sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++) {
        ans += abs(arr[i] - i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    solve();
    cout << ans;
}