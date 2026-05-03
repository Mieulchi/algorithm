#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//종류, 배열 인덱스
unordered_map<string, int> um;
int idx;
int arr[30];

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int n = clothes.size();
    
    for (int i = 0; i < n; ++i) {
        
        //이미 있는 종류
        if (um.find(clothes[i][1]) != um.end()) {
            arr[um[clothes[i][1]]]++;
        }
        else {
            um[clothes[i][1]] = idx;
            arr[idx]++;
            idx++;
        }
    }
    
    for(int i = 0; i < idx; ++i) {
        answer *= arr[i] + 1;
    }
    answer--;
    
    
    return answer;
}