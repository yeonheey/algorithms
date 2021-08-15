#include <string>
#include <iostream>

using namespace std;

int main() {
    string word, bomb;
    cin >> word >> bomb;

    int bombSize = bomb.size();
    string result = "";

    for (int i = 0; i < word.size(); i++)
    {
        result += word[i];

        if(result.size() < bombSize || result.back() != bomb.back())
            continue;

        bool same = true;
        for (int j = 0; j < bombSize; j++)
            if(result[result.size() - j - 1] != bomb[bombSize - 1 - j])
                same = false;

        if(same)
            for(int i = 0; i < bombSize; i++)
                result.pop_back();
    }
    
    if (result == "") {
        cout << "FRULA\n";
    }
    else {
        cout << result << "\n";
    }
    
    return 0;
}