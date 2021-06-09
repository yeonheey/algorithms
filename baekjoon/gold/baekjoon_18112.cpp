#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

const int MAX = 1 << 10;

string origin, goal;
int Count = 0;
bool isVisited[1 << 11];

int stringToNumber(string str) {
    int value = 0, Size = str.size();

    for(int i = Size - 1; i >= 0; i--) 
        if(str[i] == '1')
            value += pow(2, Size - 1 - i);
    
    return value;
}

string numberToString(int num) {
    string binary = "";

    while(num > 0) {
        binary = to_string(num % 2) + binary;
        num = (num >> 1);
    }

    return binary;
}

int main () {
    cin >> origin >> goal;

    int goalNumber = stringToNumber(goal);
    int originNumber = stringToNumber(origin);

    queue<pair<int, int> > q;
    q.push( {originNumber, 0} );
    isVisited[originNumber] = true;

    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == goalNumber) {
            Count = cnt;
            break;
        }

        //보수
        string binaryStr = numberToString(cur);

        for(int i = 1; i < binaryStr.size(); i++) {
            string temp = binaryStr;

            if(binaryStr[i] == '0') 
                temp[i] = '1';
            else
                temp[i] = '0';

            int tempNum = stringToNumber(temp);
                
            if(tempNum >= MAX || isVisited[tempNum]) continue;

            isVisited[tempNum] = true;
            q.push( {tempNum, cnt + 1} );
        }

        //1 더하기
        if(cur < MAX && !isVisited[cur + 1]) {
            isVisited[cur + 1] = true;
            q.push( {cur + 1, cnt + 1} );
        }
        //1 빼기
        if(cur < MAX && cur > 0 && !isVisited[cur - 1]) {
            isVisited[cur - 1] = true;
            q.push( {cur - 1, cnt + 1} );
        }
    }

    cout << Count << "\n";

    return 0;
}