#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    unordered_map<string ,int> checkGem;
    
    set<string> gemType;
    
    for(string gem: gems)  gemType.insert(gem);
    
    int gemCount = gemType.size();
    int gemsSize = gems.size();
    
    answer[0] = 0, answer[1] = gems.size() - 1;
    int start = 0, end = 0;
    
    checkGem[gems[0]]++;
    
    while(start <= end)
    {
        if(checkGem.size() == gemCount)
        {
            //update shorter len
            if(answer[1] - answer[0] > end - start)
            {
                answer[0] = start;
                answer[1] = end;
            }
            
            if(start == end) break; //there is no jewels to count
            
            checkGem[gems[start]]--;
            if(checkGem[gems[start]] == 0) checkGem.erase(gems[start]);
            
            start++;
        }
        else
        {
            if(end + 1 >= gemsSize) break;
            
            checkGem[gems[++end]]++;
        }
    }
    
    answer[0]++, answer[1]++;
    
    return answer;
}