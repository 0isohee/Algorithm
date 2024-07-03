#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

struct Node {
    long long value;
    int index;
};

Node query(vector<Node>& tree, int node, int start, int end, int left, int right) {
    if (start > right || end < left) return {LLONG_MAX, -1}; // 범위를 벗어나면 큰 값 반환
    if (start >= left && end <= right) return tree[node];

    int mid = (start + end) / 2;
    Node left_value = query(tree, node * 2, start, mid, left, right);
    Node right_value = query(tree, node * 2 + 1, mid + 1, end, left, right);

    if (left_value.value < right_value.value) return left_value;
    if (left_value.value > right_value.value) return right_value;
    return left_value.index < right_value.index ? left_value : right_value;
}

void update(vector<long long>& a, vector<Node>& tree, int node, int start, int end, int idx, long long value) {
    if (start > idx || end < idx) return;
    if (start == end) {
        a[idx] = value;
        tree[node] = {a[idx], idx};
    } else {
        int mid = (start + end) / 2;
        update(a, tree, node * 2, start, mid, idx, value);
        update(a, tree, node * 2 + 1, mid + 1, end, idx, value);
        if (tree[node * 2].value < tree[node * 2 + 1].value) {
            tree[node] = tree[node * 2];
        } else if (tree[node * 2].value > tree[node * 2 + 1].value) {
            tree[node] = tree[node * 2 + 1];
        } else {
            tree[node] = (tree[node * 2].index < tree[node * 2 + 1].index) ? tree[node * 2] : tree[node * 2 + 1];
        }
    }
}

void init(vector<long long>& a, vector<Node>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = {a[start], start};
    } else {
        int mid = (start + end) / 2;
        init(a, tree, node * 2, start, mid);
        init(a, tree, node * 2 + 1, mid + 1, end);
        if (tree[node * 2].value < tree[node * 2 + 1].value) {
            tree[node] = tree[node * 2];
        } else if (tree[node * 2].value > tree[node * 2 + 1].value) {
            tree[node] = tree[node * 2 + 1];
        } else {
            tree[node] = (tree[node * 2].index < tree[node * 2 + 1].index) ? tree[node * 2] : tree[node * 2 + 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int tree_size = 1 << (int)(ceil(log2(N)) + 1);
    vector<Node> tree(tree_size, {LLONG_MAX, -1});
    vector<long long> numbers(N, 0);

    for (int i = 0; i < N; i++) {
        long long temp;
        cin >> temp;
        numbers[i] = temp;
    }

    init(numbers, tree, 1, 0, N - 1);

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int mode;
        cin >> mode;

        if (mode == 1) {
            int idx;
            long long value;
            cin >> idx >> value;
            update(numbers, tree, 1, 0, N - 1, idx - 1, value);
        } else if (mode == 2) {
            int left, right;
            cin >> left >> right;
            Node result = query(tree, 1, 0, N - 1, left - 1, right - 1);
            cout << result.index + 1 << "\n";
        }
    }
    return 0;
}
