#include <vector>
#include <iostream>

using namespace std;

int n;
int arr[101];
vector<int> selectNumber;

void dfs(int start, int current, vector<bool>& isVisited) {
    if(isVisited[current]) {
        if(start == current)
            selectNumber.push_back(start);
    }
    else {
        isVisited[current] = true;
        dfs(start, arr[current], isVisited);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    for(int i = 1; i <= n; i++) {
        vector<bool> isVisited(n + 1, false);
        dfs(i, i, isVisited);
    }
    
    cout << selectNumber.size()<<"\n";
    for(int number: selectNumber)
        cout << number << "\n";
    
    return 0;
}