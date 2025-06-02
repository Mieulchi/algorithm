#include <iostream>
#include <queue>
#include <set>
using namespace std;

string s;
int k;
string ans;

bool bigger(string tmp) {
	if (ans == "") {
		return true;
	}
	for (int i = 0; i < s.length(); i++) {
		if (tmp[i] > ans[i]) {
			return true;
		}
		else if (tmp[i] < ans[i]) {
			return false;
		}
	}
}

void solve() {
	queue<string> q;
	q.push(s);
	for (int i = 0; i < k; i++) {
		set<string> st;
		while (!q.empty()) {
			string front = q.front();
			q.pop();
			for (int j = 0; j < front.length() - 1; j++) {
				for (int k = j + 1; k < front.length(); k++) {
					string tmp = front;
					swap(tmp[j], tmp[k]);
					if (tmp[0] != '0') {
						st.insert(tmp);
					}
				}
			}
		}
		if (st.empty()) {
			ans = "-1";
			break;
		}
		for (auto it = st.begin(); it != st.end(); it++) {
			q.push(*it);
		}
	}
	if (ans == "-1") {
		return;
	}
	while (!q.empty()) {
		string front = q.front();
		q.pop();
		if (bigger(front)) {
			ans = front;
		}
	}
 }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> k;
	if (s.length() > 1) {
		solve();
	}
	else {
		ans = "-1";
	}
	cout << ans;
}
