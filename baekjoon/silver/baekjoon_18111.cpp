#include <iostream>

using namespace std;

int rows, cols, inventory;
int ground[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> rows >> cols >> inventory;
    for(int r = 0; r < rows; r++)
        for(int c = 0; c < cols; c++)
            cin >> ground[r][c];
    
    int time = 999999999, height = -1;
    for(int h = 256; h >= 0; h--) {
        int tempTime = 0, useBlock = 0;
        
        for(int r = 0; r < rows; r++)
            for(int c = 0; c < cols; c++) {
                int diff = ground[r][c] - h;

                if(diff < 0) {
                    tempTime += -diff;
                    useBlock += diff;
                }
                else {
                    tempTime += 2 * diff;
                    useBlock += diff;
                }
            }

        if(inventory + useBlock >= 0) {
            if(tempTime < time) {
                time = tempTime;
                height = h;
            }
            else if(tempTime == time && height < h)
                height = h;
        }
    }

    cout << time << " " << height << "\n";

    return 0;
}