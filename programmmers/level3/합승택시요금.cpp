#include <vector>
#include <algorithm>

using namespace std;

const int MAX_NUM = 999999999;

int solution(int n, int s, int a, int b, vector<vector<int> > fares) {
    int answer = MAX_NUM;
    vector<vector<int> > costs(n + 1, vector<int>(n + 1, MAX_NUM));
    
    for(int i = 1; i <= n; i++)
        costs[i][i] = 0;
    
    for(vector<int> fare : fares)
    {
        costs[fare[0]][fare[1]] = fare[2];
        costs[fare[1]][fare[0]] = fare[2];
    }
    
    for(int i = 1; i <= n; i++) //거쳐가는 노드
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                costs[j][k] = min( costs[j][k], costs[j][i] + costs[i][k] );
    
    for(int i = 1; i <= n; i++)
    {
        if(costs[s][i] < MAX_NUM && costs[i][a] < MAX_NUM && costs[i][b] < MAX_NUM)
            answer = min(answer, costs[s][i] + costs[i][a] + costs[i][b]);
    }
    
    return answer;
}
