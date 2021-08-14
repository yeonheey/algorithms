#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

struct File
{
    string name, extension;
    bool isReadable = false;

    File(string _n, string _e) {name = _n, extension = _e;}
};

unordered_set<string> osRead;
vector<File> files;

bool cmp(File& a, File& b) {
    if(a.name < b.name) return true;
    else if(a.name == b.name) {
        if (a.isReadable && !b.isReadable) return true;
        else {
            if(a.extension < b.extension) return true;
            return false;
        }
        
        return false;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string fullFile; 
        cin >> fullFile;

        for(int i = 0; i < fullFile.size(); i++)
            if(fullFile[i] == '.') {
                files.push_back(File(fullFile.substr(0, i), fullFile.substr(i + 1)));
                break;
            }
    }

    for(int i = 0; i < M; i++) {
        string exten;
        cin >> exten;

        osRead.insert(exten);
    }

    for(File& file: files) 
        if(osRead.find(file.extension) != osRead.end())
            file.isReadable = true;
    

    sort(files.begin(), files.end(), cmp);

    for(File file: files) 
        cout << file.name << "." <<file.extension << "\n";

    return 0;
}