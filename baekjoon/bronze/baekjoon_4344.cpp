#include <cstdio>

using namespace std;

int score[1001];

int main() {
    int Test;
    scanf("%d", &Test);
    
    while(Test--) {
        int N;
        scanf("%d", &N);
        
        double avg = 0;
        for(int i = 0; i < N; i++) {
            scanf("%d", &score[i]);
            avg += score[i];
        }
        
        avg /= N;
        
        double overAvg = 0;
        for(int i = 0; i < N; i++)
            if(avg < score[i]) overAvg++;
        
        double percent = overAvg * 100 / N;
        printf("%.3f%%\n", percent);
    }
    
    return 0;
}