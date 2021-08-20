#include <string>
#include <iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    
    for(char& ch: str) {
        if(ch >= 'a' && ch <= 'z') {
            int step = ((ch - 'a') + 13) % 26;
            ch = 'a' + step;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            int step = ((ch - 'A') + 13) % 26;
            ch = 'A' + step;
        }
    }
    
    cout << str << "\n";
    
    return 0;
}