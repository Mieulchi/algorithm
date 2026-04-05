#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long k;
	cin >> k;
	
	for (int i = 0; i < k; i++) {
		long long n;
		cin >> n;

		long long count = 0;
		while (n >= 5) {
			count += n / 5;
			n /= 5;
		}
		
		cout << count << '\n';
	}
}