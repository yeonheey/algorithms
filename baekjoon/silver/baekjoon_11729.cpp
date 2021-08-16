#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int>> result;

void hanoi(int n, int start, int dst, int step) {
    if(n == 1) {
        result.push_back({start, dst});
        return;
    }

    hanoi(n - 1, start, step, dst);
    result.push_back({start, dst});
    hanoi(n - 1, step, dst, start);
}

int main() {
    int N;
    cin >> N;

    hanoi(N, 1, 3, 2);

    cout << result.size() <<"\n";
    for(pair<int, int> ele: result) 
        cout << ele.first << " " << ele.second << "\n";

    return 0;
}