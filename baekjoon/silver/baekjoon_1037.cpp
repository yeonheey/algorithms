#include <algorithm>
#include <iostream>

using namespace std;

int divide[50];

int main() {
    int cnt; 
    cin >> cnt;

    for(int i = 0; i < cnt; i++) 
        cin >> divide[i];

    sort(divide, divide + cnt);

    cout << divide[0] * divide[cnt - 1] << "\n";

    return 0;
}