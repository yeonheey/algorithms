#include <stack>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, height;
    cin >> N;
    
    stack<pair<int, int> > stk; // idx, height
    for(int i = 0; i < N; i++) {
        cin >> height;
        
        while(!stk.empty() && stk.top().second < height) 
            stk.pop();
        
        if(stk.empty()) 
            cout << 0 << " ";
        else 
            cout << stk.top().first << " ";

        stk.push({i + 1, height});
    }

    return 0;
}