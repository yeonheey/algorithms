#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return (a[1] > b[1]);
    }
};

int solution(vector<vector<int>> jobs) {
    int sumTime = 0;
    int jobSize = jobs.size();
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq; //작업 순
    
    sort(jobs.begin(), jobs.end()); //들어온 순
    
    int curTime = 0, idx = 0;
    while(idx < jobSize || !pq.empty()) {
        if(idx < jobSize && curTime >= jobs[idx][0]) {
            pq.push(jobs[idx++]);
            continue;
        }
        
        if(!pq.empty()) {
            curTime += pq.top()[1];
            sumTime += (curTime - pq.top()[0]);
            
            pq.pop();
        }
        else 
            curTime = jobs[idx][0];
    }
    
    return (sumTime / jobSize);
}