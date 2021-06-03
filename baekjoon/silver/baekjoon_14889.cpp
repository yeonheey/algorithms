#include <cmath>
#include <iostream>

using namespace std;

const int SIZE = 21;

int N, differ = 999999999;
int arr[SIZE][SIZE] = {0, };
bool team[SIZE];

void dfs(int player, int cnt) {    
    if(cnt == N / 2) {
        int team1 = 0, team2 = 0;
        
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
                if(team[i] == true && team[j] == true) 
                    team1 += arr[i][j];
                else if(team[i] == false && team[j] == false)
                    team2 += arr[i][j];
            }
        
        int tempDiffer = abs(team1 - team2);
        if(differ > tempDiffer) 
            differ = tempDiffer;
        
        return;
    }
    
    for(int i = player; i < N; i++) {
        team[i] = true;
        dfs(i + 1, cnt + 1);
        team[i] = false;
    }
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];
    
    dfs(0, 0);
    
    cout << differ <<"\n";
    
    return 0;
}