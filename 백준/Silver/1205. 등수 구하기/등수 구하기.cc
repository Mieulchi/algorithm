#include <iostream>
using namespace std;

unsigned int scores[51];

int main() {
	int n, num, p;
	cin >> n >> num >> p;

	for (int i = 0; i < n; i++) {
		cin >> scores[i];
	}

	int rank = 1;
	int i;
	int sameflag = 0;
	for (i = 0; i < n; i++) {
		if (scores[i] < num) {
			sameflag = 0;
			break;
		}
		else if (scores[i] == num) {
			sameflag = 1;
		}
		else {
			sameflag = 0;
			rank++;
		}
	}

	if ((sameflag == 1 && i >= p) || (i >= p)) {
		rank = -1;
	}


	cout << rank;
}