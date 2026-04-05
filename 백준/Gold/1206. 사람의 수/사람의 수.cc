#include <iostream>
using namespace std;

long long means[51];

long long getT(int n) {
	while (n % 1000 != 0) {
		n++;
	}
	return n;
}

int main() {
	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;
		if (s.length() == 6) {
			means[i] = 10000;
		}
		else {
			means[i] += (long long)(s[0] - '0') * 1000;
			means[i] += (long long)(s[2] - '0') * 100;
			means[i] += (long long)(s[3] - '0') * 10;
			means[i] += (long long)(s[4] - '0') * 1;
		}
	}

	long long i = 1;
	while (i <= 1000) {
		int flag = 1;
		for (int j = 0; j < k; j++) {
			long long tmp1 = means[j] * i;

			if (tmp1 % 1000 != 0 || (tmp1 < 1000 && tmp1 > 0)) {
				long long op = getT(tmp1);

				if (op - tmp1 >= i) {
					flag = 0;
					break;
				}

			}
		}
		if (flag == 1) {
			break;
		}
		i++;
	}

	cout << i;
}
