#include <queue>
#include <string>
#include <iostream>

using namespace std;

int N, number;
string order;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    queue<int> q;

    while(N-- > 0) {
        cin >> order;

        if(order == "size")
            cout << q.size() << "\n";
        else if(order == "push") {
            cin >> number;
            q.push(number);
        }        
        else if(order == "empty") {
            if(q.empty()) 
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if(q.empty())
            cout << "-1\n";
        else if(order == "front")
            cout << q.front() << "\n";
        else if(order == "back")
            cout << q.back() << "\n";
        else if(order == "pop") {
            cout << q.front() << "\n";
            q.pop();
        }
    }

    return 0;
}