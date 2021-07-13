#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>

using namespace std;

void divideProfit(vector<int>& answer, const vector<int>& parent, int cur, int profit) {
    int give = profit / 10;
    
    answer[cur] += (profit - give);
    profit -= give;
    
    if(parent[cur] == -1) return;
    if(profit < 1) return;
    
    divideProfit(answer, parent, parent[cur], give);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    
    vector<int> parent(enroll.size(), -1);
    unordered_map<string, int> checkIndex;
    
    for(int i = 0; i < enroll.size(); i++) 
        checkIndex[enroll[i]] = i;
    
    for(int i = 0 ; i < referral.size(); i++) {
        if(referral[i] == "-") continue;
        
        int idx = checkIndex[referral[i]];
        parent[i] = idx;
    }
    
    for(int i = 0; i < seller.size(); i++) {
        int idx = checkIndex[seller[i]];
        
        divideProfit(answer, parent, idx, amount[i] * 100);
    }

    return answer;
}