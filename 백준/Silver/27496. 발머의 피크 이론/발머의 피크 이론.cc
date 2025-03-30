#include <iostream>
using namespace std;

int n, l;
int arr[1000001];
int ans;

void solve() {
    int time = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        time++;
        if (time - l - 1 >= 0) {
            sum -= arr[time - l - 1];
        }
        if (sum >= 129 && sum <= 138) {
            ans++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l;
    solve();
    cout << ans;
}