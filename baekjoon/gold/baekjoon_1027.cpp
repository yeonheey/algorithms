#include <iostream>

using namespace std;

int N;
int height[51];
int cnt[51] = {0, };

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> height[i];

    for(int i = 0; i < N; i++) {
        double m = -9999999999;

        for(int j = i + 1; j < N; j++) {
            double tempM = (double)(height[i] - height[j]) / (i - j);

            if(tempM > m) {
                m = tempM;
                cnt[i]++;
                cnt[j]++;
            }
        }
    }

    int result = 0;
    for(int i = 0; i < N; i++)
        if(result < cnt[i])
            result = cnt[i];

    cout << result << "\n";

    return 0;
}