#include <iostream>
using namespace std;

int board[10][10];
int color[10];
int h, w, c;

void solve() {
    int th = 0, tw = 0;
    for(int i = 1; i <= c; i++) {
        while(color[i] > 0) {
            board[th][tw] = i;
            if (th + 1 < h){
                th++;
            }
            else {
                tw++;
                th = 0;
            }
            color[i]--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> h >> w >> c;

    for(int i = 1; i <= c; i++) {
        cin >> color[i];
    }
    
    solve();
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}