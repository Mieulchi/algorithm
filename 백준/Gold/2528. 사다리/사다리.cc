#include <iostream>
using namespace std;

int n, l;
pair<int, int> arr[3001];
int stt[3001];
int ans;

void sim(int floor) {
	for (int i = floor; i <= n; i++) {
		int len = arr[i].first;
		int dir = arr[i].second;
		if (dir == 0) {
			stt[i]++;
		}
		else {
			stt[i]--;
		}
		if (dir == 0 && stt[i] + len == l) {
			arr[i].second = 1;
		}
		if (dir == 1 && stt[i] == 0) {
			arr[i].second = 0;
		}
	}
}

void solve() {
	int floor = 1;
	while (floor < n) {
		int flag = 0;
		for (int i = stt[floor]; i <= stt[floor] + arr[floor].first; i++) {
			if (i >= stt[floor + 1] && i <= stt[floor + 1] + arr[floor + 1].first) {
				floor++;
				flag = 1;
				break;
			}
		}
		if (flag) {
			continue;
		}
		ans++;
		sim(floor);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
		stt[i] = arr[i].second == 0 ? 0 : l - arr[i].first;
	}
	solve();
	cout<<ans;
}