#include <cstdio>

int n, k, answer = 0;
int digits[4];

void find(int num) {
    if(num > n) return;
    if(answer < num) answer = num;
    
    for(int i = 0; i < k; i++)
        find(num * 10 + digits[i]);
}

int main() {
    scanf("%d %d", &n, &k);
    
    for(int i = 0; i < k; i++)
        scanf("%d", &digits[i]);
    
    find(0);
    
    printf("%d\n", answer);
    
    return 0;
}