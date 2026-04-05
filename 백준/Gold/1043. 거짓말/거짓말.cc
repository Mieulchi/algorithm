#include <iostream>
#include <string>
using namespace std;

//people[] == 1 -> know truth
int people[51] = { 0 };
int parties[51][52] = {0};
int graph[52][52];

void find_truth(int size, int n) {
	for (int i = 1; i <= size; i++) {
		if (graph[n][i] == 1) {
			if (people[i] == 1) {
				continue;
			}
			else {
				people[i] = 1;
				find_truth(size, i);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		people[tmp] = 1;
	}
	int peoplenum[51] = { 0 };

	for (int i = 0; i < m; i++) {
		cin >> peoplenum[i];
		//input one party
		parties[i][0] = 0;
		int tmpeople[51] = { 0 };

		for (int j = 0; j < peoplenum[i]; j++) {
			cin >> tmpeople[j];
			parties[i][j + 1] = tmpeople[j];
		}

		for (int j = 0; j < peoplenum[i] - 1; j++) {
			for (int k = j + 1; k < peoplenum[i]; k++) {
				graph[tmpeople[j]][tmpeople[k]] = 1;
				graph[tmpeople[k]][tmpeople[j]] = 1;
			}

		}

		if (parties[i][0] == 1) {
			for (int j = 1; j <= peoplenum[i]; j++) {
				people[parties[i][j]] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (people[i] == 1) {
			find_truth(n, i);
		}
	}


	int count = 0;
	for (int i = 0; i < m; i++) {
		int flag = 1;
		for (int j = 1; j <= peoplenum[i]; j++) {
			if (people[parties[i][j]] == 1) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			count++;
		}
	}
	cout << count;
}