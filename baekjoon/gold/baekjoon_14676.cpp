#include <vector>
#include <iostream>

using namespace std;

const int Size = 100001;

vector<int> relation[Size];
int before_built[Size] = {0, }; // n 건물까지 지어져야하는 건물
int built[Size] = {0, };

vector<pair<int,int>> game;

bool gamePlay() {
    for(pair<int,int> turn: game) {
        int number = turn.second;

        if(turn.first == 1) {
            if(before_built[number] == 0) {
                built[number]++;

                if(built[number] == 1) 
                    for(int i = 0; i < relation[number].size(); i++)
                        before_built[relation[number][i]]--;
            }
            else {
                return false;
            }
        }
        else {
            if(built[number] > 0) {
                built[number]--;

                if(built[number] == 0) 
                    for(int i = 0; i < relation[number].size(); i++)
                        before_built[relation[number][i]]++;
            }
            else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        relation[a].push_back(b);
        before_built[b]++;
    }

    for(int i = 0; i < K; i++) {
        int type, a;
        cin >> type >> a;
        
        game.push_back({type, a});
    }

    if(gamePlay()) 
        cout << "King-God-Emperor\n";
    else
        cout << "Lier!\n";

    return 0;
}