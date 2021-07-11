#include <algorithm>
#include <vector>

#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int j = 0;
    for(int i = 0; i < A.size(); i++) 
        if(A[i] < B[j]) {
            answer++; j++;
        }
    
    return answer;
}