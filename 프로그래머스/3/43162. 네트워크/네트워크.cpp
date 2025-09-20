#include <string>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    int visited[200]={0};
    
    for(int i=0;i<n;i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int size = q.size();
                while(size--) {
                    int front = q.front();
                    q.pop();
                    if(!visited[front]) {
                        visited[front]=1;
                        for(int j=0;j<computers[front].size();j++) {
                            if (computers[front][j] && !visited[j]) {
                                q.push(j);
                            }
                        }
                    }
                }
            }
            answer++;
        }
    }
    
    return answer;
}