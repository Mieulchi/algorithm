#include <iostream>
using namespace std;

int graph[16];

int main() {
	int days;
	long long money;
	cin >> days >> money;

	for (int i = 0; i < days; i++) {
		cin >> graph[i];
	}

	long long coins = 0;
	int i;

	if (days != 1) {
		for (i = 0; i < days - 1; i++) {
			if (graph[i + 1] > graph[i]) {
				if (money >= graph[i]) {
					coins += money / graph[i];
					money = money - graph[i] * coins;
				}
			}
			else if (graph[i + 1] < graph[i]) {
				money += graph[i] * coins;
				coins = 0;
			}
		}
	}
	
	if (coins) {
		money += graph[i] * coins;
	}


	cout << money;
}