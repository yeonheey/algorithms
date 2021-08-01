#include <algorithm>
#include <iostream>

using namespace std;

const int MAXSIZE = 100001;

int arr[MAXSIZE];

int main() {
    int N, S;
    cin >> N >> S;

    for(int i = 0; i < N; i++) cin >> arr[i];

    int start = 0, end = 0;
    int minLength = MAXSIZE + 1;
    int sum = arr[0];

    while (start <= end && end < N) {
        if(sum >= S) {
            minLength = min(minLength, end - start + 1);
            sum -= arr[start++];
        }
        else 
            sum += arr[++end];
    }

    if(minLength == MAXSIZE + 1) minLength = 0;

    cout << minLength << "\n";

    return 0;
}