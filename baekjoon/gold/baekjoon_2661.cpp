#include <cstdio>
#include <string>

using namespace std;

int n;
char digits[3] = {'1', '2', '3'};
string answer;
bool isFound = false;

bool isGood(string str) {
    int size = str.size();
    
    for(int len = 1; len <= (size / 2); len++)
        if(str.substr(size - len, len) == str.substr(size - len * 2, len))
            return false;
    return true;
}

void goodSeq(int cnt, string number) {
    if(isFound) return;

    if(!isGood(number)) return;

    if(cnt == n) {
        answer = number;
        isFound = true;
        return;
    }
    
    for(int i = 0; i < 3; i++) {
        string next = number + digits[i];
        goodSeq(cnt + 1, next);
    }
}

int main() {
    scanf("%d", &n);
    
    goodSeq(0, "");
    
    printf("%s\n", answer.c_str());
    
    return 0;
}