#include <vector>
#include <iostream>

using namespace std;

struct Node
{
    int idx = 0;
    char ch, left, right;

    Node(char _c, char _l, char _r){
        ch = _c, left = _l - 'A', right = _r - 'A';
        idx = ch - 'A';
    }
};

int N;
vector<Node> tree;

void preorder(int idx) {
    cout <<tree[idx].ch;
    
    if(tree[idx].left != '.' - 'A')
        preorder(tree[idx].left);

    if(tree[idx].right != '.' - 'A')
        preorder(tree[idx].right);
}

void inorder(int idx) {
    if(tree[idx].left != '.' - 'A') 
        inorder(tree[idx].left);
        
    cout <<tree[idx].ch;

    if(tree[idx].right != '.' - 'A') 
        inorder(tree[idx].right);
}

void postorder(int idx) {
    if(tree[idx].left != '.' - 'A') 
        postorder(tree[idx].left);
        
    if(tree[idx].right != '.' - 'A') 
        postorder(tree[idx].right);

    cout <<tree[idx].ch;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++)
        tree.push_back(Node(0,'.','.'));

    for(int i = 0; i < N; i++) {
        char ch, left, right;
        cin >> ch >> left >> right;

        tree[ch - 'A'] = Node(ch, left, right);
    }

    Node root = tree[0];

    preorder(root.idx);
    cout <<"\n";

    inorder(root.idx);
    cout <<"\n";
    
    postorder(root.idx);
    cout <<"\n";

    return 0;
}