#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;


long long query(vector<long long>& tree, int node, int start, int end, int left, int right) {
    if (start > right || end < left) return LLONG_MAX; // 범위를 벗어나면 큰 값 반환
    if (start >= left && end <= right) return tree[node];

    int mid = (start + end) / 2;
    long long left_value = query(tree, node * 2, start, mid, left, right);
    long long right_value = query(tree, node * 2 + 1, mid + 1, end, left, right);

    return min(left_value, right_value);
}

void update(vector<long long>&a, vector<long long>&tree, int node, int start, int end, int idx, long long value) {
    if (start > idx || end < idx) return;
    if (start == end) {
        a[idx] = value;
        tree[node] = a[idx];
    }
    else {
        int mid = (start + end) / 2;
        update(a, tree, node * 2, start, mid, idx, value);
        update(a, tree, node * 2 + 1, mid + 1, end, idx, value);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}

void init(vector<long long>&a, vector<long long>&tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    }
    else {
        int mid = (start + end) / 2;
        init(a, tree, node * 2, start, mid);
        init(a, tree, node * 2 + 1, mid + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int tree_size = 1 << (int)(ceil(log2(N)) + 1);
    vector<long long> tree(tree_size, LLONG_MAX);
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
        }
        else if (mode == 2) {
            int left, right;
            cin >> left >> right;
            long long result = query(tree, 1, 0, N - 1, left - 1, right - 1);
            cout << result << "\n";
        }
    }

    return 0;
}
