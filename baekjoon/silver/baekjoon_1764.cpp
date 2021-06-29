#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std; 

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    set<string> people;
    vector<string> result;

    string name;
    for(int i = 0; i < N; i++) {
        cin >> name;
        people.insert(name);
    }

    for(int i =0 ; i < M; i++) {
        cin >> name;

        if(people.find(name) != people.end())
            result.push_back(name);
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for(string person: result)
        cout << person << "\n";
    
    return 0;
}