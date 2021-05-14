#include <string>
#include <stack>

using namespace std;

string solution(string new_id) {
    string recommand = "";
    
     //1,2
    for(int i = 0; i < new_id.size(); i++)
    {
        char ch = new_id[i];
        
        if(ch == '.' || ch == '-' || ch == '_')
            recommand += ch;
        else if(ch - '0' >= 0 && ch - '0' <= 9)
            recommand += ch;
        else if(ch >= 'a' && ch <= 'z')
            recommand += ch;
        else if(ch >= 'A' && ch <= 'Z') 
            recommand += (char)(ch + 32);
        else 
            continue;
    }
    
    //3, 4
    stack<char> stk;
    while(!recommand.empty())
    {
        char back = recommand.back(); recommand.pop_back();
        if(stk.empty())
        {
            if(back == '.') continue;
            
            stk.push(back);
        }
        else if(stk.top() == '.' && back == '.') continue;
        else  stk.push(back);
    }
    if(!stk.empty() && stk.top() == '.') stk.pop();
    
    //5
    if(stk.empty())
        for(int i = 0; i < 3; i++) stk.push('a');

    //6
    for(int i = 0; i < 15 && !stk.empty(); i++)
    {
        recommand += stk.top(); stk.pop();
    }
    if(recommand.back() == '.') recommand.pop_back();
    
    //7
    while(recommand.size() < 3)
        recommand += recommand.back();

    return recommand;
}