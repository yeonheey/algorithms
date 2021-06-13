
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int numsSize = nums.size();
        vector<int> result(numsSize);
        
        vector<pair<int,int>> vec(numsSize);
        map<int, int> checkMap;
        
        for(int i = 0; i < numsSize; i++) {
            checkMap[nums[i]]++;
            vec[i] = {nums[i], i};
        }
        
        sort(vec.begin(), vec.end());
        
        for(int i = 0; i < numsSize; i++)
        {
            result[vec[i].second] = i;
            
            if(checkMap[vec[i].first] > 1) result 
        }
        
        return result;
    }
};