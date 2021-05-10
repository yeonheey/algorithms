#include <cstdio>
#include <algorithm>

using namespace std;

int N, K;

int main() {
    scanf("%d\n%d", &N, &K);
    
    int num = -1;
    int left = 0, right = K;
    
    while(left <= right)
    {
        int mid = (left + right) / 2;
        int count = 0;
        
        for(int i = 1; i <= N; i++)
            count += min(mid / i, N);
        
        if(count < K)
            left = mid + 1;
        else
        {
            num = mid;
            right = mid - 1;
        }
    }
    
    printf("%d\n", num);
    
    return 0;
}