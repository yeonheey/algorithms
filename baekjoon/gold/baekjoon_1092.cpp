#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> crane;
vector<int> box;

int main()
{
    int temp;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        crane.push_back(temp);
    }
    
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &temp);
        box.push_back(temp);
    }
    
    sort(crane.begin(), crane.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());
    
    if(box[0] > crane[0])
    {
        printf("-1\n");
        return 0;
    }
    
    int time = 0;
    while(!box.empty())
    {
        time++;
        
        for(int i = 0; i < N; i++)
            for(int j = 0; j < box.size(); j++)
            {
                if(crane[i] >= box[j])
                {
                    box.erase(box.begin() + j);
                    break;
                }
            }
    }
    
    printf("%d\n", time);
    
    return 0;
}