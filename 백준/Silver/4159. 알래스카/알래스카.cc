#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int counts[11][11];

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}

		int* charge = new int[n];
		for (int i = 0; i < n; i++) {
			charge[i] = 0;
		}
		string result = "POSSIBLE";

		for (int i = 0; i < n; i++) {
			cin >> charge[i];
		}
			
		sort(charge, charge + n);
			
		int i;
		for (i = 0; i < n - 1; i++) {
			if (charge[i + 1] - charge[i] > 200) {
				result = "IMPOSSIBLE";
				break;
			}
		}
		if (1422 - charge[n - 1] > 100) {
			result = "IMPOSSIBLE";
		}


		for (i = n - 1; i >= 1; i--) {
			if (charge[i] - charge[i - 1] > 200) {
				result = "IMPOSSIBLE";
				break;
			}
		}


		cout << result << "\n";
		
		delete [] charge;
	}
}