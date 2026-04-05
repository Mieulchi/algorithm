#include <iostream>
#include <cmath>
using namespace std;

int button[11] = { 0 };

int isPosb(int n) {
	int flag = 1;

	int degree = 0;
	int tmp = n;

	if (tmp == 0) {
		degree++;
	}
	while (tmp > 0) {
		tmp /= 10;
		degree++;
	}

	int search[7] = { 0 };
	tmp = n;
	for (int i = 0; i < degree; i++) {
		search[i] = tmp / pow(10, degree - i - 1);
		if (button[search[i]] == -1) {
			flag = 0;
			break;
		}
		tmp = tmp - search[i] * pow(10, degree - i - 1);
	}

	return flag;
}

int main() {
	int n;
	cin >> n;

	int m;
	cin >> m;

	int allbroken = 0;
	if (m == 10) {
		allbroken = 1;
	}

	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		button[tmp] = -1;
	}

	int upposib = -1, downposib = -1;

	for (int i = n; i <= 1000000; i++) {
		if (isPosb(i) == 1) {
			upposib = i;
			break;
		}
	}

	for (int i = n; i >= 0; i--) {
		if (isPosb(i) == 1) {
			downposib = i;
			break;
		}
	}


	int degree1 = 0;
	int tmp = upposib;
	if (tmp == 0) {
		degree1++;
	}
	while (tmp > 0) {
		tmp /= 10;
		degree1++;
	}


	int degree2 = 0;
	tmp = downposib;
	if (tmp == 0) {
		degree2++;
	}
	while (tmp > 0) {
		tmp /= 10;
		degree2++;
	}

	int count1;
	if (n < 100) {
		count1 = 100 - n;
	}
	else {
		count1 = n - 100;
	}

	int count2;
	int result;

	if (allbroken == 0) {
		if (upposib == -1 && downposib != -1) {
			count2 = n - downposib + degree2;
		}
		else if (upposib != -1 && downposib == -1) {
			count2 = upposib - n + degree1;
		}
		else if (upposib == -1 && downposib == -1) {
			count2 = count1;
		}
		else {
			if (upposib - n + degree1 > n - downposib + degree2) {
				count2 = n - downposib + degree2;
			}
			else {
				count2 = upposib - n + degree1;
			}
		}
		if (count1 > count2) {
			result = count2;
		}
		else {
			result = count1;
		}
	}
	else {
		result = count1;
	}
	cout << result;
}