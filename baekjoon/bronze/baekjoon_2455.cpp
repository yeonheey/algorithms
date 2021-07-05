#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int maxCount = 0, tempCount = 0;

    for(int i = 0; i < 4; i++) {
        int out, in;
        cin >> out >> in;

        tempCount = tempCount - out + in;
        maxCount = max(maxCount, tempCount);
    }

    cout << maxCount << "\n";

    return 0;
}