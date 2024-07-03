#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	if(start >= left && end <= right) return tree[node];

	int mid = (start + end) / 2;
	long long left_value = sum(tree, node * 2, start, mid, left, right);
	long long right_value = sum(tree, node * 2 + 1, mid + 1, end, left, right);
	return left_value + right_value;
}

void modify(vector<long long>& tree, int node, int start, int end, int idx, int value) {
	if (start > idx || end < idx) return;
	if (start == end){
		tree[node] = value;
	}
	else {
		int mid = (start + end) / 2;
		modify(tree, node * 2, start, mid, idx, value);
		modify(tree, node * 2+1, mid+1, end, idx, value);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int tree_size = 1 << (int)(ceil(log2(N))+1);
	vector<long long> tree(tree_size, 0);

	for (int m = 0; m < M; m++) {
		int mode;
		cin >> mode;

		if (mode == 0) {
			int i, j;
			cin >> i >> j;
			if (i > j) {
				swap(i, j);
			}
			long long ans = sum(tree, 1, 0, N - 1, i-1, j-1);
			cout << ans << "\n";
		}
		else {
			int idx, k;
			cin >> idx >> k;
			modify(tree, 1, 0, N - 1, idx-1, k);
		}
	}
	return 0;
}