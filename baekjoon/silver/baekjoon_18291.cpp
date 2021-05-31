#include <iostream>
using namespace std;
const int MOD = 1000000007;
int t;
long long N;
long long calculate(int digit, int n) {
    if(n == 0) return 1;
    
    long long result = calculate(digit, n / 2);
    result = (result * result) % MOD;
    
    if(n % 2 == 0) return result;
    
    return (result * digit) % MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    
    for(int test = 0; test < t; test++) {
        cin >> N;
        
        if(N == 1 || N == 2) cout << "1\n";
        else {
            N -= 2;
            cout << calculate(2, N) << "\n";
        }
    }
    
    return 0;
}