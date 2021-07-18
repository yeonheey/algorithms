#include <string>
#include <stack>

using namespace std;

bool isRightString(string s) {
    stack<char> stk;
    
    for(char ch: s) {
        if(stk.empty()) {
            if(ch == ')' || ch == '}' || ch == ']') return false;
            
            stk.push(ch);
        }
        else {
            char top = stk.top();
            
            if(top == '(' && ch == ')') stk.pop();
            else if(top == '{' && ch == '}') stk.pop();
            else if(top == '[' && ch == ']') stk.pop();
            else stk.push(ch);
        }
    }
    
    if(stk.empty()) return true;
    
    return false;
}

int solution(string s) {
    int answer = 0;
    int sSize = s.size();
    
    for(int i = 0; i < sSize; i++) {
        string str = s.substr(i) + s.substr(0, i);
        
        if(isRightString(str)) answer++;
    }
    
    return answer;
}