#include <iostream>

using namespace std;

double arr[1001];

int main() {
    int N;
    cin >> N;
    
    double maxScore = -1;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];

        if(arr[i] > maxScore)
            maxScore = arr[i];
    }
    
    double avgScore = 0;
    for(int i = 0 ; i < N; i++) {
        arr[i] = (arr[i] / maxScore) * 100;
        avgScore += arr[i];
    }
    
    cout << avgScore / N << "\n";
    
    return 0;
}