#include <iostream>
using namespace std;

int t, n;
char cube[6][3][3];

void init(int d, char c) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[d][i][j] = c;
		}
	}
}

void U(int cnt) {
	for (int i = 0; i < cnt; i++) {
		char tmp[3] = { cube[0][2][0], cube[0][2][1] ,cube[0][2][2] };

		cube[0][2][0] = cube[0][2][2];
		cube[0][2][1] = cube[0][1][2];
		cube[0][2][2] = cube[0][0][2];

		cube[0][2][2] = cube[0][0][2];
		cube[0][1][2] = cube[0][0][1];
		cube[0][0][2] = cube[0][0][0];

		cube[0][0][2] = cube[0][0][0];
		cube[0][0][1] = cube[0][1][0];
		cube[0][0][0] = cube[0][2][0];

		cube[0][0][0] = tmp[0];
		cube[0][1][0] = tmp[1];
		cube[0][2][0] = tmp[2];

		tmp[0] = cube[1][0][0];
		tmp[1] = cube[1][0][1];
		tmp[2] = cube[1][0][2];

		cube[1][0][0] = cube[2][0][0];
		cube[1][0][1] = cube[2][0][1];
		cube[1][0][2] = cube[2][0][2];

		cube[2][0][0] = cube[3][0][0];
		cube[2][0][1] = cube[3][0][1];
		cube[2][0][2] = cube[3][0][2];

		cube[3][0][0] = cube[4][0][0];
		cube[3][0][1] = cube[4][0][1];
		cube[3][0][2] = cube[4][0][2];

		cube[4][0][0] = tmp[0];
		cube[4][0][1] = tmp[1];
		cube[4][0][2] = tmp[2];
	}
}

void F(int cnt) {
	for (int i = 0; i < cnt; i++) {
		char tmp[3] = { cube[1][2][0], cube[1][2][1] ,cube[1][2][2] };

		cube[1][2][0] = cube[1][2][2];
		cube[1][2][1] = cube[1][1][2];
		cube[1][2][2] = cube[1][0][2];

		cube[1][2][2] = cube[1][0][2];
		cube[1][1][2] = cube[1][0][1];
		cube[1][0][2] = cube[1][0][0];

		cube[1][0][2] = cube[1][0][0];
		cube[1][0][1] = cube[1][1][0];
		cube[1][0][0] = cube[1][2][0];

		cube[1][0][0] = tmp[0];
		cube[1][1][0] = tmp[1];
		cube[1][2][0] = tmp[2];

		tmp[0] = cube[5][0][0];
		tmp[1] = cube[5][0][1];
		tmp[2] = cube[5][0][2];

		cube[5][0][0] = cube[2][2][0];
		cube[5][0][1] = cube[2][1][0];
		cube[5][0][2] = cube[2][0][0];

		cube[2][2][0] = cube[0][2][2];
		cube[2][1][0] = cube[0][2][1];
		cube[2][0][0] = cube[0][2][0];

		cube[0][2][0] = cube[4][2][2];
		cube[0][2][1] = cube[4][1][2];
		cube[0][2][2] = cube[4][0][2];

		cube[4][2][2] = tmp[2];
		cube[4][1][2] = tmp[1];
		cube[4][0][2] = tmp[0];
	}
}

void R(int cnt) {
	for (int i = 0; i < cnt; i++) {
		char tmp[3] = { cube[2][2][0], cube[2][2][1] ,cube[2][2][2] };

		cube[2][2][0] = cube[2][2][2];
		cube[2][2][1] = cube[2][1][2];
		cube[2][2][2] = cube[2][0][2];

		cube[2][2][2] = cube[2][0][2];
		cube[2][1][2] = cube[2][0][1];
		cube[2][0][2] = cube[2][0][0];

		cube[2][0][2] = cube[2][0][0];
		cube[2][0][1] = cube[2][1][0];
		cube[2][0][0] = cube[2][2][0];

		cube[2][0][0] = tmp[0];
		cube[2][1][0] = tmp[1];
		cube[2][2][0] = tmp[2];

		tmp[0] = cube[5][0][2];
		tmp[1] = cube[5][1][2];
		tmp[2] = cube[5][2][2];

		cube[5][0][2] = cube[3][2][0];
		cube[5][1][2] = cube[3][1][0];
		cube[5][2][2] = cube[3][0][0];

		cube[3][2][0] = cube[0][0][2];
		cube[3][1][0] = cube[0][1][2];
		cube[3][0][0] = cube[0][2][2];

		cube[0][0][2] = cube[1][0][2];
		cube[0][1][2] = cube[1][1][2];
		cube[0][2][2] = cube[1][2][2];

		cube[1][0][2] = tmp[0];
		cube[1][1][2] = tmp[1];
		cube[1][2][2] = tmp[2];
	}
}

