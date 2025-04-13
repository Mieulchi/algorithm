#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a;
vector<int> b;
int n;
int main(void)
{
	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		a.push_back(num);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		b.push_back(num);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i] * b[i];
	}
	cout << res;
}