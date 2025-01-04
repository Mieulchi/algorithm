#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n;
int ans;
void solve() {
	string s = to_string(n);
	int m = s.length();

	int i;
	for (i = 1; i < m; i++) { 
		int op = pow(10, i) - pow(10, i - 1);
		ans += i * op;
	}

	
	int op = n - pow(10, m - 1) + 1;
	
	
	ans += m * op;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	solve();

	cout << ans;
}