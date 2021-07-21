#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 1001;
int N, maxVal = 0;
int maxValue[MAX] = {0, };
int cards[MAX][5];

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < 5; j++)
            cin >> cards[i][j];
    
    vector<bool> isSelected(5, false);
    for(int i = 0; i < 3; i++) 
        isSelected[4 - i] = true;
    
    do {
        for(int i = 0; i < N; i++) {
            int sum = 0;
            
            for(int j = 0; j < 5; j++) 
                if(isSelected[j])
                    sum += cards[i][j];
            
            sum %= 10;

            maxValue[i] = max(maxValue[i], sum);
            maxVal = max(maxValue[i], maxVal);
        }
    } while( next_permutation(isSelected.begin(), isSelected.end()) );
    
    for(int i = N - 1; i >= 0; i--)
        if(maxVal == maxValue[i]) {
            cout << i + 1 <<"\n";
            break;
        }
    
    return 0;
}