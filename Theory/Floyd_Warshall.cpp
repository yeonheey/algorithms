#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int INF = 999999999;
const int n = 6;
const vector<vector<int> > edges = { {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} };

int main()
{
    vector<vector<int> > cost(n + 1, vector<int>(n + 1, INF));

    for (vector<int> edge : edges)
    {
        cost[edge[0]][edge[1]] = edge[2];
        cost[edge[1]][edge[0]] = edge[2];
    }

    for (int i = 1; i <= n; i++)
        cost[i][i] = 0;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

    for (int i = 1; i <= n; i++)
    {
        cout << "from: " << i << endl;

        for (int j = 1; j <= n; j++)
            cout << "  >" << j << cost[i][j] << endl;
    }

    return 0;
}
