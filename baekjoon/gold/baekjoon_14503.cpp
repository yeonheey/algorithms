#include <iostream>

using namespace std;

int N, M;
int robotR, robotC, robotDir;
int arr[51][51];
bool isClean[51][51] = {false, };

int dr[4] = {-1, 0, 1, 0}; //북동남서
int dc[4] = {0, 1, 0, -1};

int main() {
    cin >> N >> M;
    cin >> robotR >> robotC >> robotDir;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];
    
    int clearCount = 0;

    while (true) {
        if(!isClean[robotR][robotC]) {
            clearCount++;
            isClean[robotR][robotC] = true;
        }

        bool canClean = false;
       
        for(int i = 0; i < 4; i++) {
            int ndir = (robotDir - i + 3) % 4;
            int nr = robotR + dr[ndir]; 
            int nc = robotC + dc[ndir];
            
            if(nr < 0 || nc < 0 || nr >= N || nc >= M || arr[nr][nc] == 1) continue;
            if(isClean[nr][nc]) continue;
            
            canClean = true; 
            robotR = nr, robotC = nc; robotDir = ndir;
            break;
        }

        if(!canClean) {
            int nr = robotR + dr[(robotDir + 2) % 4];
            int nc = robotC + dc[(robotDir + 2) % 4];
           
           if(arr[nr][nc] == 1) break;
           
           robotR = nr, robotC = nc;
        }
    }
    
    cout << clearCount << "\n";
    return 0;
}