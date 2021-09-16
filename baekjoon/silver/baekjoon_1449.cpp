#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> loc;

int main() {
    int N, L;
    cin >> N >> L;

    for(int i = 0, leak; i < N; i++) {
        cin >> leak;
        loc.push_back(leak);
    }

    sort(loc.begin(), loc.end());

    int cnt = 1;
    int point = loc[0];
    for(int i = 1; i < N; i++) {
        if(loc[i] - point <= L - 1) continue;
        
        cnt++;
        point = loc[i];
    }

    cout << cnt << "\n";
    

    return 0;
}