#include <string>
#include <iostream>

using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);

    int happy = 0, sad = 0;
    for(int i = 0; i < sentence.size() - 2; i++) {
        if(sentence[i] != ':') continue;

        if(sentence[i  + 1] == '-') {
            if(sentence[i + 2] == ')') happy++;
            else if(sentence[i + 2] == '(') sad++;
            else continue;

            i+= 2;
        }
    }

    if(sad == 0 && happy == 0) cout << "none";
    else if(sad < happy) cout << "happy";
    else if(sad == happy) cout << "unsure";
    else cout << "sad";

    cout << "\n";

    return 0;
}