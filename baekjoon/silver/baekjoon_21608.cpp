#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

struct Info
{
    int likes, empty, r, c;
    Info(int _l, int _e, int _r, int _c) { likes = _l, empty = _e, r = _r, c = _c; }

    bool operator>(const Info &rhs) {
        if (likes > rhs.likes) return true;

        else if (likes == rhs.likes) {
            if (empty > rhs.empty) return true;

            else if (empty == rhs.empty) {
                if (r < rhs.r) return true;

                else if (r == rhs.r) {
                    if (c < rhs.c) return true;

                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
};

int N, totalN;
vector<pair<int, set<int>> > like;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void findLocation(int idx, Info &canLocate, const vector<vector<int> > &seat)
{
    int cur = like[idx].first;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            if (seat[r][c] != -1) continue;

            //빈칸들의 인접한 칸 check
            int empty = 0, likes = 0;
            for (int j = 0; j < 4; j++) {
                int nr = r + dr[j];
                int nc = c + dc[j];

                if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

                if (seat[nr][nc] == -1) empty++;
                else if (like[idx].second.find(seat[nr][nc]) != like[idx].second.end())
                    likes++;
            }

            Info temp(likes, empty, r, c);

            if (temp > canLocate) canLocate = temp;
        }
}

void input() {
    cin >> N;

    totalN = N * N;
    for (int i = 0, num; i < totalN; i++) {
        set<int> Set;
        cin >> num;

        for (int j = 0, temp; j < 4; j++) {
            cin >> temp;
            Set.insert(temp);
        }

        like.push_back({num, Set});
    }
}

int main()
{
    input();

    //seat
    vector<vector<int> > seat(N + 1, vector<int>(N + 1, -1));

    for (int i = 0; i < totalN; i++) {
        Info canLocate(-1, -1, N, N);

        //find location
        findLocation(i, canLocate, seat);

        seat[canLocate.r][canLocate.c] = like[i].first;
    }

    int good = 0;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            for (int j = 0; j < totalN; j++)
            {
                if (seat[r][c] != like[j].first)
                    continue;

                int likes = 0;
                for (int k = 0; k < 4; k++)
                {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                    if (like[j].second.find(seat[nr][nc]) == like[j].second.end()) continue;

                    likes++;
                }

                if (likes == 0) continue;
                good += pow(10, likes - 1);
            }

    cout << good << "\n";

    return 0;
}