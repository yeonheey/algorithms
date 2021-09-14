#include <unordered_map>
#include <iostream>

using namespace std;

int check[500000];

int main() {
    int N, M;
    unordered_map<int, int> have;
    cin >> N; 

    for(int i = 0, number; i < N; i++) {
        cin >> number;
        have[number]++;
    }

    cin >> M;
    for(int i = 0; i < M; i++) 
        cin >> check[i];

    for(int i = 0; i < M; i++) 
        cout << have[check[i]] << " ";
    
    cout << "\n";

    return 0;
}