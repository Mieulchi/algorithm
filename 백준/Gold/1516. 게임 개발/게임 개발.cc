#include <iostream>
#include <vector>
using namespace std;

int built[501];
int	buildTime[501];
vector<int> v[501];

void clearBuilt(int n) {
	for (int j = 0; j < n; j++) {
		built[j] = 0;
	}
}

int dfs(int node) {
	if (built[node]) {
		return built[node];
	}
	else {
		if (v[node].size() == 0) {
			built[node] = buildTime[node];
			return buildTime[node];
		}
		int sum = dfs(v[node].at(0));
		for (int i = 1; i < v[node].size(); i++) {
			if (built[v[node].at(i)] == 0) {
				int tmp = dfs(v[node].at(i));
				if (tmp > sum) {
					sum = tmp;
				}
			}
			else {
				int tmp = built[v[node].at(i)];
				if (tmp > sum) {
					sum = tmp;
				}
			}
		}
		built[node] = sum + buildTime[node];
		return sum + buildTime[node];
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int time;
		cin >> time;
		buildTime[i] = time;

		int tmp;
		while (true) {
			cin >> tmp;
			if (tmp == -1) {
				break;
			}
			v[i].push_back(tmp - 1);

		}
	}

	for (int i = 0; i < n; i++) {
		clearBuilt(n);
		int time;
		time = dfs(i);
		cout << time << '\n';
	}
}
