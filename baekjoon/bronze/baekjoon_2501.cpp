#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    int cnt = 0;
    for(int num = 1; num <= N; num++) {
        if(N % num == 0) cnt++;
        
        if(cnt == K) {
            cout << num << "\n";
            break;
        }
    }
    
    if(cnt < K) cout << "0\n";
    
    return 0;
}