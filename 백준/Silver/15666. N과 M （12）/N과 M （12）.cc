#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
vector<int> v;

void recursive(int idx, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int j = idx; j < n; j++) {
        int flag = 1;
        for (int k = idx; k < j; k++) {
            if (j != idx && arr[j] == arr[k]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            v.push_back(arr[j]);
            recursive(j, cnt + 1);
            v.pop_back();
        }
    }
}

void solve() {
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        int flag = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] == arr[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            v.push_back(arr[i]);
            recursive(i, 1);
            v.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve();
    
}