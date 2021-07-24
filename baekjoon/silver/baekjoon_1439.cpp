#include <string>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int one = 0, zero = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1]) continue;
        
        if(s[i - 1] == '1') one++;
        else zero++;
    }

    if(s.back() == '1') one++;
    else zero++;

    cout << min(one, zero) << "\n";

    return 0;
}