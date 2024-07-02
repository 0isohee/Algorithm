#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long query(vector<long long>& tree, long long node, long long start, long long end, long long left, long long right) {
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    long long left_value = query(tree, node * 2, start, mid, left, right);
    long long right_value = query(tree, node * 2 + 1, mid + 1, end, left, right);
    return left_value + right_value;
}

void update(vector<long long>& a, vector<long long>& tree, long long node, long long start, long long end, long long index, long long value) {
    if (index < start || index > end) return;
    if (start == end) {
        a[index] = value;
        tree[node] = value;
        return;
    }
    int mid = (start + end) / 2;
    update(a, tree, node * 2, start, mid, index, value);
    update(a, tree, node * 2 + 1, mid + 1, end, index, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void init(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        init(a, tree, node * 2, start, mid);
        init(a, tree, node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<long long> numbers(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    int tree_size = 1 << ((int)ceil(log2(N)) + 1);
    vector<long long> tree(tree_size);

    init(numbers, tree, 1, 0, N - 1);

    long long x, y, a, b;
    for (int i = 0; i < Q; i++) {
        cin >> x >> y >> a >> b;
        if (x > y) {
            swap(x, y);
        }
        cout << query(tree, 1, 0, N - 1, x - 1, y - 1) << "\n";
        update(numbers, tree, 1, 0, N - 1, a - 1, b);
    }
    return 0;
}