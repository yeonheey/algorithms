#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    vector<unordered_set<int> > check(9);
    
    int temp = 0;
    for(int i = 0; i < 8; i++)
    {
        temp = 10 * temp + 1;
        if(temp * N == number) return i + 1;
        check[i].insert(temp * N);
    }
    
    for(int i = 1; i < 9; i++) //최대 8번
    {
        for(int j = 0; j < i; j++) //j 기준
            for(int num1 : check[j])
                for(int num2 : check[i - j - 1])
                {
                    check[i].insert(num1 + num2);
                    check[i].insert(num1 - num2);
                    check[i].insert(num1 * num2);
                    
                    if(0 != num2)
                        check[i].insert(num1 / num2);
                }
        
        if(check[i].find(number) != check[i].end())
        {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}