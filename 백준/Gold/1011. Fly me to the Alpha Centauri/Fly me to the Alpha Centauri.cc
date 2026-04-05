#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;

	int start, end;
	int distance;
	for (int i = 0; i < k; i++) {
		cin >> start >> end;

		distance = end - start;
		int count = 0;
		int n = 1;
		int sum = 1;
		while (distance != 0) {
			distance -= n;
			count++;


			if (sum + n + 1 <= distance) {
				n++;
				sum += n;
			}
			else {
				if (sum > distance) {
					sum -= n;
					n--;
				}
				
			}
		}

		cout << count << '\n';
	}

}