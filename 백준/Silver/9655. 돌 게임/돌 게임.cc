#include <iostream>
using namespace std;

int n;
string ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	ans = n % 2 ? "SK" : "CY";
	cout << ans;
}