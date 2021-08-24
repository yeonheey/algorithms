#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> stk;
    int result = 0, temp = 1;
    bool isPossible = true;

    for(int i = 0; i < str.size() && isPossible; i++) {
        char ch = str[i];

        if(ch == '(') {
            stk.push(ch);
            temp *= 2;
        }
        else if(ch == '[') {
            stk.push(ch);
            temp *= 3;
        }
        else if(ch == ')') {
            if(stk.empty() || stk.top() != '(')
                isPossible = false;
            else {
                if(str[i - 1] == '(')
                    result += temp;

                stk.pop();
                temp /= 2;
            }
        }
        else if(ch == ']') {
           if(stk.empty() || stk.top() != '[')
                isPossible = false;
            else {
                if(str[i - 1] == '[')
                    result += temp;

                stk.pop();
                temp /= 3;
            }
        }
    }

    if(!isPossible || !stk.empty())
        cout << "0\n";
    else 
        cout << result << "\n";
    
    return 0;
}