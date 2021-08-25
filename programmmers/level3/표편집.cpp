#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int num;
    Node* prev = NULL;
    Node* next = NULL;

    Node(int n) {num = n;}
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');

    // init nodes vector
    vector<Node*> nodes(n);
    for(int i = 0; i < n; i++) nodes[i] = new Node(i);

    nodes[0]->next = nodes[1];
    nodes[n - 1]->prev = nodes[n - 2];

    for(int i = 1; i < n - 1; i++) {
        nodes[i]->prev = nodes[i - 1];
        nodes[i]->next = nodes[i + 1];
    }

    // operations
    stack<int> delStk;

    for(string str: cmd) 
    {
        if(str[0] == 'U' || str[0] == 'D') {
            int x = stoi(str.substr(2));

            if(str[0] == 'U') 
                while(x--) 
                    k = nodes[k]->prev->num;
            else
                while(x--)
                    k = nodes[k]->next->num;
        }
        else if(str[0] == 'C') {
            delStk.push(k);

            if(nodes[k]->prev != NULL)
                nodes[k]->prev->next = nodes[k]->next;

            if(nodes[k]->next != NULL) {
                nodes[k]->next->prev = nodes[k]->prev;
                k = nodes[k]->next->num;
            } 
            else 
                k = nodes[k]->prev->num;
        }
        else if(str[0] == 'Z') {
            int del = delStk.top(); delStk.pop();

            if(nodes[del]->prev != NULL)
                nodes[del]->prev->next = nodes[del];
            if(nodes[del]->next != NULL)
                nodes[del]->next->prev = nodes[del];
        }
        else return "";
    }

    int l = k, r = k;

    answer[l] = 'O';
    while(nodes[l]->prev != NULL) {
        l = nodes[l]->prev->num;
        answer[l] = 'O';
    }

    while(nodes[r]->next != NULL) {
        r = nodes[r]->next->num;
        answer[r] = 'O';
    }

    return answer;
}