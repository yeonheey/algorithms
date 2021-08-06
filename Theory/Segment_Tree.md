### 세그먼트 트리
#### 세그먼트 트리(Segment Tree)란?
구간 합을 구할 때 많이 사용된다. 특히, 연산에 배열의 값이 변경되는 경우에 적합하다.
특정 구간의 합을 구하는 연산(1), 특정 인덱스의 값을 벼경하는 연산(2)을 합쳐 총 M 번 진행한다고 하자.
전체 배열의 길이가 N일때, 1번 연산은 O(N), 2번 연산은 O(1)이므로 시간복잡도는 O(NM)이다.
N과 M 값이 커져버리면 많은 시간을 소요하게 되므로 이 시간 복잡도를 줄여줄 수 있는 세그먼트 트리를 이용하면 O(log N)으로 해결할 수 있다.
<br />
##### 세그먼트 트리 생성과정
트리의 구조는 각 노드에 인덱스를 저장하고, 리프노트에 각 인덱스에 해당하는 값들이 저장되게 된다.
이해를 돕기 위해 백준 '구간합 구하기' 2042번 문제 풀이를 참고하자.
(백터로 세그먼트 트리를 구성, 트리 구조 이므로 node를 탐색한 뒤에 2 * node(left), 2 * node(right) 를 탐색)
<br /> <br />
```c++
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

struct Order {
    int a, b, c;
    Order(int _a, int _b, int _c) {a = _a, b = _b, c = _c;}
};

int N, M, K;

vector<long long> arr;
vector<long long> tree;
vector<Order> orders;

long long make_segmentTree(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    
    int mid = (start + end) / 2;
    
    long long left = make_segmentTree(node * 2, start, mid);
    long long right = make_segmentTree(node * 2 + 1, mid + 1, end);
    
    tree[node] = left + right;
    return tree[node];
}
void update_SegmentTree(int node, int start, int end, int idx, long long differ) {
    if(idx < start || idx > end) return;
    
    tree[node] += differ;
    
    if(start != end) {
        int mid = (start + end) / 2;
    
        update_SegmentTree(node * 2, start, mid, idx, differ);
        update_SegmentTree(node * 2 + 1, mid + 1, end, idx, differ);
    }
}

long long sum_SegmentTree(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return tree[node];
    
    int mid = (start + end) / 2;
    
    long long leftResult = sum_SegmentTree(node * 2, start, mid, left, right);
    long long rightResult = sum_SegmentTree(node * 2 + 1, mid + 1, end, left, right);
    
    return leftResult + rightResult;
}
int main() {
    cin >> N >> M >> K;
    M += K;
    
    for(int i = 0, number; i < N; i++) {
        cin >> number;
        arr.push_back(number);
    }
    
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
    
        orders.push_back(Order(a, b, c));
    }
    
    int height = (int)ceil(log2(N));
    int Size = (1 << (height + 1));
    
    tree.resize(Size);
    make_segmentTree(1, 0, N - 1);
    
    for(Order order: orders) {
        if(order.a == 1) {
            int idx = order.b - 1;
            long long value = order.c;
            long long differ = value - arr[idx];
            
            arr[idx] = value;
            
            update_SegmentTree(1, 0, N - 1, idx, differ);
        }
        else {
            int start = order.b - 1;
            int end = order.c - 1;
            
            long long sumResult = sum_SegmentTree(1, 0, N - 1, start, end);
            
            cout << sumResult << "\n";
        }
    }
    return 0;
}
```
