#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

int test;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> test;
    
    for(int t = 0; t < test; t++) {
        stack<char> oper;
        stack<char> result;
        string line;
        cin >> line;
        
        for(char ch: line) {
            if(ch == '<') {
                if(result.empty()) continue;

                oper.push(result.top());
                result.pop();
            }
            else if(ch == '>') {
                if(oper.empty()) continue;

                result.push(oper.top());
                oper.pop();
            }
            else if(ch == '-') {
                if(result.empty()) continue;
                result.pop();
            }
            else
                result.push(ch);
        }

        line = "";
        while (!oper.empty()) {
            result.push(oper.top());
            oper.pop();
        }
        
        while (!result.empty()) {
            line += result.top();
            result.pop();
        }
        
        reverse(line.begin(), line.end());

        cout<< line <<"\n";
    }
    
    return 0;
}