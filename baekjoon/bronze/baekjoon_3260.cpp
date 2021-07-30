#include <iostream>

using namespace std;

const int MAXSIZE = 24;

int main() {
    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;

        for(int i = 0; i <= 24; i++) 
            if(N & (1 << i)) 
                cout << i << "\n";
    }
    
    return 0;
}