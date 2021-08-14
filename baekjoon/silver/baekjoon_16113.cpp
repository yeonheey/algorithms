#include <string>
#include <iostream>

using namespace std;

char arr[5][20001];
char digits[10][5][3] = {
    { {'#', '#', '#'}, {'#', '.', '#'}, {'#', '.', '#'}, {'#', '.', '#'}, {'#', '#', '#'} }, 
    { {'.'},{'.'}, {'.'}, {'.'}, {'.'}, },
    { {'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'}, {'#', '.', '.'}, {'#', '#', '#'} }, 
    { {'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'} }, 
    { {'#', '.', '#'}, {'#', '.', '#'}, {'#', '#', '#'}, {'.', '.', '#'}, {'.', '.', '#'} },
    { {'#', '#', '#'}, {'#', '.', '.'}, {'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'} }, 
    { {'#', '#', '#'}, {'#', '.', '.'}, {'#', '#', '#'}, {'#', '.', '#'}, {'#', '#', '#'} }, 
    { {'#', '#', '#'}, {'.', '.', '#'}, {'.', '.', '#'}, {'.', '.', '#'}, {'.', '.', '#'} },
    { {'#', '#', '#'}, {'#', '.', '#'}, {'#', '#', '#'}, {'#', '.', '#'}, {'#', '#', '#'} },
    { {'#', '#', '#'}, {'#', '.', '#'}, {'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'} }, 
};

bool isOne(int col) {
    for(int i = 0; i < 5; i++)
        if(arr[i][col] == '.') 
            return false;

    return true;
}

int findDigit(int col) {
    for(int j = 0; j < 10; j++) {
        if(j == 1) continue;

        bool isPossible = true;
        for(int r = 0; r < 5; r++)
            for(int c = 0; c < 3; c++) 
                if(arr[r][col + c] != digits[j][r][c]) {
                    isPossible = false;
                    break;
                }
        
        if(isPossible) return j;
    }

    return -1;
}

int main() {
    int N;
    string str;
    cin >> N >> str;
    
    int colSize = N / 5;

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < colSize; j++) 
            arr[i][j] = str[colSize * i + j];
    
    str = "";
    for(int i = 0; i < colSize;) {
        if(arr[0][i] == '#') {
            int digit = findDigit(i);

            if(digit == -1) {
                str += '1';
                i += 2;
            }
            else {
                str += (digit + '0');
                i+= 4;
            }
        }
        else {
            i++;
        }
    }

    cout << str << "\n";

    return 0;
}