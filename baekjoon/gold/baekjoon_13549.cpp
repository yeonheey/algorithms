#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

const int MAX = 100001;

int start, dst;
bool isVisited[MAX] = {false, };

int main() {
    cin >> start >> dst;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; // time, loc
    pq.push({0, start});
    isVisited[start] = true;

    while (!pq.empty()) 
    {
        int time = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cur == dst) {
            cout << time << "\n";
            break;
        }

        if(cur * 2 < MAX && !isVisited[cur * 2]) {
            pq.push({time, cur * 2});
            isVisited[cur * 2] = true;
        }
        if(cur - 1 >= 0 && !isVisited[cur - 1]) {
            pq.push({time + 1, cur - 1});
            isVisited[cur - 1] = true;
        }
        if(cur + 1 < MAX && !isVisited[cur + 1]) {
            pq.push({time + 1, cur + 1});
            isVisited[cur + 1] = true;
        }
    }

    return 0;
}