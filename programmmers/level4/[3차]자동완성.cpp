#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 999999999;

int solution(vector<string> words) {
    int cnt = 0;
    int wordSize = words.size();
    
    sort(words.begin(), words.end());
    
    for(int i = 0; i < wordSize; i++) {
        int diff = MAX;
        
        if(i - 1 >= 0) {
            int temp = 0;
            for(int j = 0; j < words[i].size(); j++) {
                ++temp;
                
                if(!(j < words[i - 1].size() && words[i][j] == words[i - 1][j])) 
                    break;
            }
            
            if(diff == MAX) diff = temp;
            else if(temp > diff) diff = temp;
        }
        if(i + 1 < wordSize) {
            int temp = 0;
            for(int j = 0; j < words[i].size(); j++) {
                ++temp;
                
                if(!(j < words[i + 1].size() && words[i][j] == words[i + 1][j])) 
                    break;
            }
            
            if(diff == MAX) diff = temp;
            else if(temp > diff) diff = temp;
        }
        
        cnt += diff;
    }
    
    return cnt;
}