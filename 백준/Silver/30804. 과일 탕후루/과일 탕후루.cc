#include <iostream>
using namespace std;

int n;
int ans;

void solve() {
	int a, b = 0, tmp;
	int count = 1;
	int seq = 0;

	cin >> a;
	for (int i = 1; i < n; i++) {
		cin >> tmp;
		if (tmp == a) {
			if (b) {
				int s = b;
				b = a;
				a = s;
				seq = 1;
			}
			count++;
			continue;
		}
		if (b == 0) {
			count++;
			seq = 1;
			b = tmp;
			continue;
		}
		if (tmp == b) {
			seq++;
			count++;
			continue;
		}
		if (count > ans) {
			ans = count;
		}
		count = seq + 1;
		seq = 1;
		a = b;
		b = tmp;
	}
	if (count > ans) {
		ans = count;
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve();

	cout << ans;
}