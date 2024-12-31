#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int d;
	int v;
}Penalty;

bool cmp(Penalty a, Penalty b) {
	return a.d < b.d;
}

Penalty p[11];

void solve() {
	for (int i = 0; i < 11; i++) {
		int d, v;
		cin >> d >> v;

		p[i] = { d, v };
	}
	sort(p, p + 11, cmp);

	int sum = 0;
	int timesum = 0;
	for (int i = 0; i < 11; i++) {
		sum += 20 * p[i].v;
		timesum += p[i].d;
		sum += timesum;
	}

	cout << sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
}