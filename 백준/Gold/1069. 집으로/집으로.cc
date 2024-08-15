#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x, y, d, t;
	cin >> x >> y >> d >> t;

	long double dist = sqrt(x * x + y * y);

	long double resulttime = 0;


	if (dist <= d) {

		if (2 * t < dist) {
			if (2 * t < t + d - dist) {
				resulttime = 2 * t;
			}
			else {
				resulttime = t + d - dist;
			}
		}
		else {
			if (dist < t + d - dist) {
				resulttime = dist;
			}
			else {
				resulttime = t + d - dist;
			}
		}

	}
		else {
			int count = dist / d;
			if ((count + 1) * t < count * t + dist - (count * d)) {
				if ((count + 1) * t < dist) {
					resulttime = (count + 1) * t;
				}
				else {
					resulttime = dist;
				}
			}
			else {
				if (count * t + dist - (count * d) < dist) {
					resulttime = count * t + dist - (count * d);
				}
				else {
					resulttime = dist;
				}
			}
		}

	cout << fixed;
	cout.precision(9);

	cout << resulttime;

}