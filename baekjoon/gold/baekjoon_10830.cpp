#include <memory.h>
#include <iostream>

using namespace std;

const int SIZE = 5;
const int MOD = 1000;

int N;
int arr[SIZE][SIZE];
int result[SIZE][SIZE];

void calculate(int A[SIZE][SIZE], int B[SIZE][SIZE]) {
    int temp[SIZE][SIZE];

    for (int r = 0; r < N; r++)
        for(int c = 0; c < N; c++) {
            temp[r][c] = 0;

            for(int k = 0; k < N; k++)
                temp[r][c] += (A[r][k] * B[k][c]);
            
            temp[r][c] %= MOD;
        }
    
    for (int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            A[r][c] = temp[r][c];
}

int main() {
    long long B;
    cin >> N >> B;

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++)
            cin >> arr[r][c];
        
        result[r][r] = 1; // 단위행렬
    }
    
    while (B > 0) {
        if(B % 2 == 1)
            calculate(result, arr);
        
        calculate(arr, arr);
        B /= 2;
    }
    
    for (int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) 
            cout << result[r][c] << " ";
        cout << "\n";
    }
    
    return 0;
}