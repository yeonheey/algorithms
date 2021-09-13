#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    
    int five = N / 5;
    
    int minCount = 999999999;
    for(int i = 0; i <= five; i++) {
        int left = (N - 5 * i);

        if(left % 2 == 0) {
            int count = i + (left / 2);

            if(minCount > count) 
                minCount = count;
        }
    }
    
    if(minCount == 999999999) minCount = -1;

    cout << minCount << "\n";

    return 0;
}