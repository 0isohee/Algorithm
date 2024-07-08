#include<iostream>
#include<vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> number(n+1, vector<int>(m+1, 0));
	vector<vector<int>> sum(n+1, vector<int>(m+1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> number[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + number[i][j];
		}
	}

	int k;
	cin >> k;

	for (int idx = 0; idx < k; idx++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		long long answer = sum[x][y] - sum[x][j-1] - sum[i-1][y] + sum[i-1][j-1];

		cout << answer << "\n";
	}
	return 0;
}