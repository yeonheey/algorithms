#include <stack>
#include <vector>
#include <iostream>

using namespace std;

const int SIZE = 100001;

int N;
int arr[SIZE];
vector<char> result;

int main() {
    cin >> N;
    
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    
    stack<int> stk;

    int idx = 1;
    for(int i = 1; i <= N; i++) {
        stk.push(i);
        result.push_back('+');

        while (!stk.empty()) {
            if(stk.top() != arr[idx]) break;

            stk.pop();
            result.push_back('-');
            idx++;
        }
    }

    if(stk.empty())
        for(int i = 0; i < result.size(); i++)
            cout << result[i] <<"\n";
    else
        cout << "NO\n";

    return 0;
}
