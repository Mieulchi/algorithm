#include <iostream>

using namespace std;

int n;
int radius[101];

int GCD(int a, int b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

void solution() {
	for (int i = 1; i < n; i++) {
		int gcd = GCD(radius[0], radius[i]);
		if (gcd == 1) 
			cout << radius[0] << "/" << radius[i] << "\n";
		else
			cout << radius[0] / gcd << "/" << radius[i] / gcd << "\n";
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n;i++) 
		cin >> radius[i];
	solution();
}