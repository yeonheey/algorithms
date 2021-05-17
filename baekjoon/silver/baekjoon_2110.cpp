#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> home;

int main() {
    scanf("%d %d", &N, &C);
    
    for(int i = 0, loc; i < N; i++) {
        scanf("%d", &loc);
        home.push_back(loc);
    }
    
    sort(home.begin(), home.end());
    
    int maxDist = 0;
    int start = 1, end = home[N - 1] - home[0];
    
    while (start <= end) {
        int mid = (start + end) / 2;
        int cnt = 1, base = home[0];
        
        for (int i = 0; i < N; i++) {
            if (home[i] - base >= mid) {
                cnt++;
                base = home[i];
            }
        }
        
        if(cnt >= C) {
            maxDist = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    
    printf("%d\n", maxDist);
    
    return 0;
}