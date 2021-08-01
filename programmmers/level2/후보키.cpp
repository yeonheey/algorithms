#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

//모든 조합에 대해 최소성을 확인하는 코드가 길어짐 -> 구글링
//비트마스킹을 이용
//적은 메모리, 속도 향상, 코드 간단

//이름, 전공, 학년도 유일하게 식별가능하지만 최소성을 만족x
//이름, 전공이 이미 후보키가 되므로 if문에서 유일하게 식별이 가능한지 확인
bool isMinimal(vector<int> vect, int bit)
{
    for(int i = 0; i < vect.size(); i++)
        if((vect[i] & bit) == vect[i]) //이미 들어온 조합인지
            return false;
    
    return true;
}

int solution(vector<vector<string>> relation) {
    vector<int> count;
    
    int rows = relation.size();
    int cols = relation[0].size();
    
    //속성들의 모든 조합 (1 ~ cols^2 - 1)
    for(int i = 0; i < (1 << cols); i++)
    {
        unordered_set<string> candidate_keys;
        
        for(int j = 0; j < rows; j++)
        {
            string candidates = "";
            
            for(int k = 0; k < cols; k++)
                if(i & (1 << k))    //같은 속성을 포함하고 있는 경우
                    candidates += relation[j][k];
            
            candidate_keys.insert(candidates);
        }
        
        //최소성 확인
        if(candidate_keys.size() == rows && isMinimal(count, i))
            count.push_back(i);
        
    }
    
    return count.size();
}