#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long number: numbers) {
        if(number % 2 == 0)
            answer.push_back(number + 1);
        else {
            long long checkBit = 1;
            
            while((number & checkBit) != 0) 
                checkBit = (checkBit << 1);
            
            checkBit = (checkBit >> 1);
            
            answer.push_back(number + checkBit);
        }
    }
    
    return answer;
}