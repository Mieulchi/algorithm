#include <iostream>
#include <vector>
using namespace std;

int mat[6][6];
int result[6][6];
int tmp[6][6];
vector<int> v;

void sqr(int n) {
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			int innertmp = 0;
			for (int l = 0; l < n; l++) {
				innertmp += tmp[j][l] * tmp[l][k];
			}
				result[j][k] = innertmp % 1000;
		}
	}

	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			tmp[j][k] = result[j][k];
		}
	}
}

void once(int n) {
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			int innertmp = 0;
			for (int l = 0; l < n; l++) {
				innertmp += tmp[j][l] * mat[l][k];
			}
				result[j][k] = innertmp % 1000;
		}
	}

	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			tmp[j][k] = result[j][k];
		}
	}
}

int main() {
	int n;
	long long b;
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			mat[i][j] %= 1000;
			tmp[i][j] = mat[i][j];
			result[i][j] = mat[i][j];
			if (result[i][j] > 1000) {
				result[i][j] %= 1000;
			}

		}
	}

	
	while (b > 1) {
		if (b % 2 == 1) {
			v.push_back(1);
			b--;
		}
		v.push_back(b % 2);
		b /= 2;
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] == 1) {
			once(n);
		}
		else {
			sqr(n);
		}
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
}