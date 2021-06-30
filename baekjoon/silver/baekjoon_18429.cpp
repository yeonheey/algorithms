#include <memory.h>
#include <iostream>

using namespace std;

const int WEIGHT = 500;

int N, K, result = 0;
int kit[8];
bool isVisited[8];

void check(int idx, int cnt, int weight) {
    if(isVisited[idx]) return;

    weight = weight - K + kit[idx];
    if(weight < WEIGHT) return;
    
    if(cnt == N) {
        result++; return;
    }

    isVisited[idx] = true;
    for(int i = 0; i < N; i++)
        check(i, cnt + 1, weight);

    isVisited[idx] = false;
}

int main() {
    cin >> N >> K;

    for(int i = 0; i < N; i++)
        cin >> kit[i];
    
    memset(isVisited, false, sizeof(isVisited));

    for(int i = 0; i < N; i++) 
        check(i, 1, WEIGHT);

    cout << result << "\n";

    return 0;
}