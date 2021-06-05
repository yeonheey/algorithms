#include <algorithm>
#include <iostream>

using namespace std;

const int SIZE = 500000;

int N, X;
int arr[SIZE];

long long gcd(long long a, long long b) {
    if(a % b == 0) return b;
    
    return gcd(b, a% b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    cin >> X;
    
    long long average = 0, cnt = 0;
    for(int i = 0; i < N; i++) {
        if(gcd(arr[i], X) == 1) {
            average += arr[i];
            cnt++;
        }
    }
    double result = (double) average / (double)cnt;
    cout << result <<"\n";
    
    return 0;
}