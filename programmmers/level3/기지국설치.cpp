#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int count = 0;
    double len = 2 * w + 1;
    sort(stations.begin(), stations.end());
    
    int checkpnt = 0;
    for(int station: stations)
    {
        int left = station - w - 1;
        int right = station + w;
        
        if(left <= checkpnt && checkpnt < right) //in range
        {
            checkpnt = right; 
            continue;
        }
        
        count += ceil((double)(left - checkpnt) / len);
        checkpnt = right;
    }
    
    if(checkpnt < n)
        count += ceil((double)(n - checkpnt) / len);

    return count;
}