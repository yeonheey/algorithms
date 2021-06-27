#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int MULTI = 65536;

int makeMultiSet(const string& str, unordered_map<string, int>& Map) {
    int count = 0;
    
    for(int i = 0; i < str.size() - 1; i++) {
        if(!(str[i] >= 'a' && str[i] <= 'z')) continue;
        if(!(str[i + 1] >= 'a' && str[i + 1] <= 'z')) continue;
        
        Map[str.substr(i, 2)]++;
        count++;
    }
    
    return count;
}

int solution(string str1, string str2) {
    double result = 0;
    unordered_map<string, int> map1, map2;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    int count1 = makeMultiSet(str1, map1);
    int count2 = makeMultiSet(str2, map2);

    if(count1 == 0 && count2 == 0) return MULTI;
    
    double interSection = 0, totalCnt = 0;
    unordered_map<string, int> total = map1;
    
    for(auto& iter: map2) {
        if(total.find(iter.first) == total.end())
            total.insert({iter.first, iter.second});
        else {
            interSection += min(total[iter.first], iter.second);
            total[iter.first] = max(total[iter.first], iter.second);
        }
    }
    
    for(auto& iter: total) totalCnt += iter.second;
    
    result = (interSection / totalCnt) * MULTI;
    
    return (int)result;
}