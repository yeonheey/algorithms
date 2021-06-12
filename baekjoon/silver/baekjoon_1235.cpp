#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

int N;
string id[1000];

int findMinLength() {
    int len = id[0].size();

    for(int k = 1; k < len; k++) {
        bool isPossible = true;
        unordered_set<string> checkId;

        for(int i = 0; i < N; i++) {
            if(checkId.end() == checkId.find(id[i].substr(len - k, k)))
                checkId.insert(id[i].substr(len - k, k));
            else {
                isPossible = false;
                break;
            }
        }

        if(isPossible) 
            return k;
    }

    return len;
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) 
        cin >> id[i];

    cout << findMinLength() <<"\n";

    return 0;
}