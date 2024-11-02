#include <iostream>
using namespace std;

int efs[1001];
int mods[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p;
	cin >> n >> p;
	
	int tmp;
	for (int i = n; i > 0; i--) {
		cin >> tmp;
		efs[i % (p - 1)] += tmp % p;
		efs[i % (p - 1)] %= p;
	}
	cin >> tmp;
	efs[p - 1] = tmp % p;

	//x == 0
	cout << efs[p - 1] << '\n';

	for (int x = 1; x < p; x++) {
		int result = 0;

		//모든 항 계산
		mods[0] = 1;
		result += efs[p - 1];
		for (int N = 0; N < p - 1; N++) {

			if (N != 0) {
				mods[N] = (mods[N - 1] * x) % p;
			}
			
			result += (efs[N] * mods[N]) % p;
			result %= p;
		}

		cout << result <<'\n';
	}
}