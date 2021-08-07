#include <set>
#include <iostream>

using namespace std;

const int MOD = 42;

int main() {
    set<int> remain;
    
    for(int i = 0; i < 10; i++) {
        int number;
        cin >> number;
        
        remain.insert(number % MOD);
    }
    
    cout << remain.size() << "\n";
    
    return 0;
}