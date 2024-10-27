#include <iostream>
using namespace std;

int status[17];


int guilty[17][17];

int dead[17];


int eunjin;
int maxday;

//1==day, 0==night

void initgame(int n, int* tmp, int* deadtmp) {
	for (int j = 0; j < n; j++) {
		status[j] = tmp[j];
		dead[j] = deadtmp[j];
	}
}

void game(int n, int days, int k) {
	int tmp[17];
	int deadtmp[17];
	if (k == 0) {
		for (int i = 0; i < n; i++) {
			tmp[i] = status[i];
			deadtmp[i] = dead[i];
		}
		for (int i = 0; i < n; i++) {
			initgame(n, tmp, deadtmp);

			if (i != eunjin && !dead[i]) {

				dead[i] = 1;
				for (int j = 0; j < n; j++) {
					status[j] += guilty[i][j];
				}
				if (days + 1 > maxday) {
					maxday = days + 1;
				}
				game(n, days + 1, 1);
			}
		}
	}
	else {
		int max = 0;
		int index = 0;
		for (int i = 0; i < n; i++) {
			if (!dead[i] && status[i] > max) {
				index = i;
				max = status[i];
			}
		}
		if (index == eunjin) {
			return;
		}
		else {
			dead[index] = 1;
			game(n, days, 0);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> status[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> guilty[i][j];
		}
	}
	cin >> eunjin;

	if (n % 2 == 1) {
		game(n, 0, 1);
	}
	else {
		game(n, 0, 0);
	}

	cout << maxday;
	}