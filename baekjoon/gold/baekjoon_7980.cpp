#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool canPlay[1000000001] = {false, };

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    return (a.second > b.second);
}

int main() {
    int N;
    cin >> N;

    vector<pair<int,int> > assignment;
    for(int i = 0; i < N; i++) {
        int d, t;
        cin >> d >> t;

        assignment.push_back({d, t});
    }

    sort(assignment.begin(), assignment.end(), cmp);

    int play = assignment[0].second - assignment[0].first;
    for(int i = 1; i < N; i++) {
        int d = assignment[i].first, t = assignment[i].second;

        if(play >= t) play = t - d;
        else play -= d;
    }

    cout << play << "\n";

    return 0;
}