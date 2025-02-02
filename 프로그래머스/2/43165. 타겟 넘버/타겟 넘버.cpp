#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int n = 1 << numbers.size();
    
    for (int i = 1; i < n; i++) {
        int sum = 0;
        for(int j = numbers.size() - 1; j >= 0; j--) {
            if ((i >> j) & 1) {
                sum += numbers[j];
            } 
            else {
                sum -= numbers[j];
            }
        }
        
        if (sum == target) {
            answer++;
        }
    }
    
    return answer;
}