#include <stack>
#include <memory.h>
#include <iostream>

using namespace std;

int arr[1000001];
int result[1000001];

int main() {
    memset(result, -1, sizeof(result));

    int N;
    cin >> N;
    for(int i = 0; i < N; i++) 
        cin >> arr[i];

    stack<int> stk;

    for(int i = 0; i < N; i++) {
        if(stk.empty() || arr[stk.top()] > arr[i]) stk.push(i);
        else {
            while(!stk.empty() && arr[stk.top()] < arr[i]) {
                result[stk.top()] = arr[i];
                stk.pop();
            }

            stk.push(i);
        }
    }

    for(int i = 0; i < N; i++) 
        cout << result[i] <<" ";

    return 0;
}