#include <vector>

using namespace std;

void check(const vector<int>& numbers, int idx, int sum, int target, int& answer) {
    if(numbers.size() == idx + 1) {
        if(sum == target) answer++;
        return;
    }
    
    check(numbers, idx + 1, sum + numbers[idx + 1], target, answer);
    check(numbers, idx + 1, sum - numbers[idx + 1], target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    check(numbers, 0, numbers[0], target, answer);
    check(numbers, 0, -numbers[0], target, answer);
    
    return answer;
}