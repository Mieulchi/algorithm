#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000007

int n, l;
int goldMedals[52];
int silverMedals[52];
int bronzeMedals[52];
int ans = 1;

int dp[52][10001];

void solve() {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= l; ++j) {
			dp[i][j] = INF;
		}
	}

	dp[0][0] = 0;
	for (int i = 2; i <= n; ++i) {
		if (goldMedals[i] > goldMedals[1]) {
			++ans;
		}
		else if (goldMedals[i] == goldMedals[1]) {
			if (silverMedals[i] > silverMedals[1]) {
				++ans;
			}
			else {
				int needSilvers = max(0, silverMedals[1] - silverMedals[i]);
				int needBronzes = max(0, bronzeMedals[1] - bronzeMedals[i] + 1);

				for (int j = i; j > 0; --j) {
					for (int k = 0; k <= l; ++k) {

						// 1) 은메달만으로 이기게 하는 경우 dp 테이블 갱신
						if (needSilvers + 1 <= l && k + needSilvers + 1 <= l) {
							dp[j][k + needSilvers + 1] = min(dp[j][k + needSilvers + 1], dp[j - 1][k]);
						}

						// 2) 은메달 동률에 동메달로 이기게 하는 경우 dp 테이블 갱신, 이 때 은메달 동메달 한 팀이 쓸어가면 안됨
						if (needSilvers + needBronzes <= l) {
							if (needSilvers <= l && k + needSilvers <= l && dp[j - 1][k] + needBronzes <= l) {
								dp[j][k + needSilvers] = min(dp[j][k + needSilvers], dp[j - 1][k] + needBronzes);
							}
						}
					}
				}

				
			}
		}
	}

	int mx = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= l; ++j) {
			if (dp[i][j] != INF) {
				mx = i;
				break;
			}
		}
	}
	ans += mx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l;
	for (int i = 1; i <= n; ++i) {
		cin >> goldMedals[i] >> silverMedals[i] >> bronzeMedals[i];
	}
	goldMedals[1] += l;
	solve();
	cout << ans;
}