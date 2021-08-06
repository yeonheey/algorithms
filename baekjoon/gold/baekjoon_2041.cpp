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