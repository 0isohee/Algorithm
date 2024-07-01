#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void update(int idx, vector<long long>&tree, int node, int start, int end){
    if (start > idx || end < idx) return;
    if (start == end) {
       tree[node] += 1;
    }
    else {
        int mid = (start + end)/2;
        update(idx, tree, node*2, start, mid);
        update(idx, tree, node*2+1, mid+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

long long query(vector<long long>&tree, int node, int start, int end, int left, int right){
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) return tree[node];

    int mid = (start + end) /2;
    long long left_value = query(tree, node*2, start, mid, left, right);
    long long right_value = query(tree, node*2+1, mid+1, end, left, right);
    return left_value + right_value;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<long long> number(n);
    for (int i=0; i<n; i++){
        cin >> number[i];
    }

    vector<long long> sorted_number = number;
    sort(sorted_number.begin(), sorted_number.end());

    //0~n-1로 좌표 압축
    for (int i = 0; i < n; i++) {
        number[i] = lower_bound(sorted_number.begin(), sorted_number.end(), number[i]) - sorted_number.begin();
    }

    int tree_size = 1 << (int)(ceil(log2(n)+1));
    vector<long long> tree(tree_size, 0);

    long long cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        cnt += query(tree, 1, 0, n - 1, 0, number[i]-1);
        update(number[i], tree, 1, 0, n - 1);
    }
    cout << cnt << "\n";
    return 0;
}