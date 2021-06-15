class Solution {
public:
    int maxArea(vector<int>& height) {
        int amount = -1;
        int left = 0, right = height.size() - 1;
        
        while(left <= right) {
            int temp = (right - left) * min(height[left], height[right]);
            
            amount = max(amount, temp);
            if(height[left] < height[right]) left++;
            else right--;
        }
        
        return amount;
    }
};