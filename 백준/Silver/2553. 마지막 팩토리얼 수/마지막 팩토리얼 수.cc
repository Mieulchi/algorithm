#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
		while (ans % 10 == 0) {
			ans /= 10;
		}
		int len = to_string(i).length();
		string s = to_string(ans);
		if (s.length() > 6) {
			s = s.substr(s.length() - 6, s.length() - 1);
			ans = stoi(s);
		}
	}


	cout << to_string(ans)[to_string(ans).length() - 1];
}