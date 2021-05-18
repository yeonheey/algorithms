#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m;
vector<long long> height;

int main() {
    scanf("%d %d", &n, &m);
    
    for(int i = 0, temp; i < n; i++) {
        scanf("%d", &temp);
        height.push_back(temp);
    }
    
    sort(height.begin(), height.end());
    
    int left = 0, right = height[n - 1];
    int cutterHeight = 0;
    
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        
        long long total = 0;
        for(int i = 0; i < height.size(); i++) {
            if(height[i] <= mid) continue;
            
            total += (height[i] - mid);
        }
        
        if(total >= m) {
            left = mid + 1;
            cutterHeight = mid;
        }
        else 
            right = mid - 1;
    }
    
    printf("%d\n", cutterHeight);
    
    return 0;
}