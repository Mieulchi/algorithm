#include <iostream>
#include <queue>
using namespace std;

int n, m;
int siz;
int ans;

struct maxCmp {
	bool operator()(int n1, int n2) {
		return n1 < n2;
	}
};

struct minCmp {
	bool operator()(int n1, int n2) {
		return n1 > n2;
	}
};

priority_queue<int, vector<int>, minCmp> minpq;
priority_queue<int, vector<int>, maxCmp> maxpq;

void solve() {
	int m;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (minpq.size() == maxpq.size()) {
			maxpq.push(m);
		}
		else {
			minpq.push(m);
		}
		if ((maxpq.size() >= 1 && minpq.size() >= 1) && maxpq.top() > minpq.top()) {
			int tmp = maxpq.top();
			maxpq.pop();
			maxpq.push(minpq.top());
			
			minpq.pop();
			minpq.push(tmp);
		}
		cout << maxpq.top() << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve();
}