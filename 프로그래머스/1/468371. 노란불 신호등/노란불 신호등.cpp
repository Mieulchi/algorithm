#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> signals) {
    int answer = 0;
    
    int n = signals.size();
    
    int t = 0;
    
    int sum[5] = {};
    for(int i = 0;i < n; ++i) {
        sum[i] = signals[i][0] + signals[i][1] + signals[i][2];
    }
    
    while (t <= 10000000) {
        
        int flag = 1;
        for(int i = 0 ; i < n; ++i) {
            int mod = (t - signals[i][0]) % sum[i];
            if (mod >= 1 && mod < 1 + signals[i][1]) {
                continue;
            }
            flag=0;
            break;
        }
        if (flag) {
            answer = t;
            break;
        }
        
        ++t;
    }
    
    if (!answer){
        answer = -1;
    }
    
    return answer;
}