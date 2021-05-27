#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

int n;
int oper[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> oper[i];
    
    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < n; i++) {
        if(0 != oper[i]) {
            pq.push( {-abs(oper[i]), -oper[i]} );
            continue;
        }

        if (pq.empty())  cout << "0\n";
        else {
            cout << -pq.top().second << "\n";
            pq.pop();
        }      
    }
    
    return 0;
}