#include <vector>
#include <memory.h>
#include <iostream>

using namespace std;

int N, M;
vector<int> edges[2001];
bool isVisited[2001];

bool isPossible = false;

void check(int cur, int cnt) {
    if(cnt > 5 || isPossible) return;

    if(cnt == 5) {
        isPossible = true;
        return;
    }
    
    for(int next: edges[cur]) {
        if(isVisited[next]) continue;

        isVisited[next] = true;
        check(next, cnt + 1);
        isVisited[next] = false;
    }
}

int main() {
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(int i = 0; i < N; i++) {
        isVisited[i] = true;
        check(i, 1);
        isVisited[i] = false;

        if(isPossible) break;
    }

    cout << isPossible << "\n";

    return 0;
}