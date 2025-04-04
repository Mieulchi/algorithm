#include <iostream>
using namespace std;

int x1, y1, x2, y2;
int arr[101][101];
int n, m;
int ans;

void solve() {
    for(int i = y1; i <= y2; i++) {
        for(int j = x1; j <= x2; j++) {
            arr[i][j]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    while(n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        solve();
    }
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            if(arr[i][j] > m) {
                ans++;
            }
        }
    }
    cout << ans;
}