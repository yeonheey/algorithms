#include <vector>
#include <iostream>

using namespace std;

int N, M;
vector<int> origin;
vector<int> party[51];
int root[51];

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count, number;
    
    cin >> N >> M;
    cin >> count;

    for(int i = 0; i < count; i++) {
        cin >> number;
        origin.push_back(number);
    }

    for(int i = 0; i < M; i++) {
        cin >> count;
        
        for(int j = 0; j < count; j++) {
            cin >> number;
            party[i].push_back(number);
        }
    }
}

int getParent(int x) {
    if(root[x] == x) return x;

    return ( root[x] = getParent(root[x]) );
}

void Union(int x, int y) {
    x = getParent(x), y = getParent(y);

    if(x < y) root[y] = x;
    else root[x] = y;
}
 
int main() {
    input();

    int result = 0;

    for(int i = 1; i <= N; i++) root[i] = i;
    
    for(int i = 0; i < M; i++) {
        int person1 = party[i][0];

        for(int j = 1; j < party[i].size(); j++)
            Union(person1, party[i][j]);
    }

    for(int i = 0; i < M; i++) {
        bool canLie = true;

        for(int person: party[i]) 
            for(int know: origin) {
                if( getParent(person) != getParent(know) ) continue;

                canLie = false;
                break;
            }

        if(canLie) result++;
    } 

    cout << result << "\n";

    return 0;
}