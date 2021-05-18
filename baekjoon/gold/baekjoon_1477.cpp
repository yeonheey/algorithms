#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, l;
vector<int> dist;

int main() {
    scanf("%d %d %d", &n, &m, &l);
    
    dist.push_back(0);
    dist.push_back(l);
    
    for (int i = 0, temp; i < n; i++) {
        scanf("%d", &temp);
        dist.push_back(temp);
    }
    
    sort(dist.begin(), dist.end());
    
    int answer = 0;
    int left = 1, right = l - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        
        int cnt = 0;
        for (int i = 1; i < dist.size(); i++) {
            int between = dist[i] - dist[i - 1];
            cnt += (between / mid);
            
            if(between % mid == 0) 
                cnt--;
        }
        if(cnt > m)
            left = mid + 1;
        else {
            right = mid - 1;
            answer = mid;
        }
    }
    
    printf("%d\n", answer);
    
    return 0;
}