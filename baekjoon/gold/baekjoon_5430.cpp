#include <deque>
#include <string>
#include <iostream>

using namespace std;

int t;
deque<int> arrQ;

void splitStr(string arrStr) {
    string num = "";
    
    for(char ch: arrStr) {
        if(ch == '[') continue;
        
        if(ch >= '0' && ch <= '9')
            num += ch;
        else if(ch == ',' || ch == ']')
            if(!num.empty()) {
                arrQ.push_back(stoi(num));
                num = "";
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>t;
    
    while (t-- > 0) {
        string funcStr, arrStr;
        int n;
        
        cin >> funcStr;
        cin >> n;
        cin >> arrStr;
        
        splitStr(arrStr);
        bool isReversed = false, canPrint = true;
        
        for(char func: funcStr) {
            if(func == 'R') 
                isReversed = !isReversed;
            else {
                if(arrQ.empty()) {
                    canPrint = false;
                    break;
                } 
                
                if(isReversed) arrQ.pop_back();
                else           arrQ.pop_front();
            }     
        }
        
        if(canPrint) {
            cout<<"[";
            
            if(isReversed) {
                while(!arrQ.empty()) {
                    cout<<arrQ.back();
                    arrQ.pop_back();
                
                    if(!arrQ.empty()) cout<<",";
                }
            }
            else {
                while(!arrQ.empty()) {
                    cout<<arrQ.front();
                    arrQ.pop_front();
                    
                    if(!arrQ.empty()) cout<<",";
                }
            }
            
            cout<<"]\n";
        }
        else
            cout<<"error\n";
    }
    
    return 0;
}