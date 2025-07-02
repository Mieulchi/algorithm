#include <iostream>
#include <queue>
using namespace std;

priority_queue<int,vector<int>, greater<int>> pq;
int H;
int N, Q;
long long sum;
int cnt;

void f() {
	if (sum < H) {
		cout << -1 << '\n';
		return;
	}
	else {
		int top;
		while (true) {
			top = pq.top();
			sum -= top;
			if (sum < H) {
				sum += top;
				break;
			}
			pq.pop();
			cnt--;
		}
		cout << cnt << '\n';
	}
}

void solve() {
	int tmp;
	for (int i = 0; i < Q; i++) {
		cin >> tmp;
		pq.push(tmp);
		cnt++;
		sum += tmp;
		f();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> H;
	cin >> N >> Q;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		pq.push(tmp);
		cnt++;
		sum += tmp;
	}
	f();
	solve();
}