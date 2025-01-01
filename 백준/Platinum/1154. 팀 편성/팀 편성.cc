#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int n;

vector<int> v[1001];

vector<int> va;
vector<int> vb;
vector<int> vtmp;

int ans;

void solve() {
	va.push_back(1);
	for (int i = 2; i <= n; i++) {
		if (find(v[1].begin(), v[1].end(), i) == v[1].end()) {
			vb.push_back(i);
		}
	}

	for (int i = 2; i <= n; i++) {
		int canA = 1, canB = 1;
		for (int j = 0; j < va.size(); j++) {
			if (va[j] != i && find(v[i].begin(), v[i].end(), va[j]) == v[i].end()) {
				if (find(vb.begin(), vb.end(), va[j]) == vb.end()) {
					canA = 0;
					break;
				}
			}
		}
		for (int j = 0; j < vb.size(); j++) {
			if (vb[j] != i && find(v[i].begin(), v[i].end(), vb[j]) == v[i].end()) {
				if (find(va.begin(), va.end(), vb[j]) == va.end()) {
					canB = 0;
					break;
				}
			}
		}
		if (canA || canB) {
			if (canA && canB) {
				vtmp.push_back(i);
			}
			else {
				if (canA) {
					va.push_back(i);
				}
				else if (canB) {
					if (find(vb.begin(), vb.end(), i) == vb.end()) {
						vb.push_back(i);
					}
				}
			}
		}
		else {
			ans = -1;
			break;
		}
	}
	for (int i = 0; i < vtmp.size(); i++) {
		int flag = 1;
		for (int j = 0; j < va.size(); j++) {
			if (find(v[vtmp[i]].begin(), v[vtmp[i]].end(), va[j]) == v[vtmp[i]].end()) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			va.push_back(vtmp[i]);
		}
		else {
			flag = 1;
			for (int j = 0; j < vb.size(); j++) {
				if (find(v[vtmp[i]].begin(), v[vtmp[i]].end(), vb[j]) == v[vtmp[i]].end()) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				vb.push_back(vtmp[i]);
			}
			else {
				ans = -1;
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	ans = 1;

	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) {
			break;
		}
		v[a].push_back(b);
		v[b].push_back(a);
	}

	solve();

	if (ans == -1) {
		cout << ans;
	}
	else {
		cout << ans << '\n';
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());
		for (int i = 0; i < va.size(); i++) {
			cout << va[i] << ' ';
		}
		cout << -1 << '\n';
		for (int i = 0; i < vb.size(); i++) {
			cout << vb[i] << ' ';
		}
		cout << -1 << '\n';
	}
}