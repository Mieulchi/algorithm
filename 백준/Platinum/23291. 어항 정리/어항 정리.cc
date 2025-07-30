#include <iostream>
using namespace std;

int n, k;
int arr[100];
int cpy[100][100];
int cpy1[100][100];
int diff[100][100];
int m = 10001;
int w, h, mx;
int ans;

void p() {
    for (int i = 0; i < n; i++) {
        if (cpy[0][i] < m) {
            m = cpy[0][i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (cpy[0][i] == m) {
            cpy[0][i]++;
        }
    }
}

void c(int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            cpy[i][j] = cpy1[i][j];
        }
    }
}
void roll() {
    cpy[1][0] = cpy[0][0];
    for (int i = 1; i < n; i++) {
        cpy[0][i - 1] = cpy[0][i];
    }
    mx = n - 1;
    w = 1;
    h = 2;
    while (mx - w >= h) {
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                cpy1[w - i][j] = cpy[j][i];
            }
        }
        for (int i = w; i < mx; i++) {
            cpy1[0][i - w] = cpy[0][i];
        }
        for (int i = mx; i < n; i++) {
            cpy1[0][i - w] = 0;
        }
        mx -= w;
        if (w == h) {
            h++;
        }
        else {
            w++;
        }
        c(w, h);

    }
}


void roll2() {
    for (int i = 0; i < n / 2; i++) {
        cpy[1][n / 2 - i - 1] = cpy[0][i];
    }
    for (int i = 0; i < n / 2; i++) {
        cpy[0][i] = cpy[0][i + n / 2];
    }
    for (int i = n / 2; i < n; i++) {
        cpy[0][i] = 0;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n / 4; j++) {
            cpy[4 - i - 1][j] = cpy[i][n / 4 - 1 - j];
        }
        for (int j = 0; j < n / 4; j++) {
            cpy[i][j] = cpy[i][j + n / 4];
        }
        for (int j = n / 4; j < n / 2; j++) {
            cpy[i][j] = 0;
        }
    }
    mx = n / 4;
    h = 4;
}

void distribute() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < mx; j++) {
            diff[i][j] = 0;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < mx; j++) {
            if (cpy[i][j]) {
                if (i + 1 < h && cpy[i + 1][j]) {
                    int d = abs(cpy[i + 1][j] - cpy[i][j]) / 5;
                    if (d) {
                        if (cpy[i][j] > cpy[i + 1][j]) {
                            diff[i][j] -= d;
                            diff[i + 1][j] += d;
                        }
                        else {
                            diff[i][j] += d;
                            diff[i + 1][j] -= d;
                        }
                    }
                }
                if (j + 1 < mx && cpy[i][j + 1]) {
                    int d = abs(cpy[i][j + 1] - cpy[i][j]) / 5;
                    if (d) {
                        if (cpy[i][j + 1] > cpy[i][j]) {
                            diff[i][j + 1] -= d;
                            diff[i][j] += d;
                        }
                        else {
                            diff[i][j + 1] += d;
                            diff[i][j] -= d;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < mx; j++) {
            cpy[i][j] += diff[i][j];
        }
    }
}

void unroll() {
    int tmp[100] = { 0, };
    int cnt = 0;
    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < h; j++) {
            if (cpy[j][i]) {
                tmp[cnt++] = cpy[j][i];
            }
            else {
                break;
            }
            if (cnt == n) {
                break;
            }
        }
        if (cnt == n) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cpy[0][i] = tmp[i];
    }
    for (int i = 0; i < mx; i++) {
        for (int j = 1; j < h; j++) {
            cpy[j][i] = 0;
        }
    }
}

bool judge() {
    int min, max;
    min = max = cpy[0][0];
    for (int i = 1; i < n; i++) {
        if (cpy[0][i] < min) {
            min = cpy[0][i];
        }
        if (cpy[0][i] > max) {
            max = cpy[0][i];
        }
    }
    if (max - min <= k) {
        return true;
    }
    return false;
}

void solve() {
    for (int i = 0; i < n; i++) {
        cpy[0][i] = arr[i];
    }
    while (true) {
        if (judge()) {
            break;
        }
        ans++;
        m = 10001;

        p();
        roll();
        distribute();
        unroll();
        roll2();
        distribute();
        unroll();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve();
    cout << ans;
}   