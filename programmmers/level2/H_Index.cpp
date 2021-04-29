#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int solution(vector<int> citations) {
    int h_idx = 0;
    int n = citations.size();
    
    sort(citations.begin(), citations.end(), compare);

    for(int i = 0; i < n; i++)
    {
        if(citations[i] > i)
            h_idx++;
        else 
            break;
    }
    
    return h_idx;
}
