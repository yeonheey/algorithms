#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int arr[8];
int result[8];

void dfs(int depth) {
    if(depth == M) {
        for(int i = 0; i < M; i++)
            cout << result[i] <<" ";
            
        cout << "\n";
        return;
    }

    for(int i = 0; i < N; i++) {
        result[depth] = arr[i];
        dfs(depth + 1);
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) 
        cin >> arr[i];
    
    sort(arr, arr + N, less<int>());

    dfs(0);

    return 0;
}