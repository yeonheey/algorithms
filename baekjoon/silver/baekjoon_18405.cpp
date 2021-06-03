#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXSIZE = 201;

struct Virus {
    int number, x, y;
    Virus(int _number, int _x, int _y) {number = _number, x = _x, y = _y;}
};

int arr[201][201];
int N, K;
int S, X, Y;

int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};

bool cmp(Virus& a, Virus& b) {
    return a.number < b.number;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<Virus> vec;
    queue<Virus> q;
    
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            vec.push_back(Virus(arr[i][j], i, j));
        }
    cin >> S >> X >> Y;
    
    sort(vec.begin(), vec.end(), cmp);

    for(int i = 0; i < vec.size(); i++) q.push(vec[i]);
    
    int prevNum = 0;
    while(!q.empty()) {
        //번호 낮은 순부터 증식
        Virus virus = q.front(); q.pop();
        
        if(prevNum > virus.number)
            if(--S <= 0) break;
        
        prevNum = virus.number;
    
        for(int i = 0; i < 4; i++) {
            int nx = virus.x + dx[i];
            int ny = virus.y + dy[i];
            
            if(nx <= 0 || nx > N || ny <= 0 || ny > N ) continue;
            if(arr[nx][ny] != 0) continue;
            
            arr[nx][ny] = virus.number;
            q.push(Virus(virus.number, nx, ny));
        }
        
        if(S == 0) break;
    }
        
    cout << arr[X][Y] <<"\n";
    
    return 0;
}