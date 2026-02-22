 #include <iostream>
#include <algorithm>
using namespace std;

long long w, h, f, c, X1, Y1, X2, Y2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> w >> h >> f >> c >> X1 >> Y1 >> X2 >> Y2;
	cout << (w * h) - (c + 1) * (Y2 - Y1) * (min(X2, w - f) - min(X1, w - f) + max(0LL, f - X1) - max(0LL, f - X2));
}
