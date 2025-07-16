#include <iostream>
using namespace std;

long long a, b, c;
long long ans = 1;

void solve() {
	int n = 0;
	long long base = a;
	while ((1LL << n) <= b) {
		if ((b >> n) & 1) {
			ans = (ans * base) % c;
		}
		base = (base * base) % c;
        n++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b >> c;
	solve();
	cout << ans;
}