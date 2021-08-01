#include <queue>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<int> pq;

    while (N-- > 0)
    {
        int x; 
        cin >> x;

        if(x == 0) {
            if(pq.empty()) cout << "0\n";
            else {
                cout << pq.top() <<"\n";
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }

    return 0;
}