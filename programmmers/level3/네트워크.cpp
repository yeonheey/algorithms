#include <string>
#include <vector>

using namespace std;

int dfs(vector<bool>& isVisited, const vector<vector<int>>& computers, int idx) {
    if (isVisited[idx]) return 0;
    
    isVisited[idx] = true;

    for(int i = 0; i < computers[idx].size(); i++) {
        if(i == idx || computers[idx][i] == 0) continue;
        
        dfs(isVisited, computers, i);
    }
    
    return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> isVisited(n, false);
    
    for(int i = 0; i < n; i++) 
        answer += dfs(isVisited, computers, i);
    
    return answer;
}