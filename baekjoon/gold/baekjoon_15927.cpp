#include <string>
#include <iostream>

using namespace std;

int main() {
    string word;
    cin >> word;
    
    bool palindrome = false;
    bool notPalindrome = false;
    
    int wordSize = word.size();
    for(int i = 0; i < wordSize / 2; i++) {
        if(word[i] != word[wordSize - 1 -i]) {
            notPalindrome = true;
            break;
        }
        if(word[i] != word[i + 1]) 
            palindrome = true;
    }
    
    if(notPalindrome) 
        cout << word.size() << "\n";
    else if(palindrome) 
        cout << word.size() - 1 << "\n";
    else 
        cout << -1 << "\n";

    return 0;
}