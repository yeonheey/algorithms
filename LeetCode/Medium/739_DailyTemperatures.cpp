//Stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int tempSize = temperatures.size();
        
        vector<int> answer(tempSize, 0);
        
        stack<int> stk; //index
        
        for(int i = 0; i < tempSize; i++) {
            while(!stk.empty()) {
                if(temperatures[i] <= temperatures[stk.top()]) 
                    break;
                
                answer[stk.top()] = i - stk.top();
                stk.pop();
            }
            
            stk.push(i);
        }
        
        return answer;
    }
};

//DP
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int tempSize = temperatures.size();
        
        vector<int> answer(tempSize, 0);
        
        for(int i = tempSize - 1; i >= 0; i--) {
            int j = i + 1;
            
            while(j < tempSize) {
                if(temperatures[j] > temperatures[i]) {
                    answer[i] = j - i;
                    break;
                }
                else if(answer[j] == 0) break;
                
                j += answer[j];
            }
        }
        
        return answer;
    }
};