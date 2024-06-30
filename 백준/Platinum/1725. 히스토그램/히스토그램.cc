#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void init(vector<long long>& a, vector<int>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
    }
    else {
        int mid = (start + end) / 2;
        init(a, tree, node*2, start, mid);
        init(a, tree, node*2 + 1, mid+1, end);
        tree[node] = (a[tree[node*2]] < a[tree[node*2+1]]) ? tree[node*2] : tree[node*2+1];
    }
}

int query(vector<long long>& a, vector<int>& tree, int node, int start, int end, int L, int R) {
    if (R < start || L > end) return -1;
    if (L <= start && end <= R) return tree[node];
    int mid = (start + end) / 2;
    int leftmin = query(a, tree, node*2, start, mid, L, R);
    int rightmin = query(a, tree, node*2+1, mid+1, end, L, R);
    if (leftmin == -1) return rightmin;
    if (rightmin == -1) return leftmin;
    return (a[leftmin] < a[rightmin] ? leftmin : rightmin);
}

long long findMaxRec(vector<long long>& a, vector<int>& tree, int start, int end) {
    if (start > end) return 0;
    int min_idx = query(a, tree, 1, 0, a.size()-1, start, end);
    long long area = (long long)a[min_idx] * (end-start + 1);
    long long left_area = findMaxRec(a, tree, start, min_idx-1);
    long long right_area = findMaxRec(a, tree, min_idx+1, end);
    return max(area, max(left_area, right_area));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int tree_size = 1 << ((int)ceil(log2(n)) + 1);
    vector<int> tree(tree_size);
    init(h, tree, 1, 0, n-1);

    long long max_area = findMaxRec(h, tree, 0, n-1);
    cout << max_area << "\n";

    return 0;
}