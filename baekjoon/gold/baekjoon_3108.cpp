#include <vector>
#include <set>
#include <iostream>

using namespace std;

struct Rect
{
    int x1, y1, x2, y2;
    Rect(int _x1, int _y1, int _x2, int _y2) 
        {x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2;}
};

int N;
int root[1001];

vector<Rect> rects;

int getParent(int x) {
    if(root[x] == x) return x;
    return (root[x] = getParent(root[x]));
}

void Union(int x, int y) {
    x = getParent(x), y = getParent(y);

    if(x < y) root[y] = x;
    else root[x] = y;
}

bool isMeeting(int i, int j) {
    Rect a = rects[i]; 
    Rect b = rects[j]; 

    if(a.x1 < b.x1 && a.y1 < b.y1 && b.x2 < a.x2 && b.y2 < a.y2) return false;
    if(b.x1 < a.x1 && b.y1 < a.y1 && a.x2 < b.x2 && a.y2 < b.y2) return false;
    if(b.y1 > a.y2 || b.x1 > a.x2 || a.y1 > b.y2 || a.x1 > b.x2) return false;

    return true;
}

int main() {
    cin >> N;

    rects.push_back(Rect(0, 0, 0, 0));

    int x1, y1, x2, y2;
    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        rects.push_back(Rect(x1, y1, x2, y2));
    }

    for(int i = 0; i <= N; i++) 
        root[i] = i;

    for(int i = 0; i < N; i++)
        for(int j = i + 1; j <= N; j++)
            if(isMeeting(i, j)) Union(i, j);

    set<int> parentSet;
    for(int i = 0; i <= N; i++) {
        parentSet.insert(getParent(root[i]));
    }
    
    cout << parentSet.size() - 1 << "\n";

    return 0;
}