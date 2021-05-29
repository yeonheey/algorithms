#include <vector>
#include <iostream>

using namespace std;

const int SIZE = 500001;

int N;
int count = 0;
vector<int> tree[SIZE];
bool isVisited[SIZE] = {false, };

void check(int node, int depth) {
    bool isLeaf = true;
    isVisited[node] = true;
    
    for(int child : tree[node]) {
        if(isVisited[child]) continue;
        
        isLeaf = false;
        check(child, depth + 1);
    }
    if(isLeaf) count += depth;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i = 1, a, b; i < N; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    check(1, 0);
    
    if(count % 2 == 1) cout << "Yes\n";
    else cout << "No\n";
    
    return 0;
}