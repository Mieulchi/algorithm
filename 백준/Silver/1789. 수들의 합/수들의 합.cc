#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long s;
int n;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	int count = 0;
	long long sum = 0;
	n = 1; 
	while (sum <= s) {
		sum += n++;
		count++;
	}
	count--;

	cout << count;
}