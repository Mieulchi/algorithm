#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, sf, l, ans;
	while (true) {
		cin >> a;
		if (!a) {
			break;
		}
		ans = 1;
		for (int i = 0; i < a; i++) {
			cin >> sf >> l;
			ans = (ans * sf) - l;
		}
		cout << ans << '\n';
	}
}