#include <cstdio>
#include <string>

using namespace std;

int checkZero(int num) {
    int cnt = 0;
    string numStr = to_string(num);
    
    for(char ch: numStr)
        if(ch == '0') cnt++;
    
    return cnt;
}

int main() {
    int test;
    scanf("%d", &test);
    
    while(test-- > 0) {
        int n, m, count = 0;
        scanf("%d %d", &n, &m);
        
        for(int i = n; i <= m; i++)
            count += checkZero(i);
        
        printf("%d\n", count);
    }
    
    return 0;
}