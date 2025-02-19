#include <iostream>
#include <string>
using namespace std;

int n;
string s[15];
int pd[15][751];
long long dp[32768][101];
string k;
int mod;
long long parent;
long long ans;

void make_pd() {
	for (int a = 0; a < n; a++) {
		if (s[a].length() < k.length()) {
			pd[a][0] = stoi(s[a]) % stoi(k);
		}
		else {
			int tmp = s[a][0] - '0';
			for (int i = 1; i < s[a].length(); i++) {
				tmp *= 10;
				tmp += s[a][i] - '0';
				tmp %= mod;
			}
			pd[a][0] = tmp % mod;	
		}
		for (int i = 1; i <= 750; i++) {
			pd[a][i] = (pd[a][i - 1] * 10) % mod;
			if (!pd[a][i]) {
				break;
			}
		}
	}
}

int getMod(string st) {
	if (st.length() < k.length()) {
		return stoi(st) % stoi(k);
	}
	else {
		int tmp = st[0] - '0';
		for (int i = 1; i < st.length(); i++) {
			tmp *= 10;
			tmp += st[i] - '0';
			tmp %= mod;
		}
		tmp %= mod;
		return tmp;
	}
}

void makeGcd() {
	long long a = parent, b = ans;
	while (b) {
		long long tmp = a % b;
		a = b;
		b = tmp;
	}
	parent /= a;
	ans /= a;
}

void solve() {
	parent = 1;
	make_pd();
	for (int i = 1; i <= n; i++) {
		parent *= i;
	}
	for (int i = 0; i < n; i++) {
		dp[1 << i][pd[i][0]] = 1;
	}
	int m = 1 << n;

	for (int i = 1; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ((i ^ (1 << j)) == i + (1 << j)) {
				int leng = 0;
				for (int k = 0; k < n; k++) {
					if ((i >> k) & 1) {
						leng += s[k].length();
					}
				}
				for (int k = 0; k < mod; k++) {
					if (dp[i][k]) {
						dp[i + (1 << j)][(pd[j][leng] + k) % mod] += dp[i][k];
					}
				}
			}
		}
	}
	ans = dp[(1 << n) - 1][0];
	makeGcd();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	cin >> k;
	mod = stoi(k);

	solve();

	cout << ans << '/' << parent;
}