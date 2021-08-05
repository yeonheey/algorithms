#include <string>
#include <stack>
#include <iostream>

using namespace std;

string word;
int order_count;

int main() {
    getline(cin, word);
    cin >> order_count;

    stack<char> left, right;
    for(char ch: word) left.push(ch);

    for(int i = 0; i < order_count; i++) {
        char order; cin >> order;
        
        if(order == 'L') {
            if (left.empty()) continue;

            right.push(left.top());
            left.pop();
        }
        else if(order == 'D') {
            if (right.empty()) continue;

            left.push(right.top());
            right.pop();
        }
        else if(order == 'B') {
            if(left.empty()) continue;
            
            left.pop();
        }
        else if(order == 'P') {
            char character; cin >> character;
            left.push(character);
        }
    }

    word = "";
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    
    while (!right.empty()) {
        word += right.top();
        right.pop();
    }
    
    cout << word << "\n";

    return 0;
}