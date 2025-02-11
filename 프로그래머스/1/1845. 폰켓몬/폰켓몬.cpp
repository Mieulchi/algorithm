#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
  
    map<int, int> m;
    for(int i = 0; i < nums.size(); i++) {
        if (m[nums[i]] == 0) {
            answer++;
            m[nums[i]]++;
        }
        if (answer >= nums.size() / 2) {
            break;
        }
    }
    
    return answer;
}