#include <iostream>
using namespace std;

int n, m;
int arr[2000];
int isPalindrome[2000][2000];


void solve() {
	for (int i = 0; i < n; ++i) {
		isPalindrome[i][i] = 1;
	}

	//마지막 글자 찾을 인덱스
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			if (arr[j] == arr[j + i] && (i == 1 || isPalindrome[j + 1][j + i - 1])) {
				isPalindrome[j][j + i] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	solve();

	cin >> m;
	int a, b;
	while (m--) {
		cin >> a >> b;
		cout << isPalindrome[a - 1][b - 1] << '\n';
	}
}