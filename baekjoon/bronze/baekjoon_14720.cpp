#include <iostream>

using namespace std;

int milk[1001];

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) cin >> milk[i];

    int maxDrink = 0;
    int turn = 0;
    for(int i = 0; i < N; i++) {
        if(turn == milk[i]) {
            turn = (turn + 1) % 3;
            maxDrink++;
        }
    }

    cout << maxDrink << "\n";

    return 0;
}