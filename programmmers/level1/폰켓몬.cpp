#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    set<int> monster;
    
    for(int num: nums) 
        monster.insert(num);
    
    if(nums.size() / 2 < monster.size())
        return nums.size() / 2;
    
    else 
        return monster.size();
}