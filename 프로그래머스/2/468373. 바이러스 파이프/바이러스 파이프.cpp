#include <string>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> pp;

int arr[10];
int N, K;
int start;
int ans;

vector<int> graph[101][3];
int visited[101];

void count() {
    for(int i = 1; i <= N; ++i) {
        visited[i] = 0;
    }
    
    visited[start] = 1;
    vector<int> v = {start};
    
    for(int i = 0; i < K; ++i) {
        int pipe = arr[i];
        
        queue<int> q;
        for(int j = 0; j < v.size(); ++j) {
            q.push(v[j]);
        }
        v.clear();
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            v.push_back(front);
            
            for(int j = 0; j < graph[front][pipe].size(); ++j) {
                int next = graph[front][pipe][j];
                if (!visited[next])  {
                    q.push(next);
                    visited[next] = 1;
                }
            }
        }
    }
    
    int size = v.size();
    
    
    ans = max(ans, size);
}

void dfs(int depth) {
    if (depth != K) {
        for(int i = 0; i < 3; ++i) {
            arr[depth] = i;
            dfs(depth + 1);
        }
    }
    else {
        count();
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    K = k;
    start = infection;
    N = n;
    
    for(int i = 0 ; i < edges.size(); ++i) {
        int a = edges[i][0]; 
        int b = edges[i][1];
        int c = edges[i][2] - 1;
        graph[a][c].push_back(b);
        graph[b][c].push_back(a);
    }
    
    for(int j = 0; j < 3; ++j) {
        arr[0] = j;
        dfs(1);
    }
    answer = ans;
    
    return answer;
}