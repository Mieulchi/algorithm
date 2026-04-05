#include <iostream>
using namespace std;

int means[51];

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string a, b;
		cin >> a >> b;
		
		int count = 0;
		int zcount = 0;
		int ocount = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[j]) {
				if (a[j] == '1') {
					ocount++;
				}
				else {
					zcount++;
				}
			}
		}
		int sum = 0;

		while (zcount > 0 && ocount > 0) {
			sum++;
			zcount--;
			ocount--;
		}

		if (zcount == 0) {
			sum += ocount;
		}
		else {
			sum += zcount;
		}

		cout << sum << endl;
	}
}
