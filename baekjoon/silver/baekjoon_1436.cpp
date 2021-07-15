#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int result = 665;
    int cnt = 0;

    while(cnt < N) {
        result++;

        int temp = result;
        while(temp > 0) {
            if(temp % 1000 == 666) {
                cnt++; break;
            }

            temp /= 10;
        }
    }

    cout << result << endl;

    return 0;
}