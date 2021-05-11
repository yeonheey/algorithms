#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
    if (a == 0) return b;
    return GCD(b % a, a);
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1; i < arr.size(); i++)
        answer = LCM(answer, arr[i]);

    return answer;
}
