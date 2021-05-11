#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer, tempVec(n);
    long long cnt = 1;
    
    for(int i = 1; i <= n; i++) 
    {
        cnt *= i;
        tempVec[i - 1] = i;
    }
    
    k--; //access index
    while(n > 0)
    {
        cnt /= n;
        long long loc = k / cnt;
        
        answer.push_back(tempVec[loc]);
        tempVec.erase(tempVec.begin() + loc);
        
        k %= cnt;
        n--;
    }

    return answer;
}