#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    int size = s.size();
    vector<string> answer(size);
    
    for(int i = 0; i < size; i++) {
        stack<char> stk;
        int cnt = 0;
        
        //find all "110"
        for(int j = 0; j < s[i].size(); j++) {
            stk.push(s[i][j]);
            
            if(stk.size() >= 3) {
                char ch3 = stk.top(); stk.pop();
                char ch2 = stk.top(); stk.pop();
                char ch1 = stk.top(); stk.pop();
                
                if(ch1 == '1' && ch2 == '1' && ch3 == '0') {
                    cnt++;
                    continue;
                }
                
                stk.push(ch1);
                stk.push(ch2);
                stk.push(ch3);
            }
        }
        if(cnt == 0) {
            answer[i] = s[i];
            continue;
        }
        
        //insert "110"
        string result = "";
        int idx = stk.size();
        bool check = false;
        
        while(!stk.empty()) {
            if(stk.top() == '1' && check == false) idx--;
            else check = true;
            
            result = stk.top() + result; 
            stk.pop();
        }
        
        while(cnt-- > 0) 
            result.insert(idx, "110");
        
        answer[i] = result;
    }
    
    return answer;
}