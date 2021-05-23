#include <cstdio>
#include <queue>

using namespace std;

int n;

int main() {
    
    scanf("%d", &n);
    
    queue<int> q;
    
    for(int i = 1; i <= n; i++) q.push(i);
    
    while(q.size() > 1) {
        q.pop();
        
        int front = q.front();
        q.push(front);
        q.pop();
    }
    
    printf("%d\n", q.front());
    
    return 0;
}