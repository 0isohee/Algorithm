#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

void compute_prefix_sums(const vector<vector<int>>& board, vector<vector<int>>& prefix_sum, int n, int m) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prefix_sum[i][j] = board[i-1][j-1] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
        }
    }
}

int get_sum(const vector<vector<int>>& prefix_sum, int x1, int y1, int x2, int y2) {
    return prefix_sum[x2][y2] - prefix_sum[x1-1][y2] - prefix_sum[x2][y1-1] + prefix_sum[x1-1][y1-1];
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> board1(n, vector<int>(m));  // W부터 시작하는 체스판과 비교
    vector<vector<int>> board2(n, vector<int>(m));  // B부터 시작하는 체스판과 비교

    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < m; ++j) {
            if ((i + j) % 2 == 0) {
                board1[i][j] = row[j] == 'W' ? 0 : 1;
                board2[i][j] = row[j] == 'B' ? 0 : 1;
            } else {
                board1[i][j] = row[j] == 'B' ? 0 : 1;
                board2[i][j] = row[j] == 'W' ? 0 : 1;
            }
        }
    }

    vector<vector<int>> prefix_sum1(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> prefix_sum2(n + 1, vector<int>(m + 1, 0));

    compute_prefix_sums(board1, prefix_sum1, n, m);
    compute_prefix_sums(board2, prefix_sum2, n, m);

    int min_changes = INT_MAX;

    for (int i = 1; i + k - 1 <= n; ++i) {
        for (int j = 1; j + k - 1 <= m; ++j) {
            int sum1 = get_sum(prefix_sum1, i, j, i + k - 1, j + k - 1);
            int sum2 = get_sum(prefix_sum2, i, j, i + k - 1, j + k - 1);
            min_changes = min({min_changes, sum1, sum2});
        }
    }

    cout << min_changes << endl;
    return 0;
}