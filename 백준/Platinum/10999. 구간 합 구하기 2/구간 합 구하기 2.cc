#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

long long query(vector<long long>& tree, vector<long long>& lazy, long long node, long long start, long long end, long long left, long long right) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    long long left_value = query(tree, lazy, node * 2, start, mid, left, right);
    long long right_value = query(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
    return left_value + right_value;
}

void update(vector<long long>& tree, vector<long long>& lazy, long long node, long long start, long long end, long long left, long long right, long long value) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start > right || end < left) return;
    if (start >= left && end <= right) {
        tree[node] += (end - start + 1) * value;
        if (start != end) {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(tree, lazy, node * 2, start, mid, left, right, value);
    update(tree, lazy, node * 2 + 1, mid + 1, end, left, right, value);
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

    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> numbers(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    int h = (int)ceil(log2(N));
    int tree_size = 1 << (h + 1);
    vector<long long> tree(tree_size);
    vector<long long> lazy(tree_size, 0);

    init(numbers, tree, 1, 0, N - 1);

    int A;
    for (int i = 0; i < M + K; i++) {
        cin >> A;
        if (A == 1) {
            long long b, c, d;
            cin >> b >> c >> d;
            update(tree, lazy, 1, 0, N - 1, b - 1, c - 1, d);
        } else {
            long long b, c;
            cin >> b >> c;
            cout << query(tree, lazy, 1, 0, N - 1, b - 1, c - 1) << "\n";
        }
    }
    return 0;
}