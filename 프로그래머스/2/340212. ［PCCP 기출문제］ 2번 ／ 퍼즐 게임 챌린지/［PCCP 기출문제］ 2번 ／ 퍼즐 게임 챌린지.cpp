#include <string>
#include <vector>

using namespace std;

int check(int level, vector<int> diffs, vector<int> times, long long limit) {
    long long sum = 0;
    for(int i=0; i<diffs.size(); i++) {
        if (diffs[i] <= level) {
            sum += times[i];
        }
        else {
            if (i == 0) {
                sum += (diffs[i] - level) * (times[i]);
            }
            else {
                sum += (diffs[i] - level) * (times[i] + times[i - 1]) + times[i];
            }
        }
        if (sum > limit) {
            return 0;
        }
    }
    if (sum <= limit) {
        return 1;
    }
    else {
        return 0;
    }
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer;
    int lower = 1;
    int upper = 100000;
    
    int flag=1;
    while (true) {
        answer = (upper + lower) / 2;
        int flag = check(answer, diffs, times, limit);
        
        if (lower == upper - 1) {
            if (!flag) {
                answer = upper;    
            }
            break;
        }
        else {
            if (flag) {
                upper = (lower + upper) / 2;
            }
            else {
                lower = (lower + upper) / 2;
            }
        }
    }
    
    
    return answer;
}