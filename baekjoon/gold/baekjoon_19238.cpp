#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int SIZE = 22;

struct Customer
{
    int sr, sc, dr, dc;
   
    Customer(int _sr, int _sc, int _dr, int _dc) {
        sr = _sr, sc = _sc, dr = _dr, dc = _dc;
    }
};

struct Taxi
{
    int r, c;
    int fuel;
};

struct CustomerInfo
{
    int r, c, dist, idx;
    CustomerInfo(int _r, int _c, int _d, int i) 
    {r = _r, c = _c, dist = _d, idx = i - 1;}
};


int N, M;
int board[SIZE][SIZE];
bool isVisited[SIZE][SIZE];
Taxi taxi;
vector<Customer> customers;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int fuel, r, c;
    
    cin >> N >> M >> fuel;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) board[i][j] = -1;
        }
    
    cin >> r >> c;
    taxi.r = r, taxi.c = c, taxi.fuel = fuel;
    
    int sr, sc, dr, dc;
    for (int i = 1; i <= M; i++) {
        cin >> sr >> sc >> dr >> dc;

        customers.push_back(Customer(sr, sc, dr, dc));
        board[sr][sc] = i;
    }
}

bool cmp (CustomerInfo& c1, CustomerInfo& c2) {

    if(c1.dist < c2.dist) return true;
    else if(c1.dist == c2.dist) {
        if(c1.r < c2.r) return true;
        else if(c1.r == c2.r) {
            if(c1.c < c2.c) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

int shortestCustomerIndex() { //taxi to customer
    memset(isVisited, false, sizeof(isVisited));

    queue<pair<pair<int, int>, pair<int, int>> > q;
    
    q.push( {{taxi.r, taxi.c}, {0, taxi.fuel}} ); 
    isVisited[taxi.r][taxi.c] = true; 

    vector<CustomerInfo> vec;
    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dist = q.front().second.first;
        int fuel = q.front().second.second;
        q.pop();

        if(board[r][c] > 0)
            vec.push_back( CustomerInfo(r, c, dist, board[r][c]) );
        
        if(fuel == 0) continue;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr <= 0 || nr > N || nc <= 0 || nr > N) continue;
            if(isVisited[nr][nc] || board[nr][nc] == -1) continue;

            isVisited[nr][nc] = true;
            q.push({ {nr, nc}, {dist + 1, fuel - 1} });
        }
    }

    if(vec.size() == 0)
        return -1;

    sort(vec.begin(), vec.end(), cmp);
    board[vec[0].r][vec[0].c] = 0;
    taxi.fuel -= vec[0].dist;
    
    return vec[0].idx;
}

bool moveToDst(int idx) {
    int dr = customers[idx].dr, dc = customers[idx].dc;
    int sc = customers[idx].sc, sr = customers[idx].sr;

    memset(isVisited, false, sizeof(isVisited));

    queue<pair<pair<int, int>, pair<int, int>> > q;
    
    q.push({ {sr, sc}, {0, taxi.fuel} }); 
    isVisited[sr][sc] = true; 

    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dist = q.front().second.first;
        int fuel = q.front().second.second;
        q.pop();

        if(r == dr && c == dc) {
            taxi.fuel -= dist;
            taxi.fuel += (2 * dist);
            taxi.r = dr, taxi.c = dc;

            return true;
        }
       
        if(fuel == 0) return false;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr <= 0 || nr > N || nc <= 0 || nr > N) continue;
            if(isVisited[nr][nc] || board[nr][nc] == -1) continue;

            isVisited[nr][nc] = true;
            q.push({ {nr, nc}, {dist + 1, fuel - 1} });
        }
    }

    return false;
}

int main() {
    input();

    bool isRemain = true;

    while (M-- > 0) 
    {
        int i = shortestCustomerIndex();
        if(i == -1) {
            isRemain = false; break;
        }

        if(!moveToDst(i)) {
            isRemain = false; break;
        }
    }

    if(isRemain) cout << taxi.fuel <<"\n";
    else cout <<"-1\n";

    return 0;
}
