#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int w, h;
		cin >> h >> w;
		if (w == 0 && h == 0) {
			break;
		}

		int comp = w * w + h * h;
		int tcmp = 0;

		//1 == h 2 == w

		int ans1 = h, ans2 = w;
		int op1 = 1, op2 = 2;
		while (true) {
			if (op1 > 150) {
				break;
			}
			if (op2 > 150) {
				op1++;
				op2 = op1 + 1;
				continue;
			}
			int res = op1 * op1 + op2 * op2;
			if (res == comp) {
				if (op1 > h) {
					ans1 = op1;
					ans2 = op2;
					break;
				}
				else {
					op2++;
				}
			}
			else if (res > comp) {
				if (tcmp == 0 || res < tcmp) {
					ans1 = op1;
					ans2 = op2;
					tcmp = res;
				}
				op1++;
				op2 = op1 + 1;
			}
			else {
				op2++;
			}
		}

		cout << ans1 << " " << ans2 << '\n';
	}
}