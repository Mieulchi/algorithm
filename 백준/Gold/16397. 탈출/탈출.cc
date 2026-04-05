#include <iostream>
#include <queue>
using namespace std;

int n, t, g;
int ans;
int visited[100001];
int flag;

void solve() {
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int front = q.front();
            q.pop();
            if (!visited[front]) {
                visited[front] = 1;
                if (front == g) {
                    flag = 1;
                    return;
                }
                if (front + 1 <= 99999 && !visited[front + 1]) {
                    q.push(front + 1);
                }

                if (front * 2 <= 99999) {
                    int cpy, tmp;
                    cpy = tmp = front * 2;
                    int m = 1;
                    while (cpy >= 10) {
                        cpy /= 10;
                        m *= 10;

                    }
                    tmp -= m;
                    if (tmp >= 0 && !visited[tmp]) {
                        q.push(tmp);
                    }
                }
            }
        }
        ++ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t >> g;
    solve();
    if (ans <= t && flag) {
        cout << ans;
    }
    else {
        cout << "ANG";
    }
}