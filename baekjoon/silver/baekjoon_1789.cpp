#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
    unordered_set<int> check;
    int S;
    cin >> S;

    int cnt = 0;
    int num = 1;
    long long sum = 0;

    while(true) {
        sum += num;
        
        if(sum > S) break;

        cnt++;
        num++;
    }

    cout << cnt << "\n";

    return 0;
}