#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<string> splitStr(string str)
{
    vector<string> strVec;
    int idx = 0;
    string word = "";
    
    while(str.size() > idx)
    {
        if(str[idx] == ' ')
        {
            strVec.push_back(word);
            word = "";
        }
        else
            word += str[idx];
        
        idx++;
    }
    strVec.push_back(word);
    
    return strVec;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> nickName;
    queue<pair<bool, string> > q;
    
    for(int i = 0; i < record.size(); i++)
    {
        vector<string> strVec = splitStr(record[i]);
        
        if(strVec.size() == 3)
           nickName[strVec[1]] = strVec[2];
       
        if(strVec[0] == "Enter")
            q.push({1, strVec[1]});
        else if(strVec[0] == "Leave")
            q.push({0, strVec[1]});
    }
    
    while(!q.empty())
    {
        bool type = q.front().first;
        string usr = q.front().second;
        q.pop();
        
        string stat = (nickName[usr] + "님이");
        
        if(true == type)
            stat += " 들어왔습니다.";
        else
            stat += " 나갔습니다.";
        
        answer.push_back(stat);
    }
    
    return answer;
}