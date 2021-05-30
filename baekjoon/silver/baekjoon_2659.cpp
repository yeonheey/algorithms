#include <algorithm>
#include <iostream>

using namespace std;

int arr[4];
int minNum = 0;
int isVisited[10000];

int getClockNumber(int a, int b, int c, int d) {
    int min1 = 1000 * a + 100 * b + 10 * c + d;
    int min2 = 1000 * b + 100 * c + 10 * d + a;
    int min3 = 1000 * c + 100 * d + 10 * a + b;
    int min4 = 1000 * d + 100 * a + 10 * b + c;
    
    return min( {min1, min2, min3, min4} );
}

int main() {
    for(int i = 0; i < 4; i++)
        cin >> arr[i];

    minNum = getClockNumber(arr[0], arr[1], arr[2], arr[3]);
    
    for(int i = 1; i < 10; i++)
        for(int j = 1; j < 10; j++)
            for(int k = 1; k < 10; k++)
                for(int l = 1; l <10; l++) {
                    int clockNumber = getClockNumber(i, j, k, l);
                    if(isVisited[clockNumber]) continue;
                    
                    isVisited[clockNumber] = true;
                }
    
    int count = 0;
    for(int num = 1111; num <= minNum; num++) 
        if(isVisited[num]) count++;
    
    cout <<count<<"\n";
    
    return 0;
}