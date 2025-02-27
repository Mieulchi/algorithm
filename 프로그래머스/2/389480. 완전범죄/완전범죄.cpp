#include <string>
#include <vector>

using namespace std;

pair<int, int> dp[40][120];

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 121;
    
    if (info[0][1] < m) {
        dp[0][0] = { 1, info[0][1]};        
    }
    if (info[0][0] < n) {
        dp[0][info[0][0]] = {1, 0};
    }
    
    for(int i=1; i<info.size(); i++) {
        for(int j=0; j < 120; j++) {
            if (dp[i - 1][j].first == 1) {
                if (dp[i - 1][j].second + info[i][1] < m) {
                    if(!dp[i][j].second || dp[i][j].second > dp[i - 1][j].second + info[i][1] ) {
                        dp[i][j] = { 1, dp[i - 1][j].second + info[i][1] };
                    }
                }
                if (j + info[i][0] < n) {
                    if (!dp[i][j + info[i][0]].second || dp[i][j + info[i][0]].second > dp[i - 1][j].second) {
                        dp[i][j + info[i][0]] = { 1, dp[i - 1][j].second };
                    }
                }
            }
        }
    }
    for(int i = 0; i<120; i++) {
        if (dp[info.size() - 1][i].first == 1)  {
            answer = i;
            break;
        }
    }
    answer = answer == 121 ? -1 : answer;
    return answer;
}