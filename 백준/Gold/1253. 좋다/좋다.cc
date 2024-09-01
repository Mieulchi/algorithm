#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int goods[2001];
int check[2001];

int main() {
	int n;
	cin >> n;

	int zerocount = 0;
	for (int i = 0; i < n; i++) {
		cin >> goods[i];
		if (goods[i] == 0) {
			zerocount++;
		}
	}
	sort(goods, goods + n);
	int tmp = 0;

	for (; tmp < n; tmp++) {
		if (goods[tmp] == 0 && zerocount > 2) {
			check[tmp] = 1;
		}
		if (goods[tmp] > 0) {
			break;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (j != 1 && goods[j] == goods[j - 1] && (goods[i] == 0 && goods[j] == 0)) {
				continue;
			}
			int sum = goods[i] + goods[j];

			int k = 0;
			while (goods[k] < sum && k < n) {
				k++;
			}
			while (goods[k] == sum && k < n) {
				if (k != i && k != j && check[k] != 1) {
					check[k] = 1;
				}
				k++;
			}
		}
	}

	int count = 0;

	for (int i = 0; i < n; i++) {
		check[i] == 1 ? count++ : NULL;
	}

	cout << count;
}