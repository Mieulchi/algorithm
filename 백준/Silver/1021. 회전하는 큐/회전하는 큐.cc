#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int find_dequeue(int* dequeue, int key, int* idx, int size) {
	int rindex, lindex;
	rindex = lindex = *idx;
	int rcount = 0, lcount = 0;
	while (dequeue[rindex] != key) {
		rindex++;
		rindex %= size;
		if (dequeue[rindex] != 0) {
			rcount++;
		}
	}
	while (dequeue[lindex] != key) {
		lindex--;
		if (lindex < 0) {
			lindex += size;
		}
		if (dequeue[lindex] != 0) {
			lcount++;
		}
	}
	dequeue[rindex] = 0;

	do {
		rindex++;
		rindex %= size;
	} while (dequeue[rindex] == 0 && rindex != lindex);
	*idx = rindex;

	if (lcount < rcount) {
		return lcount;
	}
	else {
		return rcount;
	}
}

int main() {
	int size;
	int k;
	cin >> size >> k;

	int* find = new int[k];

	int* dequeue = new int[size];
	for (int i = 0; i < size; i++) {
		dequeue[i] = i + 1;
	}

	int sum = 0;
	int idx = 0;
	for (int i = 0; i < k; i++) {
		cin >> find[i];
		int tmp = find_dequeue(dequeue, find[i], &idx, size);

		sum += tmp;
	}
	cout << sum << endl;
}