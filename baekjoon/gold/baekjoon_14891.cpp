#include <deque>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

vector<deque<bool> > saw(4);
int K;

void move_saw(int idx, int clockwise) {
    if(clockwise == 1) {
        bool back = saw[idx].back();
        saw[idx].push_front(back);
        saw[idx].pop_back();
    }
    else {
        bool front = saw[idx].front();
        saw[idx].push_back(front);
        saw[idx].pop_front();
    }
}

int main() {
    for(int i = 0; i < 4; i++) {
        int value;
        for(int j = 0; j < 8; j++) {
            scanf("%1d", &value);
            saw[i].push_back(value);
        }
    }

    scanf("%d", &K);
    for(int i = 0; i < K; i++) {
        int idx, move;
        scanf("%d %d", &idx, &move);
        idx--;
        
        vector<deque<bool> > temp_saw = saw;
        move_saw(idx, move);

        int rotation = move;
        for(int i = idx; i > 0; i--) {
            if(temp_saw[i][6] == temp_saw[i - 1][2]) break;
            
            rotation = (-1) * rotation;
            move_saw(i - 1, rotation);
        }

        rotation = move;
        for(int i = idx; i < 3; i++) {
            if(temp_saw[i][2] == temp_saw[i + 1][6]) break;
            
            rotation = (-1) * rotation;
            move_saw(i + 1, rotation);
        }
    }

    int sum = 0;
    for(int i = 0; i < 4; i++) 
        if(saw[i].front())
            sum += pow(2, i);

    printf("%d\n", sum);

    return 0;
}