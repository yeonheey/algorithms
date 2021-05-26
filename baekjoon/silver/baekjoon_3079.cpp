#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    vector<long long> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    long long left = 1;
    long long right = (*max_element(arr.begin(), arr.end())) * m;
    long long answer = right;
    
    while(left <= right) {
        long long mid = (left + right) / 2;
        
        long long cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += mid / arr[i];
        
        if(cnt < m)
            left = mid + 1;
        else {
            answer = min(answer, mid);
            right = mid - 1;
        }
    }
    
    cout << answer <<"\n";
    
    return 0;
}