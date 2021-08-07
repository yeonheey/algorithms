#include <string>
#include <iostream>

using namespace std;

int main() {
    int N; 
    cin >> N;
    
    while(N--) {
        string problem;
        cin >> problem;
        
        int score = 0;
        int tempScore = 0;
        for(char ch: problem) {
            if(ch == 'X')
                tempScore = 0;
            else
                score += ++tempScore;
        }
        
        cout << score << "\n";
    }
    
    return 0;
}