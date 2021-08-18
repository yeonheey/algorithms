#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;

int scv[3] = {0, };
int power[61][61][61];

int check(int a, int b, int c) {
    if(a < 0) return check(0, b, c);
    if(b < 0) return check(a, 0, c);
    if(c < 0) return check(a, b, 0);
    
    if(a == 0 && b == 0 && c == 0)
        return 0;
    
    int& value = power[a][b][c];
    
    if(value != -1) return value;
    
    value = 999999999;
    value = min(check(a - 9, b - 3, c - 1) + 1, value);
    value = min(check(a - 9, b - 1, c - 3) + 1, value);
    value = min(check(a - 3, b - 9, c - 1) + 1, value);
    value = min(check(a - 1, b - 9, c - 3) + 1, value);
    value = min(check(a - 1, b - 3, c - 9) + 1, value);
    value = min(check(a - 3, b - 1, c - 9) + 1, value);
    
    return value;
}

int main() {
    int N;    
    cin >> N;
    
    for(int i = 0; i < N; i++) 
        cin >> scv[i];
    
    memset(power, -1, sizeof(power));
    cout << check(scv[0], scv[1], scv[2]) << "\n";
    
    return 0;
}