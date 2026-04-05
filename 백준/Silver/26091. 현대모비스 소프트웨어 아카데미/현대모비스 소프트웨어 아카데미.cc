#include <iostream>
#include <algorithm>
using namespace std;

int people[100001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> people[i];
	}

	sort(people, people + n);

	int i; 
	for (i = 0; i < n; i++) {
		if (people[i] + people[n - 1] > m) {
			break;
		}
	}
	int j = n - 1;
	int count = 0;
	while (i < j) {
		if (people[i] + people[j] >= m) {
			count++;
			i++;
			j--;
		}
		else {
			i++;
		}
	}

	cout << count;
}