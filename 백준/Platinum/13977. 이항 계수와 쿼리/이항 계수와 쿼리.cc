#include <iostream>
using namespace std;

long long mods[4000001];

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int m;
	cin >> m;

	mods[0] = 1;
	mods[1] = 1;
	for (int i = 2; i < 4000001; i++) {
		mods[i] = (mods[i - 1] * i) % MOD;
	}

	for (int i = 0; i < m; i++) {
		int n, k;
		cin >> n >> k;

		long long op1 = mods[n];
		long long op2 = mods[k];
		long long op3 = mods[n - k];

		long long mod2 = 1, mod3 = 1;

		int times = MOD - 2;
		while (times > 0) {
			if (times % 2 == 1) {
				mod2 = (mod2 * op2) % MOD;
				mod3 = (mod3 * op3) % MOD;
			}
			op2 = (op2 * op2) % MOD;
			op3 = (op3 * op3) % MOD;
			times /= 2;
		}

		long long result = op1;
		result = (result * mod2) % MOD;
		result = (result * mod3) % MOD;
		
		cout << result << '\n';
	}
}