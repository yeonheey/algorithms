#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int dy[4] = {1, 0, -1, 0}; //북서남동
int dx[4] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--) {
        string order;
        cin >> order;
        
        int minX = 0, minY = 0;
        int maxX = 0, maxY = 0;
        
        int dir = 0;
        int curX = 0, curY = 0;
        for(char ch: order) {
            if(ch == 'L') {
                dir = (dir + 1) % 4;
                continue;
            }
            else if(ch == 'R') {
                dir = (dir + 3) % 4;
                continue;
            }
            else if(ch == 'F') {
                curX += dx[dir];
                curY += dy[dir];
            } 
            else if(ch == 'B') {
                curX -= dx[dir];
                curY -= dy[dir];
            }
            
            minX = min(minX, curX);
            maxX = max(maxX, curX);
            minY = min(minY, curY);
            maxY = max(maxY, curY);
        }
        
        cout << (maxX - minX) * (maxY - minY) << "\n";
    }
    
    return 0;
}