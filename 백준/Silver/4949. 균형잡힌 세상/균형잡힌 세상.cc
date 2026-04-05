#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    string str;
    while (true) {
        getline(cin, str);
        string ans = "yes";
        stack<int> s;
        if (str[0] == '.') {
            break;
        }
        
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '.') {
                break;
            }
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                s.push(str[i]);
            }
            else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
                if (s.empty()) {
                    ans = "no";
                    break;
                }
                char top = s.top();
                s.pop();
                if (str[i] == ')') {
                    if (top != '(') {
                        ans = "no";
                        break;
                    }
                }
                else if (str[i] == ']') {
                    if (top != '[') {
                        ans = "no";
                        break;
                    }
                }
                else if (str[i] == '}') {
                    if (top != '{') {
                        ans = "no";
                        break;
                    }
                }
            }
        }
        if (!s.empty()) {
            ans = "no";
        }
        cout << ans << '\n';
    }
}