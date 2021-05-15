#include <vector>
#include <algorithm>
using namespace std;
const int MAXNUM = 10;
int solution(int n, vector<int> weak, vector<int> dist) {
    int count = MAXNUM;
    int weakSize = weak.size();
    
    for(int i = 0; i < weakSize; i++)
        weak.push_back(weak[i] + n);
    
    sort(dist.begin(), dist.end()); //for permutation
    
    do {
        for (int i = 0; i < weakSize; i++) {
            int start = weak[i];
            int end = weak[i + weakSize - 1];
            
            for (int j = 0; j < dist.size(); j++) {
                start += dist[j];
                
                if(start >= end) {
                    count = min(count, j + 1);
                    break;
                }
                
                int next = upper_bound(weak.begin(), weak.end(), start) - weak.begin();
                start = weak[next];
            }
        }
        
    } while(next_permutation(dist.begin(), dist.end()));
    
    if(count == MAXNUM) count = -1;
    
    return count;
}