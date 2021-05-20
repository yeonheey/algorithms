#include <cstdio>
#include <queue>
#include <unordered_set>

using namespace std;

int n, k;
int d[2] = {-1, 1};

int main() {
    scanf("%d %d", &n, &k);
    
    queue<pair<int, int>> q;
    unordered_set<int> loc;
    
    for(int i = 0, temp; i < n; i++) {
        scanf("%d", &temp);
        q.push({temp, 0}); //present, dist
        
        loc.insert(temp);
    }
    
    long long amount = 0;
    while(!q.empty() && k > 0) {
        int x = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        for(int i = 0; i < 2; i++) {
            int nx = x + d[i];
            int nDist = dist + 1;
            
            if(loc.count(nx) > 0 || k <= 0) continue;
            
            k--;
            amount += (long long)nDist;
            
            loc.insert(nx);
            q.push({nx, nDist});
        }
    }
    
    printf("%lld\n", amount);
    
    return 0;
}