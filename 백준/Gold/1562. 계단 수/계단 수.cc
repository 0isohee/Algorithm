#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(10, vector<long long>(1 << 10, 0)));

    for (int i = 1; i <= 9; ++i) {
        dp[1][i][1 << i] = 1; 
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int bitmask = 0; bitmask < (1 << 10); ++bitmask) {
                if (j > 0) {
                    dp[i][j][bitmask | (1 << j)] = (dp[i][j][bitmask | (1 << j)] + dp[i - 1][j - 1][bitmask]) % MOD;
                }
                if (j < 9) {
                    dp[i][j][bitmask | (1 << j)] = (dp[i][j][bitmask | (1 << j)] + dp[i - 1][j + 1][bitmask]) % MOD;
                }
            }
        }
    }

    long long result = 0;
    for (int j = 0; j <= 9; ++j) {
        result = (result + dp[N][j][(1 << 10) - 1]) % MOD;
    }

    cout << result << endl;

    return 0;
}