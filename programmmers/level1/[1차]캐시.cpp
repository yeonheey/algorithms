#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dq;
    
    if(cacheSize == 0)
        return 5 * cities.size();
    
    for(string city: cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        bool find = false;
        for(int i = 0; i < dq.size(); i++) 
            if(dq[i] == city) {
                find = true;
                answer++;
                dq.erase(dq.begin() + i);
                dq.push_back(city);
                
                break;
            }
        
        if(!find) {
            answer += 5;
            if(dq.size() == cacheSize) 
                dq.pop_front();
            
            dq.push_back(city);
        }
    }
    
    return answer;
}