#include <stack>
#include <iostream>

using namespace std;

int main() {
    int K;
    cin >> K;

    stack<int> stk;
    for(int i = 0; i < K; i++) {
        int number;
        cin >> number;

        if(number == 0 && !stk.empty()) stk.pop();
        else stk.push(number);
    }

    int sum = 0;
    while (!stk.empty()) {
        sum += stk.top();
        stk.pop();
    }
    
    cout << sum << "\n";

    return 0;
}