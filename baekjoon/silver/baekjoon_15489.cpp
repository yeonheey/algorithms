#include <iostream>

using namespace std;

int R, C, W;
int triangle[30][30] = {0, };

int main() {
    cin >> R >> C >> W;

    for(int i = 0; i < 30; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;
    }
    
    for(int i = 2; i < 30; i++) {
        for(int j = 1; j < i; j++)
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
    }

    int sum = 0;
    for(int i = 0; i < W; i++) {
        int r = R + i - 1;
        
        for(int j = 0; j <= i; j++) {
            int c = C - 1 + j;
            sum += triangle[r][c];
        }
    }
    
    cout << sum <<"\n";
    
    return 0;
}