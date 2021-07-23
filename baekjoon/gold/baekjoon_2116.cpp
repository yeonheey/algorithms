#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int n;
vector<vector<int> > cubes(10001, vector<int>(6));

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) 
        cin >> cubes[i][0] >> cubes[i][1] >> cubes[i][2] >> cubes[i][4] >> cubes[i][5] >> cubes[i][3];
    
    int maxSum = 0;
    for(int i = 0; i < 6; i++) {
        int up = cubes[0][i], down;
        int sum = 0;
        
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < 6; k++) 
                if(up == cubes[j][k])
                    down = cubes[j][(k + 3) % 6];

            int maxNum = 0;
            for(int k = 0; k < 6; k++) {
                if(cubes[j][k] != up && cubes[j][k] != down) 
                    maxNum = max(maxNum, cubes[j][k]);
            }

            up = down;
            sum += maxNum;
        }
        
        maxSum = max(maxSum, sum);
    }

    cout << maxSum << "\n";

    return 0;
}