#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//language, work, experience, food
vector<int> info_score[3][2][2][2];

vector<int> split(string str) {
    string temp = "";
    vector<int> result;
    
    int n = 0;
    for(char ch: str) 
    {
        if(ch == ' ')
        {
            if (temp == "and") 
            {
                temp = ""; continue;
            }
            
            if(temp == "-") n = -1;
            else if(temp == "java" || temp == "frontend" || temp == "senior" || temp == "pizza") n = 1;
            else if(temp == "python") n = 2;
            else n = 0;
            
            result.push_back(n);
            temp = "";
        }
        else
            temp += ch;
    }
    
    result.push_back(stoi(temp));
    
    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    int info_size = info.size();
    int query_size = query.size();
    vector<int> answer;

	//info to vector
    for(string str: info) 
    {
        vector<int> loc = split(str);
        info_score[loc[0]][loc[1]][loc[2]][loc[3]].push_back(loc[4]);
    }
    
    //sort to binary search
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                for(int l = 0; l < 2; l++)
                    sort(info_score[i][j][k][l].begin(), info_score[i][j][k][l].end());
    
    //query to vector
    for(string str: query) 
    {
        vector<int> loc = split(str);
        
        int count = 0;
        
        int lang_a = 0, lang_b = 2, work_a = 0, work_b = 1;
        int exp_a = 0, exp_b = 1, food_a = 0, food_b = 1;
        int score = loc[4];
        
        if(loc[0] != -1)
            lang_a = lang_b = loc[0];
        if(loc[1] != -1) 
            work_a = work_b = loc[1];
        if(loc[2] != -1) 
            exp_a = exp_b = loc[2];
        if(loc[3] != -1)
            food_a = food_b = loc[3];
        
        //만족하는 조건 찾기
        for(int i = lang_a; i <= lang_b; i++)
            for(int j = work_a; j <= work_b; j++)
                for(int k = exp_a; k <= exp_b; k++)
                    for(int l = food_a; l <= food_b; l++) 
                    {
                        int size = info_score[i][j][k][l].size();
                        if(size == 0) continue;
                        
                        vector<int>::iterator iter = 
                            lower_bound(info_score[i][j][k][l].begin(), info_score[i][j][k][l].end(), score);
                        
                        if(iter == info_score[i][j][k][l].end()) continue;
                        
                        count += size - (iter - info_score[i][j][k][l].begin());
                    }
        
        answer.push_back(count);
    }
    
    return answer;
}
