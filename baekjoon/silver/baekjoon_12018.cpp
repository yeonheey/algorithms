#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
vector<int> result;
int classCount = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0, total, apply; i < N; i++) {
        cin >> total >> apply;

        vector<int> vec(total);
        for(int j = 0, value; j < total; j++) 
            cin >> vec[j];

        if(total < apply) 
            result.push_back(1);
        else {
            sort(vec.begin(), vec.end(), greater<int>());
            result.push_back(vec[apply - 1]);
        }
    }

    sort(result.begin(), result.end());

    for(int mile: result) {
        if(M < mile) break;

        M -= mile;
        classCount++;
    }

    cout << classCount <<"\n";

    return 0;
}