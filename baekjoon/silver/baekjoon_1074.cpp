#include <iostream>

using namespace std;

int N, R, C;
int answer = 0;

void findZ(int r, int c, int n) {
    if(R == r && C == c) {
        cout << answer << "\n";
        return;
    }

    if(R < r + n && R >= r && C < c + n && C >= c) {
        int half_n = n / 2;
        findZ(r, c, half_n);
        findZ(r, c + half_n, half_n);
        findZ(r + half_n, c, half_n);
        findZ(r + half_n, c + half_n, half_n);
    }
    else {
        answer += n * n;
    }
}

int main() {
    cin >> N >> R >> C;

    findZ(0, 0, (1 << N));
    
    return 0;
}