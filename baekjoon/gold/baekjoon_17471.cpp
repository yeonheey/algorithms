#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 999999999;

int N, result = MAX;
int area[11];
vector<int> node_info[11];
bool isSelected[11];

bool checkConnect(vector<int>& zone, bool value) {
    vector<bool> isVisited(11, false);
    queue<int> q;

    isVisited[zone[0]] = true;
    q.push(zone[0]);
    int cnt = 1;

    while (!q.empty())
    {
        int front = q.front(); q.pop();

        for(int next: node_info[front]) {
            if(isSelected[next] != value || isVisited[next]) continue;

            cnt++;
            isVisited[next] = true;
            q.push(next);
        }
    }

    if(cnt == zone.size()) return true;
    
    return false;
}

bool isAllConnected() {
    vector<int> zone1, zone2;
    
    for(int i = 1; i <= N; i++) {
        if(isSelected[i]) zone1.push_back(i);
        else zone2.push_back(i);
    }

    if(zone1.empty() || zone2.empty()) return false;
    if(!checkConnect(zone1, true) || !checkConnect(zone2, false)) return false;

    return true;
}

void dfs(int idx, int cnt) {
    if(cnt > N) return;

    if(isAllConnected()){
        int sum1 = 0, sum2 = 0;
        for(int i = 1; i <= N; i++) {
            if(isSelected[i]) sum1 += area[i];
            else sum2 += area[i];
        }

        result = min(result, abs(sum1 - sum2));
    }
    
    for(int i = idx; i <= N; i++) {
        if(isSelected[i]) continue;

        isSelected[i] = true;
        dfs(i + 1, cnt + 1);
        isSelected[i] = false;
    }
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> area[i];
    
    for(int i = 1, n; i <= N; i++) {
        cin >> n;

        for(int j = 0, node; j < n; j++) {
            cin >> node;
            node_info[i].push_back(node);
        }
    }

    dfs(0, 1);

    if(result == MAX) result = -1;

    cout << result << "\n";

    return 0;
}