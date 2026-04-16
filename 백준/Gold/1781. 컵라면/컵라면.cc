#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1e9 + 7

typedef pair<int, int> pp;

int n, ans;
pp arr[200000];

void solve() {
    sort(arr, arr + n);

    priority_queue<int> pq;

    int prev = arr[n - 1].first;
    for (int i = n - 1; i >= 0; --i) {
        int due = arr[i].first;
        int num = arr[i].second;
        if (due != prev) {
            int size = prev - due;

            while (size-- && !pq.empty()) {
                ans += pq.top();
                pq.pop();
            }

            prev = due;
            pq.push(num);
        }
        else {
            pq.push(num);
        }
    }

    while (prev-- && !pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    solve();

    cout << ans;
}