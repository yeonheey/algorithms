#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXSIZE = 99999999;

int N, M;
int map[51][51];
vector<pair<int,int> > chicken;

int calculate(int r1, int c1, int r2, int c2) {
    return (abs(r1 - r2) + abs(c1 - c2));
}

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            
            if(map[i][j] == 2) 
                chicken.push_back({i, j});
        }
    
    vector<bool> isSelected(chicken.size(), false);
    for(int i = 0; i < M; i++)
        isSelected[chicken.size() - 1 - i] = true;

    int minDist = MAXSIZE;

    do {
        int tempMinDist = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(map[i][j] == 0 || map[i][j] == 2) continue;

                //이 집에서부터 모든 치킨가게까지 거리구하고 최솟값 갱신
                int chickenDist = MAXSIZE;
                for(int k = 0; k < chicken.size(); k++) {
                    if(!isSelected[k]) continue;
                    
                    chickenDist = min( chickenDist, calculate(i, j, chicken[k].first, chicken[k].second) );
                }

                tempMinDist += chickenDist;
            }
        }
        minDist = min(minDist, tempMinDist);

    } while( next_permutation(isSelected.begin(), isSelected.end()) );

    cout << minDist << "\n";
    
    return 0;
}