#include <iostream>

using namespace std;

int N, M;

int jewel[300001];

int main() {
    cin >> N >> M;

    int left = 1, right = -1;
    for(int i = 0; i < M; i++) {
        cin >> jewel[i];

        if(right < jewel[i]) 
            right = jewel[i]; 
    }
    
    int jealous = 999999999;
    
    while (left <= right) {
        int mid = (left + right) / 2;

        int divide = 0;
        for(int i = 0; i < M && (divide <= N); i++) {
            int jewelCnt = jewel[i];

            do {
                divide++;
                jewelCnt -= mid;
            } while(jewelCnt > mid);

            if(jewelCnt > 0) divide++;
         }

        if(divide > N) 
            left = mid + 1;
        else {
            right = mid - 1;
            jealous = min(jealous, mid);
        }   
    }

    cout << jealous << "\n";

    return 0;
}