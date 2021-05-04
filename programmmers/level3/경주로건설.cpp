#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 999999999;

int dir_r[4] = {-1, 1, 0, 0}; //up down left right
int dir_c[4] = {0, 0, -1, 1};

struct Car {
    int r, c, cost;
    int dir; // dir index
    
    Car(int _r, int _c, int _cost, int _dir) 
    {
        r = _r, c = _c, cost = _cost, dir = _dir;
    }
};

int solution(vector<vector<int> > board) {
    int totalCost = MAX;
    int N = board.size();
    
    queue<Car> q;
    q.push(Car(0, 0, 0, -1));
    
    board[0][0] = 1;
    
    while(!q.empty())
    {
        Car car = q.front(); q.pop();

        if(car.r == N - 1 && car.c == N - 1)
        {
            totalCost = min(totalCost, car.cost);
            continue;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int rNext = car.r + dir_r[i], cNext = car.c + dir_c[i];
            
            if(rNext < 0 || cNext < 0 || rNext >= N || cNext >= N) continue;
            if(board[rNext][cNext] == 1) continue;
            
            int nextCost = 0;
            
            if(car.dir == -1 || car.dir == i) //line
                nextCost = car.cost + 100;
            else if(car.dir != i) //corner
                nextCost = car.cost + 600;
            
            if(board[rNext][cNext] == 0 || board[rNext][cNext] >= nextCost)
            {
                board[rNext][cNext] = nextCost;
                q.push(Car(rNext, cNext, nextCost, i));
            }
        }
    }
    
    return totalCost;
}