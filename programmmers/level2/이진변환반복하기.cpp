#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while(s.size() > 1)
    {
        answer[0]++;
        
        int delCnt = 0, len = 0;
        for(char digit: s)
        {
            if(digit == '0') delCnt++;
            else len++;
        }
        
        answer[1] += delCnt;
        
        string tempS = "";
        while(len > 0)
        {
            tempS += to_string(len % 2);
            len /= 2;
        }
        
        s = tempS;
    }
    
    return answer;
}