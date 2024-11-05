#include <iostream>
#include <stack>
#include <queue>
using namespace std;

long long hist[100001];

typedef struct {
	long long height;
	int index;
}coor;

stack<coor> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		long long max = 0;
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		cin >> hist[0];
		coor tmp;
		tmp.height = hist[0];
		tmp.index = 0;
		s.push(tmp);

		for (int i = 1; i < n; i++) {
			cin >> hist[i];
			tmp.height = hist[i];
			tmp.index = i;

			if (hist[i] >= hist[i - 1]) {
				s.push(tmp);
			}
			else {
				while (s.size() > 0 && s.top().height >= hist[i]) {
					long long width = 0;
					if (s.top().height == hist[i]) {
						width = s.top().height * (i - s.top().index + 1);
					}
					else {
						width = s.top().height * (i - s.top().index);
					}

					if (width > max) {
						max = width;
					}
					coor tmp1 = s.top();
					tmp1.height = hist[i];
					s.pop();
					if (s.empty() || s.top().height < hist[i]) {
						s.push(tmp1);
						break;
					}
				}
				
				s.push(tmp);
			}
		}

		while (!s.empty()) {
			long long width = s.top().height * (n - s.top().index);
			if (width > max) {
				max = width;
			}
			s.pop();
		}

		cout << max << '\n';
		for (int i = 0; i < n; i++) {
			hist[i] = 0;
		}
		while (!s.empty()) {
			s.pop();
		}
	}
}