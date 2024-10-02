#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string s;
string bomb;
stack<char> stk;


int main() {
	cin >> s;
	cin >> bomb;

	int len = bomb.length();
	int pointer = 0;

	for (int i = 0; i < s.length(); i++) {
		stk.push(s[i]);
		if (stk.size() >= len) {
			string tmp;
			for (int j = 0; j < len; j++) {
				tmp += stk.top();
				stk.pop();
			}
			reverse(tmp.begin(), tmp.end());
			if (tmp == bomb) {
				continue;
			}
			else {
				for (int j = 0; j < len; j++) {
					stk.push(tmp[j]);
				}
			}
		}
	}


	if (stk.empty()) {
		cout << "FRULA";
	}
	else {
		string result;
		while (!stk.empty()) {
			result += stk.top();
			stk.pop();
		}

		reverse(result.begin(), result.end());

		cout << result;
	}
}