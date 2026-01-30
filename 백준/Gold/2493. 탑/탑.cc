#include <iostream>
#include <stack>
using namespace std;

/*
* 뒤에서부터 보면 쉬움
*/

int n;
int arr[500000];
int ans[500000];
stack<pair<int, int>> s;

void solve() {
    for (int i = n - 1; i >= 0; --i) {
        if (s.empty()) {
            s.push({ arr[n - 1], n - 1 });
        }
        else {
            if (arr[i] > s.top().first) {
                while (!s.empty() && arr[i] > s.top().first) {
                    ans[s.top().second] = i + 1;
                    s.pop();
                }
                s.push({ arr[i], i });
            }
            else {
                s.push({ arr[i], i });
            }
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

    if (s.size() == n) {
        cout << 0;
    }
    else {
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
    }

}