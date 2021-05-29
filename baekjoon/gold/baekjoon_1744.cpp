#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n, sum = 0;
vector<int> pos;
vector<int> neg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    int one = 0, zero = 0;
    for(int i = 0, number; i < n; i++) {
        cin >> number;
        
        if(number == 1) one++;
        else if(number == 0) zero++;
        else if(number < 0) neg.push_back(number);
        else pos.push_back(number);
    }
    
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());
    
    pos.push_back(1);
    neg.push_back(1); //2개씩 묶기위해서
    
    for(int i = 0; i < pos.size() - 1; i+= 2)
        sum += (pos[i] * pos[i + 1]);
    
    for(int i = 0; i < neg.size() - 1; i+= 2)
        sum += (neg[i] * neg[i + 1]);
    
    if(neg.size() % 2 == 0 && zero > 0) 
        sum -= neg[neg.size() - 2];
    
    sum += one;
    
    cout << sum <<"\n";
    
    return 0;
}