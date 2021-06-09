#include <string>
#include <cmath>
#include <iostream>

using namespace std;

string binary, answer = "";

int calculate(string str) {
    int value = 0;

    for(int i = 0; i < str.size(); i++)
        value += (pow(2, str.size() - 1 - i) * (str[i] - '0'));

    return value;
}

int main() {
    cin >> binary;

    int bSize = binary.size();

    if(bSize < 3) {
        cout << calculate(binary) <<"\n";
        return 0;
    }

    if(bSize % 3 == 1)
        binary = "00" + binary;
    else if(bSize % 3 == 2)
        binary = "0" + binary;

    bSize = binary.size();
    for(int i = 0; i < bSize; i+= 3) {
        string num = binary.substr(i, 3);
        answer += to_string(calculate(num));
    }
    
    cout <<answer <<"\n";

    return 0;
}