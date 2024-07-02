#include<iostream>
#include<vector>
#include <unordered_map>
#include<cmath>
#include<algorithm>
using namespace std;

// Function to update the segment tree
void update(vector<int>& tree, int node, int start, int end, int idx) {
    if (start == end) {
        tree[node] += 1;
    }
    else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(tree, node * 2, start, mid, idx);
        }
        else {
            update(tree, node * 2 + 1, mid + 1, end, idx);
        }
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

// Function to query the segment tree
int query(vector<int>& tree, int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(tree, node * 2, start, mid, left, right);
    int p2 = query(tree, node * 2 + 1, mid + 1, end, left, right);
    return p1 + p2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> a_numbers(N);
    unordered_map<int, int> b_numbers;
    for (int i = 0; i < N; i++) {
        cin >> a_numbers[i];
    }

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        b_numbers[temp] = i;
    }

    int h = (int)ceil(log2(N));
    int tree_size = 1 << (h + 1);
    vector<int> tree(tree_size, 0);

    long long result = 0;
    for (int i = 0; i < N; i++) {
        int now_value = a_numbers[i];
        int idx = b_numbers[now_value];
        result += query(tree, 1, 0, N - 1, idx + 1, N - 1);
        update(tree, 1, 0, N - 1, idx);
    }
    cout << result << "\n";
    return 0;
}