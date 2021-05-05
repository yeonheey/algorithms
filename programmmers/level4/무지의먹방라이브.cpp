
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = -1;
    int size = food_times.size();
    
    long long totalTime = 0;
    priority_queue<pair<int, int> > pq; //time, index

    for(int i = 0; i < size; i++)
    {
        totalTime += food_times[i];
        pq.push( {-food_times[i], i + 1} );
    }
    
    if(totalTime <= k) return answer;
    
    long long prevTime = 0;
    while((-pq.top().first - prevTime) * size <= k)
    {
        k -= (-pq.top().first - prevTime) * size;
        prevTime = -pq.top().first;
        
        size--;
        pq.pop();
    }
    
    vector<pair<int, int> > leftFood;
    while(!pq.empty())
    {
        leftFood.push_back(pq.top());
        pq.pop();
    }
    
    sort(leftFood.begin(), leftFood.end(), cmp);
    
    answer = leftFood[k % size].second;
    
    return answer;
}