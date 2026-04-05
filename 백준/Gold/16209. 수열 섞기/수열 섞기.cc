#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int arr[500000];
deque<int> dq1, dq2;

void solve() {
    sort(arr, arr + n);

    int idx = lower_bound(arr, arr + n, 1) - arr;

    int flag = 0;
    for (int i = n - 1; i >= idx; --i) {
        if (flag) {
            dq1.push_back(arr[i]);
        }
        else {
            dq1.push_front(arr[i]);
        }
        flag = flag ? 0 : 1;
    }
    flag = 0;
    for (int i = 0; i < idx; ++i) {
        if (flag) {
            dq2.push_back(arr[i]);
        }
        else {
            dq2.push_front(arr[i]);
        }
        flag = flag ? 0 : 1;
    }

    if (dq1.size()) {
        if (dq1.front() > dq1.back()) {
            reverse(dq1.begin(), dq1.end());
        }
    }
    if (dq2.size()) {
        if (dq2.front() > dq2.back()) {
            reverse(dq2.begin(), dq2.end());
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    solve();
    
    for (auto it = dq2.begin(); it != dq2.end(); ++it) {
        cout << *it << ' ';
    }
    for (auto it = dq1.begin(); it != dq1.end(); ++it) {
        cout << *it << ' ';
    }

}