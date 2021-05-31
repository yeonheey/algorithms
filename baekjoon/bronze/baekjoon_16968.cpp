#include <string>
#include <iostream>

using namespace std;

int main() {
    string format;
    cin >> format;
    
    int count = 1;
    for(int i = 0; i < format.size(); i++) {
        char loc = format[i];
        
        if(loc == 'd') {
            if(i == 0 || format[i - 1] == 'c') 
                count *= 10;
            else if(format[i - 1] == 'd') 
                count *= 9;
        }
        else if(loc == 'c') {
            if(i == 0 || format[i - 1] == 'd') 
                count *= 26;
            else if(format[i - 1] == 'c')
                count *= 25;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}