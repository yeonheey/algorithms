#include <iostream>

using namespace std;

const int SIZE = 1001;

int N;
int arr[SIZE];
int dp1[SIZE];
int dp2[SIZE];

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];

    // 가장 긴 증가 부분 수열
    for(int i = 1; i <= N; i++) {
        dp1[i] = 1;

        for(int j = 1; j <= i; j++) 
            if(arr[j] < arr[i] && dp1[i] < dp1[j] + 1)
                dp1[i] = dp1[j] + 1;
    }

    // 감소 부분 수열
    for(int i = N; i > 0; i--) {
        dp2[i] = 1;

        for(int j = N; j >= i; j--) 
            if(arr[j] < arr[i] && dp2[i] < dp2[j] + 1)
                dp2[i] = dp2[j] + 1;
    }

    int len = 0;
    for(int i = 1; i <= N; i++) 
        if(len < dp1[i] + dp2[i] - 1)
            len = dp1[i] + dp2[i] - 1;

    cout << len << "\n";

    return 0;
}