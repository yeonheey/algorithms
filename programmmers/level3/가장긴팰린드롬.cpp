#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string s)
{
    int size = s.size();
    int maxLength = 1;
    
    for(int i = 0; i < size; i++) 
        for(int j = size - 1; j > i; j--) {
            if(s[i] != s[j]) continue;
            if(maxLength > j - i + 1) break;
            
            bool isPossible = true;
            for(int k = (j - i + 1) / 2; k >= 0; k--) 
                if(s[i + k] != s[j - k]) {
                    isPossible = false; break;
                }
            
            if(isPossible) 
                maxLength = max(maxLength, j - i + 1);
        }
    
    return maxLength;
}