void B(int cnt) {
	for (int i = 0; i < cnt; i++) {
		char tmp[3] = { cube[3][2][0], cube[3][2][1] ,cube[3][2][2] };

		cube[3][2][0] = cube[3][2][2];
		cube[3][2][1] = cube[3][1][2];
		cube[3][2][2] = cube[3][0][2];

		cube[3][2][2] = cube[3][0][2];
		cube[3][1][2] = cube[3][0][1];
		cube[3][0][2] = cube[3][0][0];

		cube[3][0][2] = cube[3][0][0];
		cube[3][0][1] = cube[3][1][0];
		cube[3][0][0] = cube[3][2][0];

		cube[3][0][0] = tmp[0];
		cube[3][1][0] = tmp[1];
		cube[3][2][0] = tmp[2];

		tmp[0] = cube[5][2][0];
		tmp[1] = cube[5][2][1];
		tmp[2] = cube[5][2][2];

		cube[5][2][0] = cube[4][0][0];
		cube[5][2][1] = cube[4][1][0];
		cube[5][2][2] = cube[4][2][0];

		cube[4][0][0] = cube[0][0][2];
		cube[4][1][0] = cube[0][0][1];
		cube[4][2][0] = cube[0][0][0];

		cube[0][0][2] = cube[2][2][2];
		cube[0][0][1] = cube[2][1][2];
		cube[0][0][0] = cube[2][0][2];

		cube[2][2][2] = tmp[0];
		cube[2][1][2] = tmp[1];
		cube[2][0][2] = tmp[2];
	}
}

void L(int cnt) {
	for (int i = 0; i < cnt; i++) {
		char tmp[3] = { cube[4][2][0], cube[4][2][1] ,cube[4][2][2] };

		cube[4][2][0] = cube[4][2][2];
		cube[4][2][1] = cube[4][1][2];
		cube[4][2][2] = cube[4][0][2];

		cube[4][2][2] = cube[4][0][2];
		cube[4][1][2] = cube[4][0][1];
		cube[4][0][2] = cube[4][0][0];

		cube[4][0][2] = cube[4][0][0];
		cube[4][0][1] = cube[4][1][0];
		cube[4][0][0] = cube[4][2][0];

		cube[4][0][0] = tmp[0];
		cube[4][1][0] = tmp[1];
		cube[4][2][0] = tmp[2];

		tmp[0] = cube[5][2][0];
		tmp[1] = cube[5][1][0];
		tmp[2] = cube[5][0][0];

		cube[5][2][0] = cube[1][2][0];
		cube[5][1][0] = cube[1][1][0];
		cube[5][0][0] = cube[1][0][0];

		cube[1][2][0] = cube[0][2][0];
		cube[1][1][0] = cube[0][1][0];
		cube[1][0][0] = cube[0][0][0];

		cube[0][2][0] = cube[3][0][2];
		cube[0][1][0] = cube[3][1][2];
		cube[0][0][0] = cube[3][2][2];

		cube[3][0][2] = tmp[0];
		cube[3][1][2] = tmp[1];
		cube[3][2][2] = tmp[2];
	}
}

void D(int cnt) {
	for (int i = 0; i < cnt; i++) {
		char tmp[3] = { cube[5][2][0], cube[5][2][1] ,cube[5][2][2] };
		
		cube[5][2][0] = cube[5][2][2];
		cube[5][2][1] = cube[5][1][2];
		cube[5][2][2] = cube[5][0][2];

		cube[5][2][2] = cube[5][0][2];
		cube[5][1][2] = cube[5][0][1];
		cube[5][0][2] = cube[5][0][0];

		cube[5][0][2] = cube[5][0][0];
		cube[5][0][1] = cube[5][1][0];
		cube[5][0][0] = cube[5][2][0];

		cube[5][0][0] = tmp[0];
		cube[5][1][0] = tmp[1];
		cube[5][2][0] = tmp[2];

		tmp[0] = cube[1][2][0];
		tmp[1] = cube[1][2][1];
		tmp[2] = cube[1][2][2];

		cube[1][2][0] = cube[4][2][0];
		cube[1][2][1] = cube[4][2][1];
		cube[1][2][2] = cube[4][2][2];

		cube[4][2][0] = cube[3][2][0];
		cube[4][2][1] = cube[3][2][1];
		cube[4][2][2] = cube[3][2][2];

		cube[3][2][0] = cube[2][2][0];
		cube[3][2][1] = cube[2][2][1];
		cube[3][2][2] = cube[2][2][2];

		cube[2][2][0] = tmp[0];
		cube[2][2][1] = tmp[1];
		cube[2][2][2] = tmp[2];
	}
}

void spin(char d, int cnt) {
	if (d == 'U') {
		U(cnt);
	}
	else if (d == 'F') {
		F(cnt);
	}
	else if (d == 'R') {
		R(cnt);
	}
	else if (d == 'B') {
		B(cnt);
	}
	else if (d == 'L') {
		L(cnt);
	}
	else if (d == 'D') {
		D(cnt);
	}
}

void solve() {
	string exe;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> exe;
		int cnt = exe[1] == '+' ? 1 : 3;
		spin(exe[0], cnt);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[0][i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		init(0, 'w');
		init(1, 'r');
		init(2, 'b');
		init(3, 'o');
		init(4, 'g');
		init(5, 'y');

		solve();
	}
}