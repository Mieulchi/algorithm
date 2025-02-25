#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
stack<pair<int, int>> s;
long long ans;

void solve() {
	int k;
	cin >> k;
	s.push({ k, 1 });
	for (int i = 1; i < n; i++) {
		cin >> k;
		pair<int, int> top = s.top();
		if (k > top.first) {
			while (!s.empty()) {
				top = s.top();
				if (top.first < k) {
					if (s.size() == 1) {
						ans += top.second;
					}
					else {
						ans += top.second * 2;
					}
					s.pop();
				}
				else {
					break;
				}
			}
			if (s.empty()) {
				s.push({ k,1 });
			}
			else {
				top = s.top();
				if (k == top.first) {
					ans += s.top().second;
					s.top().second++;
				}
				else {
					s.push({ k,1 });
				}
			}
		}
		else if (k == top.first) {
			ans += s.top().second;
			s.top().second++;
		}
		else {
			s.push({ k,1 });
		}
	}
	while (s.size() > 1) {
		ans += s.top().second;
		s.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();

	cout << ans;
}