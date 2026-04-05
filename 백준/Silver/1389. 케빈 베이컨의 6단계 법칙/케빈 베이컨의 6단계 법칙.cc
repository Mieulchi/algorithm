#include <iostream>
#include <cmath>
using namespace std;

int friends[101][101] = { 0 };
int kbNum[101];

int getKb(int n, int size, int level, int visited[]) {
	if (level == size) {
		return 0;
	}

	visited[n] = 1;
	int sum = 0;
	int tovisit[101] = { 0 };
	for (int i = 0; i < size; i++) {
		if (friends[n][i] == 1 && visited[i] == 0) {
			sum += level;
			visited[i] = 1;
			tovisit[i] = 1;
		}
	}
	for (int i = 0; i < size; i++) {
		if (tovisit[i] == 1) {
			sum += getKb(i, size, level + 1, visited);
		}
	}

	return sum;
}


int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		friends[a - 1][b - 1] = 1;
		friends[b - 1][a - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		int visited[101] = { 0 };
		kbNum[i] = getKb(i, n, 1, visited);
	}

	int kbMin = kbNum[0];
	int mindex = 0;

	for (int i = 0; i < n; i++) {
		if (kbNum[i] < kbMin) {
			kbMin = kbNum[i];
			mindex = i;
		}
	}

	cout << mindex + 1;
}