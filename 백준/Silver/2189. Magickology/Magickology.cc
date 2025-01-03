#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int square[8][8];
vector<int> v;
string ans;

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> square[i][j];
			v.push_back(square[i][j]);
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += square[i][0];
	}

	//NOT MAGIC
	int sum1 = 0, sum2 = 0;;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum1 += square[i][j];
			sum2 += square[j][i];
		}
		if (sum1 != res || sum2 != res) {
			ans = "Not a Magick Square";
		}
		sum1 = 0;
		sum2 = 0;
	}
	//Semi-Magick
	if (!ans.length()) {
		for (int i = 0; i < n; i++) {
			sum1 += square[i][i];
			sum2 += square[n - 1 - i][i];
		}
		if (sum1 != res || sum2 != res) {
			ans = "Semi-Magick Square";
		}
	}
	sum1 = 0;
	sum2 = 0;
	if (!ans.length()) {
		for (int i = 0; i < n; i++) {
			sum1 += square[i][i];
			sum2 += square[n - 1 - i][i];
		}
		if (sum1 != res || sum2 != res) {
			ans = "Semi-Magick Square";
		}
		else {
			ans = "Weakly-Magick Square";
			sort(v.begin(), v.end());
			int flag = 1;
			for (int i = 1; i < v.size(); i++) {
				if (v[i] == v[i - 1]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				ans = "Strongly-Magick Square";
				for (int i = 1; i < v.size(); i++) {
					if (v[i] != v[i - 1] + 1) {
						flag = 0;
						break;
					}
				}
				if (flag) {
					ans = "Magically-Magick Square";
				}
			}
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int i = 1;
	while (true) {
		cin >> n;
		if (!n) { break; }

		ans = "";
		solve();
		cout << "Square " << i << ": " << ans << '\n';
		i++;
		v.clear();
	}
}