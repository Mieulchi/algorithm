#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long n;
vector<string> v;

string pow(int i) {
	string s = "1";
	while (i--) {
		string t;
		int prev = 0;
		for (int j = s.length() - 1; j >= 0; j--) {
			int tmp = (s[j] - '0') * 3 + prev;
			if (t.empty()) {
				t = to_string(tmp % 10);
			}
			else {
				t = to_string(tmp % 10) + t;
			}

			prev = tmp / 10;
			
		}
		if (prev) {
			t = to_string(prev) + t;
		}
		
		s = t;
	}
	return s;
}

void solve() {
	n -= 1;
	v.clear();
	for (long long i = 0; i < 64; i++) {
		if ((n >> i) & 1) {
			v.push_back(pow(i));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> n;
		if (!n) {
			break;
		}
		solve();
		cout << "{ ";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
			if (i != v.size() - 1) {
				cout << ", ";
			}
			else {
				cout << " ";
			}
		}
		cout << "}\n";
	}
}