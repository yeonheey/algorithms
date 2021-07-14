#include <queue>
#include <string>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int K, Size;
string number;

int stringToInt(string str) {
    int num = 0;

    for(int i = 0; i < str.size(); i++) {
        num *= 10;
        num += (str[i] - '0');
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> number >> K;
    Size = number.size();

    if(Size == 1 || (Size == 2 && stringToInt(number) % 10 == 0)) {
        cout <<"-1\n"; return 0;
    }

    int maxValue = -1, curK = 0;

    queue<string> q;
    q.push(number);

    while (!q.empty() && curK < K) {
        int qSize = q.size();
        set<string> visited;

        while(qSize-- > 0) {
            string cur = q.front(); q.pop();

            for(int i = 0; i < Size - 1; i++) 
                for(int j = i + 1; j < Size; j++) {
                    if(i == 0 && cur[j] == '0') continue;

                    swap(cur[i], cur[j]);

                    if(visited.count(cur) == 0) {
                        if(curK == K - 1)
                            maxValue = max(maxValue, stringToInt(cur));
                        
                        q.push(cur);
                        visited.insert(cur);
                    }

                    swap(cur[i], cur[j]);
                }
        }
        curK++;
    }
    
    if(curK != K) cout << "-1\n";
    else cout << maxValue << "\n";

    return 0;
}