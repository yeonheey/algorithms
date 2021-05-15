#include <vector>
using namespace std;
vector<int> solution(int n, int s) {
    vector<int> answer(n); //오름차순
    
    int base = s / n;
    if(base < 1) 
        answer = { -1 };
    else
    {
        for(int i = 0; i < n; i++)
            answer[i] = base;
        
        int left = s % n;
        for(int i = 0; i < left; i++)
            answer[n - 1 - i]++;
    }
    
    return answer;
}