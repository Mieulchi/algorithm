#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


struct Cup {
	int rad;
	string name;
	Cup() : rad(0), name("") {}
};

Cup cup[20];

bool cmp(Cup c1, Cup c2) {
	return c1.rad < c2.rad;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();

	string first, second;
	for (int i = 0; i < n; ++i) {

		cin >> first >> second;
		if (first[0] - '0' >= 0 && first[0] - '0' < 10) {
			int num = stoi(first);
			cup[i].rad = num / 2;
			cup[i].name = second;
		}
		else {
			int num = stoi(second);
			cup[i].rad = num;
			cup[i].name = first;
		}
	}
	sort(cup, cup + n, cmp);

	for (int i = 0; i < n; ++i) {
		cout << cup[i].name << '\n';
	}
}
