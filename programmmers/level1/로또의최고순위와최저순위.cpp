#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2, 0);
    
    set<int> winNumSet;
    for(int num: win_nums)
        winNumSet.insert(num);
    
    int leastWin = 0, zero = 0;
    for(int lotto: lottos) {
        if(lotto == 0) zero++;
        else {
            if(winNumSet.find(lotto) == winNumSet.end()) continue;
            
            leastWin++;
        }
    }
    
    answer[0] = 6 - leastWin - zero + 1;
    answer[1] = 6 - leastWin + 1;
    
    for(int i = 0; i < 2; i++)
        if(answer[i] > 6) answer[i] = 6;
    
    return answer;
}