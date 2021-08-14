#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXSIZE = 1001;

int len[MAXSIZE][MAXSIZE];

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int size1 = str1.size();
    int size2 = str2.size();

    for(int i = 1; i <= size1; i++) 
        for(int j = 1; j <= size2; j++) {
            if(str1[i - 1] == str2[j - 1]) 
                len[i][j] = len[i - 1][j - 1] + 1;
            else 
                len[i][j] = max(len[i - 1][j], len[i][j - 1]);
        }
    
    cout << len[size1][size2] << "\n";

    return 0;
}