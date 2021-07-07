#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int L, C;
vector<char> alpha;
bool isVisited[16] = {false, };

bool isVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

void checkWord(string str, int idx, int cnt) {
    str += alpha[idx];

    if(cnt == L) {
        int vCnt = 0, cCnt = 0;
        
        for(char ch: str) {
            if(isVowel(ch)) vCnt++;
            else cCnt++;
        }

        if(vCnt >= 1 && cCnt >= 2) 
            cout << str << "\n";
        
        return;
    }

    for(int i = idx + 1; i < C; i++) 
        checkWord(str, i, cnt + 1);
}

int main() {
    cin >> L >> C;

    for(int i = 0; i < C; i++) {
        char ch;
        cin >> ch;
        alpha.push_back(ch);
    }

    sort(alpha.begin(), alpha.end());

    for(int i = 0; i <= C - L; i++) 
        checkWord("", i, 1);
    
    return 0;
}