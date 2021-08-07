#include <string>
#include <iostream>

using namespace std;

bool isPossible(string number) {
    int diff = number[0] - number[1];
    
    for(int i = 2; i < number.size(); i++) 
        if(number[i - 1] - number[i] != diff)
            return false;
    
    return true;
}

int main() {
    int N;
    cin >> N;
    
    int cnt = 0;
    for(int num = 1; num <= N; num++) {
        string number = to_string(num);
        
        if(number.size() < 3) cnt++;
        else if(isPossible(number)) cnt++;
    }
    
    cout << cnt << "\n";
    
    return 0;
}