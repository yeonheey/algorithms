#include <string>
#include <iostream>

using namespace std;

int N;
int dict[26];
int answer = 0;

int allcheck = (1 << ('z' - 'a' + 1)) - 1;

void check(int alpha, int idx) {
    if(idx == N) {
        if(alpha == allcheck) answer++;
        
        return;
    }

    check(alpha, idx + 1); // idx 미포함
    check(alpha | dict[idx], idx + 1); // idx 포함
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        string word; cin >> word;

        int useAlpha = 0;
        for(char ch: word)
            useAlpha = useAlpha | (1 << (ch - 'a'));
        
        dict[i] = useAlpha;
    }

    check(0, 0);

    cout << answer << "\n";

    return 0;
}