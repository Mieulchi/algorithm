#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int sum(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += i;
	}

	return sum;
}

int main() {
	int s, e;
	cin >> s >> e;
	
	int sum = 0;
	int count = 0;
	for (int i = 1; count <= e; i++) {
		for (int j = 0; j < i; j++) {
			count++;
			if (count >= s && count <= e) {
				sum += i;
			}
		}
	}

	printf("%d", sum);
}