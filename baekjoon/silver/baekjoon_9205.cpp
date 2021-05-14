#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const int SIZE = 105;

bool isVisited[SIZE] = {false, };
vector<int> edges[SIZE];

int calDist(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void check(int node)
{
    isVisited[node] = true;

    for(int i = 0; i < edges[node].size(); i++)
    {
        int nextNode = edges[node][i];
        if(!isVisited[nextNode])
            check(nextNode);
    }
}

int main()
{
    int t, n;
    scanf("%d", &t);

    while(t-- > 0)
    {
        scanf("%d", &n);
        vector<pair<int, int> > vec(n + 2);
        memset(isVisited, 0, sizeof(isVisited));
        for(int i = 0; i < SIZE; i++) edges[i].clear();

        for(int i = 0; i < n + 2; i++)
            scanf("%d %d", &vec[i].first, &vec[i].second);

        for (int i = 0; i < n + 2; i++)
            for(int j = i + 1; j < n + 2; j++)
            {
                int dist = calDist(vec[i], vec[j]);
                if(dist <= 1000)
                {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }

        check(0);
        
        if(isVisited[n + 1])
            printf("happy\n");
        else
            printf("sad\n");
    }

    return 0;
}