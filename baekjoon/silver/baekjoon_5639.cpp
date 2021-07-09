#include<memory.h>
#include <iostream>

using namespace std;

int tree[1000001][2]; // 0: left, 1: right

void preOrder(int find, int cur) {
    if(find < cur) {
        if(tree[cur][0] == -1) tree[cur][0] = find;
        else preOrder(find, tree[cur][0]);
    }
    else {
        if(tree[cur][1] == -1) tree[cur][1] = find;
        else preOrder(find, tree[cur][1]);
    }
}

void postOrder(int cur) {
    //left, right, root
    if(tree[cur][0] != -1) 
        postOrder(tree[cur][0]);
    if(tree[cur][1] != -1) 
        postOrder(tree[cur][1]);
    
    cout << cur << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int root = -1;
    memset(tree, -1, sizeof(tree));

    while(true) {
        int number; 
        cin >> number;

        if(cin.eof() == true) break;
        
        if(root == -1) root = number;
        else preOrder(number, root);
    }

    postOrder(root);

    return 0;
}