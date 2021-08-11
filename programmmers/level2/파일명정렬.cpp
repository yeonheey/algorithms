#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct File {
    string Head, Number;
    int idx;
    
    File(string H, string N, int i) {Head = H, Number = N, idx = i;}
};

bool cmp(const File& a, const File& b) {
    if(a.Head < b.Head) return true;
    else if(a.Head == b.Head) {
        if(stoi(a.Number) < stoi(b.Number)) return true;
        else if(stoi(a.Number) == stoi(b.Number)) {
            if(a.idx < b.idx) return true;
            
            return false;
        }
        return false;
    }
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> check;
    
    for(int i = 0; i < files.size(); i++) {
        string file = files[i];
        transform(file.begin(), file.end(), file.begin(), ::tolower);
        
        string head = "", number = "";
        
        int idx = 0;
        for(int i = 0; i < files.size(); i++) {
            if(file[i] >= '0' && file[i] <= '9') {
                idx = i;
                break;
            }
            
            head += file[i];
        }
        
        for(int i = idx; i < files.size(); i++) {
            if(file[i] >= '0' && file[i] <= '9')
                number+= file[i];
            else 
                break;
        }
        
        check.push_back(File(head, number, i));
    }    
    
    sort(check.begin(), check.end(), cmp);
    
    for(File file: check) {
        answer.push_back(files[file.idx]);
    }
    
    return answer;
}