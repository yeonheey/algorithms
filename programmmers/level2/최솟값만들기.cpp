#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int vecSize = A.size();

    if(*max_element(A.begin(), A.end()) < *max_element(B.begin(), B.end()) ) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), greater<int>());
    } 
    else {
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end());
    }

    for(int i = 0; i < vecSize; i++) {
        answer += A[i] * B[i];
    }

    return answer;
}