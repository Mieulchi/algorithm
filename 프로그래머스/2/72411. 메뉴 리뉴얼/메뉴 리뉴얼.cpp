#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string ,int> m;
int mymax;

void recursive(string tmp, string s, int idx, int cnt) {
    if (cnt == 0) {
        m[tmp]++;
        if (m[tmp] > mymax) {
            mymax = m[tmp];
        }
        return;
    }
    else {
        for(int i = idx; i < s.length() - cnt + 1; i++) {
            string cpy = tmp;
            cpy += s[i];
            recursive(cpy, s, i + 1, cnt - 1);
        }
    }
}

void solve(string s, int cnt) {
    for (int i = 0; i < s.length() - cnt + 1; i++) {
        string tmp = "";
        tmp += s[i];
        recursive(tmp, s, i + 1, cnt - 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }
    
    for (int i = 0; i < course.size(); i++) {
        int key = course[i];
        m.clear();
        mymax = 0;
        for (int j = 0; j < orders.size(); j++) {
            if (orders[j].length() >= key) {
                solve(orders[j], key);
            }
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            if (mymax > 1 && m[it->first] == mymax) {
                answer.push_back(it->first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}