#include <iostream>

using namespace std;

const int Size = 9;
int arr[Size];

int main() {
    int idx, maxNum = -1;
    for(int i = 0; i < Size; i++) {
        cin >> arr[i];
        
        if(maxNum < arr[i]) {
            idx = i;
            maxNum = arr[i];
        }
    }
    
    cout << maxNum << "\n" << idx + 1 << "\n";
    
    return 0;
}