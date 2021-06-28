#include <iostream>

using namespace std;

int N, M;
int money[100001];

bool check(int amount, int& cnt) {
    int temp = amount;

    for(int i = 0; i < N; i++) {
        if(money[i] > amount) 
            return false;
        if(money[i] > temp) {
            cnt++;
            temp = amount;
        }

        temp -= money[i];
    }
    
    return true;
}

int main() {
    cin >> N >> M;

    int left = 0, right = 0;
    for(int i = 0; i < N; i++) {
        cin >> money[i];
        right += money[i];
    }

    int min_cost = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int cnt = 1;
        
        if(check(mid, cnt) && M >= cnt) {
            min_cost = mid;
            right = mid - 1;
        } 
        else
            left = mid + 1;
    }

    cout << min_cost <<"\n";

    return 0;
}