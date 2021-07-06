#include <iostream>

using namespace std;

//LIS algorithm(가장 긴 증가하는 부분 수열)

int n, result = 0;
int cube[1001];
int check[1001];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> cube[i];
    
    for(int i = 0; i < n; i++) {
        check[i] = 1;

        for(int j = 0; j < i; j++) {
            if(cube[i] > cube[j] && check[i] < check[j] + 1) 
                check[i] = check[j] + 1;
        }
        result = max(result, check[i]);
    }
    
    cout << result << "\n";

    return 0;
}