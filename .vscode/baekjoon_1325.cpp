#include <vector>
#include <queue>
#include <memory.h>
#include <iostream>

using namespace std;

const int SIZE = 10001;

vector<int> graph[SIZE];
vector<int> results;
bool isVisited[SIZE] = {false, };

int depthCnt = 0;

int check(int node) {
    if(isVisited[node]) return 0;
    
    isVisited[node] = true;
    
    int cnt = 1;
    for(int next: graph[node])
        cnt += check(next);
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        graph[b].push_back(a);
    }
    
    for(int i = 1; i <= N; i++) {
        memset(isVisited, false, sizeof(isVisited));
        int depth = check(i);

        if(depth == depthCnt)
            results.push_back(i);
        else if(depth > depthCnt) {
            results.clear();
            results.push_back(i);

            depthCnt = depth;
        }
    }

    for(int node: results)
        cout << node << " ";
    cout << "\n";
    
    return 0;
}