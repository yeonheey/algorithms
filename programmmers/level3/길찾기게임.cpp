#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x, y, idx;
    Node* rChild = NULL;
    Node* lChild = NULL;
    
    Node(int _x, int _y, int _idx) {x = _x, y = _y, idx = _idx;}
};

vector<int> post;
vector<int> pre;

bool cmp(const Node& a, const Node& b) {
    if(a.y == b.y) 
        return (a.x < b.x);
    
    return (a.y > b.y);
}

void makeTree(Node* parent, Node* child) {
    if(parent->x < child->x) {
        if(parent->rChild == NULL)
            parent->rChild = child;
        else
            makeTree(parent->rChild, child);
    }
    else {
        if(parent->lChild == NULL)
            parent->lChild = child;
        else
            makeTree(parent->lChild, child);
    }
}

void preorder(Node* node) {
    if(node == NULL) return;
    
    pre.push_back(node->idx);
    preorder(node->lChild);
    preorder(node->rChild);
}

void postorder(Node* node) {
    if(node == NULL) return;

    postorder(node->lChild);
    postorder(node->rChild);
    post.push_back(node->idx);
}

vector<vector<int> > solution(vector<vector<int> > nodeinfo) {
    vector<vector<int> > answer;
    vector<Node> tree;
    
    for(int i = 0; i < nodeinfo.size(); i++) 
        tree.push_back(Node(nodeinfo[i][0], nodeinfo[i][1], i + 1));
    
    sort(tree.begin(), tree.end(), cmp);
    Node* root = &tree[0];
    
    for(int i = 1; i < tree.size(); i++)
        makeTree(root, &tree[i]);
    
    preorder(root);
    postorder(root);
    
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}