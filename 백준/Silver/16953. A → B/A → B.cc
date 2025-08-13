#include <map>
#include <queue>
using namespace std;

#include <stdio.h>

int a, b;
map<int, int> visited;
int ans;

void bfs() {
    queue<int> q;
    q.push(a);
    int cnt = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int front = q.front();
            q.pop();
            if (!visited[front]) {
                visited[front] = 1;
                if (front * 2 <= b) {
                    q.push(front * 2);
                }
                if ((long long)front * 10 + 1 <= b) {
                    q.push(front * 10 + 1);
                }
            }
        }
        if (visited[b]) {
            ans = cnt + 1;
            break;
        }
        cnt++;
    }
    if (!ans) {
        ans = -1;
    }
}

int main() {
    scanf("%d %d", &a, &b);

    bfs();
    printf("%d", ans);
}