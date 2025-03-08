#include <iostream>
#include <algorithm>
using namespace std;

long long n;
int b;
string ans;

void solve() {
	long long sum = 1;
	for (long long i = 1; i <= b; i++) {
		sum += (1LL << i);
	}
	if (sum >= n) {
		ans = "yes";
	}
	else {
		ans = "no";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> b;
	solve();
	cout << ans;
}