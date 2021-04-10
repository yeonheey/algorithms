#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<int, int>> work; //t_i, s_i
bool cmp (pair<int, int> a, pair<int, int> b) {
    //먼저 끝내야 하는 일의 순서로 정렬
    return (a.second < b.second);
}
bool can_wakeup(int time) {
    int sum = time;
    
    for(int i = 0; i < n; i++) {
        if(sum + work[i].first <= work[i].second)
            sum += work[i].first;
        else 
            return false;
    }
        
    return true;
}