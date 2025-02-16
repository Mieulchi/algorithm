#include <iostream>
using namespace std;

int w, n;
int arr[5000];
pair<int, pair<int,int>> dp[799995];
string ans = "NO";

void solve() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int target = arr[i] + arr[j];
			dp[target] = { 1,{i,j} };
			if (w - target >= 0 && w - target <= 799994) {
				pair<int, pair<int, int>> opp = dp[w - target];
				if (opp.first) {
					if (opp.second.first != i && opp.second.first != j && opp.second.second != i && opp.second.second != j)
						ans = "YES";
					break;
				}
			}
		}
		if (ans == "YES") {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> w >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	solve();

	cout << ans;
}