class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int numSize = nums.size();
        vector<int> numbers = nums;
        
        sort(numbers.begin(), numbers.end());
        
        for(int i = 0; i < numSize; i++)
            if(numbers[i] == numbers[i + 1])
                return numbers[i];
        
        return -1;
    }
};