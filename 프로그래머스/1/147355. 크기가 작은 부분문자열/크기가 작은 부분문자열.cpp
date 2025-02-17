#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i=0; i<=t.length() - p.length(); i++) {
        int flag=1;
        for(int j=0; j<p.length();j++) {
            if (t[i + j] - '0' != p[j] - '0'){
                if (t[i + j] - '0' > p[j] - '0') {
                    flag=0;
                }
                break;                
            }
        }
        if (flag) {
            answer++;
        }
    }
    return answer;
}