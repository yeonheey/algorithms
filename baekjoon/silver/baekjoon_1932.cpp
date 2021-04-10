#include <cstdio>
#include <cmath>

using namespace std;

int triangle[501][501];
int check[501][501];

int main() {
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            scanf("%d", &triangle[i][j]);
    
    //삼각형의 맨 밑
    for(int i = 1; i <= n; i++)
        check[n][i] = triangle[n][i];
    
    for(int i = n - 1; i > 0; i--)
        for(int j = 1; j <= i; j++)
            check[i][j] = triangle[i][j] + max(check[i + 1][j], check[i + 1][j + 1]);
    
    printf("%d\n", check[1][1]);
    
    return 0;
}