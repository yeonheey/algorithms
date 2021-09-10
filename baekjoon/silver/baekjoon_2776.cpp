#include <set>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int N, M, number;
        set<int> nums;
        vector<int> check;
        cin >> N;
        
        while(N--) {
            cin >> number;
            nums.insert(number);
        }
        
        cin >> M;
        for(int i = 0; i < M; i++) {
            cin >> number;
            check.push_back(number);
        }
        
        for(int i = 0; i < M; i++) {
            if(nums.find(check[i]) == nums.end()) cout << "0";
            else cout << "1";

            cout << "\n";
        }
    }
    
    return 0;
}