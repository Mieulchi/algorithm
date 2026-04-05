#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

vector<int> v;
long long sosu[10000001];

int main() {
	long long a, b;
	cin >> a >> b;


	long long i = 2;
	long long point = sqrt(b);
	while (i <= point) {
		v.push_back(i);
		int j = i;
		int op = j;
		while (j <= point) {
			if (sosu[j] == 0) {
				sosu[j] = 1;
			}
			j += op;
		}
		while (sosu[i] == 1) {
			i++;
		}
	}

	long long count = 0;

	for (int i = 0; i < v.size(); i++) {
		long long op = v[i];
		unsigned long long tmp = op * op;
		while (tmp <= b) {
			if (tmp >= a) {
				count++;
			}
			if (tmp > LLONG_MAX / op) {
				break;
			}
			tmp *= op;
		}
	}
	
	cout << count;
}