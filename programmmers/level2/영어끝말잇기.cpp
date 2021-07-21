#include <string>
#include <set>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    
    set<string> checkWord;
    for(int i = 0; i < words.size(); i++) {
        if(checkWord.size() == 0) 
            checkWord.insert(words[i]);
        else if(words[i - 1].back() == words[i].front() && checkWord.find(words[i]) == checkWord.end()) 
            checkWord.insert(words[i]);
        else {
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            break;
        }
    }

    return answer;
}