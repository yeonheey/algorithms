#include <stack>
#include<string>

using namespace std;

int solution(string s)
{
    int size = s.size();
    int answer = 0;

    stack<char> stk;
    
    int idx = 0;
    while(idx < size)
    {
        if(stk.empty() || stk.top() != s[idx]) 
            stk.push(s[idx]);
        else
            stk.pop();
        
        idx++;
    }
   
    if(stk.empty()) answer = 1;
    
    return answer;
}