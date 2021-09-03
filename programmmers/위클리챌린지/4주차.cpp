#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    int maxScore = 0;
    
    map<string, int> lang;
    for(int i = 0; i < languages.size(); i++) 
        lang[languages[i]] = preference[i];
    
    for(string str: table) {
        vector<string> arr;
        int sum = 0;
        
        int prev = 0, cur = str.find(' ');
        
        while(cur != string::npos)  {
            arr.push_back(str.substr(prev, cur - prev));
            
            prev = cur + 1;
            cur = str.find(' ', prev);
        }
        arr.push_back(str.substr(prev, cur - prev));
        
        for(int i = 1; i < 6; i++) {
            if(lang.find(arr[i]) != lang.end()) 
                sum += lang[arr[i]] * (6 - i);
        }
        
        if(sum > maxScore || (sum == maxScore && answer > arr[0])) {
            maxScore = sum;
            answer = arr[0];
        }
    }
    
    return answer;
}