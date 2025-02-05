#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
pair<int, int> points[100000];
pair<int, int> start;
stack<pair<int, int>> s;
int ans;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	pair<long long, long long> v1 = { p1.first - start.first, p1.second - start.second };
	pair<long long, long long> v2 = { p2.first - start.first, p2.second - start.second };
	if (v1.first * v2.second - v2.first * v1.second == 0) {
		if (p1.first < start.first) {
			return p1.first > p2.first;
		}
		else {
			return p1.first < p2.first;
		}
	}
	return (v1.first * v2.second - v2.first * v1.second > 0);
}

int ccw(pair<long long, long long> v1, pair<long long, long long> v2) {
	long long cp = v1.first * v2.second - v1.second * v2.first;
	return cp == 0 ? v1.first * v2.first > 0 ? 0 : -1 : cp > 0 ? 1 : -1;
}

void solve() {
	sort(points + 1, points + n, cmp);

	pair<long long, long long> v1 = { points[1].first - points[0].first, points[1].second - points[0].second };
	s.push(points[0]);
	s.push(points[1]);
	for (int i = 2; i <= n && i > 1; i++) {
		if (i == n) {
			i = 0;
		}
		pair<long long, long long> t = s.top();
		pair<long long, long long> v2 = { points[i].first - t.first, points[i].second - t.second };
		int direction = ccw(v1, v2);
		if (direction > 0) {
			s.push(points[i]);
			v1 = v2;
		}
		else if (direction == 0) {

			s.pop();
			v1 = { points[i].first - s.top().first, points[i].second - s.top().second };
			s.push(points[i]);
		}
		else {
			s.pop();
			if (s.size() == 1) {
				v1 = { points[i].first - s.top().first, points[i].second - s.top().second };
				s.push(points[i]);
			}
			else {
				while (true) {
					pair<int, int> tmp1 = s.top();
					s.pop();
					pair<int, int> tmp2 = s.top();
					v1 = { tmp1.first - tmp2.first, tmp1.second - tmp2.second };
					v2 = { points[i].first - tmp1.first, points[i].second - tmp1.second };
					direction = ccw(v1, v2);
					if (direction > 0) {
						s.push(tmp1);
						s.push(points[i]);
						v1 = v2;
						break;
					}
					else if (direction == 0) {
						s.push(points[i]);
						v1 = { points[i].first - tmp2.first, points[i].second - tmp2.second };
						break;
					}
				}
			}
		}
	}

	ans = s.size() - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	cin >> points[0].first >> points[0].second;
	start = points[0];
	int idx = 0;

	for (int i = 1; i < n; i++) {
		cin >> points[i].first >> points[i].second;
		if (points[i].second <= start.second) {
			if (points[i].second == start.second) {
				if (points[i].first < start.first) {
					start = points[i];
					idx = i;
				}
			}
			else {
				start = points[i];
				idx = i;
			}
		}
	}
	swap(points[0], points[idx]);

	solve();

	cout << ans;
}
