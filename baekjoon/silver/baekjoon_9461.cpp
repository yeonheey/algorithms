#include <iostream>

using namespace std;

int N;

long long waveArray() {
    if(N >= 1 && N <= 3) return 1;
    
    long long len[101];    
    len[1] = 1, len[2] = 1, len[3] = 1;
    
    for(int i = 4; i <= N; i++) 
        len[i] = len[i - 2] + len[i - 3];
    
    return len[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T-- > 0) {
        cin >> N;
        
        cout << waveArray() <<"\n";
    }
    
    return 0;
}