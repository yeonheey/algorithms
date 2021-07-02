#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int N, K;
string word[50];
bool alpha[26] = {false, };

int result = -1;

void check_words() {
    int cnt = 0;
    
    for(int i = 0; i < N; i++) {
        bool flag = true;

        for(char ch: word[i]) {
            if(alpha[ch - 'a'] == false) {
                flag = false;
                break;
            }
        }

        if(flag) cnt++;
    }

    result = max(result, cnt);
}

void dfs(int idx, int cnt) {
    if(cnt == K) {
        check_words();
        return;
    }

    for(int i = idx; i < 26; i++) {
        if(alpha[i]) continue;

        alpha[i] = true;
        dfs(i, cnt + 1);
        alpha[i] = false;
    }
}

int main() {
    cin >> N >> K;

    for(int i = 0; i < N; i++) 
        cin >> word[i];

    if(K < 5) {
        cout << "0\n";
        return 0;
    }

    alpha['a' - 'a'] = true;
    alpha['c' - 'a'] = true;
    alpha['t' - 'a'] = true;
    alpha['i' - 'a'] = true;
    alpha['n' - 'a'] = true;

    K -= 5;

    dfs(0, 0);
    
    cout << result <<"\n";

    return 0;
}