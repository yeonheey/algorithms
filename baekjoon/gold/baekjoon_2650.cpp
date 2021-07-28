#include <vector>
#include <iostream>

using namespace std;

const int NUMBER = 10000000;

int calLocation(int x, int y) {
    if(x == 1) return y;
    else if(x == 4) return (NUMBER + y);
    else if(x == 2) return (NUMBER * x + NUMBER - y);
    else if(x == 3) return (NUMBER * x + NUMBER - y);

    return -1;
}

int main() {
    int N;
    vector<pair<int, int> > lines;

    cin >> N;
    for(int i = 0; i < N / 2; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int pnt1 = calLocation(a, b);
        int pnt2 = calLocation(c, d);
        
        if(pnt1 < pnt2)
            lines.push_back({pnt1, pnt2});
        else
        lines.push_back({pnt2, pnt1});
    }

    int minCross = 0, maxMeetLine = 0;
    for (int i = 0; i < lines.size(); i++) {
        int cnt = 0;

        for(int j = 0; j < lines.size(); j++) {
            if(j == i) continue;

            if(lines[i].first < lines[j].first) {
                if(lines[j].first < lines[i].second && lines[i].second < lines[j].second) 
                    cnt++;
            }
            else {
                if(lines[i].first < lines[j].second && lines[j].second < lines[i].second) 
                    cnt++;
            }
        }

        maxMeetLine = max(maxMeetLine, cnt);
        minCross += cnt;
    }
    
    cout << minCross / 2 << "\n";
    cout << maxMeetLine << "\n";

    return 0;
}