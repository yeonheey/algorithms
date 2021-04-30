#include <vector>
#include <cmath>

using namespace std;

const int COLS = 4;

int solution(vector<vector<int> > land)
{
    int answer = -1;
    int N = land.size();
    vector<vector<int> > checkScore(N, vector<int>(COLS, 0));
    
    for(int i = 0; i < COLS; i++)
        checkScore[0][i] = land[0][i];
    
    for(int i = 1; i < N; i++)
        for(int j = 0; j < COLS; j++)
            for(int k = 0; k < COLS; k++)
                if(j != k)
                    checkScore[i][j] = max(checkScore[i][j], land[i][j] + checkScore[i - 1][k]);
    
    for(int i = 0; i < COLS; i++)
        answer = max(answer, checkScore[N - 1][i]);

    return answer;
}