#include <iostream>
using namespace std;

#define MAX 1000000000000000000

int q;
long long n;
char c;
int line;
long long l = MAX * -1 - 1 , r = MAX + 1;

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);

	int flag = 1;
	cin >> q;
	for (int i = 0;i < q;i++) {
		cin >> n >> c;
		if (c == '^') {
			if (n > l) {
				l = n;
			}
		}
		else {
			if (n < r) {
				r = n;
			}
		}
		if (r - l <= 1) {
			flag = 0;
			cout << "Paradox!\n";
			cout << i + 1;
			break;
		}
		if (!line && r - l == 2) {
			line = i + 1;
		}
	}
	if (flag) {
		if (line) {
			cout << "I got it!\n";
			cout << line;
		}
		else {
			cout << "Hmm...";
		}
	}
}