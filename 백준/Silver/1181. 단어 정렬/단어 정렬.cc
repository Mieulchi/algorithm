#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int k;

int compare(string s1, string s2) {
	if (s1.length() != s2.length()) {
		return s1.length() < s2.length();
	}
	else {
		return s1 < s2;
	}

}

int main() {
    int i;
	vector<string> v;
   
    cin >> k;
	v.resize(k);
    
	for (i = 0; i < k; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	k = v.size();
	sort(v.begin(), v.end(), compare);

	for (i = 0; i < k; i++) {
		cout << v[i] << ' ';
	}

}