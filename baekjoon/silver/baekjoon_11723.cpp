#include <string>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int M; cin >> M;

    long long Set = 0;
    
    string order; int number;
    while(M--) {
        cin >> order;

        if(order == "all") {
            Set = (1 << 21) - 1;
            continue;
        }
        else if(order == "empty") {
            Set = 0;
            continue;
        }

        cin >> number;
        if(order == "add") {
            Set |= (1 << number);
        }
        else if(order == "remove") {
            Set &= ~(1 << number);
        }
        else if(order == "check") {
           if(Set & (1 << number)) cout << "1\n";
           else cout << "0\n";
        }
        else if(order == "toggle") {
            Set ^= (1 << number);
        }
    }

    return 0;
}