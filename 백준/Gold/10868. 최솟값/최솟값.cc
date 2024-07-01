#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const long long INF = 1e9 + 1;

void init(vector<long long>&a, vector<long long>&tree, int node, int start, int end){
    if (start == end) {
        tree[node] = a[start];
    }
    else {
        int mid = (start + end) / 2;
        init(a, tree, node*2, start, mid);
        init(a, tree, node*2+1, mid+1, end);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

int query(vector<long long>&tree, int node, int start, int end, int left, int right){    
    if (start > right || end < left) return INF;
    if (start >= left && end <= right) return tree[node];

    int mid = (start + end) /2;
    int minL = query(tree,node*2, start, mid, left, right);
    int minR = query(tree,node*2+1, mid+1, end, left, right);
    return min(minL, minR);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    vector<long long> number(N);
    for (int i=0; i<N; i++){
        cin >> number[i];
    }

    int tree_size = 1 << (int)(ceil(log2(N)+1));
    vector<long long> tree(tree_size);

    init(number, tree, 1, 0, N-1);

    for (int i=0; i<M; i++){
        int s, e;
        cin >> s >> e;
        cout << query(tree, 1, 0, N-1, s-1, e-1) << "\n";
    }
    return 0;
}